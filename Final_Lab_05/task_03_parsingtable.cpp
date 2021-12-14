#include <bits/stdc++.h>
using namespace std;

struct Rule{
	string rule;
	char parent;
	string first;
	string follow;
};

string findTerminal(Rule rules[],int n,char parent);
string findFirst(Rule rules[],int n,char parent);
int firstPos(Rule rules[],int n,char parent);
string findFollow(Rule rules[],int n,char parent,char currentP,string follow);
string getUniqueChar(string str);
void constructTable(Rule rules[],int n);
string findFirstTable(Rule rules[],int n,char parent);
void match();
string getAction(char chnT,char chT);

string table[1000][1000];
int nonT = -1;
int noT = -1;
string terminals = "";
string nonTerminals = "";
string matched = "";
string todo = "";
string input = "";
string action = "";

int main(){
    cout<<"\n(A-Z is non-terminals) and (a-z except e is terminals) and (| is or) and (= is to define) and (e is epsilon)\nExample, A=ab|B|e"<<endl;
	cout<<"\nEnter number of rules: ";
	int t;
	cin>>t;
	Rule rules[t];
	cout<<"\nEnter rules:\n"<<endl;
	for(int i=0;i<t;i++){
		string str;
		getline(cin>>ws,str);
		str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
		for(int j=0;j<str.length();j++){
			if(str[j]=='|'){
				str[j] = ' ';
			}
		}
		str += " ";
		rules[i].rule = str.substr(2,str.length());
		rules[i].parent = str[0];
		rules[i].first = "";
		if(i==0) rules[i].follow = "$";
		else rules[i].follow = "";
	}
	for(int i=0;i<t;i++){
		string first = findFirst(rules,t,rules[i].parent);
		rules[i].first += getUniqueChar(first);
	}
	cout<<endl;
	for(int i=0;i<t;i++){
		cout<<"First("<<rules[i].parent<<") = { ";
		string first = rules[i].first;
		for(int j=0;j<first.length();j++){
			cout<<first[j];
			if(j==first.length()-1) break;
			cout<<", ";
		}
		cout<<" }"<<endl;
	}
	for(int i=0;i<t;i++){
		string follow = findFollow(rules,t,rules[i].parent,rules[i].parent,rules[i].follow);
		rules[i].follow = getUniqueChar(follow);
	}
	cout<<endl;
	for(int i=0;i<t;i++){
		cout<<"Follow("<<rules[i].parent<<") = { ";
		string follow = rules[i].follow;
		for(int j=0;j<follow.length();j++){
			cout<<follow[j];
			if(j==follow.length()-1) break;
			cout<<", ";
		}
		cout<<" }"<<endl;
	}
	cout<<endl<<endl;
	constructTable(rules,t);
	return 0;
}

void constructTable(Rule rules[],int n){
	for(int i=0;i<n;i++){
		terminals+=rules[i].rule;
		nonTerminals+=rules[i].parent;
	}
	for(int i=0;i<terminals.length();i++){
		if(terminals[i]>='A'&&terminals[i]<='Z'){
			terminals[i] = ' ';
		}
	}
	terminals = getUniqueChar(terminals);
	terminals.erase(std::remove(terminals.begin(), terminals.end(), 'e'), terminals.end());
	terminals+='$';
	nonT = nonTerminals.length();
	noT = terminals.length();
	for(int i=0;i<n;i++){
		string first = findFirstTable(rules,n,rules[i].parent);
		istringstream ss(rules[i].rule);
		string rule;
		int r = 0;
		while(ss>>rule){
			r++;
			istringstream ff(first);
			string ifirst;
			int f = 0;
			while(ff>>ifirst){
				f++;
				if(r==f){
					string selected = getUniqueChar(ifirst);
					if(ifirst[ifirst.length()-1]=='e'){
						string follow = rules[i].follow;
						for(int j=0;j<follow.length();j++){
							for(int k=0;k<noT;k++){
								if(terminals[k]==follow[j]){
									table[i][k] = rule;
								}
							}
						}
					}
					if(selected[0]!='e'){
						for(int j=0;j<selected.length();j++){
							for(int k=0;k<noT;k++){
								if(terminals[k]==selected[j]){
									table[i][k] = rule;  
								}
							}
						}
					}
				}
			}
		}
	}
	cout<<"NT/T\t|\t";  
	for(int i=0;i<noT;i++){
		cout<<terminals[i]<<"\t|\t";
	}
	cout<<endl<<endl;
	for(int i=0;i<nonT;i++){
		cout<<nonTerminals[i]<<"\t|\t";
		for(int j=0;j<noT;j++){
			cout<<table[i][j]<<"\t|\t";
		}
		cout<<endl<<endl;
	}
	cout<<endl;
	cout<<"Enter String: "; 
	string en;
	getline(cin,en);
	input = en+"$";
	todo+=rules[0].parent;
	todo+="$";
	cout<<endl<<endl;
	cout<<"Matched\t|\tTodo\t|\tInput\t|\tAction"<<endl;
	cout<<matched<<"\t|\t"<<todo<<"\t|\t"<<input<<"\t|\t"<<action<<endl;
	match();
	cout<<endl<<endl;
}

void match(){
	char chnT = todo[0];
	char chT = input[0];
	string tA = "";
	tA += chnT;
	tA += " = ";
	action = getAction(chnT,chT);
	if(chnT=='$'&&chT=='$'){
		cout<<"\n\nInput Matched!"<<endl;
		return;
	}else if(chnT==chT){
		todo.erase(0,1);
		input.erase(0,1);
		tA = "match ";
		tA += chnT;
		matched += chnT;
		cout<<matched<<"\t|\t"<<todo<<"\t|\t"<<input<<"\t|\t"<<tA<<endl;
		match();
		return;
	}else if(action==""){
		tA = "no action";
		cout<<matched<<"\t|\t"<<todo<<"\t|\t"<<input<<"\t|\t"<<tA<<endl;
		cout<<"\n\nInput is not Matched!"<<endl;
		return;
	}else if(action[0]=='e'){
		todo.erase(0,1);
		string temp = action;
		temp.erase(0,1);
		todo = temp+todo;
		tA += "e";
		cout<<matched<<"\t|\t"<<todo<<"\t|\t"<<input<<"\t|\t"<<tA<<endl;
		match();
		return;
	}
	todo.erase(0,1);
	todo = action+todo;
	tA += action;
	cout<<matched<<"\t|\t"<<todo<<"\t|\t"<<input<<"\t|\t"<<tA<<endl;
	match();
}

string getAction(char chnT,char chT){
	action = "";
	int npos = -1;
	int tpos = -1;
	for(int i=0;i<nonT;i++){
		if(nonTerminals[i]==chnT){
			npos = i;
			break;
		}
	}
	for(int i=0;i<noT;i++){
		if(terminals[i]==chT){
			tpos = i;
			break;
		}
	}
	if(npos!=-1&&tpos!=-1) return table[npos][tpos];
	return "";
}

string findFirstTable(Rule rules[],int n,char parent){
	string first = "";
	for(int i=0;i<n;i++){
		if(rules[i].parent==parent){
			istringstream ss(rules[i].rule);
			string word;
			first += rules[i].first;
			while(ss>>word){
				string terminal = "";
				if(word[0]>='a'&&word[0]<='z'&&word[0]!='e'){
					terminal+=word[0];
				}else if(word[0]=='e'){
					terminal+=word[0];
				}else if(word[0]>='A'&&word[0]<='Z'){
					terminal += findTerminal(rules,n,word[0]);
					int pos = 0;
					while(terminal[terminal.length()-1]=='e' && word.length()>(pos+1)){
						terminal.pop_back();
						pos++;
						terminal += findTerminal(rules,n,word[pos]);
					}
				}
				first+=terminal;
				first+=' ';
			}
		}
	}
	return first;
}

string findTerminal(Rule rules[],int n,char terminal){
		string rr = " ";
		if(terminal>='A'&&terminal<='Z'){
			return findFirst(rules,n,terminal);
		}else{
			rr[0] = terminal;
			return rr;
		}
}

string findFirst(Rule rules[],int n,char parent){
	string first = "";
	for(int i=0;i<n;i++){
		if(rules[i].parent==parent){
			istringstream ss(rules[i].rule);
			string word;
			first += rules[i].first;
			while(ss>>word){
				string terminal = "";
				if(word[0]>='a'&&word[0]<='z'&&word[0]!='e'){
					terminal+=word[0];
				}else if(word[0]=='e'){
					terminal+=word[0];
				}else if(word[0]>='A'&&word[0]<='Z'){
					terminal += findTerminal(rules,n,word[0]);
					int pos = 0;
					while(terminal[terminal.length()-1]=='e' && word.length()>(pos+1)){
						terminal.pop_back();
						pos++;
						terminal += findTerminal(rules,n,word[pos]);
					}
				}
				first+=terminal;
			}
		}
	}
	return first;
}

int firstPos(Rule rules[],int n,char parent){
	for(int i=0;i<n;i++){
		if(rules[i].parent==parent){
			return i;
		}
	}
	return 0;
}

string findFollow(Rule rules[],int n,char parent,char currentP,string follow){
	for(int i=0;i<n;i++){
		istringstream ss(rules[i].rule);
		string word;
		while(ss>>word){
			for(int j=0;j<word.length();j++){
				if(word[j]==parent){
					if((j+1)==word.length()){
						if(rules[i].parent!=parent && rules[i].parent!=currentP){
							follow += findFollow(rules,n,rules[i].parent,currentP,rules[i].follow);
						}
					}else if((j+1)<word.length()){
						if(word[j+1]>='a'&&word[j+1]<='z'&&word[j+1]!='e'){
							follow += word[j+1];
						}else if(word[j+1]>='A'&&word[j+1]<='Z'){
							string first = rules[firstPos(rules,n,word[j+1])].first;
							follow += first;
							if(follow.find('e') != std::string::npos){
								int pos = j+1;
								while(follow.find('e') != std::string::npos && pos<word.length()){
									follow.erase(std::remove(follow.begin(), follow.end(), 'e'), follow.end());
									if(word[pos]>='a'&&word[pos]<='z'&&word[j]!='e'){
										follow += word[pos];
									}else{
										follow += rules[firstPos(rules,n,word[pos])].first;
									}
									pos++;
								}
								if(follow.find('e') != std::string::npos && pos==word.length()){
									follow.erase(std::remove(follow.begin(), follow.end(), 'e'), follow.end());
									follow += findFollow(rules,n,rules[i].parent,rules[i].parent,rules[i].follow);
								}
							}
						}
					}
				}
			}
		}
	}
	return follow;
}

string getUniqueChar(string str){
	for(int i=0;i<str.length();i++){
		char ch = str[i];
		for(int j=i+1;j<str.length();j++){
			if(str[j]==ch) str[j] = ' ';
		}
	}
	str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
	return str;
}
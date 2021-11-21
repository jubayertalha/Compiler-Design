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
string findFollow(Rule rules[],int n,char parent,string follow);
string getUniqueChar(string str);

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
		string follow = findFollow(rules,t,rules[i].parent,rules[i].follow);
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
	cout<<endl;
	return 0;
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

string findFollow(Rule rules[],int n,char parent,string follow){
	for(int i=0;i<n;i++){
		istringstream ss(rules[i].rule);
		string word;
		while(ss>>word){
			for(int j=0;j<word.length();j++){
				if(word[j]==parent){
					if((j+1)==word.length()){
						if(rules[i].parent!=parent){
							follow += findFollow(rules,n,rules[i].parent,rules[i].follow);
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
									follow += findFollow(rules,n,rules[i].parent,rules[i].follow);
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
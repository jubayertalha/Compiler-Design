#include <bits/stdc++.h>
using namespace std;

struct Rule{
	string rule;
	char parent;
	string first;
};

string findTerminal(Rule rules[],int n,char parent);
string findFirst(Rule rules[],int n,char parent);
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
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;

string op = "";
int totalKey = 0;
string key[100];
int totalID = 0;
string id[100];
int totalInValidID = 0;
string inValidID[100];

void checkWord(string word){
    string keyword[33]={
        "auto","double","int","struct","break","else","long",
        "switch","case","enum","register","typedef","char",
        "extern","return","union","const","float","short",
        "unsigned","continue","for","signed","void","default",
        "goto","sizeof","voltile","do","if","static","while","main"
    };

    bool isKey = false;
    bool isIdentifier = true;
    for(int i=0;i<33;i++){
        if(keyword[i]==word){
            isKey = true;
            break;
        }
    }
    if(isKey){
        key[totalKey++]=word;
    }else{
        for(int i=0; i<word.length(); i++){
            if(i==0){
                if(!((word[i]>='A'&&word[i]<='Z') || (word[i]>='a'&&word[i]<='z') || word[i]=='_')){
                    isIdentifier = false;
                    break;
                }
            }else if(!((word[i]>='A'&&word[i]<='Z') || (word[i]>='a'&&word[i]<='z') || (word[i]>='0'&&word[i]<='9') || word[i]=='_')){
                isIdentifier = false;
                break;
            }
        }
    }
    if(isIdentifier&&!isKey){
        id[totalID++]=word;
    }else if(!isKey){
        inValidID[totalInValidID++]=word;
    }
}

bool checkOperator(char ch){
    if(ch=='+' || ch=='-' || ch=='*' || ch=='/'  || ch=='%' || ch=='=')
        return true;
    else
        return false;
}

bool checkValidCh(char ch){
    if(ch=='+' || ch=='-' || ch=='*' || ch=='/'  || ch=='%' || ch=='='
           || ch=='_' || (ch>='a'&&ch<='z') || (ch>='A'&&ch<='Z') || (ch>='0'&&ch<='9'))
        return true;
    else
        return false;
}

void print(){
    for(int i=0; i<op.length(); i++){
        cout<<"Operator "<<i+1<<": "<<op[i]<<endl;
    }
    cout<<"\nKeyword: ";
    for(int i=0; i<totalKey; i++){
        cout<<key[i]<<" ";
    }
    cout<<"\n\nIdentifiers: ";
    for(int i=0; i<totalID; i++){
        cout<<id[i]<<" ";
    }
    cout<<"\n\nInvalid Identifiers: ";
    for(int i=0; i<totalInValidID; i++){
        cout<<inValidID[i]<<" ";
    }
    cout<<endl;
}

int main(){
    ifstream inFile;
    inFile.open("task_01_code.txt");
    if(!inFile){
        cout<<"File not found!"<<endl;
        inFile.close();
        return 0;
    }
    char ch;
    string word = "";
    bool read = false;
    while(inFile.get(ch)){
        if(checkValidCh(ch)){
            if(checkOperator(ch)){
                if(read){
                    read=false;
                    checkWord(word);
                    word = "";
                } 
                op+=ch;
            }else{
                if(!read){
                    read=true;
                    word+=ch;
                }else{
                    word+=ch;
                }
            }
        }else{
            if(read){
                read=false;
                checkWord(word);
                word="";
            }
        }
    }

    print();
    
	return 0;
}

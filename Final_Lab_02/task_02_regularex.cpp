#include <bits/stdc++.h>
using namespace std;

void pattern1(string ptrn){
    cout<<"Enter a string: ";
    string str;
    cin>>str;
    if(str == ptrn){
        cout<<"Valid string"<<endl;
        return;
    }
    cout<<"Not a valid string."<<endl;
}

void pattern2(string ptrn){
    cout<<"Enter a string: ";
    string str;
    cin>>str;
    if(str.length()>=2){
        if(str[0]==ptrn[0]&&str[1]==ptrn[1]){
            for(int i=2;i<str.length();i++){
                if(str[i]!=ptrn[2]){
                    cout<<"Not a valid string."<<endl;
                    return;
                }
            }
            cout<<"Valid string"<<endl;
            return;
        }
    }
    cout<<"Not a valid string."<<endl;
}

void pattern3(string ptrn){
    cout<<"Enter a string: ";
    string str;
    cin>>str;
    if(str.length()>=3){
        if(str[0]==ptrn[0]&&str[1]==ptrn[1]&&str[2]==ptrn[2]){
            for(int i=3;i<str.length();i++){
                if(str[i]!=ptrn[2]){
                    cout<<"Not a valid string."<<endl;
                    return;
                }
            }
            cout<<"Valid string"<<endl;
            return;
        }
    }
    cout<<"Not a valid string."<<endl;
}

void pattern4(string ptrn){
    cout<<"Enter a string: ";
    string str;
    cin>>str;
    if(str.length()>=3 && (str.length()%2)==1){
        if(str[0]==ptrn[0]&&str[1]==ptrn[2]&&str[2]==ptrn[3]){
            for(int i=3;i<str.length();i+=2){
                if(str[i]!=ptrn[2] || str[i+1]!=ptrn[3]){
                    cout<<"Not a valid string."<<endl;
                    return;
                }
            }
            cout<<"Valid string"<<endl;
            return;
        }
    }
    cout<<"Not a valid string."<<endl;
}

void pattern5(string ptrn){
    cout<<"Enter a string: ";
    string str;
    cin>>str;
    if(str.length()==3){
        if(str[0]==ptrn[0]&&str[1]==ptrn[2]&&str[2]==ptrn[3]){
            cout<<"Valid string"<<endl;
            return;
        }
    }else if(str.length()==1){
        if(str[0]==ptrn[0]){
            cout<<"Valid string"<<endl;
            return;
        }
    }
    cout<<"Not a valid string."<<endl;
}

void pattern6(string ptrn){
    cout<<"Enter a string: ";
    string str;
    cin>>str;
    if(str.length()==1 && (str[0]!=ptrn[2]&&str[0]!=ptrn[3])){
        cout<<"Valid string."<<endl;
        return;
    }
    cout<<"Not a valid string."<<endl;
}

void pattern7(string ptrn){
    cout<<"Enter a string: ";
    string str;
    cin>>str;
    if(str.length()==1 && (str[0]==ptrn[0]||str[0]==ptrn[2])){
        cout<<"Valid string."<<endl;
        return;
    }
    cout<<"Not a valid string."<<endl;
}

void matchPattern(string str){
    if(str.length()==3){
        bool matched = true;
        for(int i=0;i<str.length();i++){
            if(!(str[i]>='a'&&str[i]<='z')){
                matched = false;
                break;
            }
        }
        if(matched){
            pattern1(str);
            return;
        }
    }
    if(str.length()==4 && str[3]=='*'){
        bool matched = true;
        for(int i=0;i<str.length()-1;i++){
            if(!(str[i]>='a'&&str[i]<='z')){
                matched = false;
                break;
            }
        }
        if(matched){
            pattern2(str);
            return;
        }
    }
    if(str.length()==4 && str[3]=='+'){
        bool matched = true;
        for(int i=0;i<str.length()-1;i++){
            if(!(str[i]>='a'&&str[i]<='z')){
                matched = false;
                break;
            }
        }
        if(matched){
            pattern3(str);
            return;
        }
    }
    if(str.length()==6 && str[1]=='(' && str[4]==')' && str[5]=='+'){
        bool matched = true;
        if(!(str[0]>='a'&&str[0]<='z')&&!(str[2]>='a'&&str[2]<='z')&&!(str[3]>='a'&&str[3]<='z')){
            matched = false;
        }
        if(matched){
            pattern4(str);
            return;
        }
    }
    if(str.length()==6 && str[1]=='(' && str[4]==')' && str[5]=='?'){
        bool matched = true;
        if(!(str[0]>='a'&&str[0]<='z')&&!(str[2]>='a'&&str[2]<='z')&&!(str[3]>='a'&&str[3]<='z')){
            matched = false;
        }
        if(matched){
            pattern5(str);
            return;
        }
    }
    if(str.length()==5 && str[0]=='[' && str[1]=='^' && str[4]==']'){
        bool matched = true;
        if(!(str[2]>='a'&&str[2]<='z')&&!(str[3]>='a'&&str[3]<='z')){
            matched = false;
        }
        if(matched){
            pattern6(str);
            return;
        }
    }
    if(str.length()==3 && str[1]=='|'){
        bool matched = true;
        if(!(str[0]>='a'&&str[0]<='z')&&!(str[2]>='a'&&str[2]<='z')){
            matched = false;
        }
        if(matched){
            pattern7(str);
            return;
        }
    }
    cout<<"Enter a valid pattern."<<endl;
}

int main(){
    while(1){
        cout<<"Enter Pattern: ";
        string str;
        cin>>str;
        matchPattern(str);
        cout<<endl;
    }
	return 0;
}
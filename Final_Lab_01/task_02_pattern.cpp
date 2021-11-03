#include <bits/stdc++.h>
using namespace std;

void pattern1(){
    cout<<"Enter a string: ";
    string str;
    cin>>str;
    if(str.length()>=2){
        if(str[0]=='a'&&str[1]=='b'){
            for(int i=2;i<str.length();i++){
                if(str[i]!='c'){
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

void pattern2(){
    cout<<"Enter a string: ";
    string str;
    cin>>str;
    if(str.length()>=3){
        if(str[0]=='a'&&str[1]=='b'&&str[2]=='c'){
            for(int i=3;i<str.length();i++){
                if(str[i]!='c'){
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

void pattern3(){
    cout<<"Enter a string: ";
    string str;
    cin>>str;
    if(str.length()==1 && (str[0]>='a'&&str[0]<='z')){
        cout<<"Valid string."<<endl;
        return;
    }
    cout<<"Not a valid string."<<endl;
}

void pattern4(){
    cout<<"Enter a string: ";
    string str;
    cin>>str;
    if(str.length()==1 && (str[0]=='a'||str[0]=='b')){
        cout<<"Valid string."<<endl;
        return;
    }
    cout<<"Not a valid string."<<endl;
}

int main(){
    while(1){
        cout<<"1: abc*"<<endl;
        cout<<"2: abc+"<<endl;
        cout<<"3: [a-z]"<<endl;
        cout<<"4: a|b"<<endl;
        cout<<"Select Pattern: ";
        int p;
        cin>>p;
        switch(p){
            case 1:
                pattern1();
                break;
            case 2:
                pattern2();
                break;
            case 3:
                pattern3();
                break;
            case 4:
                pattern4();
                break;
            default:
                cout<<"Select a valid optioin."<<endl;
        }
        cout<<endl;
    }
	return 0;
}
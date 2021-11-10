#include <bits/stdc++.h>
using namespace std;

void pattern1(){
    cout<<"Enter a string: ";
    string str;
    cin>>str;
    if(str == "abc"){
        cout<<"Valid string"<<endl;
        return;
    }
    cout<<"Not a valid string."<<endl;
}

void pattern2(){
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

void pattern3(){
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

void pattern4(){
    cout<<"Enter a string: ";
    string str;
    cin>>str;
    if(str.length()>=3 && (str.length()%2)==1){
        if(str[0]=='a'&&str[1]=='b'&&str[2]=='c'){
            for(int i=3;i<str.length();i+=2){
                if(str[i]!='b' || str[i+1]!='c'){
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

void pattern5(){
    cout<<"Enter a string: ";
    string str;
    cin>>str;
    if(str.length()==3){
        if(str[0]=='a'&&str[1]=='b'&&str[2]=='c'){
            cout<<"Valid string"<<endl;
            return;
        }
    }else if(str.length()==1){
        if(str[0]=='a'){
            cout<<"Valid string"<<endl;
            return;
        }
    }
    cout<<"Not a valid string."<<endl;
}

void pattern6(){
    cout<<"Enter a string: ";
    string str;
    cin>>str;
    if(str.length()==1 && (str[0]!='a'&&str[0]!='b')){
        cout<<"Valid string."<<endl;
        return;
    }
    cout<<"Not a valid string."<<endl;
}

void pattern7(){
    cout<<"Enter a string: ";
    string str;
    cin>>str;
    if(str.length()==1 && (str[0]=='a'||str[0]=='b')){
        cout<<"Valid string."<<endl;
        return;
    }
    cout<<"Not a valid string."<<endl;
}

int matchPattern(string str){
    if(str == "abc") return 1;
    else if(str == "abc*") return 2;
    else if(str == "abc+") return 3;
    else if(str == "a(bc)+") return 4;
    else if(str == "a(bc)?") return 5;
    else if(str == "[^ab]") return 6;
    else if(str == "a|b") return 7;
    else return 0;
}

int main(){
    while(1){
        cout<<"Enter Pattern: ";
        string str;
        cin>>str;
        int p = matchPattern(str);
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
            case 5:
                pattern5();
                break;
            case 6:
                pattern6();
                break;
            case 7:
                pattern7();
                break;
            default:
                cout<<"Enter a valid pattern."<<endl;
        }
        cout<<endl;
    }
	return 0;
}
#include <iostream>
#include <string>
using namespace std;

int main(){
    string in;
    cout<<"Enter Input: ";
    cin>>in;
    bool isIdentifier = true;
    for(int i=0; i<in.length(); i++){
        if(i==0){
            if(!((in[i]>='A'&&in[i]<='Z') || (in[i]>='a'&&in[i]<='z') || in[i]=='_')){
                isIdentifier = false;
                break;
            }
        }else if(!((in[i]>='A'&&in[i]<='Z') || (in[i]>='a'&&in[i]<='z') || (in[i]>='0'&&in[i]<='9') || in[i]=='_')){
            isIdentifier = false;
            break;
        }
    }
    if(isIdentifier){
        cout<<in<<" is a Identifier"<<endl;
    }else{
        cout<<in<<" is NOT a Identifier"<<endl;
    }
    return 0;
}
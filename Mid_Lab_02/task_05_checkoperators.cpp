#include <iostream>
#include <string>
using namespace std;

int main(){
    string in;
    cout<<"Enter Input: ";
    getline(cin,in);
    string op = "";
    for(int i=0; i<in.length(); i++){
        if(in[i]=='+' || in[i]=='-' || in[i]=='*' || in[i]=='/'  || in[i]=='%' || in[i]=='='){
            op+=in[i];
        }
    }
    for(int i=0; i<op.length(); i++){
        cout<<"Operator "<<i+1<<": "<<op[i]<<endl;
    }
    return 0;
}
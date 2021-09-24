#include <iostream>
#include <string>
using namespace std;

int main(){
    string in;
    cout<<"Enter Input: ";
    cin>>in;
    bool isConstant = true;
    for(int i=0; i<in.length(); i++){
        if(in[i]<48 || in[i]>57){
            isConstant = false;
            break;
        }
    }
    if(isConstant){
        cout<<in<<" is a Numeric Constant"<<endl;
    }else{
        cout<<in<<" is not a Numeric Constant"<<endl;
    }
    return 0;
}
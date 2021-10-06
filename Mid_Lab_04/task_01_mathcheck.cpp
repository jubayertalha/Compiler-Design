#include <iostream>
using namespace std;

int main(){
    string line;
    getline(cin,line);
    bool isValid = true;
    bool startParenthisis = false;
    bool endParenthisis = false;
    bool startParameter  = false;
    bool endParameter = false;
    for(int i=0;i<line.length(); i++){
        char ch = line[i];
        if(ch=='('){
            if(!startParenthisis && !endParenthisis){
                startParenthisis = true;
            }else{
                isValid = false;
                break;
            }
        }else if(ch==')'){
            if(startParenthisis && !endParenthisis){
                endParenthisis = true;
            }else{
                isValid = false;
                break;
            }
        }else if(ch == ' '){
            continue;
        }else if(ch>='a' && ch<='z'){
            if(i<line.length()-1){
                if(line[i+1]==' ' || line[i+1]=='+'||line[i+1]=='-'||line[i+1]=='*'||line[i+1]=='/'){
                    if(!startParameter && !endParameter){
                        startParameter = true;
                    }else if(!endParameter){
                        endParameter = true;
                    }else{
                        isValid = false;
                        break;
                    }
                }
            }
        }else if(ch=='+'||ch=='-'||ch=='*'||ch=='/'){
            if(startParameter && !endParameter){
                continue;
            }else{
                isValid = false;
                break;
            }
        }else{
            isValid = false;
            break;
        }
    }
    if(isValid){
        cout<<"Valid Statement"<<endl;
    }else{
        cout<<"Invalid Statement"<<endl;
    }
	return 0;
}

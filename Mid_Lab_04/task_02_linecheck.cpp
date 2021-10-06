#include <bits/stdc++.h>
using namespace std;

int main(){
    string line;
    getline(cin,line);
    bool isValid = true;
    int total = 0;
    string word;
    istringstream ss(line);
    while(ss>>word){
        for(int i=0; i<word.length(); i++){
            char ch = word[i];
            if(total==0){
                if(i==0){
                    if(ch>='A'&&ch<='Z'){
                        continue;
                    }else{
                        isValid = false;
                        break;
                    }
                }else{
                    if(ch>='a'&&ch<='z'){
                        continue;
                    }else if(i==word.length()-1){
                        if(ch=='.'){
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
            }else{
                if(i==0){
                    if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')){
                        continue;
                    }else{
                        isValid = false;
                        break;
                    }
                }else{
                    if((ch>='a'&&ch<='z')){
                        continue;
                    }else if(i==word.length()-1){
                        if(ch=='.'){
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
            }
        }
        total++;
    }
    if(word[word.length()-1]!='.'){
        isValid = false;
    }
    if(isValid){
        cout<<"Valid Statement"<<endl;
    }else{
        cout<<"Invalid Statement"<<endl;
    }
	return 0;
}

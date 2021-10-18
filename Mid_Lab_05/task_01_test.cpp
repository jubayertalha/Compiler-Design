#include <bits/stdc++.h>
using namespace std;

int main(){
    ifstream inFile;
    inFile.open("program.cpp");
    if(!inFile){
        cout<<"File not found!"<<endl;
        inFile.close();
        return 0;
    }
    string variables[100];
    string preprocessors[100];
    int totalPre = 0;
    int totalVar = 0;
    bool isMain = false;
    string line;
    while(getline(inFile,line)){
        istringstream ss(line);
        string word;
        int start = 0;
        while(ss>>word){
            if(word[0]=='#' && !isMain){
                string pre = "";
                for(int i=1;i<word.length();i++){
                    char ch = word[i];
                    if(ch=='<'){
                        break;
                    }
                    pre+=word[i];
                }
                bool isUnique = true;
                for(int i=0;i<totalPre;i++){
                    if(pre==preprocessors[i]){
                        isUnique = false;
                        break;
                    }
                }
                if(isUnique){
                    preprocessors[totalPre++] = pre;
                    pre = "";
                }
            }else if(word=="int" && start == 0){
                start++;
                continue;
            }else if(start==1 && !isMain){
                string fun = "";
                for(int i=0;i<word.length();i++){
                    if(word[i]=='('){
                        if(fun=="main"){
                            isMain = true;
                        }
                        break;
                    }
                    fun+=word[i];
                }
            }else if(start==1 && isMain){
                string var = "";
                for(int i=0;i<word.length();i++){
                    char ch = word[i];
                    if(ch==','||ch=='='||ch==';'){
                        bool isUnique = true;
                        for(int i=0;i<totalVar;i++){
                            if(var==variables[i]){
                                isUnique = false;
                                break;
                            }
                        }
                        if(isUnique){
                            variables[totalVar++] = var;
                            var = "";
                        }
                        break;
                    }
                    var+=ch;
                }
            }
        }
    }
    for(int i=0;i<totalVar;i++){
        cout<<"Variable-"<<i+1<<": "<<variables[i]<<endl;
    }
    cout<<"Total number of the variables: "<<totalVar<<endl;
    for(int i=0;i<totalPre;i++){
        cout<<"Preprocessor-"<<i+1<<": "<<preprocessors[i]<<endl;
    }
    cout<<"Total number of the preprocessors: "<<totalPre<<endl;
	return 0;
}
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(){
    ifstream inFile;
    inFile.open("task_06_comment.txt");
    if(!inFile){
        cout<<"File not found!"<<endl;
        inFile.close();
        return 0;
    }
    char ch;
    string comments[1000];
    comments[0] = " ";
    int total = 0;
    int readS = 0; //0=not reading 1=read 1st ch 2=start reading
    int readM = 0; //0=not reading 1=read 1st ch 2=start reading 3=stop reading
    char temp = '*';
    while(inFile.get(ch)){
        if(readM==0&&readS==0){
            if(ch=='/'){
                readM = 1;
                readS = 1;
            }
        }else if(readM==1&&readS==1){
            if(ch=='*'){
                readM = 2;
                readS = 0;
            }else if(ch=='/'){
                readM = 0;
                readS = 2;
            }else{
                readM = 0;
                readS = 0;
            }
        }else if(readM==2){
            if(ch=='*'){
                readM = 3;
            }else{
                comments[total]+=ch;
            }
        }else if(readM==3){
            if(ch=='/'){
                comments[total++][0] = temp;
                comments[total] = " ";
                readM = 0;
            }else{
                comments[total]+=temp;
                comments[total]+=ch;
                readM = 2;
            }
        }else if(readS==2){
            if(ch=='\n'){
                comments[total++][0] = '/';
                comments[total] = " ";
                readS = 0;
            }else{
                comments[total]+=ch;
            }
        }
    }
    inFile.close();
    for(int i=0;i<total;i++){
        if(comments[i][0]=='/'){
            cout<<"\nComment "<<i+1<<" (SingleLine): /"<<comments[i]<<endl;
        }else{
            cout<<"\nComment "<<i+1<<" (MultiLine):\n"<<endl;
            cout<<"/"<<comments[i]<<"*/"<<endl;
        }
    }
    return 0;
}
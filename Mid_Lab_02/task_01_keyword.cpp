#include <iostream>
#include <string>
#include <fstream>
using namespace std;

bool check(string key){
    ifstream inFile;
    inFile.open("keyword.txt");
    if(!inFile){
        cout<<"File not found!"<<endl;
        inFile.close();
        return false;
    }
    string strLine;
    string words[1000];
    int totalWord = 0;
    while(getline(inFile,strLine)){
      char c = strLine[i++];
      bool start = false;
      while(c!='\0'){
        if(c == ' ' || c == ','){
          continue;
        }else if(c == '\"'){
          if(!start){
            start = true;
          }else{
            start = false;
            totalWord++;
          }
        }else{
          words[totalWord]+=c;
        }
      }
    }
    for(int i=0;i<=totalWord;i++){
      if(words[i] == key){
    }
    inFile.close();
}

int main(){
    cout<<"Enter a keyword: ";
	return 0;
}
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
    while(getline(inFile,strLine)){      int i = 0;
      char c = strLine[i++];
      bool start = false;
      while(c!='\0'){
        if(c == ' ' || c == ','){          c = strLine[i++];
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
        }        c = strLine[i++];
      }
    }    bool match = false;
    for(int i=0;i<=totalWord;i++){
      if(words[i] == key){        match = true;        break;      }
    }
    inFile.close();    return match;
}

int main(){    string key;
    cout<<"Enter a keyword: ";    cin>>key;	if(check(key)){        cout<<"The keyword \""<<key<<"\" is valid!"<<endl;	}else{        cout<<"The keyword \""<<key<<"\" is invalid!"<<endl;	}
	return 0;
}
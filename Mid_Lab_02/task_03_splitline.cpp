#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void read(){
    ifstream inFile;
    inFile.open("split.txt");
    if(!inFile){
        cout<<"File not found!"<<endl;
        inFile.close();
        return;
    }
    string strLine;
    while(getline(inFile,strLine,';')){
    }
    inFile.close();
}

int main(){


	return 0;
}
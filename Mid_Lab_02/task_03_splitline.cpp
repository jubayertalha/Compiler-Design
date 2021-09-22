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
    while(getline(inFile,strLine,';')){      cout<<strLine<<endl;
    }
    inFile.close();
}

int main(){
	read();

	return 0;
}
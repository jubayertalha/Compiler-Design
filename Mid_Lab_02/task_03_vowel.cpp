#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void check(){
    ifstream inFile;
    inFile.open("task_03_vowel.txt");
    if(!inFile){
        cout<<"File not found!"<<endl;
        inFile.close();
        return;
    }
    char ch;
    int vowel = 0;
    int consonant = 0;
    string text = "";
    while(inFile.get(ch)){
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U'){
            vowel++;
            text = text + '(' + ch + ')';
        }else if((ch>=65 && ch<=90) || (ch>=97 && ch<=122)){
            consonant++;
            text+=ch;
        }else{
            text+=ch;
        }
    }
    cout<<text<<endl;
    cout<<"\n\nTotal Vowel: "<<vowel<<endl;
    cout<<"Total Consonant: "<<consonant<<endl;
    inFile.close();
}

int main(){
    check();
	return 0;
}

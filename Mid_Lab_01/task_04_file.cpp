#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void read(){
    ifstream inFile;
    inFile.open("task_04_file.txt");
    if(!inFile){
        cout<<"File not found!"<<endl;
        inFile.close();
        return;
    }
    int i=1;
    string str;
    while(getline(inFile,str)){
		if(i%2==1) cout<<"Name: "<<str<<endl;
		else cout<<"Mark: "<<str<<endl;
		i++;
    }
    inFile.close();
}

void write(int n){
    ofstream outFile;
    outFile.open("task_04_file.txt");
    string name;
    int mark;
    for(int i=0;i<n;i++){
		cout<<"Enter Name: ";
		getline(cin>>ws,name);
		cout<<"Enter Mark: ";
		cin>>mark;
		outFile<<name<<endl;
		outFile<<mark<<endl;
    }
    outFile.close();
}

int main(){
	int n;

	cout<<"Enter Number: ";
	cin>>n;

	write(n);
	cout<<"\nOutput\n"<<endl;
	read();

	return 0;
}


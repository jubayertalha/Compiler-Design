#include <bits/stdc++.h>
using namespace std;

char input[100], todo[100];
int itop = -1, ttop = -1;

void pushI(char ch){
    input[++itop] = ch;
}
void pushT(char ch){
    todo[++ttop] = ch;
}

void popI(){
    itop--;
}
void popT(){
    ttop--;
}

char topI(){
    return input[itop];
}
char topT(){
    return todo[ttop];
}

/* the grammer
S = A
A = aBX
X = dX | e
B = bBC | f
C = g
*/

string table[5][6] = {
    {"A","","","","",""},
    {"aBX","","","","",""},
    {"","","dX","","","e"},
    {"","bBC","","","f",""},
    {"","","","g","",""}
};

string returnRule(char Nterminal, char terminal){
    int npos = -1;
    int tpos = -1;
    switch(Nterminal){
        case 'S':
            npos = 0;
            break;
        case 'A':
            npos = 1;
            break;
        case 'X':
            npos = 2;
            break;
        case 'B':
            npos = 3;
            break;
        case 'C':
            npos = 4;
            break;
        default:
            npos = -1;
            break;
    }
    switch(terminal){
        case 'a':
            tpos = 0;
            break;
        case 'b':
            tpos = 1;
            break;
        case 'd':
            tpos = 2;
            break;
        case 'g':
            tpos = 3;
            break;
        case 'f':
            tpos = 4;
            break;
        case '$':
            tpos = 5;
            break;
        default:
            npos = -1;
            break;
    }
    if(npos!=-1&&tpos!=-1) return table[npos][tpos];
    return "";
}

void match(){
    char ter = topI();
    char nter = topT();
    if(ter=='$'&&nter=='$'){
        cout<<"Matched";
        return;
    }
    if(ter==nter){
        popI();
        popT();
        match();
        return;
    }
    if(nter=='e'){
        popT();
        if(topT()!='$')
        popT();
        match();
        return;
    }
    string rule = returnRule(nter,ter);
    if(rule==""){
        cout<<"Not Matched";
        return;
    }
    popT();
    for(int i=rule.length()-1;i>=0;i--){
        pushT(rule[i]);
    }
    match();
}

int main(){
    string uinput;
    getline(cin,uinput);
    pushT('$');
    pushT('S');
    pushI('$');
    for(int i=uinput.length()-1;i>=0;i--){
        pushI(uinput[i]);
    }
    match();
    return 0;
}
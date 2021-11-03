#include <bits/stdc++.h>
using namespace std;

int main(){
    string line;
    getline(cin,line);
    string sub;
    getline(cin,sub);
    bool isSub = false;
    int lineLen = line.length();
    int subLen = sub.length();
    int subPos = 0;
    if(subLen>lineLen){
        cout<<"No"<<endl;
        return 0;
    }else{
        for(int i=0;i<lineLen;i++){
            if(line[i]==sub[0]&&!isSub){
                isSub = true;
                subPos = i;
                if((i+subLen)>lineLen){
                    cout<<"No"<<endl;
                    return 0;
                }else{
                    for(int j=1,t=i+1;j<subLen;j++,t++){
                        if(sub[j]!=line[t]){
                            isSub = false;
                        }
                    }
                    if(isSub){
                        cout<<"Yes"<<endl;
                        cout<<"Position: "<<subPos<<endl;
                        return 0;
                    }
                }
            }
        }
        cout<<"No";
    }
	return 0;
}
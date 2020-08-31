//14:47-15:16
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
//M (≤ 1000), N and S
// being the total number of forwards,
//the skip number of winners
//the index of the first winner (the indices start from 1). 
int main(){
    int m,n,s;
    string name;
    cin>>m>>n>>s;
    // map<string,int>mapinfo;
    set<string>setinfo;
    vector<string>vecinfo;
    for(int i=0;i<m;i++){
        cin>>name;
        vecinfo.push_back(name);
    }
    int count=0;
    int i=0;
    i=s-1;
    while(i<vecinfo.size()){
        if(setinfo.find(vecinfo[i])!=setinfo.end()){
            i+=1;
            continue;
        }
        else{
            cout<<vecinfo[i]<<endl;
            setinfo.insert(vecinfo[i]);
            i+=(n);
            count++;
        }
    }
    if(count==0)
    cout<<"Keep going..."<<endl;
}
#include <iostream>
#include <stdio.h>
#include <string>
#include <map>

using namespace std;

map<char , int> evaBeads;
map<char , int> ownerBeads;

int main(){
    string owner,eva;
    cin>>owner;
    
    cin>>eva;
    for(int i=0;i<owner.size();i++){
        if(ownerBeads.find(owner[i])==ownerBeads.end()){
            ownerBeads[owner[i]]=1;
        }
        else ownerBeads[owner[i]]+=1;
    }
    int lack=0,cur=0;
    for(int i=0;i<eva.size();i++){
        if(ownerBeads.find(eva[i])==ownerBeads.end()){
            //cout<<eva[i]<<endl;
            lack++;
        }
        else if(ownerBeads[eva[i]]==0)lack++;
        else{
           // cout<<eva[i]<<' '<<ownerBeads[eva[i]]<<' '<<cur<<endl;
            ownerBeads[eva[i]]--;
            cur++;
        }
    }
    cout<<lack<<endl;
    if(lack!=0){
        cout<<"No "<<lack<<endl;
    }
    else cout<<"Yes "<<owner.size()-cur<<endl;
    //这里第一次编译的时候写成了ownerBeads.size()!!!!!!!!!
}

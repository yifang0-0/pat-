#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
//20:37-20:44
//水
//输入的另外一种方式 cin.getline(s2, 100000);
int main(){
    string ori;
    getline(cin,ori);
    map <char,int>countOri;
    for(int i=0;i<ori.size();i++){
        if(countOri.find(ori[i])==countOri.end()){
            countOri[ori[i]]=1;
        }
        else countOri[ori[i]]+=1;
    }
    string cutoff;
    getline(cin,cutoff);
    for(int i=0;i<cutoff.size();i++){
        if(countOri.find(cutoff[i])!=countOri.end()){
            countOri[cutoff[i]]=0;
        }
    }
    for(int i=0;i<ori.size();i++){
        if(countOri[ori[i]]>0){
            
            cout<<ori[i];
        }
    }
    return 0;
}

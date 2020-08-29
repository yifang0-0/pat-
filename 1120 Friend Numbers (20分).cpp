#include <string>
#include <iostream>
#include <map>
#include <cstdio>
using namespace std;
map<int,int>recordExist;
int main(){
    int n;
   scanf("%d\n",&n);
   map<int ,int>output;
    map<int ,int>outputreal;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        int newNum=0;
        for(int j=0;a>0;j++){
            newNum+=a%10;
            a/=10;
        } 
        if(output.find(newNum)==output.end()) output[newNum]=1;
        if(output[newNum]==1)outputreal[newNum]=1;
    }
    cout<<outputreal.size()<<endl;
    int count=0;
    map<int,int>::iterator it;
    for(it=outputreal.begin();it!=outputreal.end();it++){
            if(count==0)cout<<it->first;
            else cout<<' '<<it->first;
            count++; 
    }
}
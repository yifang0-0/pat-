#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;
string outputs[5]={
    "Checked",
    "Mystery Award",
    "Minion",//ranked as a prime number
    "Chocolate",
    "Are you kidding?"
};

void buildPrime(int* p,int maxNum){
    
    for(int i=3;i<=maxNum;i++){
        int isPrime=1;
        for(int j=2;;j++){
            if(j*j>i)break;
            else if(i%j==0){
                isPrime=0;
                break;
            }
        }
        if(isPrime==1)p[i]=1;
        else p[i]=0;
    }
}

int main(){
    string name;
    map<string , int>infom;
    vector<pair<string,int > >outinfo;
    int n,k;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>name;
        infom[name]=i+1;
    }
    int *isprime = new int[n+1];
    if(n>1){
        isprime[2]=1;
        buildPrime(isprime,n);
    }
    cin>>k;
    for(int i=0;i<k;i++){
        cin>>name;
        if(infom.find(name)==infom.end()){
            outinfo.push_back(make_pair(name,4));
        }
        else {
            if(infom[name]==-1)  outinfo.push_back(make_pair(name,0));        
            else if(isprime[infom[name]]==1){
                 outinfo.push_back(make_pair(name,2));        
                infom[name]=-1;
            }
            else if(infom[name]==1){
                 outinfo.push_back(make_pair(name,1));        
                infom[name]=-1;
            }
            else{
                 outinfo.push_back(make_pair(name,3));
                infom[name]=-1;
            }
        }
    }
    for(int i=0;i<k;i++){
        cout<<outinfo[i].first<<": "<<outputs[outinfo[i].second]<<endl;
    }
}

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <map>
using namespace std;

//N个数字大于N
//贪心?
    

int main(){
    int n;
    cin>>n;
    int *times=new int[n+2];
    for(int i=0;i<n+2;i++)times[i]=0;
    for(int i=0;i<n;i++){
        int newNum;
        cin>>newNum;
        times[i]++;
    }
    //int max=0;
    for(int i=n;i>0;i++){
        times[i]+=times[i+1];
        if(times[i]==i){
            cout<<i;
            return;
        }
    }
    
}

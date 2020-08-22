#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
//20:53-21:14
//n个数字 
int main(){
    int n;
    cin>>n;
    int sequence[100001] = {0,0,};
    int exit[10001]={0,0,};
    for(int i=0;i<n;i++){
       sequence[i]=0;
    }
    int max=0;
    for(int i=0;i<n;i++){
        int cur;
        cin>>cur;
        if(exit[cur]==0){
            sequence[i]=cur;
            exit[cur]=1;
            max+=1;
        }
        else {
            if(exit[cur]!=-1){
                exit[cur]=-1;
                max-=1;
            }
        }
    }
    int flag=0;
     if(max==0)cout<<"None"<<endl;
     else {
        for(int i=0;i<n;i++){ //这个地方卡了!!!做题的时候先设计清楚 两个数组各自多大代表什么意思最好写下来!
        if(sequence[i]!=0&&exit[sequence[i]]==1){
            cout<<sequence[i]<<endl;
            flag=1;
            break;
            }
        }
     }
}

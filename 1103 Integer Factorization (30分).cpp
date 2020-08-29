#include <iostream>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;
int sum,num,index;
int maxSum=0;
stack<int>finishq;
stack<int>curq;

int findmul(int ori){
    int s=1;
    int i;
    for( i=0;i<index;i++){
        s*=ori;
        if(s>sum)break;
    }
    if(i!=index)return -1;
    else return s;
}

void bfs(int level,int start,int cur,int itemSum){
    if(level==num){
        
        if(cur==sum&&itemSum>=maxSum){
            maxSum=itemSum;
           // cout<<"hit and max="<<maxSum<<" "<<curq.size()<<endl;
            finishq=curq;
           // cout<<"finishq.size()"<<finishq.size()<<endl;
        }
    }
    else{
       int iffindmul=findmul(start);
        for(int i=start;iffindmul!=-1&&iffindmul+cur<=sum;i++){
            curq.push(i);
           // cout<<"level "<<level<<" i "<<i<<" mul "<<cur+iffindmul<<endl;
            bfs(level+1,i,cur+iffindmul,i+itemSum); 
            curq.pop();
            iffindmul=findmul(i+1);
        }
    }
}

int main(){
    
    int min,max;
    cin>>sum>>num>>index;
 
        bfs(0,1,0,0);
   
    if(finishq.size()==0)cout<<"Impossible"<<endl;
    else{
        printf("%d = %d^%d",sum,finishq.top(),index);
        finishq.pop();
        for(;finishq.size();){
             printf(" + %d^%d",finishq.top(),index);
            finishq.pop();
        }
    }

}

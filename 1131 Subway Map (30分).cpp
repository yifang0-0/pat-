//14:37-16：02
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <string>
#include <stdio.h>
#include <queue>
#include<algorithm>
#include <stack>
using namespace std;
//图的连通性问题
//要记录经过的节点
//要统计共有几个不同的点
set<int>stopNum;
//set<int>stopUnUsed;
queue<int>stopUnUsed;

map<int, map<int,int>>stopConnectInfo;
map<int,map<int,int>>stop;

// typedef struct stop{
//     int name;
//     int iftransfer;//如果是换乘点就要遍历下一站
// }Stop;
//层序遍历而不是最短路径算法！！！！
stack<int>final;
stack<int>temp;
int maxnum=10001;
int bfs(int start,int end){
     //cout<<"******************start end "<<start<< ' '<<end<<' '<<endl;

    if(start==end){
        if(temp.size()<maxnum){

            final=temp;
            maxnum=temp.size();
        }
    }
    /*
    4
7 1001 3212 1003 1204 1005 1306 7797
9 9988 2333 1204 2006 2005 2004 2003 2302 2001
13 3011 3812 3013 3001 1306 3003 2333 3066 3212 3008 2302 3010 3011
4 6666 8432 4011 1306
3
3011 3013
6666 2001
2004 3001
    */
    else{
        int num=stopUnUsed.size();
        for(int i=0;i<num;i++){
             int n=stopUnUsed.front();
             //cout<<"n= "<<stopUnUsed.front()<<endl;
             stopUnUsed.pop();
            if(stopConnectInfo[start].find(n)!=stopConnectInfo[start].end()){
                if( stopConnectInfo[start][n]!=0){
                    stopConnectInfo[start][n]=stopConnectInfo[n][start]=0;
                //int n=stopUnUsed.front();
               // cout<<"start n "<<start<< ' '<<n<<' '<<endl;
                //stopUnUsed.pop();
                temp.push(n);
        
                bfs(n,end);
                  stopConnectInfo[start][n]=stopConnectInfo[n][start]=1;
                temp.pop();
                
          
                }

            }
             stopUnUsed.push(n);
        }
    }
}





int  findSameLine(int a,int b,int linemax){
    //int n=stopUnUsed.size();
    for(int i=1;i<=linemax;i++){
        // int newl=stopUnUsed.front();
        // stopUnUsed.pop();
        // stopUnUsed.push(newl);
        if(stop[b].find(i)!=stop[b].end()){
            return i;//返回lineno
        }
    }
    return -1;
}


int main(){
    int a;
    cin>>a;
    for(int line=1;line<=a;line++){
        int stopNum;
        scanf("%d",&stopNum);
        int last=0;
        for(int i=0;i<stopNum;i++){
            int cur;
            scanf("%d",&cur);
           
           if(stop.find(cur)==stop.end()){
                stopUnUsed.push(cur);
           }
            stop[cur][line]=1;
            if(i!=0){
                stopConnectInfo[cur][last]=1;
                stopConnectInfo[last][cur]=1;
            cout<<"last cur connect"<<last<<' '<<cur<<' '<< stopConnectInfo[cur][last]<<endl;
            }
                last=cur;
        }
    }
    int i=stopUnUsed.size();
    while(i>0){
        int p=stopUnUsed.front();
       // cout<<"stopUnUsed"<<stopUnUsed.front()<<endl;
        stopUnUsed.pop();
        stopUnUsed.push(p);
        i--;
    }
    int search=0;
    cin>>search;
    for(int q=0;q<search;q++){
        //开始查找
        int s,e;
        final.empty();
        temp.empty();
        maxnum=10001;
        cin>>s>>e;

        bfs(s,e);
        cout<<final.size()<<endl;
       // int lastline=0;

        int laststop=s;
        int cur=laststop;
       // final.pop();
        int next;
        //int flag=0;//要输出
        //找到一个一定要中转的点再输出
        stack<int>f;
        int ppp=final.size();

        while(ppp>0){
            ppp-=1;
            f.push(final.top());
            cout<<final.top()<<endl;
            final.pop();
        }
        int lineNo=0;
        for(int i=0;i<f.size();i++){
            next=f.top();
            if(i==0){
                lineNo=findSameLine(cur,next,a);
                cout<<"last= "<<lineNo<<endl;
            }
            int newline=findSameLine(cur,next,a);
            if(newline!=lineNo){
                //找到中转点
                
                cout<<"last= "<< lineNo <<"new= "<<newline<<endl;
                printf("Take Line#%d from %04d to %04d.\n",lineNo,laststop,next);
                lineNo=newline;
                laststop=next;
            }
            cur=next;
            f.pop();
        }
         printf("Take Line#%d from %04d to %04d.\n",lineNo,laststop,cur);
        f.empty();
    }
}
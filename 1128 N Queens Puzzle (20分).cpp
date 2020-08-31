//20：54-21:18
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <string>
#include <stdio.h>
#include <queue>
using namespace std;
int record[1001][1001]={0};
vector<int>rawmat;
int judge(int x,int y,int l){
    //int flag=1;
    int x0=x, y0=y;
    while(--x0>=1&&++y0<=l){
        if(record[x0][y0]==1)return -1;
    }
    x0=x, y0=y;
    while(--x0>=1&&--y0>=1){
        if(record[x0][y0]==1)return -1;
    }
    x0=x, y0=y;
     while(++x0<=l&&++y0<=l){
        if(record[x0][y0]==1)return -1;
    }
    x0=x, y0=y;
     while(++x0<=l&&--y0>=1){
        if(record[x0][y0]==1)return -1;
    }
    x0=x, y0=y;
    while(--y0>=1){
        if(record[x0][y0]==1)return -1;
    }
    x0=x, y0=y;

     while(++y0<=l){ //同一行有没有一样的
        if(record[x0][y0]==1)return -1;
    }

    return 1;
}


int testsolution(int length){
    for(int i=1;i<=length;i++){
        int ori=rawmat[i-1];
        if(judge(ori,i,length)==-1)return -1;
    }
    return 1;
}
int main(){
    //皇后问题
    //直接从左到右给出棋子位置
    //可能最多有1000个皇后
    //一次有多个用例
    //只需要判断是否在统一斜排
    int n;
    scanf("%d\n",&n);
    for(int i=0;i<n;i++){
        int length;
        scanf("%d",&length);
       // vector<int>rawmat;
        for(int x=1;x<=length;x++){
            for(int y=1;y<=length;y++){
                record[x][y]=0;
            }
        }
        for(int j=1;j<=length;j++){
            int cur;
            scanf("%d",&cur);
            record[cur][j]=1;
            rawmat.push_back(cur);
        }
        rawmat.clear();
        if(testsolution(length)==1)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
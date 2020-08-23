//15:05-16：03
#include <iostream>
#include <algorithm>
#include <map>
#include <stdio.h>
#include <queue>
#include <stdlib.h>
using namespace std;
int main(){
    int N;
    scanf("%d",&N);
    getchar();
    int m=N,n=1;
     for(int i=2;i<=N;i++)
    { 
        //m=N/n or N/i  
        if(N/i<i)break;
        if(N%i==0){
            n=i;
            m=N/i;
        }
    }
    //找到了M行N列
    //从[0,0]开始填充
    vector<int > raw;
    int curNum;
    for(int i=0;i<N;i++)
    {
        scanf("%d ",&curNum);
        //printf("%d ",curNum);
        raw.push_back(curNum);
    }
    getchar();
   // printf("input over\n");
    sort(raw.begin(),raw.end());
    queue<int>output;
    for(int i=raw.size()-1;i>=0;i--){
        output.push(raw[i]);
       // printf("%d ",output.back());
    }

    //开始放置
    //建立一个二维数组
    int **settle=(int **)malloc(m*sizeof(int*));
    for(int i=0;i<m;i++){
        settle[i]=(int *)malloc(n*sizeof(int));
    }
    //s四个方向  右x不变 y+=1
    //          下x+=1 y不变
    //          左x不变 y-=1
    //          上x-=1 y不变
    int x=0,y=0;
    int state=0;
    int statex[4]={0,1,0,-1};
    int statey[4]={1,0,-1,0};
    int limitxMax=m-1,limityMax=n-1;
    int limitxMin=1,limityMin=0;
    while(output.size()>0){
        settle[x][y]=output.front();
       // printf("%d ",settle[x][y]);
        output.pop();
        
        if(state==0){
            if(y==limityMax){
                //向右放满
                limityMax--;
                state+=1;
                state%=4;

            }
        }
        else if(state==1){
            if(x==limitxMax){
                //向下放满
                limitxMax--;
                state+=1;
                state%=4;
            }
        }
        else if(state==3){
            if(x==limitxMin){
                //向左放满
                limitxMin++;
                state+=1;
                state%=4;
            }
        }
        else if(state==2){
           if(y==limityMin){
                //向上放满
                limityMin++;
                state+=1;
                state%=4;
            }
        }
        //cout<<x<<' '<<y<<endl;
        x+=statex[state];
        y+=statey[state];
        //cout<<x<<' '<<y<<endl;
    }
   // printf("\n start print\n");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%d",settle[i][j]);
            if(j!=n-1) printf(" ");
            else printf("\n");
        }
    }
    return 0;
}

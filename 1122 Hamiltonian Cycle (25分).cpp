#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
//19:14-19:54  应该还有更好办法吧！！！
//汉密尔顿环：判断是否是一个完全图
//n个节点 m条边
//查询k个
//给出点个数和点信息
//是否会回到原点
//存在一个数组里
#include <cstdio>
using namespace std;
map<int,int>coupleinfo;
map<int,int>guest;
int main(){
    int n,m,k;
    int matrix[201][201]={0,0,0};
    scanf("%d %d\n",&n,&m);
    for(int i=0;i<m;i++){
        int v1,v2;
        scanf("%d %d\n",&v1,&v2);
        matrix[v1][v2]= matrix[v2][v1]=1;
    }
    scanf("%d",&k);
    for(int i=0;i<k;i++){
        int nodesNum;
        int flag=1;
        scanf("%d",&nodesNum);
        if(nodesNum<n)flag=0;
        int firstnode;
        if(nodesNum!=0)scanf("%d",&firstnode);
        int Used[201][201]={0,0,0};
        int UsedNode[201]={0};
        int lastNode=firstnode;
        int curNode;
        UsedNode[firstnode]=1;
        for(int j=0;j<nodesNum-1;j++){
            scanf("%d",&curNode);
            if(flag==1){
                if(UsedNode[curNode]==1&&j!=nodesNum-2){
                    flag=0;
                   // cout<<UsedNode[curNode]<<' '<<curNode<<endl;
                }
                 UsedNode[curNode]=1;
                if(matrix[lastNode][curNode]==0){
                    flag=0; 
                    Used[lastNode][curNode]=Used[curNode][lastNode]=1;
                    }
                else if( Used[lastNode][curNode]==1){
                    flag=0;
                    }


                }
            lastNode=curNode;
        }
        if(lastNode!=firstnode)flag=0;
        if(flag==0)printf("NO\n");
        else printf("YES\n");
    

        
    }

}
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
//判断是否完全二叉树
//15:20-
using namespace std;
struct node{
    int left,right,num;
};
int num=0;
int maxID;
queue <int>dfsqueue;
void dfs(int nodeID,vector<struct node> nodesInfo){
    nodesInfo[nodeID].num=num;
    num++;
    maxID=nodeID;
    int left=nodesInfo[nodeID].left;
    int right=nodesInfo[nodeID].right;
    if(left!=-1)dfsqueue.push(left);
    if(right!=-1)dfsqueue.push(right);
    while(dfsqueue.size()>0){
        int curid=dfsqueue.front();       
        dfsqueue.pop();
        dfs(curid,nodesInfo);
    }
}
int bTree=1;
int ifBtree(int nodeID,vector<struct node> nodesInfo){
    int left=nodesInfo[nodeID].left;
    int right=nodesInfo[nodeID].right;
    int num=nodesInfo[nodeID].num;
    if(left!=-1){
        if((num*2+1)!=nodesInfo[left].num)bTree=0;
        else ifBtree(left,nodesInfo);
    }
    if(right!=-1){
        if((num*2+2)!=nodesInfo[right].num)bTree=0;
        else ifBtree(right,nodesInfo);
    }
}

int main(){
    int n;
    cin>>n;
    vector<struct node> nodesInfo(n);
    int *used=new int[n];
    for(int i=0;i<n;i++){
        used[i]=-1;
    }
    for(int i=0;i<n;i++){
        char a,b;
        scanf("%c %c\n",&a,&b);
        nodesInfo[i].left=-1;
        nodesInfo[i].right=-1;
        if(a<='9'&&a>='0'){
            used[a-'0']=1;
            nodesInfo[i].left=a-'0';
        }
        if(b<='9'&&b>='0'){
             used[b-'0']=1;
            nodesInfo[i].right=b-'0';
        }

    }
    int root;
    for(int i=0;i<n;i++){
        if(used[i]==-1){
            root=i;
            break;
        }
    }
    dfs(root,nodesInfo);
    ifBtree(root,nodesInfo);
    if(bTree==1){
        cout<<"Yes "<<maxID<<endl;
    }
    else{
        cout<<"No "<<root<<endl;
    }
}

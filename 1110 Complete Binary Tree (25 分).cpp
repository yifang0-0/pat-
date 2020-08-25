#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
//判断是否完全二叉树
//实际上可以根据节点标号的规律直接在生成的时候完成判断!
//https://github.com/yifang0-0/pat-/edit/master/%23%20%E5%88%B7%E9%A2%98%E6%8C%87%E5%8D%97.md
using namespace std;
struct node{
    int left,right,num;
};
int num=0;
int maxID;
queue <int>dfsqueue;
vector<struct node> nodesInfo(22);
void dfs(int nodeID){
    nodesInfo[nodeID].num=num;
    num++;
    maxID=nodeID;
    //cout<<maxID<<"<-nodeid "<<num-1<<endl;
    int left=nodesInfo[nodeID].left;
    int right=nodesInfo[nodeID].right;
    //cout<<"left right"<<left<<" "<<right<<endl;
    if(left!=-1)dfsqueue.push(left);
    if(right!=-1)dfsqueue.push(right);
    while(dfsqueue.size()>0){
        int curid=dfsqueue.front();       
        dfsqueue.pop();
        dfs(curid);
    }
}
int bTree=1;
int ifBtree(int nodeID,vector<struct node> nodesInfo){
    int left=nodesInfo[nodeID].left;
    int right=nodesInfo[nodeID].right;
    int num=nodesInfo[nodeID].num;
    if(left!=-1){
        if((num*2+1)!=nodesInfo[left].num){
            bTree=0;
            // cout<<"num*2+1"<<num*2+1<<" nodesInfo[left].num"<<nodesInfo[left].num<<endl;
            // //return;
            // cout<<nodeID<<"<-nodeid num->"<<num<<endl;
            }
        else ifBtree(left,nodesInfo);
    }
    if(right!=-1){
        if((num*2+2)!=nodesInfo[right].num)
        {
            bTree=0;
            // cout<<"num*2+2"<<num*2+2<<" nodesInfo[left].right"<<nodesInfo[right].num<<endl;
            // cout<<nodeID<<"<-nodeid num->"<<num<<endl;

        }
        else ifBtree(right,nodesInfo);
    }
}

int main(){
    int n;
    cin>>n;
    
    int *used=new int[n];
    for(int i=0;i<n;i++){
        used[i]=-1;
    }
    getchar();
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
    dfs(root);
    
    ifBtree(root,nodesInfo);
    if(bTree==1){
        cout<<"Yes "<<maxID<<endl;
    }
    else{
        cout<<"No "<<root<<endl;
    }
}

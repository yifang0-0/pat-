#include <iostream>
#include <cstdio>
#include <string>
#include <stdlib.h>
#include <queue>
//判断是否完全二叉树
//实际上可以根据节点标号的规律直接在生成的时候完成判断!
//https://github.com/yifang0-0/pat-/edit/master/%23%20%E5%88%B7%E9%A2%98%E6%8C%87%E5%8D%97.md
using namespace std;
struct node{
    int left,right;
};
int maxID;
int curNum=0;
int n=0;
struct node nodesInfo[30];
int dfs(int nodeID,int num){
    if(curNum<num){
         maxID=nodeID;
         curNum=num;
    }
    int left=nodesInfo[nodeID].left;
    int right=nodesInfo[nodeID].right;
    if(left!=-1)dfs(left,num*2);
    if(right!=-1)dfs(right,num*2+1);
}

int main(){
    cin>>n;
   // nodesInfo=(struct node*)malloc(sizeof(struct node)*(n+1));
    int used[30];
    for(int i=0;i<n;i++){
        used[i]=0;
    }
    
    for(int i=0;i<n;i++){
        string a,b;
        cin>>a>>b;
        nodesInfo[i].left=-1;
        nodesInfo[i].right=-1;
        
        if(a!="-"){
            int ia=stoi(a);
            //used[ia]=1;
            //nodesInfo[i].left=ia;
             sscanf(a.c_str(), "%d", &nodesInfo[i].left);
            used[nodesInfo[i].left]=1;
        }
        if(b!="-"){
             int ib=stoi(b);
             //used[ib]=1;
             //nodesInfo[i].right=ib;
            sscanf(b.c_str(), "%d", &nodesInfo[i].right);
          used[nodesInfo[i].right]=1;
        }
    }
    int  root;
    for(int i=0;i<n;i++){
        if(used[i]==0){
            root=i;
            break;
        }
    }
    dfs(root,1);
    //cout<<curNum<<endl;
    if(curNum==n){
        cout<<"YES"<<" "<<maxID;
    }
    else{
        cout<<"NO "<<root;
    }
}
// #include <iostream>
// using namespace std;

// int E[20][2];  // 存储每个节点的左右孩子
// int exist[20]; 
// int maxIndex = 0, last;
// void dfs(int u, int index)
// {
// 	if(u==-1) return;
// 	if(index>maxIndex) maxIndex = index, last = u;
// 	dfs(E[u][0], 2*index);  // 遍历左孩子
// 	dfs(E[u][1], 2*index+1);  // 遍历右孩子
// }
// int main(int argc, char const *argv[])
// {
// 	int N; cin >> N;
// 	for (int i = 0; i < N; i++)
// 	{
// 		string s1, s2; cin >> s1 >> s2;
// 		int left=-1, right=-1;
// 		if(s1!="-") sscanf(s1.c_str(), "%d", &left);
// 		if(s2!="-") sscanf(s2.c_str(), "%d", &right);
// 		exist[left] = exist[right] = 1;
// 		E[i][0]=left, E[i][1]=right;
// 	}
// 	int root;
// 	for (int i = 0; i < N; i++) if(exist[i]==0) root=i;
// 	dfs(root, 1);
// 	if(maxIndex==N) cout << "YES" << " " << last;
// 	else cout << "NO" << " " << root;
// 	return 0;
// }
//21:46-22:20
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <string>
#include <stdio.h>
#include <queue>
#include<algorithm>
using namespace std;

//构造一个节点是操作符
//叶子节点是数字or符号的东西
//用string输入
//构造一棵树
//中序遍历
//除了根节点都需左括号 左子树 右子树 右括号 

typedef struct node{
    string value;
    struct node*left,*right;
    int l,r;
}*Node;
map<int,Node>ninfo;

Node buildTree( Node a){
    cout<<a->value<<' '<<a->l<<' '<<a->r<<endl;
    if(a->l!=-1)a->left=buildTree(ninfo[a->l]);
    else a->left=NULL;
    
    if(a->r!=-1)a->right=buildTree(ninfo[a->r]);
    else a->right=NULL;
    return a;
}
int f=0;
void dfs(Node cur,int n){
    if(cur->l==cur->r)n=0;
    if(n==1)cout<<'(';
    if(cur->l!=-1)dfs(cur->left,1);
    cout<<cur->value;
    if(cur->r!=-1)dfs(cur->right,1);
    if(n==1)cout<<')';
}
int main(){
    int n;
    scanf("%d\n",&n);
    int showed[30]={0,0};
    for(int i=0;i<n;i++){
        string value;
        int l,r;
        cin>>value>>l>>r;
       // scanf("%d %d\n"&l,&r);
        Node newNode=new struct node;
        newNode->value=value;
        newNode->l=l;
        newNode->r=r;
        if(l!=-1)showed[l]=1;
        if(r!=-1)showed[r]=1;
        ninfo[i+1]=newNode;
    }
    int i;
    for( i=1;i<=n;i++){
        if(showed[i]==0)break;
    }
    Node root=buildTree(ninfo[i]);
    dfs(root,0);
}
#include <iostream>
using namespace std;
//21:20-21:45
/*
二叉查找樹
插入新節點時，如果比根節點大 在右子樹上插入 如果根節點小 在左節點上插入
*/
//Node buildNewNode(level,id)
//如果新節點是一個NULL，建立 插入
//recordLevel[level]++;
//如果不是NULL，判斷newNum<=curNum?curNode->left=buildNewNode(level+1,newNum):curNode->right=buildNewNode(level+1,newNum)
typedef struct node{
    int id;
    struct node*left,*right;
} Node;
int *recordLevel;//記錄全局
Node* createTree(int level,int id,Node* curNode){
    if(curNode==NULL){
        Node* curNode=new struct node;
        curNode->left=curNode->right=NULL;
        recordLevel[level]++;
        curNode->id=id;
        return curNode;
    }
    else{
        (id<=curNode->id)?(curNode->left=createTree(level+1,id,curNode->left)):(curNode->right=createTree(level+1,id,curNode->right));
        return curNode;
    }
}

int main(){
    int n;
    cin>>n;
    recordLevel=new int[n+2];//冗餘 留出一位作爲順序插入層數等於個數時最後break 第一位也空置
     for(int i=0;i<=1+n;i++){
        recordLevel[i]=0;
    }
    Node* curNode=NULL;
    for(int i=0;i<n;i++){
        int cur;
        cin>>cur;
        curNode=createTree(1,cur,curNode);
    }
    int max=0,index=0;;
    for(int i=1;i<=n+1;i++){
        if(recordLevel[i]==0){
            index=i;
            break;
        }
    }
   // if(n==0)cout<<'0 + 0 = 0'<<endl; //測試點5！
   //else if(n==1)cout<<'1 + 0 = 1'<<endl;
     cout<<recordLevel[index-1]<<" + "<<recordLevel[index-2]<<" = "<<recordLevel[index-2]+recordLevel[index-1]<<endl;
}
 // if(n==1)cout<<'1 + 0 = 1'<<endl;
//測試點5！
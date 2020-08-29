#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
//20:00-21:30 
//AVL树
//啊啊啊啊啊啊啊啊过了我操操操！！！
#include <cstdio>
using namespace std;
typedef struct node{
    struct node* left;
    struct node* right;
    int value;
    int level;
}*Node;
queue<Node>waitinglist;
int maxnode=1;
int getlevel(Node ori);
void bfs(){
  
    Node ori ;
    while(waitinglist.size()!=0){
        ori=waitinglist.front();
    
        if(ori->left!=NULL){
            printf(" %d",ori->left->value);
            waitinglist.push(ori->left);
        }
        if(ori->right!=NULL){
            printf(" %d",ori->right->value);
            waitinglist.push(ori->right);
        }
        waitinglist.pop();
    }

}
void dfs(Node ori,int n){
     if(n>maxnode)maxnode=n;
     if(ori->left!=NULL)dfs( ori->left,n*2);
     if(ori->right!=NULL)dfs( ori->right,n*2+1);
}
Node right(Node oriroot){
    Node newroot=oriroot->left;
    oriroot->left=newroot->right;
    newroot->right=oriroot;
    return newroot;
}

Node left ( Node oriroot){
    Node newroot=oriroot->right;
    oriroot->right=newroot->left;
    newroot->left=oriroot;
    return newroot;
}

Node rightleft ( Node oriroot){
    
    Node newroot=right(oriroot->right);
    oriroot->right=newroot->left;
    newroot->left=oriroot;
    return newroot;
}

Node leftright(Node oriroot){
    
    Node newroot=left(oriroot->left);
    oriroot->left=newroot->right;
    newroot->right=oriroot;
    return newroot;
}

Node insertNode(int value,Node ori){
   // cout<<"value= "<<value<<endl;
    if(ori==NULL){
         Node newn=new struct node;
         
            newn->value=value;
            newn->left=NULL;
            newn->right=NULL;
            
           return newn;
    }
   // cout<<"value= "<<value<<" ori->v= "<<ori->value<<endl;
    //cout<<"before ll "<<getlevel(ori->left)<<" rl= "<<getlevel(ori->right)<<endl;
    if(value<ori->value){
        ori->left = insertNode(value,ori->left);
    }
    else if(value>ori->value){
        ori->right = insertNode(value,ori->right);
    }

    //插入完成 开始旋转
     int ll=0,rl=0;
    if(ori->left!=NULL){
        ll=getlevel(ori->left);
    }
    if(ori->right!=NULL){
        rl=getlevel(ori->right);
    }
    // cout<<"after  ll "<<getlevel(ori->left)<<" rl= "<<getlevel(ori->right)<<endl;
    if(rl-ll>=2){
          // cout<<"rl-ll>=2"<<endl;
        if(value>ori->value&&value>ori->right->value){
            //cout<<"left"<<endl;
           return  left(ori);
        }
        else if(value>ori->value&&value<ori->right->value){
            //cout<<"rightleft"<<endl;

            return rightleft(ori);
        }
    }
      else if(ll-rl>=2){
          // cout<<"ll-rl>=2"<<endl;
        if(value<ori->value&&value<ori->left->value){
           // cout<<"right"<<endl;
            
           return  right(ori);
        }
        else if(value<ori->value&&value>ori->left->value){
           // cout<<"leftright"<<endl;

            return leftright(ori);
        }
    }
    return ori;
}

int getlevel(Node ori){
    int nlevel=0;
    int ll=0,rl=0;
    if(ori==NULL)return 0;
    if(ori->left!=NULL){
        ll=getlevel(ori->left);
    }
    if(ori->right!=NULL){
        rl=getlevel(ori->right);
    }
    if(ll>rl)nlevel=ll;
    else nlevel=rl;
    
    return nlevel+1;
}

int main(){
    int n,m,k;
    Node avltree;
    avltree=NULL;
    cin>>n;
   for(int i=0;i<n;i++){
        int newNum;
        scanf("%d",&newNum);
        avltree=insertNode(newNum,avltree);
   }
   printf("%d",avltree->value);
   waitinglist.push(avltree);
   bfs();
   cout<<endl;
dfs(avltree,1);
if(maxnode>n)cout<<"No"<<endl;
else cout<<"Yes"<<endl;

}
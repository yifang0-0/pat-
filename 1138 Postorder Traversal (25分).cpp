#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int n;
vector<int>pre;
vector<int>in;
typedef struct node{
    int n;
    struct node*left,*right;
}*Node;
Node buildtree(int starti,int length,int startp){
    Node cur=new struct node;
    int a=pre[startp];
    cur->left=NULL;
    cur->right=NULL;
    cur->n=a;
    //cout<<"pre "<<a<<" length "<<length<<" inadd"<<starti<<endl;
    if(length==1){//这里是精华部分···
        cout<<a;
        exit(0);
    }
    if(length>1){
        int curindex;
        for(curindex=starti;curindex<starti+length-1;curindex++){
            if(in[curindex]==a)break;
        }
        int lengthl=curindex-starti;
        if(lengthl>0)cur->left=buildtree(starti,lengthl,startp+1);
        int lengthr=length-1-lengthl;
        if(lengthr>0)cur->right=buildtree(curindex+1,lengthr,startp+1+lengthl);
    }
    return cur;
}
// int p=0;
// void reverse(Node a){
//     if(a->left!=NULL)reverse(a->left);
//     if(a->right!=NULL)reverse(a->right);
//     if(p==0){printf("%d",a->n);
//     exit(0);
//     }
// }
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        int temp;
       scanf("%d",&temp);
        pre.push_back(temp);   
    }
     for(int i=0;i<n;i++){
        int temp;
              scanf("%d",&temp);
        in.push_back(temp);   
    }
    Node root=buildtree(0,n,0);
   // reverse(root);
}
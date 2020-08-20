#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <map>
using namespace std;
//19:30-20:13
//N縂結點數 從1開始
//M 有孩子的節點個數
//M行子節點的
//K表示子節點個數
//對於不確定孩子的情況，使用左孩子右兄弟、
//則一個family的所有成員就是node+node->left+node->left->right+node->left->right->right...
//計算左邊節點的右側節點個數+1（第一個孩子節點）+1（父節點）
typedef struct node{
    int id;
    int level;
    //struct node *firstChild,*chilsSib;
} Node;
vector<int>kids;
map<int,vector<int>>nodesInfo;
vector<Node>nInfo;
//建樹的過程：找到根節點（沒有在後面出現過的）
void createTree(int level,int id){
    Node newNode;
    newNode.id=id;
    newNode.level=level;
    if(nodesInfo.find(id)!=nodesInfo.end()){
        //有子
      vector<int>kidsBuild;
      kidsBuild=  nodesInfo[id];
      
      for(int i=0;i<kidsBuild.size();i++){
          
          createTree(level+1,kidsBuild[i]);
          
      }
    }
    nInfo.push_back(newNode);
    return ;
}


int main(){
    //找到根節點，建樹，然後輸出同層的節點的個數和level數（第一層1，每一次） 
    //層序建立
    //vector<struct node>nInfo;
    int N,M;
    cin>>N>>M;
    int *nodeUsed=new int[N+1];
    for(int i=1;i<=N;i++){
        nodeUsed[i]=0;
    }
    
    
    for(int i=0;i<M;i++){
        int nodeID,knum;
        cin>>nodeID>>knum ;
        for(int j=0;j<knum;j++){
            int child;
            cin>>child;
            nodeUsed[child]=1;
            kids.push_back(child);
        }
        nodesInfo[nodeID]=kids;
        kids.clear();
    }
    int index=0;
    for(int j=1;j<=N;j++){
            if(nodeUsed[j]==0){
                index=j;
                break;
            }
        }
    createTree(1,index);
    int *levelNodeNum=new int[N+1];
    for(int i=1;i<=N;i++){
        levelNodeNum[i]=0;
    }
    int countL=0,m=0;
    //cout<<nInfo.size()<<" nInfo.size()"<<endl;
    for(int i=0;i<nInfo.size();i++){
        
        levelNodeNum[(nInfo[i]).level]++;
        if(levelNodeNum[(nInfo[i]).level]>m){
            m=levelNodeNum[(nInfo[i]).level];
            countL=(nInfo[i]).level;
        }
    }
    cout<<m<<" "<<countL<<endl;;
    //父節點信息是id
    //遍歷整個vector找到所有的同層個數

}
//vector<node> v2(v1); 将v1的所有元素放到v2中

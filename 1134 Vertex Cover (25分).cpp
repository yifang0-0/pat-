//21:22-21:57  两个测试点。。内存超限
//改成vector列表和set
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>
#include <algorithm>
using namespace std;
// Vertex Cover 题目读了半天
//这题就是所有节点遍历能够覆盖这个图的所有边 用循环 开个新数组即可
int n,m;//分别是结点数和边数
//int edgeinfo[10001][10001]={0,0};
 vector<int>a;
// int findalledge(){
//    // cout<<"in!"<<endl;
//     int size=a.size();
//     int edge=0;
//     //cout<<size<<endl;
//     int **edgerec;
//     edgerec=(int**)malloc(sizeof(int*)*(n+1));
//     for(int i=0;i<=n;i++){
//         edgerec[i]=(int*)malloc(sizeof(int)*(n+1));
//         for(int j=0;j<=n;j++)edgerec[i][j]=0;
//     }

//     for(int i=0;i<size;i++){
//         for(int j=0;j<n;j++){
//             if(edgeinfo[a[i]][j]==1){
//                  if(edgerec[a[i]][j]==0){
//                 edge++;
//                 edgerec[a[i]][j]=edgerec[j][a[i]]=1;
//                  }
//             }
//         }
//     }
//     if(edge<m)return -1;
//     else return 1;
// }

int main(){
    cin>>n>>m;
   vector<int> edgeinfo[100001];
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        edgeinfo[x].push_back(i);
        edgeinfo[y].push_back(i);
    }
    int k;
    cin>>k;
    for(int i=0;i<k;i++)
    {
        int num;
        cin>>num;
        int mmm=num;
        unordered_set<int>curedge;
        while(mmm-- >0){
            int cur;
            cin>>cur;
           int i=0;
           while(i<edgeinfo[cur].size()){
               curedge.insert(edgeinfo[cur][i]);
               i++;
           }
        }
        if(curedge.size()==m)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    //    // cout<<"here"<<endl;
    //     int result=findalledge();
    //    if( result==(-1))cout<<"No"<<endl;
    //    else  cout<<"Yes"<<endl;
    //    a.clear();
    }

}
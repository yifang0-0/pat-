//15:05-16：03
#include <iostream>
#include <algorithm>
#include <map>
#include <stdio.h>
#include <queue>
#include <stdlib.h>
#include <vector>
using namespace std;
//16:05-
/*
看起来是一道动规
我绝望了
25分题现在要做1小时···
这也就意味着考试可能只有70分
太恶心了
*/
/*
//看着像个层序遍历33
//啊这题倒是不难
//就把所有结点信息全部放到队列里面，然后节点上记录一下level 最后遍历
//建造节点的时候就用queue来搞
//每个vector
*/
vector <int> singleInfo;
map <int ,vector<int>> allInfo;
map<int,int>levelInfo;
queue<int>wait2bMake;

int maxLevel=0;

void createNodes(int level){
    while(wait2bMake.size()!=0){
        int cur=wait2bMake.front();
        wait2bMake.pop();
        //cout<<"cur "<<cur<<" level "<<level<<endl;
        if(allInfo.find(cur)!=allInfo.end()){
            for(int i=0;i<allInfo[cur].size();i++){
            //cout<<allInfo[cur][i]<<' ';
            //levelInfo[level+1]+=1;
            wait2bMake.push(allInfo[cur][i]);
            createNodes(level+1);
             }
            
        }
        else{
            if(level<maxLevel){maxLevel=level;
            //cout<<"change maxlevel at "<<cur<<endl;
            }
            //是叶子结点，可以放入level了
           // cout<<"endNode cur "<<cur<<" level "<<level<<endl;
            if(levelInfo.find(level)==levelInfo.end()){
                levelInfo[level]=1;
            }
            else levelInfo[level]+=1;
        }
        
    }
}


int main(){
   int n;
   double price,percent;
   cin>>n>>price>>percent;
   for(int i=0;i<n;i++){
       int nodesNum;
       cin>>nodesNum;
       if(nodesNum>0){
           int sninfo;
            for(int j=0;j<nodesNum;j++){
                cin>>sninfo;
                singleInfo.push_back(sninfo);
            }
            allInfo[i]=singleInfo;
            singleInfo.clear();
       }
   }
    wait2bMake.push(0);
    maxLevel=n;
    createNodes(0);
    double priceSum=price;
    for(int i=0;i<maxLevel;i++){
        priceSum*=(1+percent/100.0);
    }
    //cout<<levelInfo[0]<<' '<<levelInfo[1]<<" "<<levelInfo[2]<<' '<<levelInfo[3]<<endl;
    printf("%.4lf %d",priceSum,levelInfo[maxLevel]);
    return 0;
}

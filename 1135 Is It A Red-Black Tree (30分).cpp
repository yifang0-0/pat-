//22：01-22:50
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
/*
给一棵先序遍历的树判断是不是红黑
建树需要递归建，可以给当前层的红黑属性（1==黑 -1==红 所有数都需要是>0的否则是错的）
*/
int build(int *nodes,int length,int color){  
    //建之前判断color
    if(color==1){
        //指定为黑
        if(nodes[0]<0)return -1;//这层颜色不对
    }
    if(nodes[0]<0){color=1;}
    else color=0;
    int rednum=color;
    if(length==1){
        if(nodes[0]<0)return 0;
        else return 1;
    }
    int findleft=1;
    while(findleft<length&&abs(nodes[findleft])<abs(nodes[0])){
        findleft++;
        }
    //cout<<nodes[findleft-1]<<endl;
    //跳出循环的时候小于findleft下标的一定都是左子树
    int flaga=0,flagb=0;
    //cout<<"findleft= "<<findleft<<" lenth1= "<<findleft-1<<" length2="<<length-findleft<<endl;
    if(findleft>1){
        flaga=build(nodes+1,findleft-1,color);
       // cout<<"now root="<<nodes[0]<<' '<<flaga<<endl;
        if(flaga==-1)return -1;
    }
     if(findleft<length){
        flagb=build(nodes+findleft,length-findleft,color);
        if(flagb==-1)return -1;
    }
    if(flaga==flagb)return flaga+(rednum-1)*(-1);
    else return -1;
}
int main(){
    int num;
    cin>>num;
    for(int i=0;i<num;i++){
        int treenodes;
        cin>>treenodes;
        int *node=new int[treenodes];
        for(int j=0;j<treenodes;j++){
            cin>>node[j];
        }
        if(build(node,treenodes,1)==-1)cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
}

//15:16-15:41 睡一下 困到窒息了
//窒息，睡了半个小时···
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <string>
#include <stdio.h>
#include <queue>
//cao...题目整个意思理解错了 然后心态就崩了···乱七八糟
using namespace std;
//set遍历：https://www.cnblogs.com/austinspark-jessylu/p/7839820.html
//A graph that has an Eulerian path but not an Eulerian circuit is called semi-Eulerian.
//N<=500 M条边 判断是否是欧拉图
//Eulerian, Semi-Eulerian, or Non-Eulerian.
//It has been proven that connected graphs with all vertices of even degree have an Eulerian circuit
vector<int>vdegree; 
vector<int>ifodd; 
 int m,n,s;
int pathinfo[501][501]={0};

int findpath(int size){
    for(int i=1;i<=size;i++){
        int count=0;
        for(int j=1;j<=size;j++){
            if(pathinfo[i][j]==1)count++;
        }
        vdegree.push_back(count);
        if(count%2!=0)ifodd.push_back(i);

        if(i==1)cout<<count;
        else cout<<' '<<count;
    }
    cout<<endl;
}
//找路径 可以重复找点 但是不能重复找路
int pUsed[501][501]={0};
int pNum=0;
int findep(int startid){
    if(pNum<m){
        for(int i=1;i<=n;i++){
            cout<<"i=0<"<<i
<<endl;            cout<<"pathinfo[startid][i] "<<pathinfo[startid][i]<<" pUsed[startid][i] "<<pUsed[startid][i]<<endl;
            if(pathinfo[startid][i]==1&&pUsed[startid][i]!=1){
            cout<<"may be"<<i<<" while start = "<<startid<<" pNum"<<pNum<<endl;
                
                pUsed[startid][i]=pUsed[i][startid]=1;;
                pNum++;
                if(findep(i)==1)return 1;
                pNum--;
                pUsed[startid][i]=pUsed[i][startid]=0;
            }
            
        }
        return 0;
    }
    else return 1;
}

set<int>vnotused;
int findec(int startid,int a){ 
    for(int i:vnotused){
        cout<<i<<' ';
    }  
    cout<<endl;
    
   // cout<<endl;

    if(vnotused.size()==0){
        cout<<"finally x="<<startid<<" y="<<a<<endl;
        if(pathinfo[startid][a]==1)
        {
            return 1;
        }
        else return 0;
        }
    int flag=1;
    for(int i=1;i<=n;i++){
        if(pathinfo[startid][i]==1&&vnotused.find(i)!=vnotused.end()){
            vnotused.erase(i);
           // cout<<"may be"<<i<<" while start = "<<startid<<endl;
            flag=findec(i,a);
            if(flag==1)return 1;
            vnotused.insert(i);
            if(i==5)cout<<"can find 5 "<<(vnotused.find(5)!=vnotused.end())<<endl;
        }
    }
    return 0;
}

int main(){
   
    string name;
    cin>>n>>m;

    // map<string,int>mapinfo;
    set<string>setinfo;
    vector<string>vecinfo;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        
        if(vnotused.find(x)==vnotused.end())vnotused.insert(x);
        if(vnotused.find(y)==vnotused.end())vnotused.insert(y);
        pathinfo[x][y]=pathinfo[y][x]=1;    
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<pathinfo[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    findpath(n);
    if(ifodd.size()==0){

        cout<<"Eulerian";
        return 0;
    }
    else{
        int ifFindec,ifFindep;
        for(int i=0;i<ifodd.size();i++){
            cout<<"single"<<ifodd[i]<<endl;
            ifFindep=findep(ifodd[i]);
            if(ifFindep==1)break;
        }
        pNum=0;
        queue<int>unused;
        
        for(int i:vnotused){
            unused.push(i);
        }
        for(int i=0;i<unused.size();i++){
            int start=unused.front();
            unused.pop();
            vnotused.erase(start);
            ifFindec=findec(start,start);
            if(ifFindec==1)break;
            vnotused.insert(start);
        }
        
        cout<<"dec is "<<ifFindec<<" ep is "<<ifFindep<<endl;
        if(ifFindec==1&&ifFindep==1){
        cout<<"Eulerian";
        return 0;
        }
        else if(ifFindep==1){
            cout<<"Semi-Eulerian"<<endl;
        }
        else{
            cout<<"Non-Eulerian"<<endl;

        }
    }
}
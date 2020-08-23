//17:02-19:23
//死磕。。。。。
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

//现在给出人的属性
//只要有属性相同，就说明是一群人
//给属性放人头，从还没有被归类的人里取出新的

vector<int>peoplelikethis;
map <int,vector<int>>peoplefeature;
map <int,vector<int>>likeandpeople;
map <int,int> unusedpeople;
queue<int>feature;
map<int,int>unsedfeature;
int cluster=0;
vector <int> clusternum;
int findAllPeople(int peopleid,int num){
    //通过一个人找到其特征，通过特征再找人，没有新特征/没有新人时结束
    unusedpeople.erase(peopleid);
    if(peoplefeature.find(peopleid)!=peoplefeature.end()){
        for(int i=0;i<peoplefeature[peopleid].size();i++){
            if(unsedfeature.find(peoplefeature[peopleid][i])==unsedfeature.end()){
                unsedfeature[peoplefeature[peopleid][i]]=1;
                //当前节点对应的所有feature
                feature.push(peoplefeature[peopleid][i]);
            }
        }
        while(feature.size()>0){          
            int fea=feature.front();
            feature.pop();
            // cout<<"add new"<<endl;
            for(int i=0;i<likeandpeople[fea].size();i++){
                if(unusedpeople.find(likeandpeople[fea][i])!=unusedpeople.end()){
                    //unusedpeople.erase(likeandpeople[fea][i]);
                    //cout<<"add new node"<<' '<<likeandpeople[fea][i]<<" feature"<<' '<<fea<<endl;
                    num=findAllPeople(likeandpeople[fea][i],num+1);
                }
            }           
        }
        return num;
    }
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        unusedpeople[i]=1;
    }
    for(int i=0;i<n;i++){
        int featureNum;
        scanf("%d: ",&featureNum);
        for(int j=0;j<featureNum;j++){
            int featureid;
            cin>>featureid;
            // if(likeandpeople.find(featureid)==end()){
            //     //一个新feature
            //     likeandpeople[featureid].push_back(i);
            // }
            peoplefeature[i].push_back(featureid);
            likeandpeople[featureid].push_back(i);
        }
    }  
    while(unusedpeople.size()>0){
        int curpeople=unusedpeople.begin()->first;
        clusternum.push_back( findAllPeople(curpeople,1));
        cluster+=1;
        //cout<<"***********curpeople**********"<<curpeople<<endl;
    }
    sort(clusternum.begin(),clusternum.end());
    cout<<cluster<<endl;
    for(int i=cluster-1;i>=0;i--){
        if(i!=cluster-1){
            cout<<' '<<clusternum[i];
        }
        else cout<<clusternum[i];
    }
}

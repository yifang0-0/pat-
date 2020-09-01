//20:46-21:21(最后一个样例没有通过-5)
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int num,k;
int main(){
    vector<pair<int , string>>nodesv;
    string head;
    cin>>head>> num>>k;
    map<string ,pair<int,string>>nodes;
    for(int i=0;i<num;i++){
         char add[10],next[10];
        int val;
        scanf("%s %d %s\n",&add,&val,&next);
        nodes[add]=make_pair(val,next);
    }
    do{
        nodesv.push_back(make_pair(nodes[head].first,head));
        head=nodes[head].second;
    }while(head!="-1");
    int i=0;
    string h,n;
    int lasthead;
    h=head;
    lasthead=0;
    /*
    分三个阶段输出：
    第一阶段 负数
    第二阶段 0-k的数
    第三阶段 大于k的数字
    输出结构：当前地址+当前内容+下一地址
    由于遍历三次输出 实际上下一地址是不知道的
    所以应该是
    上一地址的下一地址（即当前地址）+\n+当前地址+当前内容
    初次输出的时候不输出上一地址和\n
    末次输出补上-1
    */
   //上一地址：lasthead

//第一阶段 负数
    for( i=0;i<nodesv.size();i++){
        if(nodesv[i].first<0){
            if(lasthead!=0)cout<<nodesv[i].second<<endl;
            cout<<nodesv[i].second<<' '<<nodesv[i].first<<' ';
            lasthead=1;
        }
    }
//第二阶段 小于等于k
    for( i=0;i<nodesv.size();i++){
        if(nodesv[i].first<=k&&nodesv[i].first>=0){
            if(lasthead!=0)cout<<nodesv[i].second<<endl;
            cout<<nodesv[i].second<<' '<<nodesv[i].first<<' ';
            lasthead=1;
        }
    }
//第三阶段 大于k
   for( i=0;i<nodesv.size();i++){
        if(nodesv[i].first>k){
             if(lasthead!=0)cout<<nodesv[i].second<<endl;
            cout<<nodesv[i].second<<' '<<nodesv[i].first<<' ';
            lasthead=1;
        }
    }
    cout<<"-1"<<endl;
}

/*
//20:46-
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int num,k;
int getv(int a){
    if(a<0)return 1;
    if(a>=0&&a<=k)return 2;
    else return 3;
}


bool cmp(pair < int , string> a, pair <int , string> b){
    return getv(a.first)<getv(b.first);
}
int main(){
    vector<pair<int , string>>nodesv;
    string head;
    cin>>head>> num>>k;
    map<string ,pair<int,string>>nodes;
    for(int i=0;i<num;i++){
        string add,next;
        int val;
        
        //scanf("%s %d %s\n",&add,&val,&next);
        cin>>add>>val>>next;
        char add[10],next[10];
        int val;
        scanf("%s %d %s\n",&add,&val,&next);
        nodes[add]=make_pair(val,next);
        //nodes.push_back(make_pair(val,add));
    }
   // map<string ,pair<int,string>>::iterator it;
    do
    {
        nodesv.push_back(make_pair(nodes[head].first,head));
        head=nodes[head].second;
    }while(head!="-1");
    sort(nodesv.begin(),nodesv.end(),cmp);
    int i=0;
    for( i=0;i<nodesv.size()-1;i++){
        cout<<nodesv[i].second<<' '<<nodesv[i].first<<' '<<nodesv[i+1].second<<endl;
    }
    cout<<nodesv[i].second<<' '<<nodesv[i].first<<" -1"<<endl;
}

*/
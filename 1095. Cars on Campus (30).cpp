#include <iostream>
#include <map>
#include <stdio.h>
#include <vector>
#include <string>
using namespace std;
typedef struct date{
    int hh;
    int mm;
    int ss;
    int ifin;
}Date;
vector<Date> carInfo;
map<string,vector<Date>>allInfo;
map<string,Date> output;
vector<pair<string,Date>>op;
/*
思路:
 N (<= 10000)条记录 K (<= 80000)个查询
 停车记录: hh:mm:ss   status 
 查看停车场上的车辆
 停车最久的车辆

使用vector存放车牌信息进入信息
另一个vector存车辆牌照与停车时长
*/
bool cmp(pair<string,Date> a,pair<string,Date> b){
    return ((a->second).hh<b->second.hh)||(a->second.hh==b->second.hh&&a->second.mm<b->second.mm)||(a->second.hh==b->second.hh&&a->second.mm==b->second.mm&&a->second.ss<b->second.ss);
}
int main(){
    int hh,mm,ss;
    int record,search;
    cin>>record>>search;
    getchar();
    for(int i=0;i<record;i++){
        string name,ifin;
        scanf("%s %d:%d:%d %s",&name,&hh,&mm,&ss,&ifin);
        if(allInfo.find(name)==allInfo.end()){
             vector<Date> car;
             allInfo[name]=car;
        }
        Date cur;
        cur.hh=hh;
        cur.mm=mm;
        cur.ss=ss;
        if(ifin=="in")cur.ifin=1;
        else cur.ifin=-1;
        allInfo[name].push_back(cur);
    }
    //全部存入了以后开始计算
    map<string,vector<Date>>::iterator it;
    for(it=allInfo.begin();it!=allInfo.end();it++){
        int isin=1;
        Date in;
        for(int i=0;i<allInfo[it->first].size();i++){
            if(allInfo[it->first][i].ifin==isin){
                if(isin==1){
                    in=allInfo[it->first][i];
                }
                else{
                    if(output.find[it->first]==output.end()){
                        output[it->first]=in;
                    }
                    if(allInfo[it->first][i].ss<in.ss){
                        in.mm+=1;
                        in.ss=allInfo[it->first][i].ss+60;
                    }
                    in.ss=allInfo[it->first][i].ss-in.ss;
                    if(allInfo[it->first][i].mm<in.mm){
                        in.hh+=1;
                        in.mm=allInfo[it->first][i].mm+60;
                    }
                    in.mm=allInfo[it->first][i].mm-in.mm;
                    in.hh=allInfo[it->first][i].hh-in.hh;
                    output[it->first].ss+=in.ss;
                    output[it->first].mm+=in.mm; output[it->first].mm+= (output[it->first].ss/60); output[it->first].ss%=60;
                    output[it->first].hh+=in.hh;output[it->first].hh+= (output[it->first].mm/60); output[it->first].mm%=60;
                }
                isin=(-isin);
                
            }
        op.push_back(<it->first,output[it->first]>);
        }
    }

    for(int i=0;i<search;i++){
        
    }

    sort(op.begin(),op.end(),cmp);
    
    for(int i=0;i<output.size();i++){
        if(i<output.size()-1&&output[i]->second.hh==output[i-1]->second.hh&&output[i]->second.mm==output[i-1]->second.mm&&output[i]->second.ss==output[i-1]->second.ss){
            cout<<' '<<output[i]->first;
        }    
        else if(i==0)cout<<output[i]->first;
        else break;
    }
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <stdio.h>
using namespace std;
//21:48-22:08
// N (<=1000), 月饼种类
// D (<=500 thousand tons), 市场需求
//水
//分月饼 
bool cmp(pair<double,int> a,pair<double,int> b){
    return (a.second/a.first>b.second/b.first)||(((a.second/a.first)==(b.second/b.first))&&(a.first>=b.first));
}
int main(){
    int n;
    double d;
    cin>>n>>d;
    double *sum = new double[n];
    double *price = new double[n];
    vector <pair<double,double> > info;
    for(int i=0;i<n;i++){
        cin>>sum[i];
    }
    for(int i=0;i<n;i++){
        cin>>price[i];
        info.push_back(make_pair(sum[i],price[i]));
    }
    sort(info.begin(),info.end(),cmp);
    double cur=0,money=0;
    int flag=0;
    for(int i=0;i<info.size();i++){
        //cout<<money<<" <-money cur-> "<<cur<<endl;
        if(info[i].first>(d-cur)){
            money+=((d*1.0-cur)/(double)(info[i].first)*1.0)*(info[i].second);
            printf("%.2f",money);
            flag=1;
            break;
        }
        else{
            cur+=info[i].first;
            money+=info[i].second;
        }
    }
    if(flag==0)printf("%.2f",money);
}

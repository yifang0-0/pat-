#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//21:22-21:35
//k行n人
//每行N/K个人，四舍五入
//最后的人站在最后一排
//最后一排人最高
//每一行最高的人在最中间
//其余的人以降序左一个右一个
//身高相同字母序
//最后一排是最上的
bool cmp(pair<int,string>a,pair<int,string>b){
    return (a.first<b.first)||(a.first==b.first&&a.second<b.second);
}
 vector<pair<int,string> >peopleInfo;
void snakePrint(int length){
    int m=(length/2+1);
    string *name=new string[length];
    int direction=-1;
//cout<<length<<endl;
    name[m-1]=peopleInfo[peopleInfo.size()-1].second;
    //cout<<name[m-1]<<endl;
    peopleInfo.pop_back();
    for(int i=1;i<length;i++){
        m+=(direction*i);
        name[m-1]=peopleInfo[peopleInfo.size()-1].second;
        peopleInfo.pop_back();
        direction=-direction;
    }
    for(int i=0;i<length;i++){
        if(i!=0)cout<<' '<<name[i];
        else  cout<<name[i];
    }
    cout<<endl;
}
int main(){
    int sum,rowNum;
    int lineNum;
    cin>>sum>>rowNum;
    lineNum=sum/rowNum;
   
    for(int i=0;i<sum;i++){
        string name;
        int height;
        cin>>name>>height;
        peopleInfo.push_back(make_pair(height,name));
    }
    sort(peopleInfo.begin(),peopleInfo.end(),cmp);
    for(int i=0;i<peopleInfo.size();i++){
        cout<<peopleInfo[i].first<<peopleInfo[i].second<<' ';
    }
    cout<<endl;
    int lastLine=sum-lineNum*(rowNum-1);
   // cout<<lineNum<<" "<<rowNum<<" "<<lastLine<<endl;
    snakePrint(lastLine);
    for(int i=0;i<rowNum-1;i++){
        if(peopleInfo.size()==0)break;
        snakePrint(lineNum);
    }
}
#include <iostream>
#include <stdio.h>
#include <queue>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

//思路
// N : name age grade.
//N (≤10​5​​ ) - the total number of people, and K (≤10​3​​ ) - the number of queries. 
// M (≤100) - the maximum number of outputs, and [Amin, Amax] which are the range of ages.
//输出 name age worth
//输出降序
//建立年龄数组 由财富
struct info{
    string name;
    int age;
    int worth;
};
vector <struct info> allInfo;
bool cmp( struct info a,struct info b){
    return ((a.worth>b.worth)||((a.worth==b.worth)&&(a.age<b.age))||((a.worth==b.worth)&&(a.age==b.age)&&(a.name<b.name)));
} 
int main(){
    int pNum,sNum;
    cin>>pNum>>sNum;
    for(int i=0;i<pNum;i++){
        struct info newInfo;
        cin>>newInfo.name>>newInfo.age>>newInfo.worth;
        allInfo.push_back(newInfo);
    }
    sort(allInfo.begin(),allInfo.end(),cmp);
    for(int i=0;i<sNum;i++){
        int maxSerNum,minA,maxA;
        cin>> maxSerNum>>minA>>maxA;
        int curOut=0;
        cout<<"Case #"<<i+1<<":"<<endl;
        for(int j=0;j<allInfo.size();j++){
            if(allInfo[j].age<=maxA&&allInfo[j].age>=minA){
                if(curOut<maxSerNum){
                    cout<<allInfo[j].name<<' '<<allInfo[j].age<<' '<<allInfo[j].worth<<endl;
                    curOut+=1;
                }
            }
        }
        if(curOut==0)cout<<"None"<<endl;
    }
    

}

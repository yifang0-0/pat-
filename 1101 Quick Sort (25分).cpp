#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
  //19:10-19：29 超时
//19：43惨成全部测试点
  //首先sort 筛选出不在同一位置的数字
  //剩下的数字需要查找是否左边全部小于ta
int main(){
    //给出的个数可能超出int范围
    long long n;
    cin>>n;
    int list[100001]={0};
    int raw[100001]={0};
    for(int i=0;i<n;i++){
        scanf("%d",&list[i]);
        raw[i]=list[i];
    }
    sort(list,list+n);
    int count=0;
    vector<int>output;
    int left_max=raw[0];
    for(int i=0;i<n;i++){
        if(raw[i]!=list[i]){
            if(raw[i]>left_max)left_max=raw[i];
            continue;
        }
        if(raw[i]>=left_max){
            count++;
            output.push_back(raw[i]);
            left_max=raw[i];
        }
    }
    printf("%d\n",count);
    for(int i=0;i<output.size();i++){
        if(i==0)printf("%d",output[i]);
        else printf(" %d",output[i]);
    }
    printf("\n");
}
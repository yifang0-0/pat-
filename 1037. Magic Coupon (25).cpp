//17:08-17:31
/*
the number of coupons NC  1<= NC, NP <= 105
coupon integers.
the number of products NP
a line with NP product values.

output:能拿回的最大金额
coupon:能拿回n倍金额

*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    int nc,np;
    cin>>nc;
    long long sum=0;
    vector<int >cPos;
    vector<int >cNag;

    for(int i=0;i<nc;i++){
        int temp;
        cin>>temp;
        if(temp>0)cPos.push_back(temp);
        if(temp<0)cNag.push_back(-temp);

    }
    cin>>np;
    vector<int >pPos;
    vector<int >pNag;
    for(int i=0;i<np;i++){
        int temp;
         cin>>temp;
        if(temp>0)pPos.push_back(temp);
        if(temp<0)pNag.push_back(-temp);
    }
    sort(cPos.begin(),cPos.end());
    sort(cNag.begin(),cNag.end());
    sort(pPos.begin(),pPos.end());
    sort(pNag.begin(),pNag.end());
    while(cPos.size()>0&&pPos.size()>0){
        sum+=cPos.back()*pPos.back();
        cPos.pop_back();
        pPos.pop_back();
    }
    while(cNag.size()>0&&pNag.size()>0){
        sum+=cNag.back()*pNag.back();
        cNag.pop_back();
        pNag.pop_back();
    }
    cout<<sum<<endl;
    //最大的正c与最大的正p
    //小的正p与最小的正p



}

#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
//19:01-19:13
//首先是配对，如果能配对 哦俩map方便

#include <cstdio>
using namespace std;
map<int,int>coupleinfo;
map<int,int>guest;
int main(){
    int cnum;
    int gnum;
    scanf("%d\n",&cnum);
    for(int i=0;i<cnum;i++){
        int c1,c2;
        scanf("%d %d\n",&c1,&c2);
        coupleinfo[c1]=c2;
        coupleinfo[c2]=c1;
    }
    scanf("%d\n",&gnum);
      for(int i=0;i<gnum;i++){
      int c0;
      scanf("%d",&c0);
      guest[c0]=1;

  }
map<int,int>::iterator it;
vector<int>lone;
for(it=guest.begin();it!=guest.end();it++){
    int c1,c2;
    c1=it->first;
    if(coupleinfo.find(c1)==coupleinfo.end()){
        lone.push_back(c1);
    }
    else {
        c2=coupleinfo[c1];
        if(guest.find(c2)==guest.end()){
            lone.push_back(c1);
        }
    }
}
sort(lone.begin(),lone.end());
    printf("%d\n",lone.size());

for(int i=0;i<lone.size();i++){
    if(i==0)
    printf("%05d",lone[i]);
    else
    printf(" %05d",lone[i]);
}
}
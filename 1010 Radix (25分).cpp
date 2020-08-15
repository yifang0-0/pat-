//21：44-
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;
//N1 N2 tag radix
//tag给出当前所确定的进制是哪个
//最多是10个字符，可能的进制有2-36
//检查每一个进制是否可能
//存储字母表示的意思
map <char,int> recordNum;
int main(){
    for(int i=0;i<10;i++)
    {
        recordNum['0'+i]=i;
    }
    for(int i=0;i<26;i++)
    {
        recordNum['a'+i]=i+10;
        recordNum['A'+i]=i+10;
    }
    //考虑越界问题！
    //int ori=0,aim=0;
    long long ori=0,aim=0;
    string t1,t2,N1,N2;
    int tag,radix;
    cin>>t1 >> t2 >> tag >> radix;
    //前面一个是已知进制的
    if(tag!=1){
       N2=t1;
       N1=t2;
    }
    else{
        N2=t2;
       N1=t1; 
    }
    for(int i=0;i<N1.length();i++){
        if(i!=0)ori*=radix;
        ori+=(recordNum[N1[i]]);
    }
    int flag=0;
     for(int j=2;;j++){
        flag=0;
        aim=0;
        int i=0;
        for(;i<N2.length();i++){
            if(j<=recordNum[N2[i]]){
                flag=1;break;
            }
            if(i!=0)
            aim*=j;
            aim+=(recordNum[N2[i]]);
            if(aim>ori){
                flag=1;break;
            }
        }
        if(flag==0&&aim==ori){
            cout<<j;
            return 0;
        }  
        if(aim>ori)break;
    }
    cout<<"Impossible";
    return 0;
}

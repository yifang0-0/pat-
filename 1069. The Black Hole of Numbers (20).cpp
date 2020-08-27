#include <map>
#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
bool cmp1(char a,char b){
    return b<a;
}
int makeint(char* ori){
        int sum=0;
    for(int i=0;i<4;i++){
        sum*=10;
        sum+=(ori[i]-'0');
    }
    return sum;
}
int makeintreverse(char* ori){
        int sum=0;
    for(int i=3;i>=0;i--){
        sum*=10;
        sum+=(ori[i]-'0');
    }
    return sum;
}
void makechar(int n,char* ori){
    int i=3;
    while(i>=0){
        if(n!=0)
        ori[i]=n%10+'0';
        else ori[i]='0';
        n/=10;
        i--;
    }
}
int main(){
    int last=10000;
    int result=0;
    int n;cin>>n;
    char ori[5];
    for(int i=0;i<4;i++)ori[i]='0';
    makechar(n,ori);
    
   do{
        sort(ori,ori+4,cmp1);
        int oriint=makeint(ori);
        int oriminus=makeintreverse(ori);
       result=oriint-oriminus;
       //cout<<result<<endl;
       if(result==last)break;
       else {
           last=result;
           printf("%04d - %04d = %04d\n",oriint,oriminus,result);
       }
       makechar(result,ori);
   }while(1);
}

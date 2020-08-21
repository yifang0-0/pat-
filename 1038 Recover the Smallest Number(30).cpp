#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//思路
/*
输入字符串片段
输出最小的组合
*/
bool cmp(string a,string b){
   return (a+b)<(b+a);
}
int main(){
    int n;
    string a;
    cin>>n;
    int num=n;
    vector<string>strParts;
 while(n--){
     cin>>a;
     strParts.push_back(a);
 }
 int flag=0;
 sort(strParts.begin(),strParts.end(),cmp);
 for(int i=0;i<strParts.size();i++){
     if(i==0){
         for(int j=0;j<strParts[i].size();j++){
             if(flag==1||strParts[i][j]!='0'){
                 cout<<strParts[i][j];
                 flag=1;
                 }
         }
     }
     else{
         flag=1;
         cout<<strParts[i];
     }
 }
 if(flag==0)cout<<0<<endl;
}

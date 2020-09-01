//17：05-17:59
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<char>res;
void sum(string a,string b){
    int carry=0;
    for(int i=0;i<a.size();i++)
    {
        int cur=((a[i]-'0')+(b[a.size()-i-1]-'0')+carry);
        if(cur>9){
            carry=1;
        }
        else carry=0;
        //cout<<cur<<endl;
        res.push_back(cur%10+'0');
    }
    if(carry==1) res.push_back('1');
}
 int main(){
     string ori;
     cin>>ori;
     int flag=0;
     string result;
           int h=1;
         for(int i=0;i<ori.size()/2;i++){
             if(ori[i]!=ori[ori.size()-1-i]){
                 h=0;
                 break;
             }
         }
         if(h==1){
               cout<<ori;
             printf(" is a palindromic number.");
             return 1;
         }
     do{
         string rev;
         rev = ori;
         
        //rev=reverse(ori.begin(),ori.end());
         sum(ori,rev);
         
         cout<<ori<<" + ";
        for(int i=rev.size()-1;i>=0;i--){
            cout<<rev[i];
        }
         cout<<" = ";
         for(int i=res.size()-1;i>=0;i--){
             result.append(1,res[i]);
             
         }

         cout<<result<<endl;
         ori=result;
         int h=1;
         for(int i=0;i<result.size()/2;i++){
             if(result[i]!=result[result.size()-1-i]){
                 h=0;
                 break;
             }
         }
         if(h==1)break;
         res.clear();
         result.clear();
         flag++;
     }while(flag<10);
     if(flag<10){
         cout<<result;
         printf(" is a palindromic number.");
     }
     else if(flag==10){
          printf("Not found in 10 iterations.");
     }
 }
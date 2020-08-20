#include <string>
#include <iostream>
#include <algorithm>

//寻找最长公共尾子串
//第一次输入反转字符串 作为最新的公共字串
//此后每一次都输入后反转然后比较 一旦发现有不同的字符 设置'\0'
//全部输入之后判断子串长度
//balabala

int main(){
    int a ;
    cin>>a;
    string common;
    cin>>common;
    common=reverse(common.begin(),common.end());
    
    for (int i=1;i<a;i++){
        string newString;
        newString=reverse(ommon.begin(),common.end());
        for(int j=0;j<common.size();j++){
            if(common[j]!=newString[j]){
                common[j]='\0';
                break;
            }
        }
    }
    if(common.size()==0)cout<<"nai"<<endl;
    else cout<<reverse(common.begin(),common.end())<<endl;
}

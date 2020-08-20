

#include <string>
#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
//寻找最长公共尾子串
//第一次输入反转字符串 作为最新的公共字串
//此后每一次都输入后反转然后比较 一旦发现有不同的字符 设置'\0'
//全部输入之后判断子串长度
//balabala

int main(){
    int a ;
    scanf("%d\n",&a);
    string common;
    getline(cin,common);
    reverse(common.begin(),common.end());
    for (int i=1;i<a;i++){
        string newString;
        getline(cin,newString);
        cout<<i<<endl;
        //cout<<newString<<endl;
        reverse(newString.begin(),newString.end());
        //cout<<newString<<endl;
        for(int j=0;j<common.size()&&j<newString.size();j++){
            if(common[j]!=newString[j]){
                common=common.substr(0,j);
                break;
            }
        }
    }
    if(common.size()==0)cout<<"nai"<<endl;
    else {reverse(common.begin(),common.end());
    cout<<common<<endl;
    }
}

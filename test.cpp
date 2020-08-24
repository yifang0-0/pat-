#include<iostream>
using namespace std;
int main(){
    string a="a";
    string b="abd";
    if(a<b)
    cout<<"a<abd"<<endl;
     a="abc";
     b="ab";
    if(a<b)
    cout<<"abc<ab"<<endl;
     a="a";
     b="acd";
    if(a<b)
    cout<<"a<acd"<<endl;
}
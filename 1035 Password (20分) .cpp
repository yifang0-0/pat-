#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <map>
#include <queue>
using namespace std;
//用一些字符代替 1->@ 0->% l->L O->o
//只显示要改的队伍 用map村
map<string,string>output;
queue <string> saved;
string ifNeedModify(string a,int *flag){
    for(int i=0;i<a.size();i++){
        switch(a[i]){
            case '1':a.replace(i,1,"@");*flag=1;break;
            case '0':a.replace(i,1,"%");*flag=1;break;
            case 'l':a.replace(i,1,"L");*flag=1;break;
            case 'O':a.replace(i,1,"o");*flag=1;break;
        }
    }
    return a;
}
//http://c.biancheng.net/view/1449.html 字符串的操作
int main(){
    int n;
    cin>>n;
    getchar();
    for(int i=0;i<n;i++){
        string name,code;
        cin>>name>>code;
        int flag=0;
        code=ifNeedModify(code,&flag);
        if(flag==1){
            output[name]=code;
            saved.push(name);
            }
    }
    //map <string,string>::iterator it;
    int it;
    int size=saved.size();
    if(size>0){
        cout<<size<<endl;
        for(it=0;it<size;it++){
        cout<<saved.front()<<' '<<output[saved.front()]<<endl;
        saved.pop();
        }
    }
    else {
        if(n==1)
        printf("There is %d account and no account is modified",n);
        else printf("There are %d accounts and no account is modified",n);
    }
}#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <map>
#include <queue>
using namespace std;
//用一些字符代替 1->@ 0->% l->L O->o
//只显示要改的队伍 用map村
map<string,string>output;
queue <string> saved;
string ifNeedModify(string a,int *flag){
    for(int i=0;i<a.size();i++){
        switch(a[i]){
            case '1':a.replace(i,1,"@");*flag=1;break;
            case '0':a.replace(i,1,"%");*flag=1;break;
            case 'l':a.replace(i,1,"L");*flag=1;break;
            case 'O':a.replace(i,1,"o");*flag=1;break;
        }
    }
    return a;
}
//http://c.biancheng.net/view/1449.html 字符串的操作
int main(){
    int n;
    cin>>n;
    getchar();
    for(int i=0;i<n;i++){
        string name,code;
        cin>>name>>code;
        int flag=0;
        code=ifNeedModify(code,&flag);
        if(flag==1){
            output[name]=code;
            saved.push(name);
            }
    }
    //map <string,string>::iterator it;
    int it;
    int size=saved.size();
    if(size>0){
        cout<<size<<endl;
        for(it=0;it<size;it++){
        cout<<saved.front()<<' '<<output[saved.front()]<<endl;
        saved.pop();
        }
    }
    else {
        if(n==1)
        printf("There is %d account and no account is modified",n);
        else printf("There are %d accounts and no account is modified",n);
    }
}

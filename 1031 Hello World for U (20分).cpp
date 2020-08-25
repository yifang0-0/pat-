#include <iostream>
#include <string>
using namespace std;
//22:08-
int main(){
    string l;
    cin>>l;
    int n=l.size();

    int nNum=(n+2)/3;
    int left= (n+2)%3;
    int botton=left+nNum;
    int out=0;
    for(int i=0;i<nNum-1;i++){
        cout<<l[out++];
        for(int i=0;i<botton-2;i++)cout<<' ';
        cout<<l[n-out]<<endl;
    }
    for(int i=0;i<botton;i++){
        cout<<l[out+i];
    }
}
//20:10-20:36
#include <string>
#include <iostream>
using namespace std;
int main(){
    //给定的都是偶数的
    string a;
    int num;
    cin>>num;
    for(int i=0;i<num;i++)
    {
        cin>>a;
       // cout<<a<<endl;
        string a1,a2;
        a1=a.substr(0,a.size()/2);
        //cout<<a1<<endl;
        a2=a.substr(a.size()/2,a.size()/2);
        // cout<<a2<<endl;
        int ia,ia1,ia2;
        
        ia=stoi(a);
        //cout<<ia;
        ia1=stoi(a1);
        ia2=stoi(a2);
        if(ia%(ia1*ia2)==0)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 1;
}
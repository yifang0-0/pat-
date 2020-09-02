//aB->cB->dG->bG
//10:25-11:24
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
#include <cstdio>
#include <set>
using namespace std;
int n,m,k;
bool cmp(pair<string,string>a,pair<string,string>b){
    return a.first<b.first||(a.first==b.first&&a.second<b.second);
}
int main(){
    unordered_map<string,vector<string>>nodeinfo;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        string n1,n2;
        n1.resize(5);
        n2.resize(5);
        scanf("%s %s",&n1[0],&n2[0]);
        nodeinfo[n1].push_back(n2);
        nodeinfo[n2].push_back(n1);
    }
    cin>>k;
    for(int i=0;i<k;i++){
        string n1,n2;
        n1.resize(5);
        n2.resize(5);
        scanf("%s %s",&n1[0],&n2[0]);
        vector<string>n1fiend;
        vector<string>n2fiend;
        vector<string>temp;
        vector<pair<string,string>>output;
        temp=nodeinfo[n1];
       // cout<<endl;
        //cout<<n1<<" n1's friend"<<endl;
        for(int j=0;j<temp.size();j++){
            if((temp[j][0]=='-'&&n1[0]=='-')||(temp[j][0]!='-'&&n1[0]!='-')){
                if(temp[j]!=n2)
                n1fiend.push_back(temp[j]);
               // cout<<temp[j]<<' ';

            }
        }
        temp=nodeinfo[n2];
       // cout<<endl;
        //cout<<n2<<" n2's friend"<<endl;

        for(int j=0;j<temp.size();j++){
            if((temp[j][0]=='-'&&n2[0]=='-')||(temp[j][0]!='-'&&n2[0]!='-')){
                if(temp[j]!=n1)
                n2fiend.push_back(temp[j]);
               // cout<<temp[j]<<' ';
            }
        }

        for(string x:n1fiend){
            for(string y:n2fiend){
                int flag=0;
               // cout<<x<<' '<<y<<endl;
                for(string n:nodeinfo[x]){
                    if(y==n){
                        flag=1;
                       // cout<<"yes"<<endl;
                        break;
                    }
                }
                if(flag==1){
                    // string x1=x,y1=y;
                    // if(x[0]=='-')x1=x.substr(1);
                    // if(y[0]=='-')y1=y.substr(1);
                    output.push_back(make_pair(x,y));
                }
            }
        }
        printf("%d\n",output.size());
        //cout<<output.size()<<endl;
        sort(output.begin(),output.end(),cmp);
        for(pair<string,string> op:output){
            printf("%04d %04d\n",abs(stoi(op.first)),abs(stoi(op.second)));
        }
        
    }
}

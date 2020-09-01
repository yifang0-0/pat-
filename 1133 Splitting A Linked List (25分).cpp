//20:46-21:21(最后一个样例没有通过-5)
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int num,k;
int getv(int a){
    if(a<0)return 1;
    if(a>=0&&a<=k)return 2;
    else return 3;
}


bool cmp(pair < int , string> a, pair <int , string> b){
    return getv(a.first)<getv(b.first);
}
int main(){
    vector<pair<int , string>>nodesv;
    string head;
    cin>>head>> num>>k;
    map<string ,pair<int,string>>nodes;
    for(int i=0;i<num;i++){
        string add,next;
        int val;
        //scanf("%s %d %s\n",&add,&val,&next);
        cin>>add>>val>>next;
        nodes[add]=make_pair(val,next);
        //nodes.push_back(make_pair(val,add));
    }
   // map<string ,pair<int,string>>::iterator it;
    do
    {
        nodesv.push_back(make_pair(nodes[head].first,head));
        head=nodes[head].second;
    }while(head!="-1");
    //sort(nodesv.begin(),nodesv.end(),cmp);
    int i=0;
    string h,n;
    string ln;
    h=head;
    lastheaf=h;
    for( i=0;i<nodesv.size()-1;i++){
        cout<<nodesv[i].second<<' '<<nodesv[i].first<<' '<<nodesv[i+1].second<<endl;
    }
    cout<<nodesv[i].second<<' '<<nodesv[i].first<<" -1"<<endl;
}
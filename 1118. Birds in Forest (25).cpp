#include <map>
#include <iostream>
using namespace std;
//改成scanf也没用···算了 换个算法吧
int main(){
    int pnum,snum;
    cin>>pnum;
    map<int,int>birdstotree;
    map<int,int>same;
    map<int,int>countTree;
    for(int i=0;i<pnum;i++){
        int bnum;
        cin>>bnum;//  cout<<bnum<<endl;
        int curtreenum=i;
        int newbird;
        for(int j=0;j<bnum;j++){
            cin>>newbird;
            if(birdstotree.find(newbird)!=birdstotree.end()){ //  cout<<"change "<<birdstotree[newbird]<<" TO "<<curtreenum<<endl;
                same[birdstotree[newbird]]=curtreenum;
                countTree.erase(birdstotree[newbird]);
            }
            birdstotree[newbird]=curtreenum;
        }
        map<int,int>::iterator it; //cout<<"birdid tree"<<endl;
        for(it=birdstotree.begin();it!=birdstotree.end();it++){
            int birdid=it->first, treeid=it->second;
            if(same.find(treeid)!=same.end()){ // cout<<"treeid repeted"<<treeid<<endl;
                birdstotree[birdid]=curtreenum;
            }//cout<< birdid<<' '<< birdstotree[birdid]<<endl;
        } // cout<<"end"<<endl;
        same.clear();
        countTree[curtreenum]=1;
    }
    cin>>snum;
    cout<<countTree.size()<<' '<<birdstotree.size()<<endl;
    for(int i=0;i<snum;i++){
        int birda,birdb;
        cin>>birda>>birdb;
        if(birdstotree[birda]==birdstotree[birdb])cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}

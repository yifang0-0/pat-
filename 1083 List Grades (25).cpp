#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
//21:19-
typedef struct score{
    char name[11] ;
    char id[11] ;
    int s;
}Score;

bool cmpl(struct score a,struct score b){
    return a.s>b.s;
}
int main(){
    int num,min,max;
    cin>>num;
    Score *s=new Score[num];
    for(int i=0;i<num;i++){
        //cin>>s[i].name>>s[i].id>>s[i].s;
        scanf("%s %s %d",&s[i].name,&s[i].id,&s[i].s);
    }
    //cin>>min>>max;
   scanf("%d %d",&min,&max);
    sort(s,s+num,cmpl);
    int flag=0;
    for(int i=0;i<num;i++){
        //if(flag==1)cout<<endl;
        if(s[i].s<min)break;
        if(s[i].s<=max){
            printf("%s %s\n",s[i].name,s[i].id);
            //cout<<s[i].name<<' '<<s[i].id<<endl; 
            
            flag=1;
        }
    }
    if(flag==0)cout<<"NONE"<<endl;
}

/*#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
//21:19-
typedef struct score{
    string name;
    int s;
}Score;
map<string,Score>studentinfo;
bool cmp(pair<string,Score>&a,pair<string,Score>&b){
    return a.second.s>b.second.s;
}
int main(){
    int num,min,max;
    cin>>num;
    for(int i=0;i<num;i++){
        string id;
        Score s;
        
        cin>>s.name>>id>>s.s;
        studentinfo[id]=s;
    }
    cin>>min>>max;
    vector <pair<string,Score>> vec(studentinfo.begin(),studentinfo.end());
    sort(vec.begin(),vec.end(),cmp);
    int flag=0;
    for(const auto i:vec){
        //if(flag==1)cout<<endl;
        if(i.second.s>=min&&i.second.s<=max){
            cout<<i.second.name<<' '<<i.first<<endl; 
            
            flag=1;
        }
    }
    if(flag==0)cout<<"NONE";
}*/
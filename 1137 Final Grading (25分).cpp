//20：10-
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
/*
// P , the number of students having done the online programming assignments
// M, the number of students on the mid-term list
// N, the number of students on the final exam list
*/
using namespace std;
typedef struct stu{
    int ps;
    int mt;
    int fn;
    int general;
}students;
map<string ,students>stuinfo;

bool cmp(pair<string,students> a,pair<string,students>b){
    return (a.second.general>b.second.general)||((a.second.general==b.second.general)&&a.first<b.first);
}
//可以没有期中 但一定要有大于等于200的project
int main(){
    int p,m,n;
    cin>>p>>m>>n;
    vector<pair<string,students>>pass;
    for(int i=0;i<p;i++){
        string name;
        name.resize(20);
        int ps;
        scanf("%s %d",&name[0],&ps);
        if(ps>=200){
          //  cout<<name<<" insert"<<endl;

            stuinfo[name].ps=ps;
            stuinfo[name].mt=-1;
            stuinfo[name].fn=0;
            stuinfo[name].general=0;
              if(stuinfo.find(name)!=stuinfo.end()){
         //   cout<<name<<" was found 1"<<endl;
                  
              }
        }
    }
    for(int i=0;i<m;i++){
       string name;
        name.resize(20);
        int mt;
        scanf("%s %d",&name[0],&mt);
        //cout<<name<<' '<<(stuinfo.find(name)!=stuinfo.end())<<endl;
        if(stuinfo.find(name)!=stuinfo.end()){
          //  cout<<name<<" was found 2"<<endl;
            stuinfo[name].mt=mt;
        }
    }
    for(int i=0;i<n;i++){
        string name;
        name.resize(20);
        int fn;
        scanf("%s %d",&name[0],&fn);
        if(stuinfo.find(name)!=stuinfo.end()){
          //  cout<<name<<" was found 3"<<endl;

            students temp=stuinfo[name];
           temp.fn=fn;
            int count1=fn;
            if(temp.mt>temp.fn)count1=temp.mt;
            temp.general=(int)(0.6*(double)fn+0.4*(double)count1+0.5);
            if(temp.general>=60){
            //cout<<name<<" passed"<<endl;
                pass.push_back(make_pair(name,temp));
            }
            //stuinfo[name]=temp;
        }
    }
    sort(pass.begin(),pass.end(),cmp);
   for(int i=0;i<pass.size();i++){
            students temp=pass[i].second;

       printf("%s %d %d %d %d\n",(pass[i].first).c_str(),temp.ps,temp.mt,temp.fn,temp.general);
   }
}
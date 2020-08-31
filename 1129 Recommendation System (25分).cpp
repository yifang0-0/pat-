//21:18-
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <string>
#include <stdio.h>
#include <queue>
#include<algorithm>
using namespace std;

//N (≤ 50,000), the total number of queries
//K (≤ 10), the maximum number of recommendations the system
//一个user接触的次数 计算出现率
//每一次查询都重新排序
int main(){
    int n,k;
    cin>>n>>k;
    int output[50001]={0,0};
    int rec[11]={0};
        int outputsize=0;
    for(int i=0;i<n;i++){
        int cur;
        scanf("%d",&cur);
        if(i>0){
                    int count=1;
                    cout<<cur<<":";
                    while(count<=k){
                    if(rec[count]==0)break;
                    cout<<" "<<rec[count];
                    count++;
                    }
                    cout<<endl;
        }
        if(output[cur]==0){
            int flag=0;
            output[cur]=1;
            if(outputsize<k){
                //cout<<"outputsize "<<outputsize<<endl;
                outputsize++;           
                rec[outputsize]=cur;
                flag=1;
            }
            else if(output[cur]>output[rec[outputsize]]||(output[cur]==output[rec[outputsize]]&&cur<rec[outputsize])){
                rec[outputsize]=cur;
                flag=1;
            }    
            int mem=rec[outputsize];
            int j;
            for(j=outputsize-1;j>0;j--){
                if(output[rec[j+1]]>output[rec[j]]||(output[rec[j+1]]==output[rec[j]]&&rec[j+1]<rec[j])){
                    int temp=rec[j+1];
                    rec[j+1]=rec[j];
                    rec[j]=temp;
                }
            }
        }
        else 
        {
            int flag=0;
            //cout<<"cur= "<<cur<<endl;
            //if(cur<=rec[outputsize]||(output[cur]>output[cur[outputsize]]))
            if(output[cur]>output[rec[outputsize]]||(output[cur]==output[rec[outputsize]]&&cur<=rec[outputsize])){
                //output已经存在
                //cout<<"output已经存在"<<endl;
                flag=1;
            }
            output[cur]++;
            if(flag==0){
                 if(output[cur]>output[rec[outputsize]]||(output[cur]==output[rec[outputsize]]&&cur<rec[outputsize])){
               // cout<<"output加入"<<endl;
                 rec[outputsize]=cur;
                }
            }
            int j;
            for(j=outputsize-1;j>0;j--){
                if(output[rec[j+1]]>output[rec[j]]||(output[rec[j+1]]==output[rec[j]]&&rec[j+1]<rec[j])){
                    int last=rec[j];
                    rec[j]=rec[j+1];
                    rec[j+1]=last;
                }
            }
           
        }
    }
}
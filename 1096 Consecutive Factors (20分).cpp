#include <iostream>
//20:40-
#include <algorithm>
#include <math.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int maxlength=0;
    int curlength=0;
    int min=-1;
    //int curlast=0;
    int curstart;
    int sum=1;
    int i=2;
    while(i<=sqrt((double)n)+1){
        //cout<<i<<' '<<sum<<' '<<endl;
        sum*=i;
        if(sum>n){
            break;
            }
        if(n%sum==0){
            //能够整除
            if(min==-1){
                //min=i;
                //curlength=1;
                curstart=i;
            }
            curlength+=1;
           // cout<<i<<' ';
            if(curlength>maxlength){
                maxlength=curlength;
                min=curstart;
            }
            if(curlength==maxlength){
                
            }
        }
        else{
            //断了
            //从头开始数 
            if(curstart!=0&&n%(sum/curstart)==0){
                sum/=curstart;
                curstart=curstart+1;              //啊啊啊啊啊什么叫做小题巨坑！一个测试点3，一个测试点6
                //这里被卡得死死的 参考https://blog.csdn.net/Strengthennn/article/details/105080768?utm_medium=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-5.channel_param&depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-5.channel_param
                //总之首先要减小复杂度（sqrt()）
                //其次要防止出现乘法避免溢出
                //最后逻辑要完备，可能出现n=a1*x1*x2*a2 和 n=x2*x3*x4*a3都成立的情况，不能一直拿着sum连续相乘，如n%sum!=0但是maxlength相等了，就把当前起始点替换到原先的后一个
            }    
            else{
                curstart=i+1;
                curlength=0;
                sum=1;   
            }
        }
        i++;
    }
    //cout<<endl;
    if(maxlength>0){
        cout<<maxlength<<endl;
        for(int i=0;i<maxlength;i++){
            cout<<min+i;
            if(i!=maxlength-1)cout<<'*';
        }    
    }
    else{
        cout<<"1"<<endl;
        cout<<n<<endl;
    }
    
}
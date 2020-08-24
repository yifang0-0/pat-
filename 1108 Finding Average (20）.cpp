#include <iostream>
#include <string>
//20:31-21:21 37
//N 两位小数
//检测输入的是否是合法的
//cin 再读一个char,如果char是空格，说明可以，如果不是，丢弃，再读一个string
using namespace std;
//补stod
int main(){
    string a;
    long s=0;
    //乘以1000，最后除以1000输出
    //如果有小数点，只有一个，且小数点的位置size-1>INDEX>=size-3
    //如果有-，只能在第一个
    //此外应该只有数字
    int n;
    scanf("%d\n",&n);
    int num=0;
    for(int i=0;i<n;i++){
        cin>>a;
         int size=a.size();
         int ifdot=0;
         int ifminus=0;
        int flag=1;
        if(size>6){
            cout<<"ERROR: "<<a<<" is not a legal number"<<endl;
            continue;
        }
        for(int j=0;j<size;j++){
            if(a[j]>='0'&&a[j]<='9'){continue;}
            else if(a[j]=='.'){
                if(ifdot==1){
                    flag=0;
                    break;
                }
                ifdot=1;
                if(j<size-3||j==0||(a[0]=='-'&&j==1)){
                    flag=0;
                    // cout<<"strange char"<<endl;
                    break;
                    }
            }
            else if(j==0&&a[j]=='-'){
                continue;
            }
            else{
               // cout<<"strange char"<<endl;
                flag=0;
                break;
            }
        }
        if(flag==0){
            cout<<"ERROR: "<<a<<" is not a legal number"<<endl;
            continue;
            }
        double cur=stod(a);
        long curlong=(long)(cur*1000);
        if((curlong)<=1000000&&curlong>=-1000000){
            s+=((long)(cur*1000));
            num++;
        }   
        else cout<<"ERROR: "<<a<<" is not a legal number"<<endl;
    }
    if(num==0)cout<<"The average of 0 numbers is Undefined"<<endl;
    else if(num==1){
        cout<<"The average of "<<num<<" number is ";
        printf("%.2f",(double)(s)/num/1000);
    }
    else {cout<<"The average of "<<num<<" numbers is ";
        printf("%.2f",(double)(s)/num/1000);
    }
}

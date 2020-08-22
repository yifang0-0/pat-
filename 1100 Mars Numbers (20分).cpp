#include <iostream>
#include <string>
#include <stdio.h>
#include <map>
using namespace std;
//17:30-17:53

string lownum0to12[13]={"tret" , "jan" , "feb" , "mar" , "apr" , "may" , "jun" , "jly" , "aug" , "sep" , "oct" , "nov" , "dec" };
string highnum12[12]={ "tam" , "hel" , "maa" , "huh" , "tou" , "kes" , "hei" , "elo" , "syy" , "lok" , "mer" , "jou"};
map <string,int>value;

void change2mars(int ori){
    if(ori>12){
        //printf("%s %s\n",highnum12[ori/13-1],lownum0to12[ori%13]);
        if(ori%13==0)cout<<highnum12[(ori/13)-1]<<endl;
        else cout<<highnum12[(ori/13)-1]<<' '<<lownum0to12[ori%13]<<endl;
    }
    else cout<<lownum0to12[ori%13]<<endl;
}

int main(){
    for(int i=0;i<13;i++){
        value[lownum0to12[i]]=i;
    }
    for(int i=0;i<12;i++){
        value[highnum12[i]]=(i+1)*13;
    }
    int n;  
    scanf("%d\n",&n);
    for(int i=0;i<n;i++){
        string num;
        getline(cin,num);
        if(num[0]<='9'&&num[0]>='0'){
            int ori=stoi(num);
            change2mars(ori);
        }
        else {
            
            
            if(num.size()>4){
                int index=num.find(' ');
                string n1=num.substr(0,index);
                string n2=num.substr(index+1,num.size()-index);
                //cout<<n1<<' '<<n2<<endl;
                printf("%d\n", value[n1]+value[n2]);
            }
            else{
                
                printf("%d\n", value[num]);
            }
        }
    }
}
//啊一道狗屎题做了这么久   不熟悉字符串操作函数！！！ and进制转换中要注意如果火星文字是13倍数，个位不输出
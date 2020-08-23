//14：43-
#include <iostream>
#include <algorithm>
#include <map>
#include <stdio.h>
using namespace std;
int main(){
    int n;
    long long sum=0;
    scanf("%d",&n);
    double newNum;
    for(int i=0;i<n;i++){
        scanf("%lf",&newNum);
        sum+=(((long long)(newNum*1000))*(i+1)*(n-i));
        //这边用double类型的sum，直接输出测试点3通不过
    }
    if(n==0)printf("\n");
    else printf("%0.2lf\n",sum/1000.0);
}

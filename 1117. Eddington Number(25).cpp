#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    int *times=new int[n+2]; 
    for(int i=0;i<n;i++) cin>>times[i];       
    sort(times,times+n);
    int curnum=1;
    int i=n-1;
    while(curnum<times[i]&&i>=0){curnum++;i--;}
    cout<<curnum-1;
}

// #include <iostream>
// #include <stdio.h>
// #include <algorithm>
// #include <map>
// using namespace std;

// //N个数字大于N
// //贪心?
// map<int,int>m;

// int main(){
//     int n;
//     cin>>n;
//     int *times=new int[n+2];
//     for(int i=0;i<n+2;i++)times[i]=0;
//     int *number=new int[n+2];
//     for(int i=0;i<n+2;i++)number[i]=0;
//     int total=0;
//     for(int i=0;i<n;i++){
//         int newNum;
//         cin>>newNum;
//         if(m.find(newNum)==m.end()){
//             number[total]=newNum;
//             total+=1;
//             m[newNum]=1;
//         }
//         else{
//             m[newNum]++;
//         }
        
//     }
//     sort(number,number+total);
//     //int max=0;
//     m[times[total]]=0;
//     for(int i=total-1;i>0;i--){
//         m[number[i]]+=m[times[i+1]];
//         if( m[number[i]]==number[i-1]){
//             cout<<number[i-1];
//             return 0;
//         }
//     }
    
// }

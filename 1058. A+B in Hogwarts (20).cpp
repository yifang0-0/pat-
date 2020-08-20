//19:50-20:05
#include <iostream>
#include <string>
#include <map>
#include "stdio.h"
using namespace std;

//思路
/*
17银->1金
29铜->1银
两种不同进制的相加
//金银铜
*/
int main(){
    int GoldA,SilverA,KuntA;
    int GoldB,SilverB,KuntB;

    scanf("%d.%d.%d %d.%d.%d",&GoldA,&SilverA,&KuntA,&GoldB,&SilverB,&KuntB);
    KuntA+=KuntB;
    if(KuntA>=29){
        SilverA+=(KuntA/29);
        KuntA%=29;
    }
    SilverA+=SilverB;
    if(SilverA>=17){
        GoldA+=(SilverA/17);
        SilverA%=17;
    }
    GoldA+=GoldB;
    cout<<GoldA<<"."<<SilverA<<"."<<KuntA<<endl;
}

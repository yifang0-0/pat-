#include<stdio.h>
#include<stdlib.h>
void swap(int*a,int m,int n){
int p;
p=a[m];
a[m]=a[n];
a[n]=p;
}
void quick(int *m,int Min,int Max){

int index,min=Min,max=Max;
index=min;
while(min<max){
	while(m[index]<=m[max]&&min<max)max--;
		{swap(m,index,max);index=max;}
	while(m[index]>=m[min]&&min<max)min++;
		{swap(m,index,min);index=min;}
}
if(Min<(index-1))quick(m,Min,index-1);
if(Max>(index+1))quick(m,index+1,Max);
}


int culculaterope(int *m){
int i=2,length=m[1];
while(i<=m[0]){
	length=(length+m[i++])/2;
}
return length;
}

int* putin(){
	int i=1,n;
	scanf("%d",&n);
	int*m=(int*)malloc((n+1)*sizeof(int));
	m[0]=n;
	while(i<=m[0])scanf("%d",&m[i++]);
	return m;
}
int main(){
int*m;
m=putin();
quick(m,1,m[0]);
printf("%d",culculaterope(m));
return 0;
}
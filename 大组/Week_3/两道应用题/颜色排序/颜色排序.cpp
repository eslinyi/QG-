#include<stdio.h>
void colorsoft(int *a,int num){
	int *p1,*p2,*p0;
	int tran;
	p1=p0=a;p2=a+num-1;
	for(;*p2==2;){
		p2--;
	}
	for(;*p0==0;){
		p0++;
	}
	for(;p1<=p2;){
		if(*p1==0){
			tran=*p0;
			*p0=*p1;
			*p1=tran;
			p0++;
		}
		else if(*p1==2){
			tran=*p2;
			*p2=*p1;
			*p1=tran;
			p2--;
		}
		if(*p1==1){
			p1++;
		} 
	}
}
int main(){
	int a[10]={1,2,0,0,2,1,2,1,2,2};;
	int i;
	colorsoft(a,10);
	for(i=0;i<10;i++){
		printf("%d ",a[i]);
	}
} 

#include<stdio.h>


int Find_date(int *a,int start,int end,int t){
 	int i,j,x,g=1,p;
 	i=start;j=end;
 	x=a[i];
 	if(i<j){
  		while(i<j){
  			while(i<j&&a[j]>x){
   			j--;
 			}
  		if(i<j){
  			a[i++]=a[j];
  			g++;
  			}
  		while(i<j&&a[i]<x){
   			i++;g++;
  			}
  		if(i<j){
   			a[j--]=a[i];
  			}
 		}
	}
 	a[i]=x;
 	if(g==t){
  		return a[i];
 	}
 	else if(g>t){
  		p=Find_date(a,start,i-1,t);
  		return p;
 	}
 	else if(g<t){
  		p=Find_date(a,i+1,end,t-g);
 		return p;
 	}
}
int main(){
	int num;
	printf("�����������������Ԫ�صĸ���:\n");
	scanf("%d",&num); 
   	int a[num];
   	int i;
   	printf("������������Ԫ�أ�\n");
   	for(i=0;i<num;i++){
   		scanf("%d",&a[i]);
	   } 
    int p,k;
    printf("��������Ҫ�ڼ����Ԫ�أ�\n");
    scanf("%d",&k);
    p=Find_date(a,0,num-1,num-k+1);
    printf("����Ҫ��Ԫ��Ϊ��\n");
    printf("%d",p);
}

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
	printf("输入你想输入的数组元素的个数:\n");
	scanf("%d",&num); 
   	int a[num];
   	int i;
   	printf("逐个输入数组的元素：\n");
   	for(i=0;i<num;i++){
   		scanf("%d",&a[i]);
	   } 
    int p,k;
    printf("输入你想要第几大的元素：\n");
    scanf("%d",&k);
    p=Find_date(a,0,num-1,num-k+1);
    printf("你需要的元素为：\n");
    printf("%d",p);
}

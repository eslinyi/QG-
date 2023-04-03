#include<stdio.h>
#include<stdlib.h> 
#include<time.h>
//插入排序
void InsertSort(int *a,int num){
	int i,t,term;
	for(i=1;i<num;){
		for(t=i+1;i>0;i--){
			if(a[i]<a[i-1]){
				term=a[i-1];
				a[i-1]=a[i];
				a[i]=term;
			}
			else{
				break; 
			}
		}
		i=t;
	}
}
//归并排序
void MergSort_dis(int *a,int start,int mid,int end){
	int t[end-start+1];
	int i,j,k=0;
	for(i=start,j=mid+1;i<=mid&&j<=end;){
		if(a[i]>=a[j]){
			t[k++]=a[i++];
		}
		else{
			t[k++]=a[j++];
		}
	}
	while(i<=mid){
		t[k++]=a[i++];
	}
	while(j<=end){
		t[k++]=a[j++];
	}
	for(i=0;i<k;i++){
		a[start+i]=t[i];
	}
}
void MergeSort_sum(int *a,int start,int end){
	int mid;
	mid=(end+start)/2;
	if(a!=NULL&&start<end){
		MergeSort_sum(a,start,mid);
		MergeSort_sum(a,mid+1,end);
	}
	MergSort_dis(a,start,mid,end);
} 
//快速排序
void QuickSort(int *a,int start,int end){
	int i,j,x;
	i=start;j=end;
	x=a[i];
	if(i<j){
		while(i<j){
		while(i<j&&a[j]>x){
			j--;
		}
		if(i<j){
			a[i++]=a[j];
		}
		while(i<j&&a[i]<x){
			i++;
		}
		if(i<j){
			a[j--]=a[i];
		}
	}	
	a[i]=x;
	QuickSort(a,start,i-1);
	QuickSort(a,i+1,end);
	}
} 
//计数排序法 
void CountSort(int *a,int num){
	int i,max,s,t,g,k;
	for(max=a[0],i=1;i<num;i++){
		max=max>a[i]?max:a[i];
	} 
	int count[max+1];
	int sum[max+1];
	for(i=0;i<max+1;i++){
		count[i]=0;
		sum[i]=0;
	}
	for(i=0;i<num;i++){				//计数数组 
		count[a[i]]+=1;
	}
	for(s=0,i=0;i<max+1;i++){		//累次计数数组 
		s+=count[i];
		sum[i]=s;
	}
	for(i=0,t=0;t<max;t++){
		if(t==0){
			if(sum[t]==1){
				a[i++]=t;continue;
			}
		}
		g=sum[t+1]-sum[t];
		if(g!=0){
			for(k=0;k<g;k++){
				a[i++]=t+1;
			}
		}	
	} 
} 
//基数计数排序法 
void RadixCountSort(int *a,int num){
	int i,max=0,t,g,k=1;
	int term[10];
	int tran[num];
	for(i=0;i<num;i++){
		max=max>a[i]?max:a[i];
	}
	for(t=0;max!=0;t++){
		max/=10; 
	}
	for(i=0;i<t;i++,k*=10){
		int term[10]={0};
		for(g=0;g<num;g++){
			term[a[g]/k%10]++;
		}
		for(g=1;g<10;g++){
			term[g]+=term[g-1];
		}
		for(g=num-1;g>=0;g--){
			tran[term[a[g]/k%10]-1]=a[g];
			term[a[g]/k%10]--;
		}
		for(g=0;g<num;g++){
			a[g]=tran[g];
		}
	}
}

//文件系统
void creatdate(int num){
	int i,a;
	FILE *fp;
	fp=fopen("生成的数据","a");
	for(i=0;i<num;i++){
		a=rand()%1000+0;
		fprintf(fp,"%d ",a);
	} 
	fclose(fp);
}
void readdate(int *a,int num){
	FILE *fp;
	int i;
	fp=fopen("生成的数据","r");
	for(i=0;i<num;i++){
		fscanf(fp,"%d ",&a[i]);
	}
	fclose(fp);
}
void deletdate(){
	remove("生成的数据"); 
}
 
int main(){
	srand((unsigned int)time(NULL));
	printf("输入你想要生成的数据个数:\n");
	int num;
	scanf("%d",&num); 
	creatdate(num);
	int a[num];
	int i,z;
	readdate(a,num);
	printf("输入你想进行的排序方法（1为插入排序，2为归并排序，3为快数排序，4为计数排序，5为基数计数排序）：\n");
	scanf("%d",&z);
	if(z==1){
		InsertSort(a,num);
	}
	else if(z==2){
		MergeSort_sum(a,0,num-1);
	}
	else if(z==3){
		QuickSort(a,0,num-1);	
	}
	else if(z==4){
		CountSort(a,num);
	}
	else if(z==5){
		RadixCountSort(a,num);
	}
	for(i=0;i<num;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
	printf("是否删除文件(0就删除，1就保留)\n");
	scanf("%d",&z);
	if(z==0){
		deletdate();
		printf("删除成功"); 
	} 
} 

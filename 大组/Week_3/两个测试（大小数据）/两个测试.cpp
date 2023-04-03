#include<stdio.h>
#include<stdlib.h> 
#include<time.h>
//基本排序函数
 
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

//操作函数模块

void Rand_date(int *a,int num){
	int g;
	for(g=0;g<num;g++){
		a[g]=rand()%1000+0;
	}
}


 
int main(){
	srand((unsigned int)time(NULL));
	int num=0,z,k,i,g,j;
	int time[5];
	printf("请输入您选择什么数据检验（0为大数据，1为小数据）：\n");
	scanf("%d",&z); 
	if(z==0){
		printf("请选择数量类别（0为10000,1为50000,2为200000）：\n");
		scanf("%d",&k);
		if(k==0){
			num=10000;
		} 
		else if(k==1){
			num=50000;
		}
		else if(k==2){
			num=200000;
		}
	}
	else{
		printf("选定小数据为100个，每个排序将进行100*k次的测试\n");
		num=100;
	}
	int a[num];int tran[num]; 
	Rand_date(a,num);
	if(z==0){
		for(g=0;g<5;g++){
		for(i=0;i<num;i++){
			tran[i]=a[i];
		}
		clock_t start=clock();
		if(g==0){
			InsertSort(tran,num);
			clock_t diff=clock()-start;
			printf("第%d号排序的时间为%dms\n",g+1,diff);
		}
		else if(g==1){
			MergeSort_sum(tran,0,num-1);
			clock_t diff=clock()-start;
			printf("\n第%d号排序的时间为%dms\n",g+1,diff);;
		}
		else if(g==2){
			QuickSort(tran,0,num-1);
			clock_t diff=clock()-start;
			printf("\n第%d号排序的时间为%dms\n",g+1,diff);
		}
		else if(g==3){
			CountSort(tran,num);
			clock_t diff=clock()-start;
			printf("\n第%d号排序的时间为%dms\n",g+1,diff);
		}
		else if(g==4){
			RadixCountSort(tran,num);
			clock_t diff=clock()-start;
			printf("\n第%d号排序的时间为%dms\n",g+1,diff);
		}
	}
	}
	else{
		printf("输入你需要对小数据运行多少个100次：\n");
		scanf("%d",&k); 
		clock_t start1=clock();
		for(j=0;j<num*k;j++){
			for(i=0;i<num;i++){
				tran[i]=a[i];
			}
		}
		clock_t diff1=clock()-start1;
		clock_t start=clock();
		for(g=0;g<5;g++){
		if(g==0){
			for(j=0;j<num*k;j++){
				for(i=0;i<num;i++){
					tran[i]=a[i];
				}
				InsertSort(tran,num);
			}
			clock_t diff=clock()-start;
			printf("第%d号排序的时间为%dms\n",g+1,diff-diff1);
		}
		else if(g==1){
			for(j=0;j<num*k;j++){
				for(i=0;i<num;i++){
					tran[i]=a[i];
				}
				MergeSort_sum(tran,0,num-1);
			}
			clock_t diff=clock()-start;
			printf("第%d号排序的时间为%dms\n",g+1,diff-diff1);
		}
		else if(g==2){
			for(j=0;j<num*k;j++){
				for(i=0;i<num;i++){
					tran[i]=a[i];
				}
				QuickSort(tran,0,num-1);
			}
			clock_t diff=clock()-start;
			printf("第%d号排序的时间为%dms\n",g+1,diff-diff1);
		}
		else if(g==3){
			for(j=0;j<num*k;j++){
				for(i=0;i<num;i++){
					tran[i]=a[i];
				}
				CountSort(tran,num);
			}
			clock_t diff=clock()-start;
			printf("第%d号排序的时间为%dms\n",g+1,diff-diff1);
		}
		else if(g==4){
			for(j=0;j<num*k;j++){
				for(i=0;i<num;i++){
					tran[i]=a[i];
				}
				RadixCountSort(tran,num);
			}
			clock_t diff=clock()-start;
			printf("第%d号排序的时间为%dms\n",g+1,diff-diff1);
		}
		}
	} 
} 

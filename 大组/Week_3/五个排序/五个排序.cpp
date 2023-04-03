#include<stdio.h>
//��������
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
//�鲢����
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
//��������
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
//�������� 
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
	for(i=0;i<num;i++){				//�������� 
		count[a[i]]+=1;
	}
	for(s=0,i=0;i<max+1;i++){		//�۴μ������� 
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
//������������ 
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
 
int main(){
	int i,num,z;
	printf("������������������Ԫ�ظ�����\n");
	scanf("%d",&num);
	int a[num];
	printf("���������Ԫ��(�س���һ��)��\n"); 
	for(i=0;i<num;i++){
		scanf("%d",&a[i]);
	} 
	printf("��ѡ������Ҫ������1Ϊ��������2Ϊ�鲢����3Ϊ��������4Ϊ��������5Ϊ������������:\n"); 
	scanf("%d",&z);
	printf("���������£�\n"); 
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
} 

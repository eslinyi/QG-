#include<stdio.h>
#include<stdlib.h>
//������ջ (��ʽ�ṹ)
typedef struct Stack{
	int date;
	struct Stack *next;
}Stack,*LinkStackPtr;
//��ʼ����ջ
void initStack(Stack *Lstack) {
	Lstack->next=NULL;
}
//�ж�ջ�Ƿ�Ϊ�� 
int isEmptyStack(Stack *Lstack){
	if(Lstack->next==NULL)
		return 1;
	else
		return 0;
}
//�õ�ջ��Ԫ��
int getTopStack(Stack *Lstack){
	return Lstack->date;
} 
//���ջ
void clearStack(Stack *Lstack){
	Stack *topNode=Lstack->next;
	while(topNode!=NULL){
		Stack *temp=topNode->next;
		free(topNode);
		topNode=temp;
	}
	Lstack->next=NULL;
} 
//����ջ
void destoryStack(Stack *Lstack){
	free(Lstack);
} 
//���ջ�Ĵ�С
int stackLength(Stack *Lstack){
	Stack *topNode=Lstack->next;
	int len=0;
	while(topNode!=NULL){
		len++;
		topNode=topNode->next;
	return len;
	} 
} 
//��ջ
void pushStack(Stack *Lstack,int stnum){
	Stack *newNode=(Stack*)malloc(sizeof(Stack));
	newNode->date=stnum;
	newNode->next=Lstack->next;
	Lstack->next=newNode;
} 
//��ջ
void popStack(Stack *Lstack){
	Stack *topNode=Lstack->next;
	Lstack->next=topNode->next;
	free(topNode);
} 
//��ӡջ�е�����
void printStack(Stack *Lstack,int Stacknum){
	Stack *topNode=Lstack->next;
	int i=Stacknum-1;
	while(topNode!=NULL){
		printf("[%d]->%d\n",i--,topNode->date);
		topNode=topNode->next; 
	}
} 



int main(){
	Stack *Lstack;
	int i,temp=0,Stacknum,z=1,p=1;
	Lstack=(Stack*)malloc(sizeof(Stack)); 
	initStack(Lstack);
	printf("����������Ҫ��ջԪ�صĸ�����\n");
	scanf("%d",&Stacknum);
	printf("�������������ջ��Ԫ�أ��س���һ��Ԫ�أ���\n");
	for(i=0;i<Stacknum;i++)
		{
			scanf("%d",&temp);
			pushStack(Lstack,temp);
		}
	printf("ջ�е�Ԫ�����£�\n") ;
	printStack(Lstack,Stacknum);
	for(z=1;z!=0;){
		if(Lstack->next!=NULL){
			printf("�Ƿ�Ҫ����ջ��Ԫ��%d���ǵĻ�����1����֮����0����\n",Lstack->next->date);
			scanf("%d",&z);
			if(z!=0){
				popStack(Lstack);
				printf("�����ɹ�!\n");
				Stacknum--;
				if(Stacknum!=0){
					printf("����Ԫ��Ϊ��\n");
				} 
				printStack(Lstack,Stacknum);
			}
			else{
				printf("�˳��ɹ���\n");
			}
		}
		else{
			printf("ջ������Ԫ�أ����������\n");
			break;
		}
	}
	destoryStack(Lstack); 
}

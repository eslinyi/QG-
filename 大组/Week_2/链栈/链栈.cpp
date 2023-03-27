#include<stdio.h>
#include<stdlib.h>
//定义链栈 (链式结构)
typedef struct Stack{
	int date;
	struct Stack *next;
}Stack,*LinkStackPtr;
//初始化链栈
void initStack(Stack *Lstack) {
	Lstack->next=NULL;
}
//判断栈是否为空 
int isEmptyStack(Stack *Lstack){
	if(Lstack->next==NULL)
		return 1;
	else
		return 0;
}
//得到栈顶元素
int getTopStack(Stack *Lstack){
	return Lstack->date;
} 
//清空栈
void clearStack(Stack *Lstack){
	Stack *topNode=Lstack->next;
	while(topNode!=NULL){
		Stack *temp=topNode->next;
		free(topNode);
		topNode=temp;
	}
	Lstack->next=NULL;
} 
//销毁栈
void destoryStack(Stack *Lstack){
	free(Lstack);
} 
//检测栈的大小
int stackLength(Stack *Lstack){
	Stack *topNode=Lstack->next;
	int len=0;
	while(topNode!=NULL){
		len++;
		topNode=topNode->next;
	return len;
	} 
} 
//入栈
void pushStack(Stack *Lstack,int stnum){
	Stack *newNode=(Stack*)malloc(sizeof(Stack));
	newNode->date=stnum;
	newNode->next=Lstack->next;
	Lstack->next=newNode;
} 
//出栈
void popStack(Stack *Lstack){
	Stack *topNode=Lstack->next;
	Lstack->next=topNode->next;
	free(topNode);
} 
//打印栈中的数据
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
	printf("请输入你想要入栈元素的个数：\n");
	scanf("%d",&Stacknum);
	printf("请逐个输入你入栈的元素（回车算一个元素）：\n");
	for(i=0;i<Stacknum;i++)
		{
			scanf("%d",&temp);
			pushStack(Lstack,temp);
		}
	printf("栈中的元素如下：\n") ;
	printStack(Lstack,Stacknum);
	for(z=1;z!=0;){
		if(Lstack->next!=NULL){
			printf("是否要弹出栈顶元素%d（是的话输入1，反之输入0）：\n",Lstack->next->date);
			scanf("%d",&z);
			if(z!=0){
				popStack(Lstack);
				printf("弹出成功!\n");
				Stacknum--;
				if(Stacknum!=0){
					printf("现有元素为：\n");
				} 
				printStack(Lstack,Stacknum);
			}
			else{
				printf("退出成功！\n");
			}
		}
		else{
			printf("栈中已无元素，程序结束！\n");
			break;
		}
	}
	destoryStack(Lstack); 
}

#include<stdio.h>
#include<stdlib.h>
typedef struct Lstack{
	int date;
	char symbol;
	struct Lstack *next;
}Lstack;
//初始化栈 
void initStack(Lstack *L) {
	L->next=NULL;
} 
//判断栈中元素的个数 
int stackLength(Lstack *L){
	Lstack *topNode=L->next;
	int len=0;
	while(topNode!=NULL){
		len++;
		topNode=topNode->next;
	return len;
	} 
} 
//入栈(符号)
void pushStack(Lstack *L,char a){
	Lstack *newNode=(Lstack*)malloc(sizeof(Lstack));
	newNode->symbol=a;
	newNode->next=L->next;
	L->next=newNode;
} 
//出栈
void popStack(Lstack *L,char *del){
	Lstack *topNode=L->next;
	*del=topNode->symbol;
	L->next=topNode->next;
	free(topNode);
} 
//转化数字
int transnum(char a){
	return a-'0';
}
//判断优先级
int judgepri(char a){
	if(a=='*'||a=='/')
		return 2;
	if(a=='+'||a=='-')
		return 1;
	if(a=='('||a==')')
		return 0;
} 
//检索链栈的符号
int checkLstacks(Lstack *L,char a)
{
	int t,i=0;
	char del;
	t=stackLength(L);
	if(a=='(')
		pushStack(L,a);
	else if(a==')'){
		for(popStack(L,&del);;){
			if(del!='('){
				printf("%c",del);
				popStack(L,&del);
			}
			else{
				break;
			}
		}
	}
	else if(t==0){
		pushStack(L,a);
	}
	else if(judgepri(a)>judgepri(L->next->symbol)){
		pushStack(L,a);
	}
	else{
		popStack(L,&del);
		printf("%c",del);
		checkLstacks(L,a);
	}
 } 
//把中缀表达式转化为后缀表达式 
char transLastexpression(Lstack *L,char *a){
	int i,t=0,len,p;
	char del;
	L=(Lstack*)malloc(sizeof(Lstack)); 
	initStack(L);
	for(i=0;a[i]!='\0';i++){
		if(a[i]<='9'&&a[i]>='0'){
			printf("%c",a[i]);
		}
		else{
			p=checkLstacks(L,a[i]);
		} 
	}
	len=stackLength(L);
	for(i=0;i<=len;i++){
		popStack(L,&del);
		printf("%c",del);
	}
}

int main(){
	char mide[100];
	printf("输入你所需要转化的中缀表达式：\n");
	gets(mide);
	Lstack *L;
	L=(Lstack*)malloc(sizeof(Lstack)); 
	initStack(L);
	printf("转化后的后缀表达式为：\n");
	transLastexpression(L,mide);
} 

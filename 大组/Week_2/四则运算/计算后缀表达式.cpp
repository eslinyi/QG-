#include<stdio.h>
#include<stdlib.h>
//定义栈
typedef struct Lstack{
	int date;
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
void pushStack(Lstack *L,int t){
	Lstack *newNode=(Lstack*)malloc(sizeof(Lstack));
	newNode->date=t;
	newNode->next=L->next;
	L->next=newNode;
} 
//出栈
void popStack(Lstack *L,int *del){
	Lstack *topNode=L->next;
	*del=topNode->date;
	L->next=topNode->next;
	free(topNode);
} 
//转化数字 
int transnum(char a){
	return a-'0';
}
//通过符号判断计算
int calsymbol(int x,int y,char s){
	if(s=='*')return x*y;
	else if(s=='-')return x-y;
	else if(s=='+')return x+y;
	else if(s=='/')return x/y;
} 
//计算后缀表达式
int calexpression(Lstack *L,char *last){
	int i,tran,outcome;
	int x1,y1,z1;
	for(i=0;last[i]!='\0';i++){
		if(last[i]<='9'&&last[i]>='0'){
			tran=transnum(last[i]);
			pushStack(L,tran);
		}
		else{
			popStack(L,&y1);
			popStack(L,&x1);
			z1=calsymbol(x1,y1,last[i]);
			pushStack(L,z1);
		}
	}
	popStack(L,&outcome);
	return outcome;
} 



int main(){
	char last[100];
	printf("请输入你需要计算的后缀表达式:\n");
	gets(last);
	int outcome;
	Lstack *L;
	L=(Lstack*)malloc(sizeof(Lstack));
	outcome=calexpression(L,last);
	printf("您的结果为%d",outcome);
} 

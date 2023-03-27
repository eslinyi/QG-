#include<stdio.h>
#include<stdlib.h>
//����ջ
typedef struct Lstack{
	int date;
	struct Lstack *next;
}Lstack; 
//��ʼ��ջ 
void initStack(Lstack *L) {
	L->next=NULL;
} 
//�ж�ջ��Ԫ�صĸ��� 
int stackLength(Lstack *L){
	Lstack *topNode=L->next;
	int len=0;
	while(topNode!=NULL){
		len++;
		topNode=topNode->next;
	return len;
	} 
}
//��ջ(����)
void pushStack(Lstack *L,int t){
	Lstack *newNode=(Lstack*)malloc(sizeof(Lstack));
	newNode->date=t;
	newNode->next=L->next;
	L->next=newNode;
} 
//��ջ
void popStack(Lstack *L,int *del){
	Lstack *topNode=L->next;
	*del=topNode->date;
	L->next=topNode->next;
	free(topNode);
} 
//ת������ 
int transnum(char a){
	return a-'0';
}
//ͨ�������жϼ���
int calsymbol(int x,int y,char s){
	if(s=='*')return x*y;
	else if(s=='-')return x-y;
	else if(s=='+')return x+y;
	else if(s=='/')return x/y;
} 
//�����׺���ʽ
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
	printf("����������Ҫ����ĺ�׺���ʽ:\n");
	gets(last);
	int outcome;
	Lstack *L;
	L=(Lstack*)malloc(sizeof(Lstack));
	outcome=calexpression(L,last);
	printf("���Ľ��Ϊ%d",outcome);
} 

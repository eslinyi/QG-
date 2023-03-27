#include<stdio.h>
#include<stdlib.h>
typedef struct Lstack{
	int date;
	char symbol;
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
void pushStack(Lstack *L,char a){
	Lstack *newNode=(Lstack*)malloc(sizeof(Lstack));
	newNode->symbol=a;
	newNode->next=L->next;
	L->next=newNode;
} 
//��ջ
void popStack(Lstack *L,char *del){
	Lstack *topNode=L->next;
	*del=topNode->symbol;
	L->next=topNode->next;
	free(topNode);
} 
//ת������
int transnum(char a){
	return a-'0';
}
//�ж����ȼ�
int judgepri(char a){
	if(a=='*'||a=='/')
		return 2;
	if(a=='+'||a=='-')
		return 1;
	if(a=='('||a==')')
		return 0;
} 
//������ջ�ķ���
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
//����׺���ʽת��Ϊ��׺���ʽ 
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
	printf("����������Ҫת������׺���ʽ��\n");
	gets(mide);
	Lstack *L;
	L=(Lstack*)malloc(sizeof(Lstack)); 
	initStack(L);
	printf("ת����ĺ�׺���ʽΪ��\n");
	transLastexpression(L,mide);
} 

#include<stdio.h>
#include<stdlib.h>

typedef struct LNode
{
	int date;
	struct LNode* next1;
	struct LNode* next2;
 }LNode;


int main()
{
	LNode *p1,*p2;
	LNode *AddDoubleLNode();
    p1=AddDoubleLNode();
	for(;p1!=NULL;p1=p1->next1)
		{
			printf("%d ",p1->date);
			if(p1->next1==NULL)
				p2=p1;
		}
	printf("\n");
	for(;p2!=NULL;p2=p2->next2)
		{
			printf("%d ",p2->date);
		}
	
 } 
 
 LNode *AddDoubleLNode()
 {
 	FILE *fp;
 	LNode *p1,*p2,*head;
 	p1=(LNode*)malloc(sizeof(LNode));
 	head=p1;
 	fp=fopen("Á´±íÊý¾Ý.txt","r");
 	while(fscanf(fp,"%d",&p1->date)!=EOF)
		{
			p2=(LNode*)malloc(sizeof(LNode));
			p1->next1=p2;
			p1=p1->next1;
		 } 
	p1->date=11;
	p1->next1=NULL;
	head->next2=NULL;
	for(p1=head;p1->next1!=NULL;p1=p1->next1)
		{
			p1->next1->next2=p1;
		}
	fclose(fp);
	return head;
 }
 

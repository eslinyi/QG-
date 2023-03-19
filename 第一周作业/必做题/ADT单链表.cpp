#include<stdio.h>
#include<stdlib.h>

typedef struct LNode
{
	int date;
	struct LNode* next;
 }LNode;


int main()
{
	LNode *p1;
	LNode *AddLNode();
    p1=AddLNode();
	for(;p1!=NULL;p1=p1->next)
		{
			printf("%d ",p1->date);
		}
	
 } 
 
 LNode *AddLNode()
 {
 	FILE *fp;
 	LNode *p1,*p2,*head;
 	p1=(LNode*)malloc(sizeof(LNode));
 	head=p1;
 	fp=fopen("Á´±íÊý¾Ý.txt","r");
 	while(fscanf(fp,"%d ",&p1->date)!=EOF)
		{
			p2=(LNode*)malloc(sizeof(LNode));
			p1->next=p2;
			p1=p1->next;
		 } 
	p1->date=999;
	p1->next=NULL;
	fclose(fp);
	return head;
 }
 

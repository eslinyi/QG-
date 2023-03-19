#include<stdio.h>
#include<stdlib.h>

typedef struct LNode
{
	int date;
	struct LNode* next;
 }LNode;


int main()
{
	LNode *p1,*p2,*head;
	LNode *AddLNode();
	LNode *recLNode(LNode *p);
    p1=AddLNode();
    head=p1;
	for(;p1!=NULL;p1=p1->next)
		{
			printf("%d ",p1->date);
		}
		printf("\n");
	p2=recLNode(head);
	for(;p2!=NULL;p2=p2->next)
		{
			printf("%d ",p2->date);
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
 
 LNode *recLNode(LNode *p)
 {
	if(p==NULL||p->next==NULL)
	{
		return p;
	}
	else
	{
		LNode *p1= recLNode(p->next);
		p->next->next=p;
		p->next=NULL;
		return p1;
	}	
}
 

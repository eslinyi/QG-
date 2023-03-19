#include<stdio.h>
#include<stdlib.h>

typedef struct LNode
{
	int date;
	struct LNode* next;
 }LNode;


int main()
{
	LNode *p1,*head;
	LNode *AddLNode();
	LNode *OEtranLNode(LNode * head) ;
    p1=AddLNode();
    head=p1;
	for(;p1!=NULL;p1=p1->next)
		{
			printf("%d ",p1->date);
		}
	printf("\n");
	p1=OEtranLNode(head);
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
 
LNode *OEtranLNode(LNode * head) 
 {
 	LNode *p1,*p2,*p3,*tran;
 	int i;
 	p1=p2=p3=head; 
 	for(p1=p1->next,i=0;p1!=NULL;p1=p1->next,i++)
 		{
 			if(i==0)
 				head=p1;
 			if(i%2==0)
 				{
 					p3->next=p1;
 					p2->next=p1->next;
 					p1->next=p2;
 		    		p1=p2;
		 		 }
		 	else
		 		{
		 			p3=p2;
		 			p2=p2->next;continue;
				 }
		 }
	return head;
 }

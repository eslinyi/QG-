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
	LNode *FingmidLNode(LNode *head);
    p1=AddLNode();
    head=p1;
	for(;p1!=NULL;p1=p1->next)
		{
			printf("%d ",p1->date);
		}
	printf("\n");
	p1=FingmidLNode(head);
	printf("%d",p1->date);
	
 } 
 
 LNode *AddLNode()
 {
 	FILE *fp;
 	LNode *p1,*p2,*head;
 	p1=(LNode*)malloc(sizeof(LNode));
 	head=p1;
 	fp=fopen("链表数据.txt","r");
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
 
 LNode *FingmidLNode(LNode *head)
 {
 	LNode *p1,*p2,*p3;
 	for(p1=p2=head;p1!=NULL;)
 	{
 		if(p1->next==NULL)
 			{
 				break;
			 }
 		if(p1->next->next!=NULL)
 			{
 				p1=p1->next->next;
 				p2=p2->next;
			 }
		else
			{
				printf("该链表的中点有两个，这个结点与下一个节点\n"); 
				break;
			}
	 }
	 return p2;
  } 

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
	LNode *AddCLNode();
	int judgeCLNode(LNode *head);
	p1=AddCLNode();
	head=p1;
	for(p1=p1->next;p1!=head;p1=p1->next)
		{
			printf("%d ",p1->date);
		}
	printf("%d\n",p1->date);
	judgeCLNode(head); 
 } 
 
 LNode *AddCLNode()
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
	p1->next=head;
	fclose(fp);
	return head;
 }
 
int judgeCLNode(LNode *head)
 {
 	LNode *p1;
 	p1=head;
 	for(p1=p1->next;p1!=NULL;p1=p1->next)
 		{
		 	if(p1==head)
		 		{
		 			printf("该链表为循环链表"); return 0;
				 }
			if(p1==NULL)
				{
					printf("该链表不是循环链表"); return 0;
				 } 
		 }
 }

#include<stdio.h>
#include<stdlib.h>
typedef struct Lqueue {
    void *p;
    int j;
    struct Lqueue *next;
} Lqueue;
typedef struct Queueu {
    Lqueue *head;
    Lqueue *tail;
} Queue;
void initQueue(Queue *Q) {
    Q->head=Q->tail=NULL;
}
void destroyQueue(Queue *Q) {
    Lqueue *p=Q->head;
    while(p!=NULL) {
        Lqueue *pnext;
        pnext=p->next;
        free(p);
        p=pnext;
    }
    Q->head=Q->tail=NULL;
}
void pushQueue(Queue *Q,void *p1,int j1) {
    Lqueue *newNode;
    newNode=(Lqueue*)malloc(sizeof(Lqueue));
    newNode->next=NULL;
    newNode->j=j1;
    newNode->p=p1;
    if(Q->tail==NULL){
        Q->head=Q->tail=newNode;
    }
    else{
        Q->tail->next = newNode;
        Q->tail = newNode;
    }
}
void printfqueue(Queue *Q){
    Lqueue *p1;
    p1=Q->head;
    int i=0;
    if(p1!=NULL){
        printf("此时的队列情况为：\n");
    }
    else{
        printf("此时队列无数据\n");
    }
    while(p1!=NULL){
        if(p1->j==0){
        	printf("[%d]->%d\n",i++,*(int*)p1->p);
        	p1=p1->next;continue;
		}
		else if(p1->j==1){
			printf("[%d]->%c\n",i++,*(char*)p1->p);
        	p1=p1->next;continue;
		}
		else if(p1->j==2){
			printf("[%d]->%s\n",i++,(char*)p1->p);
        	p1=p1->next;continue;
		}
		else if(p1->j==3){
        	printf("[%d]->%f\n",i++,*(float*)p1->p);
        	p1=p1->next;continue;
		}
    } 
}
int popqueue(Queue *Q){
    Lqueue *p;
    p=Q->head;
    if(p==NULL)return 0;
    else if(p->next==NULL){
        Q->head=Q->tail=NULL;
        return 1;
    }
    else{
        p=p->next;
        free(Q->head);
        Q->head=p;
        return 2;
    }
}
int main(){
    Queue *Q;
    int z,i,j,p;
    int i1=0,i2=0,i3=0,i4=0;
    char str[10][100];
    char chardate[100];
    int intdate[100];
    float flodate[100];
    Q=(Queue *)malloc(sizeof(Queue));
    Q->head=(Lqueue*)malloc(sizeof(Lqueue));
    Q->tail=(Lqueue*)malloc(sizeof(Lqueue));
    initQueue(Q);
    for(z=1;z!=0;){
       printf("是否输入数据(0为no/1为yes)\n");
       scanf("%d",&z);
        if(z!=0){
        	printf("输入你想存储数据的类型:(int为0，char为1，str为2，float为3)\n");
        	scanf("%d",&j);
        	getchar(); 
            printf("输入你想存入的数据\n");
            if(j==0){
            	scanf("%d",&intdate[i1]);
         
            	pushQueue(Q,&intdate[i1++],j);
			}
			else if(j==1){
				scanf("%c",&chardate[i2]);
				pushQueue(Q,&chardate[i2++],j);
			}
			else if(j==2){
				scanf("%s",str[i4]);
				pushQueue(Q,str[i4++],j);
			}
			else{
				scanf("%f",&flodate[i3]);
				pushQueue(Q,&flodate[i3++],j);
			}
        }
        else{
            printf("输入数据完毕\n");
        }
    }
    printfqueue(Q);
    for(p=1;p!=0;){
        printf("是否弹出队列第一位（0为no/1为yes）\n");
        scanf("%d",&p);
        if(p!=0){
            i=popqueue(Q);
            if(i==2){
                printf("弹出成功\n");
                printfqueue(Q);
            }
            else if(i==1){
                printf("弹出成功\n");
                printfqueue(Q);
                break;
            }
            else{
                printf("弹出失败\n");
                printfqueue(Q);
                break;
            }
        }
    }
    
}

#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int date;
	struct Node *left;
	struct Node *right;
}Node;
//创造树 
Node *Creat_tree(int t){
	Node *p;
	p=(Node*)malloc(sizeof(Node));
	p->date=t;
	p->left=NULL;
	p->right=NULL;
	return p;
}
//向数树插入元素
Node *Insert_tree(Node *p,int t){
	if(p==NULL){
        p=Creat_tree(t);
        return p;
    }
    else if(t<p->date){
        p->left=Insert_tree(p->left, t);
    }
    else if(t>p->date){
        p->right=Insert_tree(p->right, t);
    }
    return p;
}
//先序遍历（非递归）
void Preorder(Node *p,int num){
	Node *stack[num];
	Node *p0;
	int k=-1;
	if(p==NULL){
		return;
	}
	else{
		k++;
		stack[k]=p;
		while(k>-1){
			p0=stack[k--];
			printf("%d ",p0->date);
			if(p0->right!=NULL){
				stack[++k]=p0->right;
			}
			else if(p0->left!=NULL){
				stack[++k]=p0->left;
			}
		}
	}
} 
//中序遍历（非递归）
void Midorder(Node *p,int num){
	Node *stack[num];
	Node *p0;
	int k=0;
	if(p==NULL){
		return;
	}
	else{
		p0=p;
		while(p0!=NULL||k>0){
			while(p0!=NULL){
				stack[++k]=p0;
				p0=p0->left;
			}
			p0=stack[k--];
			printf("%d ",p0->date);
			p0=p0->right;
		}
		
	}
} 
//后序便利（非递归） 
void Afterorder(Node *p,int num){
	Node *stack[num];
	Node *p0,*p1;
	int k=0;
	p1=NULL;
	if(p==NULL){
		return;
	}
	else{
		p0=p;
		while(p0!=NULL||k>0){
			while(p0!=NULL){
				stack[k++]=p0;
				p0=p0->left;
			}
			p0=stack[k-1];
			if(p0->right==NULL||p1==p0->right){
				printf("%d ",p0->date);
				k--;
				p1=p0;
				p0=NULL;
			}
			else{
				p0=p0->right;
			}
		}
	}
}
//层次遍历 
void HTorder(Node *p,int num){
	Node *stack[num];
	Node *p0=p;
	int i,g;
	i=0;g=0;
	if(p==NULL){
		return;
	} 
	else{
		stack[g++]=p0;
		while(g!=i){
			p0=stack[i++];
			printf("%d ",p0->date);
			if(p0->left!=NULL){
				stack[g++]=p0->left;
			}
			if(p0->right!=NULL){
				stack[g++]=p0->right;
			}
		}
	}
}
 
int main(){
	int i,z=1,t,j,num,h;
	Node *p,*f;
	printf("请输入你想要输入元素的个数:\n");
	scanf("%d",&num);
	printf("输入你想要添加进去的元素(逐个)：\n");
	for(h=0;h<num;h++){
		scanf("%d",&i);
		p=Insert_tree(p,i);
	}
	printf("请选择你要进行的遍历方式(0为前序/1为中序/2为后序/3为层次)：\n");
	scanf("%d",&t);
	if(t==0){
		Preorder(p,num);
	}
	else if(t==1){
		Midorder(p,num);
	}
	else if(t==2){
		Afterorder(p,num);
	}
	else if(t==3){
		HTorder(p,num);
	}
}

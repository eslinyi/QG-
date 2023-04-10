#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int date;
	struct Node *left;
	struct Node *right;
}Node;
Node *root=NULL;
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
//先序遍历（递归）
void Preorder(Node *p){
	if (p==NULL)
	{
		return;
	}
	printf("%d ",p->date);
	Preorder(p->left);
	Preorder(p->right);
} 
//中序遍历（递归）
void Midorder(Node *p){
	if (p==NULL)
	{
		return;
	}
	Midorder(p->left);
	printf("%d ",p->date);
	Midorder(p->right);
} 
//后序便利（递归）
void Afterorder(Node *p){
	if (p==NULL)
	{
		return;
	}
	Afterorder(p->left);
	Afterorder(p->right);
	printf("%d ",p->date);	
} 
//查找
Node *Find_tree(Node *p,int t){
	if(p==NULL){
		return NULL;
	}
	else if(p->date==t){
		return p;
	}
	else if(p->date<t){
		return Find_tree(p->right,t);
	}
	else{
		return Find_tree(p->left,t);
	}
}
//删除
Node *Find_frontnode(Node *root,Node *p,int t){
	if(p==NULL||p==root){
		return p;
	}
	else{
		if(root->left!=NULL&&root->left->date==t){
			return root;
		}
		else if(root->right!=NULL&&root->right->date==t){
			return root;
		}
		else if(root->date>t){
			return Find_frontnode(root->left,p,t);
		}
		else{
			return Find_frontnode(root->right,p,t);
		}
	}
}
Node *Del_tree(Node *p,int t){
	Node *p1,*p2;
	if(p->left==NULL&&p->right==NULL){
		p1=Find_frontnode(root,p,t);
		if(p1->left->date){
			p1->left=NULL;
		}
		else{
			p1->right=NULL;
		}
	}
	else if(p->left==NULL){
		p1=p->right;
		p->date=p1->date;
		p->right = p1->right;
   		p->left = p1->left;
   		free(p1);
	}
	else if(p->right==NULL){
		p1=p->left;
		p->date=p1->date;
		p->right=p1->right;
		p->left=p1->left;
		free(p1);
		 
	}
	else{
		p1=p;
        p2=p->right; 
        while(p2->left!=NULL){
            p1=p2;
            p2=p2->left;
        }
        p->date=p2->date;
        if(p1!=p) 
            p1->left=p2->right;
        else
            p1->right=p2->right;
        free(p2);
	}
}

 
 
int main(){
	int i,z=1,t,j,num,h;
	Node *f;
	printf("请输入你想要输入元素的个数:\n");
	scanf("%d",&num);
	printf("输入你想要添加进去的元素(逐个)：\n");
	for(h=0;h<num;h++){
		scanf("%d",&i);
		root=Insert_tree(root,i);
	}
	printf("请选择你要进行的遍历方式(0为前序/1为中序/2为后序)：\n");
	scanf("%d",&t);
	if(t==0){
		Preorder(root);
	}
	else if(t==1){
		Midorder(root);
	}
	else if(t==2){
		Afterorder(root);
	}
	printf("\n");
	printf("请输入你要查找的数：\n");
	scanf("%d",&j);
	f=Find_tree(root,j);
	if(f==NULL){
		printf("树中无此数据\n");
	}
	else{
		printf("树中有该数据\n");
	}
	printf("请输入你要删除的数据：\n");
	scanf("%d",&i);
	f=Find_tree(root,i);
	Del_tree(f,i);
	printf("现在树中的元素为（前序）：\n");
	Preorder(root);
}

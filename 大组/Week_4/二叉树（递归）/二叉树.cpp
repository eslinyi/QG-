#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int date;
	struct Node *left;
	struct Node *right;
}Node;
Node *root=NULL;
//������ 
Node *Creat_tree(int t){
	Node *p;
	p=(Node*)malloc(sizeof(Node));
	p->date=t;
	p->left=NULL;
	p->right=NULL;
	return p;
}
//����������Ԫ��
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
//����������ݹ飩
void Preorder(Node *p){
	if (p==NULL)
	{
		return;
	}
	printf("%d ",p->date);
	Preorder(p->left);
	Preorder(p->right);
} 
//����������ݹ飩
void Midorder(Node *p){
	if (p==NULL)
	{
		return;
	}
	Midorder(p->left);
	printf("%d ",p->date);
	Midorder(p->right);
} 
//����������ݹ飩
void Afterorder(Node *p){
	if (p==NULL)
	{
		return;
	}
	Afterorder(p->left);
	Afterorder(p->right);
	printf("%d ",p->date);	
} 
//����
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
//ɾ��
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
	printf("����������Ҫ����Ԫ�صĸ���:\n");
	scanf("%d",&num);
	printf("��������Ҫ��ӽ�ȥ��Ԫ��(���)��\n");
	for(h=0;h<num;h++){
		scanf("%d",&i);
		root=Insert_tree(root,i);
	}
	printf("��ѡ����Ҫ���еı�����ʽ(0Ϊǰ��/1Ϊ����/2Ϊ����)��\n");
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
	printf("��������Ҫ���ҵ�����\n");
	scanf("%d",&j);
	f=Find_tree(root,j);
	if(f==NULL){
		printf("�����޴�����\n");
	}
	else{
		printf("�����и�����\n");
	}
	printf("��������Ҫɾ�������ݣ�\n");
	scanf("%d",&i);
	f=Find_tree(root,i);
	Del_tree(f,i);
	printf("�������е�Ԫ��Ϊ��ǰ�򣩣�\n");
	Preorder(root);
}

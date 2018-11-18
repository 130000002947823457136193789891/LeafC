#include<iostream.h>
#include<stdlib.h>
#include<stdio.h>
typedef char typedata;
typedef class BinTNode{
public:
	class BinTNode *lchild,*rchild;
	typedata data;
}BinTNode,*BiTree;


void PreCreateTree(BiTree *bt){
	typedata ch;
	cin>>ch;

	if(ch!='#')
	{
		if(ch!='@')
		{
			*bt=(BiTree)malloc(sizeof(BinTNode));
			(*bt)->data =ch;
			PreCreateTree(&(*bt)->lchild);
			PreCreateTree(&(*bt)->rchild );
		}
		else 
			*bt =NULL;
	}


}
void preorder(BiTree bt)
{
	if(bt)
	{
		cout<<bt->data <<"  ";
		preorder(bt->lchild );
		preorder(bt->rchild );
	}
}
 int a=0;
 int count=0;
int Leaf(BiTree bt)
{
	if(bt){
		if(bt->lchild ==NULL && bt->rchild ==NULL)
		{
			count =count+1;
		}
		else
		{
			Leaf(bt->lchild );
			Leaf(bt->rchild );
		}
	}
	return count;
}

void inorder(BiTree bt)
{
	if(bt)
	{
		inorder(bt->lchild );
		cout<<bt->data <<"  ";
		inorder(bt->rchild );
	}
}

void postorder(BiTree bt)
{
	if(bt )
	{
		postorder(bt->lchild );
		postorder(bt->rchild );
		cout<<bt->data <<"  ";
	}
}

int depth(BiTree bt)
{
	if(bt){
		if(depth(bt->lchild )>depth(bt->rchild ))
			return depth(bt->lchild )+1;
		else
			return depth(bt->rchild )+1;
		depth(bt->lchild );
		depth(bt->rchild );
	}
	else
		return 0;

}

int main()
{

	BiTree bt;
	PreCreateTree(&bt);
	cout<<endl;

	cout<<"叶子节点有：";
	cout<<Leaf(bt)<<"个。";
	cout<<endl;

	cout<<"depth:"<<depth(bt)<<endl;
/*
	cout<<"preorder:";
	preorder(bt);
	cout<<endl;

	cout<<"inorder:";
	inorder(bt);
	cout<<endl;

	cout<<"postorder:";
	postorder(bt);
	cout<<endl;
*/
	return 0;
}
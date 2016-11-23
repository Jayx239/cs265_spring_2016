#include <iostream>
using namespace std;

struct TNode
{
	int data;
	TNode *left_link;
	TNode *right_link;
};

TNode *create(int m)
{
	TNode *newp=new TNode;
	newp->data=m;
	newp->left_link=NULL;
	newp->right_link=NULL;
	return newp;
}

TNode *insert(TNode *treep,TNode *newp)
{
	if(treep==NULL)
		return newp;
	if(newp->data == treep->data)
		cout << "Number " << newp->data << " is already included."<<endl; 
	else if(newp->data < treep->data)
		treep->left_link=insert(treep->left_link,newp);
	else
		treep->right_link=insert(treep->right_link,newp);
	return treep;
}

void preorder(TNode *treep)
{
	if(treep!=NULL)
	{
		cout << treep->data << " ";
		preorder(treep->left_link);
		preorder(treep->right_link);
	}
}

void inorder(TNode *treep)
{
	if(treep!=NULL)
	{
		inorder(treep->left_link);
		cout << treep->data << " ";
		inorder(treep->right_link);
	}
}

void postorder(TNode *treep)
{
	if(treep!=NULL)
	{
		postorder(treep->left_link);
		postorder(treep->right_link);
		cout << treep->data << " ";
	}
}

void delete_nodes(TNode *treep)
{
	if(treep!=NULL)
	{
		delete_nodes(treep->left_link);
		if(treep->left_link!=NULL)
		{
			delete treep->left_link;
			treep->left_link=NULL;
		}
		delete_nodes(treep->right_link);
		if(treep->right_link!=NULL)
		{
			delete treep->right_link;
			treep->right_link=NULL;
		}
	}
}

void delete_tree(TNode*& root)
{
	TNode *treep=root;
	delete_nodes(root);
	delete(treep);
	root=NULL;

}

int count_nodes(TNode *treep)
{	
	if(treep!=NULL)
	{
		int l,r;
		l=count_nodes(treep->left_link);
		r=count_nodes(treep->right_link);
		return l+r+1;
	}
	else
		return 0;
}

int compute_depth(TNode *treep)
{
	if(treep!=NULL)
	{
		int l,r,max;
		l=compute_depth(treep->left_link);
		r=compute_depth(treep->right_link);
		if(l>r)
			max=l;
		else
			max=r;
		return max+1;
	}
	else
		return -1;
}

void trace_depth(TNode *treep, int& d)
{
	if(treep!=NULL)
	{
		cout << "data field " << treep->data;
		cout << ", depth " << d << endl;
		d++;
		trace_depth(treep->left_link,d);
		trace_depth(treep->right_link,d);
		d--;
	}
}

int main()
{

	TNode *root=NULL;
	TNode *newp;

	root=create(8);
	
	newp=create(4);
	insert(root,newp);
	newp=create(12);
	insert(root,newp);
	newp=create(2);
	insert(root,newp);
	newp=create(6);
	insert(root,newp);
	newp=create(10);
	insert(root,newp);
	newp=create(14);
	insert(root,newp);
	newp=create(1);
	insert(root,newp);
	newp=create(3);
	insert(root,newp);
	newp=create(5);
	insert(root,newp);
	newp=create(7);
	insert(root,newp);
	newp=create(9);
	insert(root,newp);
	newp=create(11);
	insert(root,newp);
	newp=create(13);
	insert(root,newp);
	newp=create(15);
	insert(root,newp);

	cout << "Pre-order traversal:" << endl;
	preorder(root);
	cout << endl;
	cout << endl;

	cout << "In-order traversal:" << endl;
	inorder(root);
	cout << endl;
	cout << endl;

	cout << "Post-order traversal:" << endl;
	postorder(root);
	cout << endl;
	cout << endl;

	cout << "Number of nodes: ";
	cout <<	count_nodes(root) << endl;
	cout << endl;

	cout << "Depth: ";
	cout << compute_depth(root) << endl;
	cout << endl;

	cout << "Pre-order traversal with depth tracing:" << endl;
	int d=0;
	trace_depth(root,d);

	delete_tree(root);

	return 0;
}


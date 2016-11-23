#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;

struct TNode
{
	int data;
	TNode *left_link;
	TNode *right_link;
};

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

TNode* create_node(int m)
{
	TNode *newp=new TNode;
	newp->data=m;
	newp->left_link=NULL;
	newp->right_link=NULL;
	return newp;
}

TNode* insert_new_delete_repeated(TNode* treep,TNode* newp, int& num_deleted)
{
	if(treep==NULL)
		return newp;
	if(newp->data == treep->data)
	{
		num_deleted++;
		delete newp;
	}
	else if(newp->data < treep->data)
		treep->left_link=insert_new_delete_repeated(treep->left_link,newp,num_deleted);
	else
		treep->right_link=insert_new_delete_repeated(treep->right_link,newp,num_deleted);
	return treep;
}

int create_random_tree(TNode*& treep, int n)
{
	srand((unsigned)time(NULL));
	treep=create_node(rand()%n);
	TNode* newp;
	int num_deleted=0;
	
	for(int i=0;i<n-1;i++)
	{
		newp=create_node(rand()%n);
		insert_new_delete_repeated(treep,newp,num_deleted);
	}
	return num_deleted;
}

TNode* lookup(TNode* treep, int m)
{
	while(treep!=NULL)
	{
		if(m==treep->data)
			return treep;
		else if (m<treep->data)
			treep=treep->left_link;
		else
			treep=treep->right_link;
	}
	return NULL;
}

int main()
{

	int n;
	cout << "Enter the size of the range of random numbers: ";
	cin >> n;
	cout << endl;

	TNode* root=NULL;
	int num_deleted;

	num_deleted=create_random_tree(root,n);

	cout << "Number of nodes inside the tree: ";
	int num_inserted=count_nodes(root);
	cout << num_inserted << endl;
	cout << endl;
	
	delete_tree(root);

	return 0;
}



	#include <iostream>
	#include <stdio.h>
	#include <math.h>
	#include <ctime>
	#include <algorithm>

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

void count_nodes(TNode* treep, int &count)
{

	if(treep!=NULL)
	{
		count_nodes(treep->left_link,count);
		count_nodes(treep->right_link,count);
		cout << treep->data << " ";
		count++;
	}
}

int main(int argc, char** argv)
{
	int userInput;
	bool is_first_run = true;
	cout << "Enter the value for the next node, (0 to end): ";
	cin >> userInput;
	int len = 0;
	TNode* nodeHead = userInput != 0 ? create(userInput) : NULL;
	while(userInput != 0 && nodeHead != NULL)
	{
		len++;
		if(!is_first_run)
		{
			TNode* nextNode = create(userInput);
			nextNode = insert(nodeHead,nextNode);
		}
		cout << "Enter the value for the next node, (0 to end): ";
		cin >> userInput;
		is_first_run = false;
	}

	cout << "Post order: ";
	postorder(nodeHead);
	cout << endl;
	cout << "Pre order: ";
	preorder(nodeHead);
	cout << endl;
	cout << "In order: ";
	inorder(nodeHead);
	cout << endl;

	cout << "Number of nodes inside the tree: ";
	int num_inserted=count_nodes(nodeHead);
	cout << num_inserted << endl;
	cout << endl;

	cout << "Depth: ";
	cout << compute_depth(nodeHead) << endl;
	cout << endl;

	TNode* ptr=NULL;
	int counter=0;
	clock_t start=clock();
	count_nodes(nodeHead,counter);
	/*for(int i=0;i<len;i++)
	{
		ptr=lookup(nodeHead,i);
		if(ptr!=NULL)
			counter++;
	}*/
	clock_t stop=clock();
	cout << "Total search time: ";
	cout << 1000*(stop-start) /CLOCKS_PER_SEC << endl;
	cout << endl;

	cout << "Number of successfully found nodes: ";
	cout << counter << endl;
	cout << endl;

	if(num_inserted==counter)
		cout << "All nodes of the random tree were found" << endl;
	else
		cout << "Searching failed!!!" << endl;

	return 0;
}

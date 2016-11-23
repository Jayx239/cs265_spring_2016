#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <math.h>
#include <time.h>
using namespace std;

struct TNode{
	int data;
	TNode* left;	// Lesser
	TNode* right;	// Greater
};

// Function to create a new tree node
TNode* create_node(int m)
{
	TNode *newp=new TNode;
	newp->data=m;
	newp->left=NULL;
	newp->right=NULL;
	return newp;
}
// Function to insert a tree node into the tree
TNode* insert_new_delete_repeated(TNode* &treep,TNode* &newp, int& num_deleted)
{
	if(treep==NULL)
		return newp;
	if(newp->data == treep->data)
	{
		num_deleted++;
		delete newp;
	}
	else if(newp->data < treep->data)
	{
		treep->left=insert_new_delete_repeated(treep->left,newp,num_deleted);
	}
	else
	{
		treep->right=insert_new_delete_repeated(treep->right,newp,num_deleted);
	}
	return treep;
}

// Function to create a random tree
int create_random_tree(TNode* &treep, int n)
{
	srand((unsigned)time(NULL));
	treep=create_node(rand()%n);

	int num_deleted=0;

	for(int i=0;i<n-1;i++)
	{
		int deleted = 0;
		TNode* newp = create_node(rand()%n);
		insert_new_delete_repeated(treep,newp, deleted);
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
			treep = lookup(treep->left,m);
		else
			treep = lookup(treep->right,m);
	}
	return NULL;
}

TNode* nrlookup(TNode* treep, int num)
{
	while(treep != NULL)
	{
		if(treep->data == num)
			return treep;
		else if(treep->data > num)
			treep = treep->left;
		else
			treep = treep->right;
	}
	return NULL;
}

int main(int argc, char** argv)
{
	// Create input files stream and open input file
	int size = atoi(argv[1]);

	int num_deleted = 0;
	TNode* first_node = create_node(rand()%size);
	TNode* tree = NULL;
	
	create_random_tree(tree,size);


	clock_t start,stop;
	int counter_1 = 0;
	TNode* temp_ptr = NULL;

	// Time how long it takes to lookup all tree nodes non-recursively
	start=clock();
	for(int i=0;i<size;i++)
	{
		temp_ptr=nrlookup(tree,i);
		if(temp_ptr!=NULL)
			if(temp_ptr->data==i)
				counter_1++;
	}
	stop=clock();
	
	//Print out elapsed time in miliseconds
	cout << "\nNon-recursive Lookup\n\tThe elapsed time: ";
	cout << 1000*(stop-start) /CLOCKS_PER_SEC << endl;
	cout << counter_1 << " nodes found" << endl;

	// Create temporary pointer for recursive tree loopup
	TNode* temp_ptr_2 = NULL;
	int counter_2 = 0;

	// Time how long it takes to search all tree nodes recursively
	start=clock();
	for(int i=0;i<size;i++)
	{
		temp_ptr=lookup(tree,i);
		if(temp_ptr!=NULL)
			if(temp_ptr->data==i)
				counter_2++;
	}
	stop=clock();

	//Print out elapsed time in miliseconds
	cout << "\nRecursive Lookup\n\tThe elapsed time: ";
	cout << 1000*(stop-start) /CLOCKS_PER_SEC << endl;
	cout << counter_2 << " nodes found" << endl;
	return 0;
}

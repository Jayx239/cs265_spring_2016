	#include <iostream>
	#include <stdio.h>
	#include <math.h>
	#include <ctime>
#include <algorithm>

using namespace std;

	struct TNode{
		int data;
		TNode* left;	// Lesser
		TNode* right;	// Greater
	};

	TNode* create_node(int m)
	{
		TNode *newp=new TNode;
		newp->data=m;
		newp->left=NULL;
		newp->right=NULL;
		return newp;
	}

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

	int create_random_tree(TNode*& treep, int n)
	{
		srand((unsigned)time(NULL));
		//treep=create_node(rand()%n);
	
		int num_deleted=0;
	
		for(int i=0;i<n-1;i++)
		{
			TNode* newp = create_node(rand()%n); //rand()%n
			insert_new_delete_repeated(treep,newp,num_deleted);
		}
		TNode* newp = create_node(8888);
		insert_new_delete_repeated(treep,newp,num_deleted);
		return num_deleted;
	}

	TNode* lookup(TNode* treep, int m)
	{
		TNode* temp;
		temp = *&treep;
		while(temp!=NULL)
		{
			if(m==treep->data)
				return treep;
			else if (m<treep->data)
				temp = lookup(temp->left,m);
			else
				temp = lookup(temp->right,m);
		}
		return NULL;
	}

	TNode* nrlookup(TNode* treep, int num)
	{
		while(treep != NULL)
		{
			if(treep->data == num)
				return treep;
			else if(treep->data < num)
				treep = treep->left;
			else
				treep = treep->right;
		}
		return NULL;
	}

	int main(int argc, char** argv)
	{
		int size = 2000000;
		TNode* tree = create_node(rand()%size);
		tree->left = NULL;
		tree->right = NULL;
		create_random_tree(tree,size);
	
	
		int start,stop;

		start=clock();
		lookup(tree,8888);
		stop=clock();
		//Print out elapsed time in miliseconds
		cout << "\nNon-recursive Lookup\n\tThe elapsed time: ";
		cout << 1000*(stop-start) /CLOCKS_PER_SEC << endl;
	
		start=clock();
		nrlookup(tree,8888);
		stop=clock();
		//Print out elapsed time in miliseconds
		cout << "\nRecursive Lookup\n\tThe elapsed time: ";
		cout << 1000*(stop-start) /CLOCKS_PER_SEC << endl;

		//cout << "Enter the size of the binary tree: ";
		//cin >> size;

		return 0;
	}


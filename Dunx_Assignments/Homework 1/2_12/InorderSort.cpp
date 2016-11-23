#include <iostream>
#include <stdio.h>
#include <math.h>
#include <ctime>
#include <string>
using namespace std;

// Tree node data structure
struct TNode {
	int data;
	TNode* left;	// Lesser
	TNode* right;	// Greater
};

// Function to create a new tree node
TNode* create_tree_node(int m)
{
	TNode *newp = new TNode;
	newp->data = m;
	newp->left = NULL;
	newp->right = NULL;
	return newp;
}
// Function to insert node into a tree
TNode* insert_new_delete_repeated(TNode* &treep, TNode* &newp, int& num_deleted)
{
	if (treep == NULL)
		return newp;
	if (newp->data == treep->data)
	{
		num_deleted++;
		delete newp;
	}
	else if (newp->data < treep->data)
	{
		treep->left = insert_new_delete_repeated(treep->left, newp, num_deleted);
	}
	else
	{
		treep->right = insert_new_delete_repeated(treep->right, newp, num_deleted);
	}
	return treep;
}

// Function to create a new random tree
int create_random_tree(TNode*& treep, int n)
{
	srand((unsigned)time(NULL));
	treep=create_tree_node(rand()%n);

	int num_deleted = 0;

	for (int i = 0;i<n - 1;i++)
	{
		TNode* newp = create_tree_node(rand() % n-i); //rand()%n
		insert_new_delete_repeated(treep, newp, num_deleted);
	}
	return num_deleted;
}

// List node data structure
struct LNode {
	int data;
	LNode* link;
};

// Default function for creating a new list node, no data value
LNode* create_list_node()
{
	LNode* node = new LNode;
	node->data = NULL;
	node->link = NULL;
	return node;

}

// Function to create a new list node with data value
LNode* create_list_node(int data)
{
	LNode* node = new LNode;
	node->data = data;
	node->link = NULL;
	return node;

}

void sortinorder(TNode* hNode,LNode* &out_list)
{
	LNode* orig_head = *&out_list;
	if (hNode == NULL)
		return;
	sortinorder(hNode->left, *&out_list);
	if (out_list->data == NULL)
		out_list->data = hNode->data;
	else
	{
		LNode* new_node = create_list_node(hNode->data);
		out_list->link = new_node;
		out_list = *&new_node;
	}
	sortinorder(hNode->right, *&out_list);
	
	out_list = orig_head;
}


// Test to verify linked list is sorted
bool test_is_inorder(LNode* list_head)
{
	if(list_head == NULL)
		return true;

	int previous_value = list_head->data;

	while (list_head != NULL)
	{

		if (list_head->data < previous_value)
			return false;
		list_head = list_head->link;
	}
	return true;
}

bool run_tests(LNode* list_head)
{
	bool tests_successful = true;
	LNode* temp_head = *&list_head;
	bool test_pass = test_is_inorder(temp_head);
	tests_successful = tests_successful && 
	cout << "ASSERT: Is in order - " << (test_pass ? "true" : "false") << endl;
	
	cout << "Tests " << (tests_successful ? "Pass" : "Fail") << endl;
	return tests_successful;
}

int main(int argc, char** argv)
{
	int size = atoi(argv[1]);
	clock_t start,stop;
	TNode* tree = create_tree_node(rand() % size);
	tree->left = NULL;
	tree->right = NULL;

	create_random_tree(tree, size);

	LNode* list_head = create_list_node();
	LNode* list_it = *&list_head;
	start = clock();
	sortinorder(tree, list_head);
	stop = clock();
	//Print out elapsed time in miliseconds
	cout << "\nInorder Sort: \n\tThe elapsed time: ";
	cout << 1000*(stop-start) /CLOCKS_PER_SEC << endl;
	
	run_tests(list_head);
	return 0;
}

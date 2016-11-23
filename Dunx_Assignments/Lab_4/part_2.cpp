#include <ctime>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
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

struct 	VNode
{
	int data;
	VNode* link;
};

VNode* create_v_node(int data_val)
{
	VNode* node = new VNode;
	node->data = data_val;
	node->link = NULL;
	return *&node;
}
void insert_head(VNode* &v_head, int data)
{
		VNode* new_node = create_v_node(data);
		v_head->link = *&new_node;
		v_head = *&new_node;
}

int main()
{

	VNode* v_head = create_v_node(0);
	int n;		// vector size
	cout << "Enter the vector size: ";
	cin >> n;
	
	vector<int> vector_input = vector<int>();

	for(int i=0; i<n; i++)
	{
		vector_input.push_back(i);
	}
	random_shuffle(vector_input.begin(),vector_input.end());
	
	/*for(int i=0; i<n; i++)
		cout << vector_input.at(i);
	cout << endl;
	*/

	TNode* root=NULL;
	int num_deleted = 0;
	for(int i=0; i<n; i++)
	{
		root = insert_new_delete_repeated(root,create_node(vector_input[i]),num_deleted);
	}
	//num_deleted=create_random_tree(root,n);

	cout << "Number of nodes inside the tree: ";
	int num_inserted=count_nodes(root);
	cout << num_inserted << endl;
	cout << endl;

	cout << "Depth: ";
	cout << compute_depth(root) << endl;
	cout << endl;

	TNode* ptr=NULL;
	int counter=0;
	clock_t start=clock();
	for(int i=0;i<n;i++)
	{
		ptr=lookup(root,i);
		if(ptr!=NULL)
			if(ptr->data==i)
				counter++;
	}
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

	delete_tree(root);
	return 0;
}


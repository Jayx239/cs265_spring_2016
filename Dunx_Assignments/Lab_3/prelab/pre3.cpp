#include <stdlib.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>

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

//Definition of types IntVector and IntVectorIt
typedef vector<int> IntVector;
typedef IntVector::iterator IntVectorIt;

bool is_sorted(IntVector&a,int s,int r)
{
	for(int i=s;i<r;i++)
		if(a[i]>a[i+1])
			return false;

	return true;
}

void stl_merge(IntVector& a,IntVector& b,int s,int m,int r)
{
	//Function stl_merge merges segments a[s..m] and a[m+1..r],
	//stores the result in b[s..r] and then copies the result 
	//back to a[s..r]
	IntVectorIt ita=a.begin();
	IntVectorIt itb=b.begin();
	merge(ita+s,ita+m+1,ita+m+1,ita+r+1,itb+s);
	for(int i=s;i<=r;i++)
		a[i]=b[i];

}

void mergesort(IntVector& a,IntVector& b,int s,int r)
{
	//Function mergesort is a recursive version of Merge-Sort
	//algorithm. We need vector b to store the results of merging
	//Both vectors a and b are passed by reference. The algorithm 
	//needs memory which is twice the size of the array to be sorted
	if(r<=s) return;
	int m=(r+s)/2;
	mergesort(a,b,s,m);
	mergesort(a,b,m+1,r);
	stl_merge(a,b,s,m,r);
}


void swap(int v[], int i, int j)
{
	int temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

int partition(vector<int> &v, int p, int q) {
    int x = v[p];
    int i = p;
    int j;

    for (j = p + 1; j < q; j++) {
        if (v[j] <= x) {
            i = i + 1;
            swap(v[i], v[j]);
        }

    }

    swap(v[i], v[p]);
    return i;
}

void quicksort(vector<int> &v, int p, int q) {
    int r;
    if (p < q) {
        r = partition(v, p, q);
        quicksort(v, p, r);
        quicksort(v, r + 1, q);
    }
}

int main(int argc, char** argv)
{
	
	int input;
	cout << "Enter a number for the vector size:";
	cin >> input;
	vector<int> Vector1 = vector<int>();
	vector<int> Vector2 = vector<int>();
	vector<int> Vector3 = vector<int>();
	vector<int> Vector4 = vector<int>();
	
	for(int i=0; i<input; i++)
	{
		Vector1.push_back(i);
	//	cout << Vector1.at(i);

	}

	random_shuffle(Vector1.begin(),Vector1.end());
	for(int i =0; i<input; i++)
	{
		Vector2.push_back(*&Vector1[i]);
		Vector3.push_back(*&Vector1[i]);
		Vector4.push_back(*&Vector1[i]);
	}
	
	//Start timing sorting procedure
	clock_t start=clock();
	sort(Vector1.begin(),Vector1.end());
	//Stop timing sorting procedure
	clock_t stop=clock();

	//Print out elapsed time in miliseconds
	cout << "STL Sorting\n\tThe elapsed time: ";
	cout << 1000*(stop-start) /CLOCKS_PER_SEC << endl;

	//Call function mergesort
	start=clock();
	mergesort( Vector2, Vector3,0,input-1);
	stop=clock();

	//Print out elapsed time in miliseconds
	cout << "\nMerge sort\n\tThe elapsed time: ";
	cout << 1000*(stop-start) /CLOCKS_PER_SEC << endl;
	

	//Perform merging of vectors 1 and 2 into vector 3
	start=clock();
	quicksort(Vector4,0,Vector4.size());
	stop=clock();
	//Print out elapsed time in miliseconds
	cout << "\nQuick sort\n\tThe elapsed time: ";
	cout << 1000*(stop-start) /CLOCKS_PER_SEC << endl;
	
	//cout << "Press any key to exit: ";
	//cin >> input;

		return 0;
}

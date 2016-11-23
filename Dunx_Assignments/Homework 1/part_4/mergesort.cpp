#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <ctime>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;

// Link node data structure
struct LNode 
{
	int data;
	LNode* link;
};

// Function to create new link node
LNode* create_node(int data)
{
	LNode* node = new LNode;
	node->data = data;
	node-> link = NULL;
	return node;
}

// Function to determine if input x is greater than input y
bool is_larger(int x, int y)
{
	return x > y;
}

// Add node to linked list
void add_node(LNode* &link_head, LNode* new_link)
{
	// If the link head is null, a new list is being created
	if(link_head == NULL)
	{
		link_head = create_node(new_link->data);
		return;
	}

	// Otherwise add node to linked list
	link_head->link = create_node(new_link->data);
	link_head = link_head->link;
}
void merge(LNode* link_head, int s, int m, int r)
{
	// Create temporary linked list nodes and iterators
	LNode* list_head_left = link_head;				// holds list 1, index: start to middle
	LNode* list_head_right = link_head;				// holds list 2, index: middle+1 to right
	LNode* list_head_merged = create_node(0);		// head node for merged list
	LNode* list_merged_iterator = list_head_merged;	// iterator for merged list
	LNode* list_head_s;								// list node that holds the starting index of the left list

	// Move left head to start index of linked list
	for(int i=0; i<s; i++)
	{
		list_head_left = list_head_left->link;
	}

	// Set input list iterator to start index
	list_head_s = *&list_head_left;

	// move right head to middle+1 index of linked list
	for(int i=0; i<m+1; i++)
		list_head_right = list_head_right->link;

	// Set index's of each list
	int left_index = s;
	int right_index = m;

	// boolean used for setting the head of the merged list when iterator is initialized
	bool list_head_merge_set = false;
	
	while(list_head_left != NULL && left_index < m+1 && list_head_right != NULL && right_index < r)
	{
		if(list_head_left->data <= list_head_right->data)
		{
			add_node(list_merged_iterator,list_head_left);
			list_head_left = list_head_left->link;
			left_index++;
		}
		else
		{
			add_node(list_merged_iterator,list_head_right);
			list_head_right = list_head_right->link;
			right_index++;
		}
		if(!list_head_merge_set)
		{
			list_head_merged = *&list_merged_iterator;
			list_head_merge_set = true;
		}
	}
	
	// If right list is merged first, fill the rest of the merged list with
	// the remaining left list values
	while(left_index < m+1)
	{
		add_node(list_merged_iterator, list_head_left);
		list_head_left = list_head_left->link;
		left_index++;
	}

	
	// If left list is merged first, fill the rest of the merged list with
	// the remaining right list values
	while(right_index < r)
	{
		add_node(list_merged_iterator,list_head_right);
		list_head_right = list_head_right->link;
		right_index++;
	}

	// Reset the merged list iterator to the head of the merged list
	list_merged_iterator = list_head_merged;

	// Insert merged list into the input list for the input range (start to right)
	for(int i=s; i<=r; i++)
	{
		list_head_s->data = list_merged_iterator->data;
		list_merged_iterator = list_merged_iterator->link;
		list_head_s = list_head_s->link;
	}
}

void mergesort(LNode* &vector,int size)
{
	for(int i = size-1; i>1; i--)
	{
		for(int j=size-1;j-i>=-1; j--)
			merge(vector,j-i,(int)(j-floor(i/2.0)),j);
	}
}

bool is_in_order(LNode* list_iterator, int size)
{
	for(int i=0; i<size-1; i++)
	{
		if(list_iterator->data > list_iterator->link->data)
			return false;
		list_iterator = list_iterator->link;
	}
	return true;
}

bool test(LNode* list_iterator, int size)
{
	// boolean indicating if any tests failed
	bool tests_successful = true;
	
	// Run order test and print result
	bool is_in_order_success = is_in_order(list_iterator,size);
	cout << "List is sorted test: " << (is_in_order_success? "Pass\n" : "Fail\n");
	
	// Update test suite success
	tests_successful = tests_successful && is_in_order_success;

	return tests_successful;
}

int main(int argc, char** argv)
{
	// Create input files stream and open input file
	ifstream file(argv[1]);

	// Create base node and iterator
	LNode* node_head = NULL;
	LNode* node_iterator = *&node_head;

	// Variable to hold the size of the array based on number of input values
	int number_of_values = 0;
	// Check if file is open
	if(file.is_open())
	{
		string file_line;	// Buffer for reading in file lines
		while(getline(file,file_line))
		{
			LNode* next_node = create_node(atoi(file_line.c_str()));
			add_node(node_iterator,next_node);
			if(node_head == NULL)
				node_head = *&node_iterator;
			number_of_values++;
		}
		file.close();
	}
	else
	{
		cout << "File open error" << endl;
		return -1;
	}
	// Print out list size
	cout << "List size: "<< number_of_values << endl;

	// Reset iterator to head
	node_iterator = *&node_head;

	// Print out the original input list
	cout << "Unsorted input values: " << endl;
	for(int i=0; i<number_of_values;i++)
	{
		cout << node_iterator->data << endl;
		node_iterator = node_iterator->link;
	}

	// Run merge sort algorithm
	mergesort(node_head,number_of_values);

	// Reset node iterator to head node
	node_iterator = *&node_head;

	// Print out sorted list
	cout << "Sorted list values: " << endl;
	for(int i=0; i<number_of_values;i++)
	{
		cout << node_iterator->data << endl;
		node_iterator = node_iterator->link;
	}

	// Reset node iterator to head node
	node_iterator = *&node_head;

	// Test and print outcome
	cout << "Test(s): " << (test(node_iterator, number_of_values)?" Passed\n":" Failed\n");

	return 0;
}

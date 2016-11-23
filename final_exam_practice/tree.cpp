#include <iostream>
using namespace std;
struct TNode
{
	TNode* lNode;
	TNode* rNode;
	int value;	
};

void addNode(TNode* &headNode,int value)
{	
	TNode* origHead = headNode;
	
	if(headNode->value < value)
	{
		if(headNode->rNode != __null)
                {
                        if(headNode->rNode->value > value)
                        {
                                TNode* newNode = new TNode;
                                newNode->value = value;
                                newNode->rNode = headNode->rNode;
                                newNode->lNode = headNode;
                                newNode->rNode->lNode = newNode;
                                headNode->rNode = newNode;

                        }
                        else
                        {
                                addNode(headNode->rNode,value);
                        }
                }
                else
                {
                        TNode* newNode = new TNode;
                        newNode->value = value;
                        newNode->rNode = headNode;
                        headNode->lNode = newNode;
                }		
	}
	else if(headNode->value > value)
	{
		if(headNode->lNode != __null)
		{
			if(headNode->lNode->value < value)
			{
				TNode* newNode = new TNode;
				newNode->value = value;
				newNode->lNode = headNode->lNode;
				newNode->rNode = headNode;
				newNode->lNode->rNode = newNode;
				headNode->lNode = newNode;
				
			}
			else
			{
				addNode(headNode->lNode,value);
			}
		}
		else
		{
			TNode* newNode = new TNode;
			newNode->value = value;
			newNode->rNode = headNode;
			headNode->lNode = newNode;
		}
	}
	else
		return;
	
}

void inOrderTraversal(TNode* &headNode)
{
	if(headNode->lNode != __null)
		inOrderTraversal(headNode->lNode);
	cout << headNode->value;
	//if(headNode->rNode != __null)
		//inOrderTraversal(headNode->rNode);
	//	cout << headNode->rNode->value;	
}


int main(int argc, char** argv)
{
	TNode* headNode = new TNode;
	headNode->value =16;
	addNode(headNode,4);
	addNode(headNode,9);
	addNode(headNode,25);
	addNode(headNode,21);
	inOrderTraversal(headNode);
	
	return 0;
}

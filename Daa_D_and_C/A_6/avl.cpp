#include<bits/stdc++.h> 
#include <chrono>
using namespace std; 
using namespace std::chrono; 
 
class Node 
{ 
	public: 
	int key; 
	Node *left; 
	Node *right; 
	int height; 
}; 

int max(int a, int b); 

int height(Node *N) 
{ 
	if (N == NULL) 
		return 0; 
	return N->height; 
} 

int max(int a, int b) 
{ 
	return (a > b)? a : b; 
} 

Node* newNode(int key) 
{ 
	Node* node = new Node(); 
	node->key = key; 
	node->left = NULL; 
	node->right = NULL; 
	node->height = 1;  
	return(node); 
} 
 
Node *rightRotate(Node *y) 
{ 
	Node *x = y->left; 
	Node *T2 = x->right; 

	 
	x->right = y; 
	y->left = T2; 

	 
	y->height = max(height(y->left), 
					height(y->right)) + 1; 
	x->height = max(height(x->left), 
					height(x->right)) + 1; 

	 
	return x; 
} 

Node *leftRotate(Node *x) 
{ 
	Node *y = x->right; 
	Node *T2 = y->left; 

	 
	y->left = x; 
	x->right = T2; 

	 
	x->height = max(height(x->left),	 
					height(x->right)) + 1; 
	y->height = max(height(y->left), 
					height(y->right)) + 1; 

	 
	return y; 
} 

 
int getBalance(Node *N) 
{ 
	if (N == NULL) 
		return 0; 
	return height(N->left) - height(N->right); 
} 
 
Node* insert(Node* node, int key) 
{ 

	if (node == NULL) 
		return(newNode(key)); 

	if (key < node->key) 
		node->left = insert(node->left, key); 
	else if (key > node->key) 
		node->right = insert(node->right, key); 
	else  
		return node; 

	
	node->height = 1 + max(height(node->left), 
						height(node->right)); 

	int balance = getBalance(node); 

	if (balance > 1 && key < node->left->key) 
		return rightRotate(node); 

	 
	if (balance < -1 && key > node->right->key) 
		return leftRotate(node); 

	if (balance > 1 && key > node->left->key) 
	{ 
		node->left = leftRotate(node->left); 
		return rightRotate(node); 
	} 

	if (balance < -1 && key < node->right->key) 
	{ 
		node->right = rightRotate(node->right); 
		return leftRotate(node); 
	} 

	return node; 
} 

Node* find(Node* node,int key)
{
	if(node==NULL)
	{
		return NULL;
	}
	else if(key > node->key)
	{
		return (find(node->right,key));
	}	
	else if(key < node->key)
	{
		return (find(node->left,key));
	}	
	else
	{ 
		return (node);		
	}
}
void Inorder(Node *root) 
{ 
	if(root != NULL) 
	{ 
		Inorder(root->left); 
		cout << root->key << "\n";		
		Inorder(root->right); 
	} 
}

int main() 
{ 
	Node *root = NULL,*temp;
	long long int a;
	int k=0,ch=0;
    	fstream myfile;
    	//myfile.open ("input.txt");
	cout << "Enter the no of element you wants to add\n";
	cin>>ch;

    	/*for (int j=0; j <ch; j++)
    	{
        	myfile  << (rand() % 100000) ;
        	myfile  << endl;
    	}
    	myfile.close();
*/
	myfile.open("input.txt");
	auto start = high_resolution_clock::now();
	while(myfile>>a)
	{
		root = insert(root, a);
		k++;
	}
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start); 
  	
			 
	myfile.close();

	//cout << "Inorder traversal of the \n";
	//cout <<"constructed AVL tree is \n"; 
	//Inorder(root); 

	cout << "Enter the element you wants to search\n";
	cin>>ch;
	
	auto start1 = high_resolution_clock::now();
	temp=find(root,ch);	
	auto stop1 = high_resolution_clock::now();
	auto duration1 = duration_cast<microseconds>(stop1 - start1); 
	if(temp==NULL)
        {
                cout<<"Element is not found\n";
        }
        else
        {
               	cout<<"Element "<<temp->key<<" is Found\n";
        }
	cout << "Time taken by Insert function: "<< duration.count() << " microseconds" << endl;
	cout << "Time taken by Search function: "<< duration1.count() << " microseconds" << endl;
} 

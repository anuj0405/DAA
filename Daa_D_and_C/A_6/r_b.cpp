#include <bits/stdc++.h> 
#include<chrono>
using namespace std::chrono;
using namespace std; 

enum Color {RED, BLACK}; 

struct Node 
{ 
	int data; 
	bool color; 
	Node *left, *right, *parent; 

	// Constructor 
	Node(int data) 
	{ 
	this->data = data; 
	left = right = parent = NULL; 
	this->color = RED; 
	} 
}; 

// Class to represent Red-Black Tree 
class r_btree 
{  
protected: 
	void rotateLeft(Node *&, Node *&); 
	void rotateRight(Node *&, Node *&); 
	void fix(Node *&, Node *&); 
public:
	
	Node *root;  
	r_btree() { root = NULL; } 
	void insert(const int &n); 
	int inorder(Node *);  
}; 

Node* find(Node* node,int key)
{
	if(node==NULL)
	{
		return NULL;
	}
	else if(key > node->data)
	{
		return (find(node->right,key));
	}	
	else if(key < node->data)
	{
		return (find(node->left,key));
	}	
	else
	{ 
		return (node);		
	}
}

/* Function to insert in tree same procedure as BST*/
Node* bstinsert(Node* root, Node *pt) 
{ 
	/* If the tree is empty, return a new node */
	if (root == NULL) 
	return pt; 

	if (pt->data < root->data) 
	{ 
		root->left = bstinsert(root->left, pt); 
		root->left->parent = root; 
	} 
	else if (pt->data > root->data) 
	{ 
		root->right = bstinsert(root->right, pt); 
		root->right->parent = root; 
	} 

	return root; 
} 
 

void r_btree::rotateLeft(Node *&root, Node *&pt) 
{ 
	Node *pt_right = pt->right; 

	pt->right = pt_right->left; 

	if (pt->right != NULL) 
		pt->right->parent = pt; 

	pt_right->parent = pt->parent; 

	if (pt->parent == NULL) 
		root = pt_right; 

	else if (pt == pt->parent->left) 
		pt->parent->left = pt_right; 

	else
		pt->parent->right = pt_right; 

	pt_right->left = pt; 
	pt->parent = pt_right; 
} 

void r_btree::rotateRight(Node *&root, Node *&pt) 
{ 
	Node *pt_left = pt->left; 

	pt->left = pt_left->right; 

	if (pt->left != NULL) 
		pt->left->parent = pt; 

	pt_left->parent = pt->parent; 

	if (pt->parent == NULL) 
		root = pt_left; 

	else if (pt == pt->parent->left) 
		pt->parent->left = pt_left; 

	else
		pt->parent->right = pt_left; 

	pt_left->right = pt; 
	pt->parent = pt_left; 
} 

// This function fixes violations caused by insertion Function 
void r_btree::fix(Node *&root, Node *&pt) 
{ 
	Node *parent_pt = NULL; 
	Node *grand_parent_pt = NULL; 

	while ((pt != root) && (pt->color != BLACK) && 
		(pt->parent->color == RED)) 
	{ 

		parent_pt = pt->parent; 
		grand_parent_pt = pt->parent->parent; 

		/* Case : A 
			Parent of current is left child of Grand-parent of current */
		if (parent_pt == grand_parent_pt->left) 
		{ 

			Node *uncle_pt = grand_parent_pt->right; 

			/* Case : 1 
			The uncle of current is also red 
			Only Recoloring required */
			if (uncle_pt != NULL && uncle_pt->color == RED) 
			{ 
				grand_parent_pt->color = RED; 
				parent_pt->color = BLACK; 
				uncle_pt->color = BLACK; 
				pt = grand_parent_pt; 
			} 

			else
			{ 
				/* Case : 2 
				current is right child of its parent 
				Left-rotation required */
				if (pt == parent_pt->right) 
				{ 
					rotateLeft(root, parent_pt); 
					pt = parent_pt; 
					parent_pt = pt->parent; 
				} 

				/* Case : 3 
				current is left child of its parent 
				Right-rotation required */
				rotateRight(root, grand_parent_pt); 
				swap(parent_pt->color, grand_parent_pt->color); 
				pt = parent_pt; 
			} 
		} 

		/* Case : B 
		Parent of current is right child of Grand-parent of current */
		else
		{ 
			Node *uncle_pt = grand_parent_pt->left; 

			/* Case : 1 
				The uncle of current is also red 
				Only Recoloring required */
			if ((uncle_pt != NULL) && (uncle_pt->color == RED)) 
			{ 
				grand_parent_pt->color = RED; 
				parent_pt->color = BLACK; 
				uncle_pt->color = BLACK; 
				pt = grand_parent_pt; 
			} 
			else
			{ 
				/* Case : 2 
				current is left child of its parent 
				Right-rotation required */
				if (pt == parent_pt->left) 
				{ 
					rotateRight(root, parent_pt); 
					pt = parent_pt; 
					parent_pt = pt->parent; 
				} 

				/* Case : 3 
				current is right child of its parent 
				Left-rotation required */
				rotateLeft(root, grand_parent_pt); 
				swap(parent_pt->color, grand_parent_pt->color); 
				pt = parent_pt; 
			} 
		} 
	} 

	root->color = BLACK; 
} 

void r_btree::insert(const int &data) 
{ 
	Node *pt = new Node(data); 

	root = bstinsert(root, pt); 

	 
	fix(root, pt); 
} 

int r_btree::inorder(Node *root)	 
{ 
	if (root == NULL){ 
		return (0);
	} 
	else
	{
	inorder(root->left); 
	cout << root->data << "\n"; 
	inorder(root->right);
	}
	return 0;
} 

int main() 
{  
	r_btree tree;
	Node *temp,*node;
	long long int a;
	int k=0,ch=0;
    	fstream myfile;
    	//myfile.open ("input.txt");
	cout << "Enter the no of element you wants to add\n";
	cin>>ch;

/*    	for (int j=0; j <ch; j++)
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
		tree.insert(a);;
		k++;
	}
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);				 
	myfile.close();

	cout << "Inoder Traversal of Created Tree\n"; 
	tree.inorder(tree.root); 

	cout << "Enter the element you wants to search\n";
	cin>>ch;
	node=tree.root;
	auto start1 = high_resolution_clock::now();
	temp=find(node,ch);	
	auto stop1 = high_resolution_clock::now();
	auto duration1 = duration_cast<microseconds>(stop1 - start1);
	if(temp==NULL)
        {
                cout<<"Element is not found \n";
        }
        else
        {
               	cout<<"Element "<<temp->data<<" is Found\n";
        }
	cout << "Time taken by Insert function: "<< duration.count() << " microseconds" << endl;
	cout << "Time taken by Search function: "<< duration1.count() << " microseconds" << endl;
	 
} 


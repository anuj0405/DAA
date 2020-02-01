#include <bits/stdc++.h> 
#include<chrono>
using namespace std;
using namespace std::chrono;
vector<int> arr; 

struct Node 
{ 
	int data; 
	Node* left, * right; 
}; 

Node* newNode(int data) 
{ 
	Node* node = (Node*)malloc(sizeof(Node)); 
	node->data = data; 
	node->left = node->right = NULL; 
	return (node); 
} 

Node* insertLevelOrder(Node* root,int i, int n) 
{ 
	 
	if (i < n) 
	{ 
		Node* temp = newNode(arr[i]); 
		root = temp; 

		root->left = insertLevelOrder(root->left, 2 * i + 1, n); 
 
		root->right = insertLevelOrder(root->right, 2 * i + 2, n); 
	} 
	return root; 
} 
 
void inOrder(Node* root) 
{ 
	if (root != NULL) 
	{ 
		inOrder(root->left); 
		cout << root->data <<"\n"; 
		inOrder(root->right); 
	} 
}
Node* find(Node* node,int key)
{
	Node *temp = NULL;
	if(node==NULL)
	{
		return NULL;
	}
	else if(node->data==key)
	{
		return (node);	
	}
	else 
	{ 
		temp = find(node->left,key);
		if(temp == NULL){
			temp = find(node->right,key); 
		}
		else{
			return temp;
		}
	}
	return temp;
}

int main() 
{
	Node *temp,*root=NULL;	
	long long int a;
	int k=0,ch=0;
    	fstream myfile;
    	myfile.open ("input.txt");
	cout << "Enter the no of element you wants to add\n";
	cin>>ch;

    	for (int j=0; j <ch; j++)
    	{
        	myfile  << (rand() % 100000) ;
        	myfile  << endl;
    	}
    	myfile.close();

	myfile.open("input.txt");
	while(myfile>>a)
	{
		arr.push_back(a);
		k++;
	}			 
	myfile.close();
	
	
	auto start = high_resolution_clock::now();
	root = insertLevelOrder(root, 0, k);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);  
	//cout << "Inorder traversal of the \n";
	//cout <<"constructed B-tree is \n"; 
	//inOrder(root); 
	

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
               	cout<<"Element "<<temp->data<<" is Found\n";
        }	
	cout << "Time taken by Insert function: "<< duration.count() << " microseconds" << endl;
	cout << "Time taken by Search function: "<< duration1.count() << " microseconds" << endl;
   
} 


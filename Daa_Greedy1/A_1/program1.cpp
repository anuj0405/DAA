#include<stdio.h>
#include<iostream>
#include<stdlib.h> 
#include <chrono> 
using namespace std::chrono; 
using namespace std;
struct node
{
	int item;
	struct node* left;
	struct node* right;
};
struct node* getnode(int data)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->left=temp->right=NULL;
	temp->item=data;
	return temp;
}
struct node* insertlevelorder(int arr[],struct node* root,int i,int n)
{
	if(i<n)
	{
		struct node* temp=getnode(arr[i]);
		root=temp;
		root->left=insertlevelorder(arr,root->left,2*i+1,n);
		root->right=insertlevelorder(arr,root->right,2*i+2,n);
	}
	return root;
}

int countlevel(struct node* root)
{
	if(root!=NULL)
	{
		int left=countlevel(root->left);
			return(1+left);
	}
	else
		return 0;
}	
int main()
{
	
	int i,n,ch;
	cout<<"Insert the nuber of item that you want\n";
	cin>>n;
	int a[n];
	for(i=0;i<n;i++)
		a[i]=rand()%100;
	struct node* root=NULL;	
	struct node* root_0=NULL;
	struct node* root_1=NULL;
	struct node* root_2=NULL;
	struct node* root_3=NULL;
	
	do{
		cout<<"\n1.Count no of level in binary tree: "<<"\n2.Timetaken by 0 level "<<"\n3.Timetaken by 1 level "<<"\n4.Timetaken by 2 level "<<"\n5.Timetaken by 3 level "<<"\n6.Exit"<<"\nEnter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				{ 
				root=insertlevelorder(a,root,0,n);
				auto start = high_resolution_clock::now(); 
				cout<<"\nNo. of level= "<<countlevel(root);
				auto stop = high_resolution_clock::now(); 
				auto duration = duration_cast<nanoseconds>(stop - start);
				cout << "\nTime taken by function: "<< duration.count() << " Nanoseconds" << endl;
				break;
				}
			case 2: {
				root_0=insertlevelorder(a,root_0,0,0);
				auto start1 = high_resolution_clock::now();					
				cout<<"\nNo. of level= "<<countlevel(root_0);
				auto stop1 = high_resolution_clock::now(); 
				auto duration1 = duration_cast<nanoseconds>(stop1 - start1);						
		            	cout << "\nTime taken by function: "<< duration1.count()<<" Nanoseconds"<<endl;				
				break;
				}
			case 3: {
				root_1=insertlevelorder(a,root_1,0,1);
				auto start2 = high_resolution_clock::now();
				cout<<"\nNo. of level= "<<countlevel(root_1);
				auto stop2 = high_resolution_clock::now(); 
				auto duration2 = duration_cast<microseconds>(stop2 - start2);
				cout << "\nTime taken by function: "<< duration2.count() << " Nanoseconds"<<endl;
				break;
				}
			case 4: {
				root_2=insertlevelorder(a,root_2,0,3);
				auto start3 = high_resolution_clock::now();
				cout<<"\nNo. of level= "<<countlevel(root_2);
				auto stop3= high_resolution_clock::now(); 
				auto duration3 = duration_cast<microseconds>(stop3 - start3);
				cout << "\nTime taken by function: "<< duration3.count() << " Nanoseconds"<<endl;
				break;
				}
			case 5:{
				root_3=insertlevelorder(a,root_3,0,7);
				auto start4 = high_resolution_clock::now();
				cout<<"\nNo. of level= "<<countlevel(root_3);
				auto stop4 = high_resolution_clock::now(); 
				auto duration4 = duration_cast<microseconds>(stop4 - start4);
				cout << "\nTime taken by function: "<< duration4.count()<<" Nanoseconds"<<endl;				
				break;
				}
			case 6: break;
		}
	
	}while(ch<6);
	
}

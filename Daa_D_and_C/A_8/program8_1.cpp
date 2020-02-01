#include<iostream>
#include<bits/stdc++.h> 
using namespace std; 
#define N 20
int heapstate = 0;
int PARENT(int i)
{
return i/2;
}

int LEFT(int i)
{
return 2*i;
}

int RIGHT(int i)
{
return (2*i + 1);
}

void add(int A[], int heapsize, int val)
{
	A[heapsize] = val;
    		printf("Added %d \n" , val);
}

void max_heapify(int A[], int i, int heapsize)
{

	int largest;
	int l = LEFT(i);
	int r = RIGHT(i);
	if(l<=heapsize && A[l] > A[i])
		largest = l;
	else
		largest = i;

	if(r<=heapsize && A[r] > A[largest])
		largest = r;

	int temp;
	if(largest != i)
	{
		temp = A[i];
		A[i] = A[largest];
		A[largest] = temp;
		max_heapify(A,largest,heapsize);
	}
}

void min_heapify(int A[], int i, int heapsize)
{

	int min;
	int l = LEFT(i);
	int r = RIGHT(i);
	if(l<=heapsize && A[l] < A[i])
		min = l;
	else
		min = i;

	if(r<=heapsize && A[r] < A[min])
		min = r;

	int temp;
	if(min != i)
	{
		temp = A[i];
		A[i] = A[min];
		A[min] = temp;
		min_heapify(A,min,heapsize);
	}
}

int extract(int A[], int heapsize)
{
	printf("Extracting........");
   
	int val,temp;
	val = A[1];
   
    	if(heapstate == 1)
	{
		temp = A[1];
		A[1] = A[heapsize];
		A[heapsize] = temp;
		max_heapify(A,1,heapsize-1);
	}

	if(heapstate == 2)
	{
		temp = A[1];
		A[1] = A[heapsize];
		A[heapsize] = temp;
		min_heapify(A,1,heapsize-1);
	}

	return val;
}

void make_max_heap(int A[], int heapsize)
{
	int length = heapsize;
	for (int i=length/2; i>=1; i--)
		max_heapify(A,i,heapsize);
}

void make_min_heap(int A[], int heapsize)
{    
    	int length = heapsize;
	for (int i=length/2; i>=1; i--)
		min_heapify(A,i,heapsize);
}

void heapsort(int A[], int heapsize)
{
	if(heapstate == 0) return;
   
	int temp;
	if(heapstate == 1) //maxheap
	{
		int size = heapsize;
		for(int i = size; i>=1; i--)
		{
			temp = A[i];
			A[i] = A[1];
			A[1] = temp;
			size = size-1;
			make_max_heap(A,size);
			heapstate = 0;
		}
	}

	if(heapstate == 2)  //minheap
	{
		int size = heapsize;
		for(int i = size; i>=1; i--)
		{
			temp = A[i];
			A[i] = A[1];
			A[1] = temp;
			size = size-1;
			make_min_heap(A,size);
			heapstate  = 0;
		}
	
	}

}

void print(int A[], int heapsize)
{
    	for(int i = 1; i<= heapsize; i++)
		printf("%d-",A[i]);
	printf("\n\n\n");
}
int main()
{
	

	int A[N+1];
	int heapsize = 0;
	string s1;
	int val=0;
	//Initialize
	//Remember that our arrays start with index 1
	for(int i=1;i<=N;i++)
		A[i]=0;
	
	while(s1 != "exit" ){
		printf("\nEnter Add for adding\nEnter Extract for extracting\nEnter Nither for Nothing\nEnter Max for making a max heap\nEnter Min for min heap\nEnter Sort for sorting\nEnter Exit for ending\nEnter your choice: ");
		getline(cin,s1);
		if(s1 == "add")
		{
			if(heapsize == 20)
				printf("Can't be added. Already contains 20 elements\n");
			else
			{
				cout<<"\nEnter the value to be added\n";
				scanf("%d", &val);
				heapsize++;
				add(A, heapsize, val);
			}

			heapstate = 0;

		}
		if(s1 == "extract")
		{
			cout<<"\nExtracted "<<extract(A, heapsize)<<"\n";
			heapsize--;

		}
		if(s1 == "nither")
		{
			heapstate=0;
		}
		if(s1 == "max")
		{
			heapstate = 1;
			printf("Making a max heap");
			make_max_heap(A,heapsize) ;

		}
		if(s1 == "min")
		{
			heapstate = 2;
			printf("Making a min heap");
			make_min_heap(A,heapsize) ;
		}
		if(s1 == "sort"){
			//sort into increasing order if heapstate=1
			//and into decreasing order if heapstate=2
			heapsort(A,heapsize);
		}
		//A[N+1] = heapstate;
		print(A,heapsize);	
	}
}


#include<bits/stdc++.h>
#include<chrono>
using namespace std;
using namespace std::chrono;
class sorting
{
	public:
		long a,cm=0;
		
		int i=0,j=0;
		vector<double> v1; 
		int partition(int,int);
		int median(int,int);
		void quicksort(int,int);
}; 

int sorting::partition(int low,int high)
{
	int pivot = v1[low]; 
    	int i = low - 1, j = high + 1; 
   
    	while (true) 
    	{ 
    	    do
    	    { 
    	        i++; 
    	    } while (v1[i] < pivot); 
   
    	    do
    	    { 
    	        j--; 
    	    } while (v1[j] > pivot); 
   	
    	    if (i >= j) 
    	        return j; 
    	    swap(v1[i], v1[j]); 
    	}
}

int sorting::median(int left,int right)
{
	int center=(left+right)/2;
	if(v1[left]>v1[center])
		swap(v1[left],v1[center]);
	if(v1[left]>v1[right])
		swap(v1[left],v1[right]);
	if(v1[center]>v1[right])
		swap(v1[center],v1[right]);
	swap(v1[center],v1[left]);
	return partition(left,right);
}
void sorting::quicksort(int left,int right)
{
	
	if(left<right)
	{
		int p=median(left,right);
		quicksort(left,p);
		quicksort(p+1,right);
	}
}
int main()
{
	sorting s;
	int i,j;
	int n;
	printf("Enter the number of input\n");
	scanf("%d",&n);
	fstream myfile;
	myfile.open ("average.txt");

    	for (j=0; j<n; j++)
    	{
        	myfile  << (rand()%100000) ;
        	myfile  << endl;
    	}
    	myfile.close();

	myfile.open("average.txt");
	while(myfile>>s.a)
	{
		;
	}
	auto start = high_resolution_clock::now(); 
	s.quicksort(0,n-1);
	auto stop = high_resolution_clock::now(); 
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "\nTime taken by Hoare quick sort: "<< duration.count() << " Microseconds" << endl;
				
	/*for(int i=0;i<n;i++)
	{	
		cout<<"\n"<<s.v1[i];
	}*/
}

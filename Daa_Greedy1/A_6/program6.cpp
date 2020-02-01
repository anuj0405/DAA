#include <bits/stdc++.h>  
#include<stdlib.h>
#include<chrono>

using namespace std;
using namespace std::chrono;
class sorting
{
	public:
		long a,cm=0;
		
		int i=0,j=0;
		vector<double> v1,v2; 
		int partition(int,int);
		int partition_random(int,int);
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
int sorting::partition_random(int low,int high)
{
    	int size=high-low;
    	int r = low+rand()%size;
	//cout<<"\nRandom value: "<<v1[r];
    	swap(v1[r],v1[low]);
    	return partition(low,high);
}
void sorting::quicksort(int p,int r)
{
	
	if(p<r)
	{
		int q=partition_random(p,r);
		quicksort(p,q);
		quicksort(q+1,r);
	}
}
int main()
{
	sorting s;
	int i,j;
	int n;
	cout<<"Enter the number of input\n";
	cin>>n;

    	for (j=0; j<n; j++)
    	{
		i=(rand()%100000);
        	s.v1.push_back(i);    	
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

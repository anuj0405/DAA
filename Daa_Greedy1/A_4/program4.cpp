#include <bits/stdc++.h> 
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
		int hoare_class(int,int);
		void quick(int,int);
		void quicksort_class(int,int);
}; 

int sorting::partition (int low, int high) 
{ 
	int pivot = v1[high];  
	int i = (low - 1),temp; 

	for (int j = low; j <= high- 1; j++) 
	{ 
		if (v1[j] <= pivot) 
		{ 
			i++;
			temp=v1[i];
			v1[i]=v1[j];
			v1[j]=temp; 
		} 
	}
	temp=v1[i+1];
	v1[i+1]=v1[high];
	v1[high]=temp; 
	return (i + 1); 
}
int sorting::hoare_class(int low,int high)
{
	int pivot = v2[low]; 
    	int i = low - 1, j = high + 1; 
   
    	while (true) 
    	{ 
    	    do
    	    { 
    	        i++; 
    	    } while (v2[i] < pivot); 
   
    	    do
    	    { 
    	        j--; 
    	    } while (v2[j] > pivot); 
   	
    	    if (i >= j) 
    	        return j; 
    	    swap(v2[i], v2[j]); 
    }
}
void sorting::quick(int low, int high) 
{ 
	if (low < high) 
	{ 

		int pi = partition(low, high); 
 
		quick(low, pi - 1); 
		quick(pi + 1, high); 
	} 
}
void sorting::quicksort_class(int p,int r)
{
	if(p<r)
	{
		int q=hoare_class(p,r);
		quicksort_class(p,q);
		quicksort_class(q+1,r);
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
        	s.v2.push_back(i);
    	}
	auto start = high_resolution_clock::now(); 
	s.quicksort_class(0,n-1);
	auto stop = high_resolution_clock::now(); 
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "\nTime taken by Hoare quick sort: "<< duration.count() << " Microseconds" << endl;
				
	auto start1 = high_resolution_clock::now(); 
	s.quick(0,n-1);
	auto stop1 = high_resolution_clock::now(); 
	auto duration1 = duration_cast<microseconds>(stop1 - start1);
	cout << "\nTime taken by Normal quick sort: "<< duration1.count() << " Microseconds" << endl;
	//for(int i=0;i<n;i++)
	//{	cout<<"\n"<<s.v2[i];		cout<<"\t"<<s.v1[i];
//}
}




















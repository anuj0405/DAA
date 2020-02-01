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
		vector<double> v1,v2,v3,v4,v5; 
		int partition5(int,int);
		int partition(int,int);
		int partition_random(int,int);
		int median(int,int);
		void quicksort5(int,int);		
		void quicksort(int,int);
		int partition4(int,int);
		int hoare_class(int,int);
		void quick4(int,int);
		void quicksort_class4(int,int);

}; 
int sorting::partition4 (int low, int high) 
{ 
	int pivot = v4[high];  
	int i = (low - 1),temp; 

	for (int j = low; j <= high- 1; j++) 
	{ 
		if (v4[j] <= pivot) 
		{ 
			i++;
			temp=v4[i];
			v4[i]=v4[j];
			v4[j]=temp; 
		} 
	}
	temp=v4[i+1];
	v4[i+1]=v4[high];
	v4[high]=temp; 
	return (i + 1); 
}
int sorting::hoare_class(int low,int high)
{
	int pivot = v5[low]; 
    	int i = low - 1, j = high + 1; 
   
    	while (true) 
    	{ 
    	    do
    	    { 
    	        i++; 
    	    } while (v5[i] < pivot); 
   
    	    do
    	    { 
    	        j--; 
    	    } while (v5[j] > pivot); 
   	
    	    if (i >= j) 
    	        return j; 
    	    swap(v5[i], v5[j]); 
    }
}
void sorting::quick4(int low, int high) 
{ 
	if (low < high) 
	{ 

		int pi = partition4(low, high); 
 
		quick4(low, pi - 1); 
		quick4(pi + 1, high); 
	} 
}
void sorting::quicksort_class4(int p,int r)
{
	if(p<r)
	{
		int q=hoare_class(p,r);
		quicksort_class4(p,q);
		quicksort_class4(q+1,r);
	}
}

int sorting::partition5(int low,int high)
{
	int pivot = v3[low]; 
    	int i = low - 1, j = high + 1; 
   
    	while (true) 
    	{ 
    	    do
    	    { 
    	        i++; 
    	    } while (v3[i] < pivot); 
   
    	    do
    	    { 
    	        j--; 
    	    } while (v3[j] > pivot); 
   	
    	    if (i >= j) 
    	        return j; 
    	    swap(v3[i], v3[j]); 
    	}
}

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
    	swap(v1[r],v1[low]);
    	return partition(low,high);
}
int sorting::median(int left,int right)
{
	int center=(left+right)/2;
	if(v3[left]>v3[center])
		swap(v3[left],v3[center]);
	if(v3[left]>v3[right])
		swap(v3[left],v3[right]);
	if(v3[center]>v3[right])
		swap(v3[center],v3[right]);
	swap(v3[center],v3[left]);
	return partition5(left,right);
}
void sorting::quicksort5(int left,int right)
{
	
	if(left<right)
	{
		int p=median(left,right);
		quicksort5(left,p);
		quicksort5(p+1,right);
	}
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
		i=j;
        	s.v1.push_back(i);
        	s.v2.push_back(i);
		s.v3.push_back(i);
		s.v4.push_back(i);
		s.v5.push_back(i);    	
	}
	auto start1 = high_resolution_clock::now();
	s.quick4(0,n-1);
	auto stop1 = high_resolution_clock::now(); 
	auto duration1 = duration_cast<microseconds>(stop1 - start1);
	cout << "\nTime taken by Normal quick sort: "<< duration1.count() << " Microseconds" << endl;
	auto start3 = high_resolution_clock::now();
	s.quicksort_class4(0,n-1);
	auto stop3 = high_resolution_clock::now(); 
	auto duration3 = duration_cast<microseconds>(stop3 - start3);
	cout << "\nTime taken by Hoare quick sort: "<< duration3.count() << " Microseconds" << endl;
	auto start2 = high_resolution_clock::now();
	s.quicksort5(0,n-1);
	auto stop2 = high_resolution_clock::now(); 
	auto duration2 = duration_cast<microseconds>(stop2 - start2);
	cout << "\nTime taken by Median-Of-Three quick sort: "<< duration2.count() << " Microseconds" << endl;
	auto start = high_resolution_clock::now(); 
	s.quicksort(0,n-1);
	auto stop = high_resolution_clock::now(); 
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "\nTime taken by Random quick sort: "<< duration.count() << " Microseconds" << endl;	
				
	/*for(int i=0;i<n;i++)
	{	
		cout<<"\n"<<s.v1[i];
		cout<<"\n"<<s.v3[i];
		cout<<"\n"<<s.v4[i];
		cout<<"\n"<<s.v5[i];	
	}*/
}

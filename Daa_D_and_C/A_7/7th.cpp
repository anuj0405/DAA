#include<iostream>
#include <bits/stdc++.h>
#include<vector>
#include<fstream>
#include <sys/time.h>
#include<chrono> 

using namespace std::chrono;
using namespace std;

class nsort
{
	public:
		long int a,cm=0;
		int count=0,i=0,j=0;
		long long int v1[1000000]; 
		int merge_nsort(int,int);
		void merge(int,int,int);
		void bubblensort(int);
		void semibubblensort(int);		
		int insertionnsort(int);
		void mynsort(int,int);
		void fillRandom (int);
		void check(int);

}; 
void nsort::merge(int l, int m, int r) 
{ 
	int i, j, k; 
	int n1 = m - l + 1; 
	int n2 = r - m; 

	
	int L[n1], R[n2]; 

	
	for (i = 0; i < n1; i++) 
		L[i] = v1[l + i]; 
	for (j = 0; j < n2; j++) 
		R[j] = v1[m + 1+ j]; 

	
	i = 0;  
	j = 0; 
	k = l;  
	while (i < n1 && j < n2) 
	{ 
		if (L[i] <= R[j]) 
		{ 
			v1[k] = L[i]; 
			i++;
		
		} 
		else
		{ 
			v1[k] = R[j]; 
			j++;
			 
		} 
				
		k++; 
	} 


	while (i < n1) 
	{ 
		v1[k] = L[i]; 
		i++; 
		k++;
		
	} 
	while (j < n2) 
	{ 
		v1[k] = R[j]; 
		j++;
		
		k++; 
	} 
} 


int nsort::merge_nsort(int l, int r) 
{ 
	if (l < r) 
	{ 
		int m = (l+r)/2; 

		merge_nsort(l, m); 
		merge_nsort(m+1, r);
		merge(l, m, r); 
	} 
}


void nsort::bubblensort(int n)
{
     int i, j, temp;
    	for(i = 0; i < n; i++)
    	{
    	    for(j = 0; j < n-i-1; j++)
    	    {
    	        if( v1[j] > v1[j+1])
    	        {
    		            // swap the elements
    	            temp = v1[j];
    	            v1[j] = v1[j+1];
    	            v1[j+1] = temp;
    	        } 
    	    }
    	}

}

void nsort::semibubblensort(int n)
{
     int i, j,k=0, temp;
    	for(i = 0; i < n; i++)
    	{
		k=0;
    	    for(j = 0; j < n-i-1; j++)
    	    {
    	        if( v1[j] > v1[j+1])
    	        {
    		            // swap the elements
    	            temp = v1[j];
    	            v1[j] = v1[j+1];
    	            v1[j+1] = temp;
			k=1;
    	        } 
    	    }
		if(k!=1)
		{	
			break;
		}    	
	}

}


int nsort::insertionnsort(int count)
{
	long long int key,swap=0;
	for(i=1;i<count;i++)
	{	
		key=v1[i];
		j=i-1;
			while(j>=0 && v1[j]>key)
			{
				v1[j+1]=v1[j];
				j=j-1;
				swap++;
			}
		v1[j+1]=key;
		
	}
	cout<<"\nNo of swap= "<<swap<<"\n";

}


void nsort::mynsort(int l, int r)
{
    if (l < r) 
	{ 
		int m = (l+r)/2; 

		mynsort(l, m); 
		mynsort(m+1, r);
		if(v1[m]>v1[m+1]) 
			merge(l, m, r); 
	}
}


void nsort::fillRandom(int n)
{
	int a=0;
    for (int i=0;i<n;i++)
    {
	v1[i]=rand()%10000;
	//cout<<"\n"<<v1[i];
    }
    return;
}

void nsort::check(int n)
{
    for (int i=0;i<n-1;i++)
    {
	//cout<<"\n"<<v1[i];
        if (v1[i]>v1[i+1])
	{
            cout<<"Failed  to nsort. See item: "<<i<<endl<<endl;
            return;
	}
    }
    cout<<"Check Passed"<<endl<<endl;
}


int main()
{
		
	nsort s;
	long long int t;
	long long int a=0;
	cout<<"\nEnter the size of array you want: ";
	cin>>a;
	
    	s.fillRandom(a);
	auto start = high_resolution_clock::now();
    	s.bubblensort(a);
    	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start); 
  	cout << "Time taken by Bubble sort: "<< duration.count() << " microseconds" << endl;
    	s.check(a);
   
	s.fillRandom(a);
	auto start1 = high_resolution_clock::now();
    	s.semibubblensort(a);
    	auto stop1= high_resolution_clock::now();
	auto duration1 = duration_cast<microseconds>(stop1 - start1); 
  	cout << "Time taken by Semi Bubble sort: "<< duration1.count() << " microseconds" << endl;
    	s.check(a);



	s.fillRandom(a);   	
	auto start2 = high_resolution_clock::now();
    	s.insertionnsort(a);
    	auto stop2 = high_resolution_clock::now();
	auto duration2 = duration_cast<microseconds>(stop2 - start2); 
  	cout << "Time taken by Insertion sort: "<< duration2.count() << " microseconds" << endl;
    	s.check(a);
    
    	s.fillRandom(a);    	
	auto start3 = high_resolution_clock::now();
    	s.merge_nsort(0,a-1);
    	auto stop3 = high_resolution_clock::now();
	auto duration3 = duration_cast<microseconds>(stop3 - start3); 
  	cout << "Time taken by Merge sort: "<< duration3.count() << " microseconds" << endl;
    	s.check(a);
   
    	s.fillRandom(a);
    	auto start4 = high_resolution_clock::now();
    	s.mynsort(0,a-1);
    	auto stop4 = high_resolution_clock::now();
	auto duration4 = duration_cast<microseconds>(stop4 - start4); 
  	cout << "Time taken by My own sort: "<< duration4.count() << " microseconds" << endl;
    	s.check(a);
   	
}


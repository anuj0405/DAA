#include<iostream>
#include<vector>
#include<fstream>
#include <chrono> 
using namespace std::chrono; 

using namespace std;
class sort
{
	public:
		long a,cm=0;
		int count=0,i=0,j=0;
		vector<double> v1; 
		int merge_sort(int,int);
		void merge(int,int,int);
}; 
void sort::merge(int l, int m, int r) 
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


int sort::merge_sort(int l, int r) 
{ 
	if (l < r) 
	{ 
		int m = (l+r)/2; 

		merge_sort(l, m); 
		merge_sort(m+1, r); 
		if(v1[m]>v1[m+1])
			merge(l, m, r); 
	}
	  
}


int main()
{
		
	sort s;
	int k=0,ch=0;
    	fstream myfile;
		
	cout<<"1.Merge sort best case: \n";
		s.count=0;
		myfile.open("best.txt");
		while(myfile>>s.a)
		{
			s.v1.push_back(s.a);
			s.count++;
		}

		auto start = high_resolution_clock::now();
		s.merge_sort(0,s.count - 1);
		auto stop = high_resolution_clock::now();
		cout<<"\nNo of Swap is: "<<s.cm<<"\n";
		
		auto duration = duration_cast<microseconds>(stop - start); 
  		cout << "Time taken by function: "<< duration.count() << " microseconds" << endl;
		myfile.close();
		s.v1.clear();
	/*cout<<"2.Merge sort average case: \n";	
		s.count=0;	
		myfile.open("average.txt");
		while(myfile>>s.a)
		{
			s.v1.push_back(s.a);
			s.count++;
		}
		auto start1 = high_resolution_clock::now();
		s.merge_sort(0,s.count - 1);
		auto stop1 = high_resolution_clock::now(); 
		cout<<"\nNo of swaps: "<<s.cm<<"\n";
			
		auto duration1 = duration_cast<microseconds>(stop1 - start1); 
  		cout << "Time taken by function: "<< duration1.count() << " microseconds" << endl;
		myfile.close();	
		s.v1.clear();	
	cout<<"3.Merge sort worst case: \n";
		s.count=0;
		myfile.open("worst.txt");
		while(myfile>>s.a)
		{
			s.v1.push_back(s.a);
			s.count++;
		}
		auto start2 = high_resolution_clock::now();
		s.merge_sort(0,s.count - 1);
		auto stop2 = high_resolution_clock::now();
		cout<<"\nNo of swaps: "<<s.cm<<"\n";
		auto duration2 = duration_cast<microseconds>(stop2 - start2); 
  		cout << "Time taken by function: "<< duration2.count() << " microseconds" << endl;
		myfile.close();*/
				
		
	myfile.open ("sort.txt");
		

	for(int i=0;i<s.count;i++)
	{
		myfile<<s.v1[i]<<"\n";
	
	}
	myfile.close();
	

}

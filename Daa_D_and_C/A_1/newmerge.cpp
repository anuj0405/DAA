#include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include<fstream>
#include <sys/time.h> 

using namespace std;

class nsort
{
	public:
		long a,cm=0;
		int count=0,i=0,j=0;
		vector<long int> v1; 
		int merge_sort(int,int);
		void merge(int,int,int);
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


int nsort::merge_sort(int l, int r) 
{ 
	if (l < r) 
	{ 
		int m = (l+r)/2; 

		merge_sort(l, m); 
		merge_sort(m+1, r); 

		merge(l, m, r); 
	} 
}



int main()
{
	struct timeval start, end;
	double t;	
	nsort s;
	int k=0,ch=0;
    	fstream myfile;
		
	cout<<"1.Merge sort best case: \n";
		myfile.open("best.txt");
		while(myfile>>s.a)
		{
			s.v1.push_back(s.a);
			s.count++;
		}
		gettimeofday(&start,NULL);
		s.merge_sort(0,s.count - 1);
		gettimeofday(&end,NULL);
		cout<<" "<<s.cm<<"\n";
		s.count=0;
		t= (end.tv_sec - start.tv_sec)*1e6; 
    		t= (t + (end.tv_usec - start.tv_usec)) *1e-6;
  		s.v1.clear();
    		cout << "Time taken by program is : " << fixed << t << setprecision(6); 
    		cout << " sec" << endl;
		myfile.close();
	cout<<"2.Merge sort average case: \n";	
		myfile.open("average.txt");
		while(myfile>>s.a)
		{
			s.v1.push_back(s.a);
			s.count++;
		}
		gettimeofday(&start,NULL);
		s.merge_sort(0,s.count - 1);
		gettimeofday(&end,NULL);
		cout<<" "<<s.cm<<"\n";
		s.count=0;
		t= (end.tv_sec - start.tv_sec)*1e6; 
    		t= (t + (end.tv_usec - start.tv_usec)) *1e-6;
  
    		cout << "Time taken by program is : " << fixed << t << setprecision(6); 
    		cout << " sec" << endl;
		s.v1.clear();
		myfile.close();		
	cout<<"3.Merge sort worst case: \n";
		myfile.open("worst.txt");
		while(myfile>>s.a)
		{
			s.v1.push_back(s.a);
			s.count++;
		}
		gettimeofday(&start,NULL);		
		s.merge_sort(0,s.count - 1);
		gettimeofday(&end,NULL);
		cout<<" "<<s.cm<<"\n";
		s.count=0;
		t= (end.tv_sec - start.tv_sec)*1e6; 
    		t= (t + (end.tv_usec - start.tv_usec)) *1e-6;
  
    		cout << "Time taken by program is : " << fixed << t << setprecision(6); 
    		cout << " sec" << endl;

		myfile.close();
				
		
	myfile.open ("sort_file1.txt");
		

	for(int i=0;i<s.count;i++)
	{
		myfile<<s.v1[i]<<"\n";
	
	}
	myfile.close();
	

}


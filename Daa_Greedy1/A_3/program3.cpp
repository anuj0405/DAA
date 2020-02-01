#include<chrono>
#include<vector>
#include<fstream>
#include<iostream> 
using namespace std::chrono; 

using namespace std;
class sort
{
	public:
		long a,cm=0;
		
		int i=0,j=0;
		vector<double> v1; 
		void mergesort(int,int);
		void merge_count(int,int,int);
		void countingversion(int);
}; 
static long long int count_merge=0;

void sort::countingversion(int n)
{
	int i,j;
	long long int count=0;
	for(j=0;j<n-1;j++)
	{
		for(i=1+j;i<n;i++)
		{
			if(v1[j]>v1[i])
			{
				count++;
			}
		}
	}
	cout<<"\nNumber of inversion in countinversion: "<<count;
}
void sort::merge_count(int p,int q,int r)
{		int i,j,k,count=0;
		int n1=q-p+1,n2=r-q;
		int L[n1],R[n2];
		for(i=0;i<n1;i++)
			L[i]=v1[p+i];
		for(j=0;j<n2;j++)
			R[j]=v1[q+j+1];
		i=0;j=0,k=p;
		while(i<n1 && j<n2)
		{
			if(L[i]<=R[j])
			{
				v1[k]=L[i];
				i++;
			}
			else 
			{
				v1[k]=R[j];
				j++;	
				count_merge=count_merge+(n1-i);
			}
				k++;
		}
		while(i<n1)
		{
			v1[k]=L[i];
			i++;
			k++;
		}
		while(j<n2)
		{
			v1[k]=R[j];
			j++;
			k++;
		}
}

void sort::mergesort(int p,int r)
{
		if(p<r)
		{
			int q=(p+r)/2;
			mergesort(p,q);
			mergesort(q+1,r);
			merge_count(p,q,r);
		}
}
int main()
{
	sort s;
	int i,j;
	int n;
	cout<<"Enter the number of input\n";
	cin>>n;

    	for (j=0; j<n; j++)
    	{
		i=(rand()%100000);
        	s.v1.push_back(i) ;
    	}
	auto start = high_resolution_clock::now();
	s.countingversion(n);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start); 
  	cout << "\nTime taken by function: "<< duration.count() << " microseconds" << endl;
		
	auto start1 = high_resolution_clock::now();
	s.mergesort(0,n-1);
	auto stop1 = high_resolution_clock::now();
	auto duration1 = duration_cast<microseconds>(stop1 - start1); 
  			
	//for(i=0;i<n;i++)
	//	cout<<"\n"<<s.v1[i];
	cout<<"\nNumber of inversion in merge: "<<count_merge;
	cout << "\nTime taken by function: "<< duration1.count() << " microseconds" << endl;

}





















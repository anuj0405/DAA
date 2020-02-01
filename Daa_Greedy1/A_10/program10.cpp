#include<bits/stdc++.h>
#include<chrono>

using namespace std;
using namespace std::chrono;
class sorting
{
	public:
		long a,cm=0;
		int i=0,j=0;
		
		int getMax(int [],int);
		void countingsort(int[],int);
}; 
int sorting::getMax(int v1[],int size) 
{
	   int max = v1[1];
	   for(int i = 2; i<=size; i++) 
	   {
	      if(v1[i] > max)
	         max = v1[i];
	   }

   	   return max; //the max element from the v1
}
void sorting::countingsort(int v1[],int size) 
{
 	  int out[size+1];
	  int max = getMax(v1,size);
	  int count[max+1];

   	for(int i = 0; i<=max; i++)
      		count[i] = 0; 
   	for(int i = 1; i <=size; i++)
      		count[v1[i]]++; 
   	for(int i = 1; i<=max; i++)
   		count[i] += count[i-1];

   	for(int i = size; i>=1; i--) 
	{
      		out[count[v1[i]]] = v1[i];
      		count[v1[i]] -= 1; 
   	}

   	for(int i = 1; i<=size; i++) 
	{
	      	v1[i] = out[i]; 
 	}
}	
int main()
{
	sorting s;
	int i,j;
	int n;
	printf("Enter the number of input\n");
	scanf("%d",&n);
	int v1[n];
    	for (j=1; j<=n; j++)
    	{
        	v1[j]=(rand()%100000) ;
    	}
	auto start = high_resolution_clock::now(); 
	s.countingsort(v1,n);
	auto stop = high_resolution_clock::now(); 
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "\nTime taken by counting sort: "<< duration.count() << " Microseconds" << endl;
				
	for(int i=1;i<=n;i++)
	{	
		cout<<"\n"<<v1[i];
	}
	
}

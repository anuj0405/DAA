#include<iostream>
#include<cstring>
#include<chrono>

using namespace std::chrono;
using namespace std;

struct billboards
{
	int position; 
	int revenue; 
};

typedef struct billboards Billboards;

int max(int a, int b)
{
	return((a>b)?a:b);
}

int maxRevenue(Billboards arr[], int n, int length, int range)
{
	int maxRevTable[length+1];
	memset(maxRevTable,0,sizeof(maxRevTable));
	int nextBB=0; 
  	for(int m=1;m<=length;m++)
  	{
    		if(nextBB < n)
		{ 
 	     		if(arr[nextBB].position != m)
			{
 		       		maxRevTable[m] = maxRevTable[m-1];
 	     		}
 	     		else
			{
 		       		if(m < range)
				{ 
 	         			maxRevTable[m] = max(maxRevTable[m-1], arr[nextBB].revenue);
 		       		}
 		       	else
			{ 
          			maxRevTable[m] = max(maxRevTable[m-range-1] + arr[nextBB].revenue, maxRevTable[m-1]);
        		}
        			nextBB++; 
      			}
    		}
    		else
		{ 
      			maxRevTable[m] = maxRevTable[m-1];
    		}
  	}
  	return maxRevTable[length];
}

int main()
{
  	int length,n,range;
  	cout << "Enter the length of highway in miles : ";
  	cin>>length;
  	cout << "Enter the number of billboards to be placed on the heighway : ";
  	cin>>n;
  	cout << "Enter the range within which no two billboards can be placed : ";
  	cin>>range;
  	Billboards arr[n]; 
  	for(int i=0;i<n;i++)
	{
  		cout << "Enter the position and associated revenue for billboard : ";
    		cin>>arr[i].position>>arr[i].revenue;
  	}
	auto start1 = high_resolution_clock::now(); 
  	cout << "Maximum Revenue : " << maxRevenue(arr,n,length,range) << "\n";
	auto stop1 = high_resolution_clock::now(); 
	auto duration1 = duration_cast<microseconds>(stop1 - start1);
	cout << "\nTime taken by Other function: "<< duration1.count() << "Microseconds" << endl;
	
  	return 0;
}

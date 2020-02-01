#include <bits/stdc++.h> 
#include<chrono>

using namespace std::chrono;
using namespace std; 

int max(int a, int b) { return (a > b)? a : b; } 

int knapSack(int W, int wt[], int val[], int n) 
{ 
	
if (n == 0 || W == 0) 
	return 0; 

if (wt[n-1] > W) 
	return knapSack(W, wt, val, n-1); 

else return max( val[n-1] + knapSack(W-wt[n-1], wt, val, n-1),knapSack(W, wt, val, n-1) ); 
} 

int main() 
{ 
	int n,w;
  	cout << "\nEnter the number of items : ";
  	cin>>n;
  	cout << "\nEnter the capacity of Knapsack : ";
  	cin>>w;
	int val[n],wt[n];
  	for(int i=0;i<n;i++)
  	{
		cout << "\nEnter the weight and profit : ";
  		cin>>wt[i]>>val[i];
  	}
	auto start1 = high_resolution_clock::now(); 
  	cout << "\nMaximum Profit : " << knapSack(w, wt, val, n) << "\n";
	auto stop1 = high_resolution_clock::now(); 
	auto duration1 = duration_cast<microseconds>(stop1 - start1);
	cout << "\nTime taken by Other function: "<< duration1.count() << "Microseconds" << endl;
	
	return 0; 
} 


#include<bits/stdc++.h> 
#include<chrono>

using namespace std::chrono;
using namespace std; 

int minCoins(int coins[], int m, int V) 
{ 
	int table[V+1]; 

	table[0] = 0; 

	for (int i=1; i<=V; i++) 
		table[i] = INT_MAX; 

	for (int i=1; i<=V; i++) 
	{ 
		for (int j=0; j<m; j++) 
		if (coins[j] <= i) 
		{ 
			int sub_res = table[i-coins[j]]; 
			if (sub_res != INT_MAX && sub_res + 1 < table[i]) 
				table[i] = sub_res + 1; 
		} 
	} 
	return table[V]; 
} 
int main() 
{
	int amount,n;
  	cout << "Enter the amount for which change need to be computed : ";
  	cin>>amount;
  	cout << "Enter the number of coins (assume each denomination has infinite supply) : ";
  	cin>>n;
  	int coins[n];
  	for(int i=0;i<n;i++)
	{
  		  cout << "Enter the denomination of "<< i+1 << " coin : ";
  		  cin>>coins[i];
  	}
	auto start1 = high_resolution_clock::now(); 
	cout << "Minimum number of coins : " << minCoins(coins, n, amount) << "\n";
	auto stop1 = high_resolution_clock::now(); 
	auto duration1 = duration_cast<microseconds>(stop1 - start1);
	cout << "\nTime taken by Other function: "<< duration1.count() << "Microseconds" << endl;
	  	
	return 0; 
} 


//implement counting sort
#include<iostream>
#include<cstring>
#include<iomanip> // for setting precision
#include<chrono>
using namespace std::chrono;
using namespace std;

typedef unsigned long long LL;
LL range=0;
void randomInput(LL arr[], LL n){
  for(LL i=0;i<=n;i++){
    arr[i] = (rand() % range)+1;
  }
}

void printArr(LL arr[], LL n){
  for(LL i=0;i<n;i++){
    cout << arr[i] << " ";
  }
  cout << "\n";
}

void countingSort(LL arr[], LL n)
{
  	LL count[range];
  	LL outputArr[n] = {0};
  	memset(count,0,sizeof(count));
  	for(LL i=0;i<n;i++){
  	  count[arr[i]]++;
  	}
  	for(LL i=1;i<range;i++){
  	  count[i] = count[i] + count[i-1];
  	}
  	for(LL i=0;i<n;i++){
  	  outputArr[count[arr[i]]-1] = arr[i];
  	  count[arr[i]]--;
  	}
  	printArr(outputArr, n);
}

int main(void)
{
	LL n;
  	cout << "Enter the value of n for range of input [0:n] : ";
  	cin>>range;
  	cout << "Enter the  size of array : ";
  	cin>>n;
  	LL arr[n];
	randomInput(arr,n);
  	auto start = high_resolution_clock::now(); 
        countingSort(arr, n);
	auto stop = high_resolution_clock::now(); 
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "\nTime taken by Hoare quick sort: "<< duration.count() << " Microseconds" << endl;
	return 0;
}

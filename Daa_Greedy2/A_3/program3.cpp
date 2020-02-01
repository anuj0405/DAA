#include<bits/stdc++.h> 
#include<chrono>

using namespace std::chrono;
using namespace std; 

struct Interval 
{ 
	int start, end; 
}; 

bool compareInterval(Interval i1, Interval i2) 
{ 
	return (i1.end < i2.end); 
} 

bool compareInterval1(Interval i1, Interval i2) 
{ 
	return (i1.start < i2.start); 
} 

void printMaxActivities1(Interval s[], int n) 
{ 
	int i, j; 

	cout<<"\nFollowing activities are selected: "; 

	i = n-1; 
	cout<<"\n["<<s[i].start<<","<<s[i].end<<"]"; 
	for (j = n-1; j >=0; j--) 
	{ 
	if (s[i].start >= s[j].end) 
	{ 
		cout<<",\t"<<"["<<s[j].start<<","<<s[j].end<<"]"; 
		i = j; 
	} 
	}
	cout<<"\n"; 
}

void printMaxActivities(Interval s[], int n) 
{ 
	int i, j; 

	cout<<"\nFollowing activities are selected: "; 

	i = 0; 
	cout<<"\n["<<s[i].start<<","<<s[i].end<<"]";
	for (j = 1; j < n; j++) 
	{ 
	if (s[j].start >= s[i].end) 
	{ 
		cout<<",\t"<<"["<<s[j].start<<","<<s[j].end<<"]"; 
		i = j; 
	} 
	}
	cout<<"\n"; 
}

int main() 
{ 
	int n,i,j,k;
	cout<<"\nEnter the no of jobs: ";
	cin>>n;
	Interval arr[n],arr1[n];
	int s[n],f[n];
	for(i=0;i<n;i++)
	{
		cout<<"\nEnter the start time of "<<i<<" job, Finish time of"<<i<<"job(i,j) : ";
		cin>>arr[i].start>>arr[i].end;
		arr1[i].start=arr[i].start;
		arr1[i].end=arr[i].end;
	}
	sort(arr, arr+n, compareInterval);
	sort(arr1, arr1+n, compareInterval1);
	/*for (int i=0; i<n; i++) 
	{	
	cout << "[" << arr[i].start << "," << arr[i].end 
			<< "] ";
	}
	cout<<"\n";*/
	auto start = high_resolution_clock::now(); 
	printMaxActivities(arr, n);
	auto stop = high_resolution_clock::now(); 
	auto duration = duration_cast<microseconds>(stop - start);
					
	/*for (int i=0; i<n; i++) 
	{	
	cout << "[" << arr1[i].start << "," << arr1[i].end 
			<< "] ";
	}
	cout<<"\n";*/
	auto start1 = high_resolution_clock::now(); 
	printMaxActivities1(arr1, n);
	auto stop1 = high_resolution_clock::now(); 
	auto duration1 = duration_cast<microseconds>(stop1 - start1);

	cout << "\nTime taken by class function: "<< duration.count() << " Microseconds" << endl;
	cout << "\nTime taken by Other function: "<< duration1.count() << "Microseconds" << endl;

	return 0; 
}




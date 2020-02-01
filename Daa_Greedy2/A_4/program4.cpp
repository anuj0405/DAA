#include<bits/stdc++.h> 
#include<chrono>

using namespace std::chrono;
using namespace std; 
static int lecture_hall=0;
//bool hall=0;

struct Interval 
{ 
	double start, end; 
}; 

bool compareInterval(Interval i1, Interval i2) 
{ 
	return (i1.start < i2.start); 
} 

void selection(Interval s[], int n,vector <double> a) 
{ 
	int i, j;
	double k; 
	i=0;
	cout<<"\nNo Lecture hall are selected: ";
	k=s[i].end;
	a.push_back(k);
	lecture_hall++; 
	for (j = 1; j < n; j++) 
	{
		for(i=0;i<a.size();i++)
		{ 
			if (s[j].start >= a[i]) 
			{ 
				a[i]=s[i].end;
				break;
			}
			else
			{
				k=s[i].end;
				a.push_back(k);
				lecture_hall++;
				break;
			}
		}
		
	}
		
}

int main() 
{ 
	int n,i,j,k;
	//cout<<"\nEnter the no of lectures Halls: ";
	//cin>>lecture_hall;
	cout<<"\nEnter the no of lectures: ";
	cin>>n;
	vector <double> a;
	//for(k=0;k<lecture_hall;k++)
	//	a[k]=0;	
	Interval arr[n];
	//int s[n],f[n];
	for(i=0;i<n;i++)
	{
		cout<<"\nEnter the start time of "<<i<<" job, Finish time of"<<i<<"job(i,j) : ";
		cin>>arr[i].start>>arr[i].end;
	}
	sort(arr, arr+n, compareInterval);
	/*for (int i=0; i<n; i++) 
	{	
		cout << "[" << arr[i].start << "," << arr[i].end 
			<< "] ";
	}
	cout<<"\n";*/
	auto start = high_resolution_clock::now(); 
	selection(arr, n,a);
	auto stop = high_resolution_clock::now(); 
	auto duration = duration_cast<microseconds>(stop - start);
					
	/*for (int i=0; i<n; i++) 
	{	
		cout << "[" << arr1[i].start << "," << arr1[i].end 
			<< "] ";
	}
	*/
	cout<<"\nNo of lecture hall: "<<lecture_hall;
	cout << "\nTime taken by class function: "<< duration.count() << " Microseconds" << endl;

	return 0; 
}

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
	int i, j,count=0,select=1,temp=0;
	double k;
	Interval array[n]; 
	i=0;

	for (j =0; j < n; j++) 
	{
		if(s[j].start>12 && s[j].end<12)
		{
			array[i].start=s[j].start;
			array[i].end=s[j].end;
			count++;
			i++;
		}
		
	}
	for(i=0;i<count;i++)
	{
		for (j =0; j < n; j++) 
		{
			if((s[j].start)<12 || (s[j].end)>12)
			{
				if(array[i].end<s[j].start && array[i].start>s[j].end)
				{
					select++;				
				}			
			}
		
		}
		if(temp<select)
		{		
			temp=select;
			select=1;
		}
		
	}	
	cout<<"\nNo of class selected: "<<temp;
}

int main() 
{ 
	int n,i,j,k;
	char time;
	cout<<"\nEnter the no of classes: ";
	cin>>n;
	vector <double> a;
	Interval arr[n];
	for(i=0;i<n;i++)
	{
		cout<<"\nEnter the start time of "<<i<<" job, Finish time of"<<i<<"job(i,j) : ";
		cin>>arr[i].start>>arr[i].end;
	}
	//time=arr[i].s_time;
	/*for(i=0;i<n;i++)
	{
		if(arr[i].s_time==time)
		{
			arr[i].start=arr[i].start+12;		
		}
		if(arr[i].e_time==time)
		{
			arr[i].end=arr[i].end+12;		
		}
	}*/
//	sort(arr, arr+n, compareInterval);
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
	cout << "\nTime taken by class function: "<< duration.count() << " Microseconds" << endl;

	return 0; 
}


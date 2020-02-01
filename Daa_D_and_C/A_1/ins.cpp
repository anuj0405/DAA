#include<iostream>
#include<vector>
#include<fstream>
#include <chrono> 
using namespace std::chrono; 
using namespace std;
class sort
{
	public:
		long long int a,ci=0,cm=0,che=0,cib=0;
		long long int count=0,i=0,j=0;
		vector<long long int> v1; 
		int insertion();
};

int sort::insertion()
{
	auto start = high_resolution_clock::now();
	long long int key,swap=0;
	for(i=1;i<count;i++)
	{	
		key=v1[i];
		j=i-1;
			while(j>=0 && v1[j]>key)
			{
				v1[j+1]=v1[j];
				j=j-1;
				swap++;
			}
		v1[j+1]=key;
		
	}
	cout<<"\nNo of swap= "<<swap<<"\n";
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start); 
  	cout << "Time taken by function: "<< duration.count() << " microseconds" << endl;

}


int main()
{
	
	sort s;
	int k=0,ch=0;
    	fstream myfile;
    	/*myfile.open ("sort.txt");

    	for (int j=0; j <15000; j++)
    	{
        	myfile  << (rand() % 10000) ;
        	myfile  << endl;
    	}
    	myfile.close();
	*/

	cout<<"1.Insertition sort worst case: \n";
	cout<<"2.Insertition sort Best  case: \n";
	cout<<"3.Insertition sort Average  case: \n";			
	cout<<"Enter your choice: \n";
	cin>>ch;
	switch(ch)
	{	
			
		case 1:	myfile.open("worst.txt");
			while(myfile>>s.a)
			{
				s.v1.push_back(s.a);
				s.count++;
			} 
			s.insertion();
			myfile.close();
			break;		
		
		case 2:	myfile.open("best.txt");
			while(myfile>>s.a)
			{
				s.v1.push_back(s.a);
				s.count;
			} 
			s.insertion();
			myfile.close();
			break;
		case 3: myfile.open("average.txt");
			while(myfile>>s.a)
			{
				s.v1.push_back(s.a);
				s.count++;
			} 
			s.insertion();
			myfile.close();
			break;
	}	
	
	myfile.open ("sort_file1.txt");
	

	/*for(unsigned long long int i=0;i<s.count;i++)
	{
		myfile<<s.v1[i]<<"\n";
		
	}
	myfile.close(); */


}

#include<iostream>
#include<fstream>

using namespace std;

int main()
{
	long long int j=0,ch=0;
    	fstream myfile;
	cout<<"\nEnter the size of file: ";
	cin>>ch;
    	myfile.open ("worst.txt");

    	for (j=ch; j>0; j--)
    	{
        	myfile  << (j) ;
        	myfile  << endl;
    	}
    	myfile.close();

	myfile.open ("best.txt");

    	for (j=0; j<ch; j++)
    	{
        	myfile  << (j) ;
        	myfile  << endl;
    	}
    	myfile.close();

	myfile.open ("average.txt");

    	for (j=0; j<ch; j++)
    	{
        	myfile  << (rand()%100000) ;
        	myfile  << endl;
    	}
    	myfile.close();


}

#include<iostream>
#include<stdio.h>
#include<chrono>
using namespace std;
using namespace std::chrono;
static int mull=0,mull1=0;
int binaryexp(unsigned long long int base,unsigned long long int power)
{
	auto start = high_resolution_clock::now();
	int q,r;
	unsigned long long int ans=1;
	while(power>0)
	{
		r=power%2;
		power=power/2;
		if(r==1)
		{
			mull++;
			ans=ans*base;
		}
		if(power<1)
		{
			break;
		}
		mull++;
		base=base*base;
	}
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<nanoseconds>(stop - start);
	cout<<"\nAnswer: "<<ans;	
	cout << "\nTime taken by function: "<< duration.count() << " Nenoseconds" << endl;
}

unsigned long long int square_mul(unsigned long long int base,unsigned long long int power)
{
  if(power == 1){ 
    return base;
  }
  else if(power % 2 == 0){ 
	mull1=mull1+1;    
	return square_mul(base*base, power/2);
  }
  else if(power % 2 != 0){ 
	mull1=mull1+2;
    return base* square_mul(base*base, (power-1)/2);
  }
}
int main()
{
	unsigned long long int power,base,choice,ans;
	printf("\nEnter base: ");
	scanf("%lld",&base);
	
	printf("\nEnter power: ");
	scanf("%lld",&power);
	
	auto start = high_resolution_clock::now();
	ans=square_mul(base,power);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<nanoseconds>(stop - start);
	cout<<"\nAnswer: "<<ans;	
	cout<<"\nNo of Multiplication in s&m: "<<mull1<<endl;
	cout << "\nTime taken by Square and multiply function: "<< duration.count() << " Nenoseconds" << endl;		
	
	binaryexp(base,power);

	cout<<"\nNo of Multiplication in B_e: "<<mull<<endl;
	
}

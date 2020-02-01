#include <iostream> 
#include <string> 
#include <vector>
#include<bits/stdc++.h> 
using namespace std; 
vector<string> arr;
void generateGrayarr(int n) 
{ 
	if (n <= 0) 
		return; 

	arr.push_back("0"); 
	arr.push_back("1"); 

	int i, j; 
	for (i = 2; i < (1<<n); i = i<<1) 
	{ 
		for (j = i-1 ; j >= 0 ; j--) 
			arr.push_back(arr[j]); 

		for (j = 0 ; j < i ; j++) 
			arr[j] = "0" + arr[j]; 

		for (j = i ; j < 2*i ; j++) 
			arr[j] = "1" + arr[j]; 
	} 

}
int binaryToDecimal(int n) 
{ 
	int num = n; 
	int dec_value = 0; 

	int base = 1; 

	int temp = num;
	while (temp) { 
		int last_digit = temp % 10; 
		temp = temp / 10; 

		dec_value += last_digit * base; 

		base = base * 2; 
	} 

	return dec_value; 
} 

int main() 
{ 
	int n,i,j,k,f,ans,max;
	string s;
	cout<<"\nEnter the no of flips: ";
	cin>>n;
	cout<<"\nEnter the input: ";
	cin>>f;
	f=binaryToDecimal(f);
	generateGrayarr(n);
	k=pow(2,n)-1;
	int a[k],b[k];
	for(i=0;i<=k;i++)
	{
		s=arr[i];
		j=stoi(s);
		a[i]=j;
	}
	for(i=0;i<=k;i++)
	{
		b[i]=binaryToDecimal(a[i]);
	}
	for(i=0;i<=k;i++)
	{
		if(b[i]==f)
		{
			ans=i;	
		}
		if(k==b[i])
		{
			max=i;	
		}

	}
	if(ans>max)
	{
		ans=k-ans+max;		
	}
	else if(max>=ans)
	{
		ans=max-ans;	
	}
	cout<<"\n"<<ans;
	return 0; 
} 


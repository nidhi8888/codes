#include<bits/stdc++.h>
#define ll long long
using namespace std;

int MatrixChain(int p[],int i,int j)
{
	if(i==j)
	return 0;
	int k;
	int min=INT_MAX;
	int count;
	for(k=i;k<j;k++)
	{
		count=MatrixChain(p,i,k)+MatrixChain(p,k+1,j)+p[i-1]*p[k]*p[j];
		if(count<min)
		min=count;
	}
	return min;
}
int main()
{
	int n,i;
	cout<<"Enter Number Of Matrix: ";
	cin>>n;
	int p[n+1];
	cout<<"Enter Dimenstions:\n";
	for(i=0;i<=n;i++)
	cin>>p[i];
	cout<<"Minimum Number Of Multiplication Needed: ";
	cout<<MatrixChain(p,1,n);
}

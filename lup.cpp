#include <bits/stdc++.h>
using namespace std;

int n;
float a[1000][1000];
float l[1000][1000];
float u[1000][1000];
 
void find(){
	for(int i=0;i<n-1;i++){
		float maxi=-100000000.12;
		int j;
		int index;
		for(j=i;j<n;j++){
			if(maxi<abs(a[j][i])){
				index=j;
				maxi=abs(a[j][i]);
			}
		}
		cout<<"swapping "<<i<<" with"<<index<<" \n";
		for(int k=0;k<=n;k++){
		swap(a[index][k], a[i][k]);
			}
		
		for(int k=i+1;k<n;k++)
			a[k][i]/=a[i][i];
			
		for(int j=i+1;j<n;j++){
			for(int k=i+1;k<n;k++){
				a[j][k] = a[j][k]-a[j][i]*a[i][k];
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<=n;j++)
				cout<<a[i][j]<<" ";
			cout<<endl;
		}
		cout<<endl<<endl;
	}
	
	for(int i=0;i<n;i++){
			for(int j=0;j<i;j++)
				l[i][j]=a[i][j];
			for(int j=i;j<n;j++)
				l[i][j]=0;
			l[i][i]=1;
			for(int j=i;j<n;j++)
				u[i][j]=a[i][j];
			for(int j=0;j<i;j++)
				u[i][j]=0;
	}
	
	cout<<"L Matrix\n";
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			cout<<l[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
	cout<<"U Matrix\n";
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			cout<<u[i][j]<<" ";
		cout<<endl;
	}
	
	float y[n];
	y[0]=a[0][n];
	for(int i=1;i<n;i++){
		float sum=0;
		for(int j=0;j<i;j++)
			sum+=(y[j]*l[i][j]);
		y[i]=a[i][n]-sum;
	}
	cout<<endl;
	for(int i=0;i<n;i++)
		cout<<y[i]<<" ";
		cout<<endl;
	
	float x[n];
	
	for(int i=n-1;i>=0;i--){
		float sum=0;
		for(int j=n-1;j>i;j--)
			sum+=(x[j]*u[i][j]);
		x[i]=(y[i]-sum)/u[i][i];
	}
	for(int i=0;i<n;i++)
		cout<<x[i]<<" ";
	
} 

int main(){
	cout<<"No. of variables\n";
	cin>>n;
	cout<<"ax +by +cz....=d\n";
	for(int i=0;i<n;i++)
		for(int j=0;j<=n;j++)
			cin>>a[i][j];
	
	int p[1][n];
	for(int i=0; i<n;i++)
		p[0][i]=i+1;

	find();		
}

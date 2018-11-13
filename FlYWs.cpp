#include <bits/stdc++.h>
using namespace std;

int n;
int v[101][101];
int par[101][101];

int main(){
cin>>n;
int e;
cin>>e;

for(int i=1;i<=n;i++){
	for(int j=1;j<=n;j++){
		v[i][j]=10000;
		par[i][j]=-1;
		}
}

for(int i=1;i<=n;i++){
	v[i][i]=0;
	par[i][i]=i;
	}
	
for(int i=1;i<=e;i++){
	int a, b, w;
	cin>>a>>b>>w;
	v[a][b]=w;
	par[a][b]=a;
}



for(int k=1;k<=n;k++){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(v[i][j]<10000 || (v[i][k]<10000 && v[k][j]<10000)){
				if(v[i][j]> v[i][k]+v[k][j]){
					par[i][j]=par[k][j];
					v[i][j] = v[i][k]+v[k][j];		
				}
			}
	}
}
}
for(int i=1;i<=n;i++){
	for(int j=1;j<=n;j++)
		cout<<v[i][j]<<"   ";
	cout<<endl;
}

for(int i=1;i<=n;i++){
	for(int j=1;j<=n;j++){
		if(par[i][j]!=-1){
			cout<<"path from "<<i<<" to "<<j<<" : ";
			stack <int> s;
			cout<<"dist = "<<v[i][j]<<"       ";
			int x=j;
			while(x!=i){
				s.push(x);
				int t=par[i][x];
				x=t;
			}
			s.push(i);
			while(!s.empty()){
				cout<<s.top()<<" ";
				s.pop();
			}
			cout<<endl;
		}
	}
}
}

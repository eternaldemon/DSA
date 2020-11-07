#include<bits/stdc++.h>
using namespace std;

int dfs(int i,int j,vector<vector<char>>& a){
	if(a[i][j]=='C')
	return 1;
	else if(i>=0 && i<a.size() && j>=0 && j<a[0].size() && a[i][j]!='C'){
		if(a[i][j]=='R')
		dfs(i,j+1,a);
		else if(a[i][j]=='D')
		dfs(i+1,j,a);
	}
	/*
	if(a[i][j]=='R'&& dfs(i,j,a,count)==0){
		if(dfs(i,j+1,a,count)==1){
		count.insert(make_pair(i,j));	
			}
		}
	if(a[i][j]=='D' && dfs(i,j,a,count)==0){
		if(dfs(i,j+1,a,count)==1){
		count.insert(make_pair(i,j));	
		}
		}*/
		return 0;
	}
	
	
int main(){
	int t;
	cin>>t;
	while(t--){
		 int n,m;
		 cin>>n>>m;
		 int result = 0,count=INT_MAX;
		 vector<vector<char>> a(n,vector<char>(m));
		 //vector<vector<char>> temp(n,vector<char>(m));
		 for(int i=0;i<n;i++){
		 	for(int j=0;j<m;j++){
		 		cin>>a[i][j];
		 		//temp[i][j] = a[i][j];
			 }
		 }
		 for(int i=n-1;i>=0;i--){
		 	for(int j=m-1;j>=0;j--){
		 		if(dfs(i,j,a)==0 && a[i][j]!='C'){
		 			if(a[i][j]=='R')
		 				a[i][j] = 'D';
		 			else
		 				a[i][j] = 'R';
		 			if(dfs(i,j,a)==1)
		 				result++;
		 			count = min(count,result);
		 			cout<<count<<endl;
				}
				else
				continue;
		 		//result = result + dfs(i,j,a);
			 }
		 }
		 cout<<"HEYOOO"<<endl;
		 cout<<count<<endl;
	}
	return 0;
}

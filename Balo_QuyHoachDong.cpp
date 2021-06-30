#include <iostream>
using namespace std;
	int n,w;
	int a[100];
	int c[100];
	int f[100][100];
	int kq[100];
int main (){
	cin >>n>>w;
	for (int i=0; i<n; i++){
		cin >>a[i];
		cin >>c[i];
	}
	for (int v=1; v<=w; v++){
		if (a[0]>v) f[0][v]=0;
		else f[0][v]=c[0];
	}
	for (int k=1; k<n; ++k){
		for (int v=1; v<=w; ++v){
			if (a[k]>v)
				f[k][v] = f[k-1][v];
			else
				f[k][v] = max(f[k-1][v], f[k-1][v - a[k]] + c[k]);
		}
	}
	cout <<f[n-1][w]<<endl;

	int c=w;
	for (int v=w - 1; v>=1; --v){
		if (f[n-1][w]==f[n-1][v]){
			c=v;
		}
	}
	int dem=0;
	for (int k=n - 1; k>=0; --k){
		if (f[k][c]>f[k-1][c]){
			kq[dem++]=k;
			c=c-a[k];
		}
	}
	int tong=0;
	    for (int i=dem - 1; i>=0; i--){
		    cout <<kq[i]+1<<" ";
		    }
	return 0;
}
//input
//5  14  
//2  3 
//4  2 
//3  5 
//4  4 
//3  3 

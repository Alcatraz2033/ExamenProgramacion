#include<iostream>
#include<cmath>
using namespace std;

void combSR(char *datos, int n, int r, int y = 0, int i=0, int *indexs=NULL){
	if(indexs==NULL){
		indexs = new int[r];
	}
	if(i<r){
		for(int x=y; x<n; x++){
			indexs[i]=x;
			combSR(datos,n,r,x+1,i+1,indexs);
		}
	}else{
		cout<<"\n\t";
		for(int w=0; w<r; w++){
			cout<<datos[indexs[w]];
		}
	}
}

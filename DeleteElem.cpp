#include<iostream>
using namespace std;

const int Maxmem = 5;
struct chart{
	int *data;
	int length;
};

void InitL(chart &L,int s){
	L.data = new int[s];
	for(int i=0;i<s;i++){
		L.data[i]=0;
	}
	L.length = 0;
}

bool Insert(chart &L,int i,int n){
	if(L.length==Maxmem) return false;
	for(int j=L.length+1;j>i;j--)
	{
		L.data[j]=L.data[j-1];
	}
	L.data[i]=n;
	L.length++;
	return true;
}

bool DeleteElem(chart &L,int i){
	if(i>L.length||i<0)	return false;
	L.data[i]=L.data[L.length-1];
	L.length--;	
	return true;
}

int main(){
	chart L;
	InitL(L,Maxmem);	
	int i = 0 ,n,min=1<<31-1,index=-1;
	while(i<Maxmem)
	{	
		cin>>n;
		if(n<min){
			min=n;
			index=i;
		}
		if(!Insert(L,i,n)){break;}
		i++;
	}
	if(DeleteElem(L,index)){
		cout<<"successful"<<endl;
		for(int j=0;j<L.length;j++){
			cout<<L.data[j]<<endl;
		}
	}
	else 
		cout<<"fault"<<endl;
	return 0;
}

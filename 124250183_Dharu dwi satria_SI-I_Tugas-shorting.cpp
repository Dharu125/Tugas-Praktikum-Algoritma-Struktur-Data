#include <iostream>
using namespace std;

void bubble(string ary[],int n);
void quick(string array[],int awal,int akhir);
int main(){
	int n=0;
	int menu;
	cout<<"masukkan berapa nama orang: ";cin>>n;
	string ary[n];
	for(int i=0;i<n;i++){
		cout<<"masukkan nama ke "<< i+1<<" : ";cin>>ary[i];
		}
	do{
	cout<<"\n1. shorting ascending bubble short"<<endl;
	cout<<"2. shorting decending quick short"<<endl;
	cout<<"3. keluar"<<endl;
	cout<<"shorting dengan cara apa: ";cin>>menu;
	cout<<"nama sebelum di urutkan"<<endl;
	for(int i=0;i<n;i++){
		cout<<i+1<<". "<<ary[i]<<endl;
		}
	if(menu==1){
		bubble(ary,n);
		}else if(menu==2){
			quick(ary,0,n-1);
			cout<<"\nNama setelah diurutkan: "<<endl;
            for(int i=0;i<n;i++){
                cout<<i+1<<". "<<ary[i]<<endl;
            }
			}else if(menu==3){
				cout<<"Sekian terima gaji";
				}else{
					cout<<"input eror"<<endl;
					}
	}while(menu!=3);
	}
void bubble(string ary[],int n){
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-1-i;j++){
			if(ary[j]>ary[j+1]){
			string temp=ary[j+1];
            ary[j+1]=ary[j];
            ary[j]=temp;
				}
			}
		}
	cout<<"\nnama setelah di urutkan"<<endl;
	for(int i=0;i<n;i++){
		cout<<i+1<<". "<<ary[i]<<endl;
		}
	}
void quick(string array[],int awal,int akhir){
    int low=awal,high=akhir;
    string pivot=array[(awal+akhir)/2];
    do{
        while(array[low]>pivot)
            low++;
        while(array[high]<pivot)
            high--;
        if(low<=high){
            swap(array[low],array[high]);
            low++;
            high--;
        }
    }while(low<=high);
    if(awal<high){
        quick(array,awal,high);
	}
    if(low<akhir){
        quick(array,low,akhir);
	}
	}

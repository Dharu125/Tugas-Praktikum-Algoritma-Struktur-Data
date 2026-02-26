#include <iostream>
using namespace std;

void binare();
void sekuensial();
void nonsekuensial();
struct toko{
	string nama;
	int harga;
	};
	toko buku[6];
	bool found;
	int cari;
int main(){
	buku[0].nama="teras";
	buku[0].harga=50000;
	
	buku[1].nama="seporsi";
	buku[1].harga=60000;
	
	buku[2].nama="how";
	buku[2].harga=70000;
	
	buku[3].nama="investasi";
	buku[3].harga=80000;
	
	buku[4].nama="patualangan";
	buku[4].harga=100000;
	
	buku[5].nama="null";
	buku[5].harga=0;	
	int metode;
	do{
	cout<<"silahkan cari buku"<<endl;
	cout<<"1. metode pencarian biner"<<endl;
	cout<<"2. metode pencarian sekuensial"<<endl;
	cout<<"3. keluar"<<endl;
	cout<<"metode: ";cin>>metode;
	if(metode==1){
		binare();
		}else if(metode==2){
			sekuensial();
			}else if(metode>3){
				cout<<"input tidak valid"<<endl;
				}
	}while(metode!=3);
	cout<<"Terima kasih:)";
		

	}
void binare(){
	int i=0,j=4,k;
	cout<<"silahkan cari harga buku: ";cin>>cari;
	found=false;
	while(found==false&&i<=j){
		k=(i+j)/2;
		if(cari==buku[k].harga){
			found=true;
			}else if(cari<buku[k].harga){
				j=k-1;
				}else{
					i=k+1;
					}
		}
	if(found){
		cout<<"buku dengan harga: "<<cari<<" berjudul "<<buku[k].nama<<endl;
		}else{
			cout<<"buku tidak ditemukan di harga tersebut"<<endl;
			}
	}
void sekuensial(){
	found=false;
	int metode1,i=0;
	do{
	cout<<"1. dengan sentinel"<<endl;
	cout<<"2. tanpa sentinel"<<endl;
	cout<<"3. kembali"<<endl;
	cout<<"silahkan pilih: ";cin>>metode1;
	if(metode1==2){
		cout<<"cari buku dengan harga: ";cin>>cari;
		found=false;
		i=0;
		while(i<5&&found==false){
				if(buku[i].harga==cari){
					found=true;
					}else{
						i++;
						}
				}
		if(found){
			cout<<"buku dengan harga: "<<cari<<" berjudul "<<buku[i].nama<<endl;
			}else{
				cout<<"buku tidak ditemukan di harga tersebut"<<endl;
				}
				
			}else if(metode1==3){
				return;
				}else if(metode1==1){
					cout<<"cari buku dengan harga: ";cin>>cari;
					buku[5].harga=cari;
					i=0;
					while(buku[i].harga!=cari){
						i++;
					}
						if(i<5){
							cout<<"buku dengan harga: "<<cari<<" berjudul "<<buku[i].nama<<endl;
							}else{
								cout<<"buku dengan harga "<<cari<<" tidak di temukan"<<endl;
								}
					}else{
						cout<<"input tidak valid"<<endl;
						}
			
	}while(metode1!=3);
	}

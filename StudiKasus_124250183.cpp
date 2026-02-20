#include <iostream>
using namespace std;

int main(){
	//deklarasi
	int n;
    cout << "masukkan jumlah array: "; cin >> n;
    int arr[n];
    int *ptr = arr;
	//masukkan isi array
    cout << "masukkan nilai array:\n";
    for (int i = 0; i < n; i++) {
        cin >> *(ptr + i);
    }
	//menampilkan isi array
    cout << "\nisi array: ";
    for (int i = 0; i < n; i++) {
        cout << *(ptr + i) << " ";
    }

    //menampilkan isi minimal, maksimal, jumlah dan rata rata
    int max = *ptr;
    int min = *ptr;
    int jumlah = 0;

    
    for (int i = 0; i < n; i++) {
        if (*(ptr + i) > max) {
            max = *(ptr + i);
        }
        if (*(ptr + i) < min) {
            min = *(ptr + i);
        }
        jumlah += *(ptr + i);
    }

    float rata = (float)jumlah / n;

    //hasil
    cout << "\nnilai maksimum = " << max <<endl;
    cout << "nilai minimum = " << min << endl;
    cout << "jumlah = " << jumlah << endl;
    cout << "rata-rata = " << rata << endl;
}

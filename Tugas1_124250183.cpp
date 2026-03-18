#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

struct Produk {
    char nama[50];
    float harga;
    char kategori[30];
    int stok;
};
Produk arr[100];
int n = 0;
void loadFile() {
    FILE *file = fopen("lelele.csv", "r");
    if (!file) return;
    n = 0;
    while (fscanf(file, " %[^,],%f,%[^,],%d\n",
                  arr[n].nama,
                  &arr[n].harga,
                  arr[n].kategori,
                  &arr[n].stok) != EOF) {
        n++;
    }
    fclose(file);
}
void saveFile() {
    FILE *file = fopen("lelele.csv", "w");
    for (int i = 0; i < n; i++) {
        fprintf(file, "%s,%.1f,%s,%d\n",
                arr[i].nama,
                arr[i].harga,
                arr[i].kategori,
                arr[i].stok);
    }
    fclose(file);
}
void tambahProduk() {
    cout << "\n=== Tambah Produk ===\n";
    cin.ignore();
    cout << "Nama: ";
    cin.getline(arr[n].nama, 50);
    cout << "Harga: ";
    cin >> arr[n].harga;
    do {
        cout << "Kategori (makanan/minuman): ";
        cin >> arr[n].kategori;
    } while (strcmp(arr[n].kategori, "makanan") != 0 &&
             strcmp(arr[n].kategori, "minuman") != 0);
    cout << "Stok: ";
    cin >> arr[n].stok;
    n++;
    saveFile();
    cout << "Data berhasil ditambahkan!\n";
}
void tampil() {
    cout << "\n=== Data Produk ===\n";
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". "
             << arr[i].nama << " | "
             << arr[i].harga << " | "
             << arr[i].kategori << " | "
             << arr[i].stok << endl;
    }
}
void bubbleSort() {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(arr[j].nama, arr[j + 1].nama) > 0) {
                Produk temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void quickSort(int low, int high) {
    int i = low, j = high;
    float pivot = arr[(low + high) / 2].harga;
    while (i <= j) {
        while (arr[i].harga > pivot) i++;
        while (arr[j].harga < pivot) j--;
        if (i <= j) {
            Produk temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    if (low < j) quickSort(low, j);
    if (i < high) quickSort(i, high);
}
void sequentialSearch() {
    char cari[50];
    bool found = false;
    cin.ignore();
    cout << "Masukkan nama produk: ";
    cin.getline(cari, 50);
    for (int i = 0; i < n; i++) {
        if (strcmp(arr[i].nama, cari) == 0) {
            cout << "Ditemukan:\n";
            cout << arr[i].nama << " | "
                 << arr[i].harga << " | "
                 << arr[i].kategori << " | "
                 << arr[i].stok << endl;
            found = true;
        }
    }
    if (!found) cout << "Produk tidak ditemukan!\n";
}
void binarySearch() {
    char cari[50];
    cin.ignore();
    cout << "Masukkan nama produk: ";
    cin.getline(cari, 50);
    bubbleSort();
    int kiri = 0, kanan = n - 1;
    bool found = false;
    while (kiri <= kanan) {
        int mid = (kiri + kanan) / 2;
        int cmp = strcmp(arr[mid].nama, cari);
        if (cmp == 0) {
            cout << "Ditemukan:\n";
            cout << arr[mid].nama << " | "
                 << arr[mid].harga << " | "
                 << arr[mid].kategori << " | "
                 << arr[mid].stok << endl;
            found = true;
            break;
        } else if (cmp < 0) {
            kiri = mid + 1;
        } else {
            kanan = mid - 1;
        }
    }
    if (!found) cout << "Produk tidak ditemukan!\n";
}
void menu() {
    int pilih;
    do {
        cout << "\n=== MENU ===\n";
        cout << "1. Tambah Produk\n";
        cout << "2. Tampilkan Produk\n";
        cout << "3. Sorting\n";
        cout << "4. Searching\n";
        cout << "5. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;
        switch (pilih) {
            case 1:
                tambahProduk();
                break;
            case 2:
                tampil();
                break;
            case 3: {
                int p;
                cout << "1. Bubble Sort (Nama Asc)\n";
                cout << "2. Quick Sort (Harga Desc)\n";
                cout << "Pilih: ";
                cin >> p;
                if (p == 1) bubbleSort();
                else if (p == 2) quickSort(0, n - 1);
                tampil();
                break;
            }
            case 4: {
                int p;
                cout << "1. Sequential Search\n";
                cout << "2. Binary Search\n";
                cout << "Pilih: ";
                cin >> p;
                if (p == 1) sequentialSearch();
                else if (p == 2) binarySearch();
                break;
            }
        }
    } while (pilih != 5);
}
int main() {
    loadFile();
    menu();
    return 0;
}

#include <iostream>
using namespace std;
#define MAX_BUAH 100 // Ukuran maksimum array buah
int main() {
int panjang = 0; // Jumlah elemen saat ini
string buah[MAX_BUAH]; // Array dengan ukuran tetap
int pilihan, index;
do {
system("clear");
cout << "Menu Program" << endl;
cout << "1. Tampilkan Buah" << endl;
cout << "2. Tambah Buah" << endl;
cout << "3. Ubah Buah" << endl;
cout << "4. Hapus Buah" << endl;
cout << "5. Keluar" << endl;
cout << "Pilihan: ";
cin >> pilihan;
switch (pilihan) {
case 1:
if (panjang == 0) {
    cout << "Belum ada buah" << endl;
    } else {
    for (int i = 0; i < panjang; i++) {
    cout << "Buah ke-" << i + 1 << ": " << buah[i] << endl;
    }
    }
break;
case 2:
if (panjang < MAX_BUAH) {
    cout << "Masukkan nama buah: ";
    cin.ignore();
    getline(cin, buah[panjang]);
    panjang++;
    cout << "Buah berhasil ditambahkan" << endl;
    } else {
    cout << "Kapasitas penuh! Tidak bisa menambah buah lagi." << endl;
    }
break;
case 3:
if (panjang == 0) {
    cout << "Belum ada buah untuk diubah." << endl;
    } else {
    for (int i = 0; i < panjang; i++) {
    cout << "Buah ke-" << i + 1 << ": " << buah[i] << endl;
    }
    cout << "Masukkan nomor buah yang akan diubah: ";
    cin >> index;
    if (index > 0 && index <= panjang) {
    cout << "Masukkan nama buah baru: ";
    cin.ignore();
    getline(cin, buah[index - 1]);
    cout << "Buah berhasil diubah" << endl;
    } else {
    cout << "Nomor buah tidak valid" << endl;
    }
    }
break;
case 4:
if (panjang == 0) {
    cout << "Belum ada buah untuk dihapus." << endl;
    } else {
    for (int i = 0; i < panjang; i++) {
    cout << "Buah ke-" << i + 1 << ": " << buah[i] << endl;
    }
    cout << "Masukkan nomor buah yang akan dihapus: ";
    cin >> index;
    if (index > 0 && index <= panjang) {
    for (int i = index - 1; i < panjang - 1; i++) {
    buah[i] = buah[i + 1]; // Ngegeser elemen ke kiri kek nimpa jadinya
    }
    panjang--;
    cout << "Buah berhasil dihapus" << endl;
    } else {
    cout << "Nomor buah tidak valid" << endl;
    }
    }
break;
case 5:
cout << "Program selesai" << endl;
break;
default:
cout << "Pilihan tidak valid" << endl;
break;
}
} while (pilihan != 5);
return 0;
}
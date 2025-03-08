#include <iostream>
using namespace std;

int main() {
    while (true) {
        cout << "\nMenu\n";
        cout << "1. Perkalian\n";
        cout << "2. Pembagian\n";
        cout << "3. Penjumlahan\n";
        cout << "4. Pengurangan\n";
        cout << "5. Keluar\n";
        
        string pilihan;
        cout << "Masukan Pilihan : ";
        cin >> pilihan;

        if (pilihan == "1") {
            float angka1, angka2, hasil;
            cout << "Masukan Angka Pertama : ";
            cin >> angka1;
            cout << "Masukan Angka Kedua : ";
            cin >> angka2;
            hasil = angka1 * angka2;
            cout << "Hasilnya Adalah " << hasil << "\n";
        }   
        
        else if (pilihan == "2") {
            float angka1, angka2, hasil;
            cout << "Masukan Angka Pertama : ";
            cin >> angka1;
            cout << "Masukan Angka Kedua : ";
            cin >> angka2;
            if (angka2 != 0) {
                hasil = angka1 / angka2;
                cout << "Hasilnya Adalah " << hasil << "\n";
            } else {
                cout << "Tidak Bisa Dibagi 0\n";
            }
        }   
        
        else if (pilihan == "3") {
            float angka1, angka2, hasil;
            cout << "Masukan Angka Pertama : ";
            cin >> angka1;
            cout << "Masukan Angka Kedua : ";
            cin >> angka2;
            hasil = angka1 + angka2;
            cout << "Hasilnya Adalah " << hasil << "\n";
        }   
        
        else if (pilihan == "4") {
            float angka1, angka2, hasil;
            cout << "Masukan Angka Pertama : ";
            cin >> angka1;
            cout << "Masukan Angka Kedua : ";
            cin >> angka2;
            hasil = angka1 - angka2;
            cout << "Hasilnya Adalah " << hasil << "\n";
        }   
        
        else if (pilihan == "5") {
            break;
        }

        else {
            cout << "Invalid Input\n";
        }
    }
    return 0;
}
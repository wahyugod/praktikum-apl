#include <iostream>
using namespace std;

int main() {
    string username, password;
    string pilih, pilihan;
    int login_attempts = 0;
    bool login_success = false;

    while (true) {
        cout << "\n==============================" << endl;
        cout << "| KONVERSI SATUAN LOGIN MENU |" << endl;
        cout << "==============================" << endl;
        cout << "| 1. Login                   |" << endl;
        cout << "| 2. Keluar                  |" << endl;
        cout << "==============================" << endl;
        cout << "Masukan Pilihan: ";
        cin >> pilih;

        if (pilih == "1") {
            while (login_attempts < 3) {
                cout << "\nMasukan Username: ";
                cin >> username;
                cout << "Masukan Password: ";
                cin >> password;

                if (username == "zeydanfazlemawla" && password == "2409106010") {
                    login_success = true;
                    break;
                } else {
                    cout << "Username atau Password salah! Percobaan ke-" << login_attempts + 1 << " dari 3\n";
                    login_attempts++;
                }
            }

            if (!login_success) {
                cout << "Kamu gagal login 3 kali. Program berhenti." << endl;
                return 0;
            }

            while (true) {
                cout << "\n=================================================" << endl;
                cout << "|           KONVERSI SATUAN MAIN MENU           |" << endl;
                cout << "=================================================" << endl;
                cout << "| 1. Konversi Meter ke (Centimeter, Mile, Foot) |" << endl;
                cout << "| 2. Konversi Centimeter ke (Meter, Mile, Foot) |" << endl;
                cout << "| 3. Konversi Mile ke (Meter, Centimeter, Foot) |" << endl;
                cout << "| 4. Konversi Foot ke (Meter, Centimeter, Mile) |" << endl;
                cout << "| 5. Logout                                     |" << endl;
                cout << "=================================================" << endl;
                cout << "Masukan Pilihan: ";
                cin >> pilihan;
                cout << endl;

                if (pilihan == "1") {
                    double angka;
                    cout << "Masukan nilai (m): ";
                    cin >> angka;
                    cout << angka << " m sama dengan:" << endl;
                    cout << angka * 100 << " cm" << endl;
                    cout << angka * 0.000621371 << " mile" << endl;
                    cout << angka * 3.28084 << " foot" << endl;
                } else if (pilihan == "2") {
                    double angka;
                    cout << "Masukan nilai (cm): ";
                    cin >> angka;
                    cout << angka << " cm sama dengan:" << endl;
                    cout << angka / 100 << " m" << endl;
                    cout << angka * 0.00000621371 << " mile" << endl;
                    cout << angka * 0.0328084 << " foot" << endl;
                } else if (pilihan == "3") {
                    double angka;
                    cout << "Masukan nilai (mile): ";
                    cin >> angka;
                    cout << angka << " mile sama dengan:" << endl;
                    cout << angka * 1609.34 << " m" << endl;
                    cout << angka * 160934 << " cm" << endl;
                    cout << angka * 5280 << " foot" << endl;
                } else if (pilihan == "4") {
                    double angka;
                    cout << "Masukan nilai (foot): ";
                    cin >> angka;
                    cout << angka << " foot sama dengan:" << endl;
                    cout << angka * 0.3048 << " m" << endl;
                    cout << angka * 30.48 << " cm" << endl;
                    cout << angka * 0.000189394 << " mile" << endl;
                } else if (pilihan == "5") {
                    break;
                } else {
                    cout << "Pilihan tidak valid!" << endl;
                }
            }
        } else if (pilih == "2") {
            cout << "Program selesai." << endl;
            break;
        } else {
            cout << "Pilihan tidak valid!" << endl;
        }
    }
    return 0;
}
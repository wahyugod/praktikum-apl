#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX_AKUN = 100;
const int MAX_PRODUK = 100;

struct Akun {
    string username = {"zeydanfazlemawla"};
    string password = {"2409106010"};
};

struct NamaProduk {
    string merek;
    string nama;
};

struct ProdukLaptop {
    int id;
    NamaProduk namaProduk;
    int harga;
};

ProdukLaptop daftarProduk[MAX_PRODUK];
Akun daftarAkun[MAX_AKUN];
int jumlahProduk = 0;
int jumlahAkun = 1;

int main() {
    string username, password;
    string pilih, pilihan;
    int login_attempts = 0;
    bool login_success = false;

    while (true) {
        cout << "\n===============================\n";
        cout << "|   MANAJEMEN PRODUK LAPTOP   |\n";
        cout << "===============================\n";
        cout << "| 1. Login                    |\n";
        cout << "| 2. Register                 |\n";
        cout << "| 3. Keluar                   |\n";
        cout << "===============================\n";
        cout << "Masukkan Pilihan: ";
        cin >> pilih;
        cin.ignore();

        if (pilih == "1") {
            int login_attempts = 0;
            while (login_attempts < 3) {
                cout << "\n===================================";
                cout << "\n|              LOGIN              |";
                cout << "\n===================================";
                cout << "\nMasukkan Username: ";
                cin >> username;
                cout << "Masukkan Password: ";
                cin >> password;
                
                bool found = false;
                for (int i = 0; i < jumlahAkun; i++) {
                    if (daftarAkun[i].username == username && daftarAkun[i].password == password) {
                        found = true;
                        break;
                    }
                }
                
                if (found) {
                    login_success = true;
                    cout << "Login Berhasil.\n";
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


            while (login_success) {
                cout << "\n=======================================\n";
                cout << "|  MANAJEMEN PRODUK LAPTOP MAIN MENU  |\n";
                cout << "=======================================\n";
                cout << "| 1. Tambah Laptop                    |\n";
                cout << "| 2. Lihat Laptop                     |\n";
                cout << "| 3. Ubah Laptop                      |\n";
                cout << "| 4. Hapus Laptop                     |\n";
                cout << "| 5. Logout                           |\n";
                cout << "=======================================\n";
                cout << "Masukkan Pilihan: ";
                cin >> pilihan;
                cin.ignore();

                if (pilihan == "1") {
                    if (jumlahProduk >= MAX_PRODUK) {
                        cout << "Data penuh! Tidak bisa menambahkan produk lagi." << endl;
                    } else {
                        int idBaru;
                        cout << "Masukkan ID Produk: ";
                        cin >> idBaru;
                        cin.ignore();
                        
                        bool idExists = false;
                        for (int i = 0; i < jumlahProduk; i++) {
                            if (daftarProduk[i].id == idBaru) {
                                cout << "ID Produk sudah ada! Gunakan ID lain." << endl;
                                idExists = true;
                                break;
                            }
                        }
                        if (!idExists) {
                            daftarProduk[jumlahProduk].id = idBaru;
                            cout << "Masukkan Merek Produk: ";
                            getline(cin, daftarProduk[jumlahProduk].namaProduk.merek);
                            cout << "Masukkan Nama Produk: ";
                            getline(cin, daftarProduk[jumlahProduk].namaProduk.nama);
                            cout << "Masukkan Harga Produk: ";
                            cin >> daftarProduk[jumlahProduk].harga;
                            cin.ignore();
                            jumlahProduk++;
                            cout << "Produk berhasil ditambahkan!\n";
                        }
                    }
                } 
                else if (pilihan == "2") {
                    if (jumlahProduk == 0) {
                        cout << "Tidak ada produk.\n";
                    } else {
                        cout << "\nDaftar Produk:\n";
                        cout << left << setw(10) << "ID" << setw(20) << "Merek" << setw(25) << "Nama" << setw(15) << "Harga" << endl;
                        cout << "--------------------------------------------------------------------\n";
                        for (int i = 0; i < jumlahProduk; i++) {
                            cout << left << setw(10) << daftarProduk[i].id << setw(20) << daftarProduk[i].namaProduk.merek << setw(25) << daftarProduk[i].namaProduk.nama << "Rp " << daftarProduk[i].harga << endl;
                        }
                    }
                } 
                else if (pilihan == "3") {
                    if (jumlahProduk == 0) {
                        cout << "Tidak ada produk yang dapat diubah!\n";
                    } else {
                        cout << "\nDaftar Produk:\n";
                        cout << left << setw(10) << "ID" << setw(20) << "Merek" << setw(25) << "Nama" << setw(15) << "Harga" << endl;
                        cout << "--------------------------------------------------------------------\n";
                        for (int i = 0; i < jumlahProduk; i++) {
                            cout << left << setw(10) << daftarProduk[i].id << setw(20) << daftarProduk[i].namaProduk.merek << setw(25) << daftarProduk[i].namaProduk.nama << "Rp " << daftarProduk[i].harga << endl;
                        }
                        int id, index = -1;
                        cout << "\nMasukkan ID produk yang ingin diubah: ";
                        cin >> id;
                        cin.ignore();
                        
                        for (int i = 0; i < jumlahProduk; i++) {
                            if (daftarProduk[i].id == id) {
                                index = i;
                                break;
                            }
                        }
                        if (index != -1) {
                            int idBaru;
                            cout << "Masukkan ID baru: ";
                            cin >> idBaru;

                            bool idSudahAda = false;
                            for (int i = 0; i < jumlahProduk; i++) {
                                if (daftarProduk[i].id == idBaru && i != index) {
                                    cout << "ID baru sudah digunakan oleh produk lain!\n";
                                    idSudahAda = true;
                                    break;
                                }
                            }

                            if (!idSudahAda) {
                                daftarProduk[index].id = idBaru;
                                cin.ignore();
                                cout << "Masukkan Merek baru: ";
                                getline(cin, daftarProduk[index].namaProduk.merek);
                                cout << "Masukkan Nama baru: ";
                                getline(cin, daftarProduk[index].namaProduk.nama);
                                cout << "Masukkan Harga baru: ";
                                cin >> daftarProduk[index].harga;
                                cin.ignore();
                                cout << "Produk berhasil diperbarui!\n";
                            }
                        } else {
                            cout << "Produk tidak ditemukan!\n";
                        }
                    }
                } 
                else if (pilihan == "4") {
                    if (jumlahProduk == 0) {
                        cout << "Tidak ada produk yang dapat dihapus!\n";
                    } else {
                        cout << "\nDaftar Produk:\n";
                        cout << left << setw(10) << "ID" << setw(20) << "Merek" << setw(25) << "Nama" << setw(15) << "Harga" << endl;
                        cout << "--------------------------------------------------------------------\n";
                        for (int i = 0; i < jumlahProduk; i++) {
                            cout << left << setw(10) << daftarProduk[i].id << setw(20) << daftarProduk[i].namaProduk.merek << setw(25) << daftarProduk[i].namaProduk.nama << "Rp " << daftarProduk[i].harga << endl;
                        }
                
                        int id, index = -1;
                        cout << "\nMasukkan ID produk yang ingin dihapus: ";
                        cin >> id;
                        cin.ignore();
                
                        for (int i = 0; i < jumlahProduk; i++) {
                            if (daftarProduk[i].id == id) {
                                index = i;
                                break;
                            }
                        }
                
                        if (index != -1) {
                            for (int i = index; i < jumlahProduk - 1; i++) {
                                daftarProduk[i] = daftarProduk[i + 1];
                            }
                
                            jumlahProduk--;
                            cout << "Produk berhasil dihapus!\n";
                        } else {
                            cout << "Produk tidak ditemukan!\n";
                        }
                    }
                }                
                else if (pilihan == "5") {
                    login_success = false;
                } else {
                    cout << "Pilihan tidak valid!\n";
                }
            }
        } else if (pilih == "2") {
            string userBaru;
            if (jumlahAkun >= MAX_AKUN) {
                cout << "Jumlah akun maksimal telah tercapai!" << endl;
            } else {
                cout << "\n===================================";
                cout << "\n|             REGISTER            |";
                cout << "\n===================================";
                cout << "\nMasukkan Username: ";
                cin >> userBaru;
                bool userExists = false;
                for (int i = 0; i < jumlahAkun; i++) {
                    if (daftarAkun[i].username == userBaru) {
                        cout << "Username sudah ada! Gunakan user lain." << endl;
                        userExists = true;
                        break;
                    }
                }
                if (!userExists) {
                    daftarAkun[jumlahAkun].username = userBaru;
                    cout << "Masukkan Password: ";
                    cin >> daftarAkun[jumlahAkun].password;
                    jumlahAkun++;
                    cout << "Akun berhasil didaftarkan!" << endl;
                }
            }
        } else if (pilih == "3") {
            cout << "Program selesai." << endl;
            break;
        } else {
            cout << "Pilihan tidak valid!" << endl;
        }
    }
    return 0;
}
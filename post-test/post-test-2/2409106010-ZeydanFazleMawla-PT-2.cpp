#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX_PRODUK = 100;
int idProduk[MAX_PRODUK];
string namaProduk[MAX_PRODUK][2];
int hargaProduk[MAX_PRODUK];
int jumlahProduk = 0;

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
        cout << "| 2. Keluar                   |\n";
        cout << "===============================\n";
        cout << "Masukkan Pilihan: ";
        cin >> pilih;
        cin.ignore();

        if (pilih == "1") {
            while (login_attempts < 3) {
                cout << "\n===================================";
                cout << "\n|              LOGIN              |";
                cout << "\n===================================";
                cout << "\nMasukkan Username: ";
                cin >> username;
                cout << "Masukkan Password: ";
                cin >> password;

                if (username == "zeydanfazlemawla" && password == "2409106010") {
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
                            if (idProduk[i] == idBaru) {
                                cout << "ID Produk sudah ada! Gunakan ID lain." << endl;
                                idExists = true;
                            }
                        }
                        if (!idExists) {
                            idProduk[jumlahProduk] = idBaru;
                            cout << "Masukkan Merek Produk: ";
                            getline(cin, namaProduk[jumlahProduk][0]);
                            cout << "Masukkan Nama Produk: ";
                            getline(cin, namaProduk[jumlahProduk][1]);
                            cout << "Masukkan Harga Produk: ";
                            cin >> hargaProduk[jumlahProduk];
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
                            cout << left << setw(10) << idProduk[i] << setw(20) << namaProduk[i][0] << setw(25) << namaProduk[i][1] << "Rp " << hargaProduk[i] << endl;
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
                            cout << left << setw(10) << idProduk[i] << setw(20) << namaProduk[i][0] << setw(25) << namaProduk[i][1] << "Rp " << hargaProduk[i] << endl;
                        }
                        int id, index = -1;
                        cout << "\nMasukkan ID produk yang ingin diubah: ";
                        cin >> id;
                        cin.ignore();
                        
                        for (int i = 0; i < jumlahProduk; i++) {
                            if (idProduk[i] == id) {
                                index = i;
                            }
                        }
                        if (index != -1) {
                            int idBaru;
                            cout << "Masukkan ID baru: ";
                            cin >> idBaru;

                            bool idSudahAda = false;
                            for (int i = 0; i < jumlahProduk; i++) {
                                if (idProduk[i] == idBaru && i != index) {
                                    cout << "ID baru sudah digunakan oleh produk lain!\n";
                                    idSudahAda = true;
                                    break;
                                }
                            }

                            if (!idSudahAda) {
                                idProduk[index] = idBaru;
                                cin.ignore();
                                cout << "Masukkan Merek baru: ";
                                getline(cin, namaProduk[index][0]);
                                cout << "Masukkan Nama baru: ";
                                getline(cin, namaProduk[index][1]);
                                cout << "Masukkan Harga baru: ";
                                cin >> hargaProduk[index];
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
                            cout << left << setw(10) << idProduk[i] << setw(20) << namaProduk[i][0] << setw(25) << namaProduk[i][1] << "Rp " << hargaProduk[i] << endl;
                        }
                
                        int id, index = -1;
                        cout << "\nMasukkan ID produk yang ingin dihapus: ";
                        cin >> id;
                        cin.ignore();
                
                        for (int i = 0; i < jumlahProduk; i++) {
                            if (idProduk[i] == id) {
                                index = i;
                                break;
                            }
                        }
                
                        if (index != -1) {
                            for (int i = index; i < jumlahProduk - 1; i++) {
                                idProduk[i] = idProduk[i + 1];
                                namaProduk[i][0] = namaProduk[i + 1][0];
                                namaProduk[i][1] = namaProduk[i + 1][1];
                                hargaProduk[i] = hargaProduk[i + 1];
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
            cout << "Program selesai." << endl;
            break;
        } else {
            cout << "Pilihan tidak valid!" << endl;
        }
    }
    return 0;
}
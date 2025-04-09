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
bool loginFailed = false;

void clear();
void menuLogin();
void menuUtama();
void login();
void registerAkun();
bool idExists(int id);
void tambahLaptop();
bool tambahLaptop(int id, int harga);
bool tambahLaptop(string merek, string nama);
bool lihatLaptop(int index = 0);
void ubahLaptop();
void hapusLaptop();

int main() {
    clear();
    string pilih;
    while (true) {
        menuLogin();
        cin >> pilih;
        cin.ignore();
        if (pilih == "1") {
            login();
            if (loginFailed) break;
        } else if (pilih == "2") {
            registerAkun();
        } else if (pilih == "3") {
            cout << "Program selesai." << endl;
            break;
        } else {
            cout << "Pilihan tidak valid!" << endl;
        }
    }
    return 0;
}

void clear() {
    system("cls");
}

void menuLogin () {
    cout << "\n===============================\n";
    cout << "|   MANAJEMEN PRODUK LAPTOP   |\n";
    cout << "===============================\n";
    cout << "| 1. Login                    |\n";
    cout << "| 2. Register                 |\n";
    cout << "| 3. Keluar                   |\n";
    cout << "===============================\n";
    cout << "Masukkan Pilihan: ";
}

void menuUtama() {
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
}

void login() {
    clear();
    string username, password;
    int login_attempts = 0;
    bool login_success = false;

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
        loginFailed = true;
        return;
    }

    string pilihan;
    while (login_success) {
        menuUtama();
        cin >> pilihan;
        cin.ignore();
        clear();

        if (pilihan == "1") {
            tambahLaptop();
        } else if (pilihan == "2") {
            lihatLaptop();
        } else if (pilihan == "3") {
            ubahLaptop();
        } else if (pilihan == "4") {
            hapusLaptop();
        } else if (pilihan == "5") {
            login_success = false;
        } else {
            cout << "Pilihan tidak valid!\n";
        }
    }
}

void registerAkun() {
    clear();
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
}

bool idExists(int id) {
    for (int i = 0; i < jumlahProduk; i++) {
        if (daftarProduk[i].id == id) {
            return true;
        }
    }
    return false;
}

void tambahLaptop() {
    if (jumlahProduk >= MAX_PRODUK) {
        cout << "Data penuh! Tidak bisa menambahkan produk lagi." << endl;
        return;
    }

    int id, harga;
    string merek, nama;

    cout << "Masukkan ID Produk: ";
    cin >> id;
    if (idExists(id)) {
        cout << "ID sudah digunakan! Gunakan ID lain.\n";
        return;
    }

    cout << "Masukkan Harga Produk: ";
    cin >> harga;
    cin.ignore();

    cout << "Masukkan Merek Produk: ";
    getline(cin, merek);
    cout << "Masukkan Nama Produk: ";
    getline(cin, nama);

    if (tambahLaptop(id, harga) && tambahLaptop(merek, nama)) {
        cout << "Produk berhasil ditambahkan!\n";
    } else {
        cout << "Gagal menambahkan produk.\n";
    }
}

bool tambahLaptop(int id, int harga) {
    if (jumlahProduk >= MAX_PRODUK) return false;
    daftarProduk[jumlahProduk].id = id;
    daftarProduk[jumlahProduk].harga = harga;
    return true;
}

bool tambahLaptop(string merek, string nama) {
    if (jumlahProduk >= MAX_PRODUK) return false;
    daftarProduk[jumlahProduk].namaProduk.merek = merek;
    daftarProduk[jumlahProduk].namaProduk.nama = nama;
    jumlahProduk++;
    return true;
}

bool lihatLaptop(int index) {
    if (jumlahProduk == 0) {
        cout << "Tidak ada produk.\n";
        return false;
    }

    if (index == 0) {
        cout << "\nDaftar Produk:\n";
        cout << left << setw(10) << "ID"
             << setw(20) << "Merek"
             << setw(25) << "Nama"
             << setw(15) << "Harga" << endl;
        cout << "--------------------------------------------------------------------\n";
    }

    if (index >= jumlahProduk) {
        return true;
    }

    cout << left << setw(10) << daftarProduk[index].id
         << setw(20) << daftarProduk[index].namaProduk.merek
         << setw(25) << daftarProduk[index].namaProduk.nama
         << "Rp " << daftarProduk[index].harga << endl;

    return lihatLaptop(index + 1);
}

void ubahLaptop() {
    if (jumlahProduk == 0) {
        cout << "Tidak ada produk yang dapat diubah!\n";
    } else {
        lihatLaptop();
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

void hapusLaptop() {
    if (jumlahProduk == 0) {
        cout << "Tidak ada produk yang dapat dihapus!\n";
    } else {
        lihatLaptop();
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
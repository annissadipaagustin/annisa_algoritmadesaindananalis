#include <iostream>
using namespace std;

class Kontak {
private:
    string nama;
    string noTelepon;

public:
    // Constructor
    Kontak(string n, string t) {
        nama = n;
        noTelepon = t;
        cout << "Kontak berhasil ditambahkan\n";
    }

    // Destructor
    ~Kontak() {
        cout << "Menghapus kontak: " << nama << endl;
    }

    // Method untuk menampilkan data kontak
    void tampilkan(int index) {
        cout << "Kontak ke = " << index + 1 << endl;
        cout << "Nama : " << nama << endl;
        cout << "Nomor Telepon : " << noTelepon << endl;
        cout << "=============================\n";
    }
};

int main() {
    const int maksKontak = 10;
    Kontak* daftarKontak[maksKontak];
    int jumlahKontak = 0;
    char pilihan;

    cout << "Masukkan kontak (maksimal 10 kontak)\n\n";

    do {
        if (jumlahKontak >= maksKontak) {
            cout << "Sudah mencapai batas maksimal kontak!\n";
            break;
        }

        string nama, telp;
        cout << "Masukkan nama kontak ke - " << jumlahKontak + 1 << " : ";
        getline(cin, nama); // Menggunakan getline agar bisa input nama panjang

        cout << "Masukkan nomor telepon kontak ke - " << jumlahKontak + 1 << " : ";
        getline(cin, telp);

        // Menambahkan kontak ke array menggunakan constructor
        daftarKontak[jumlahKontak] = new Kontak(nama, telp);
        jumlahKontak++;

        cout << "Tambahkan kontak lagi? (y/n): ";
        cin >> pilihan;
        cin.ignore(); // Membersihkan buffer agar getline bisa berjalan dengan benar
        cout << endl;
    } while (pilihan == 'y' || pilihan == 'Y');

    // Menampilkan semua kontak
    cout << "\nDaftar Kontak:\n";
    for (int i = 0; i < jumlahKontak; i++) {
        daftarKontak[i]->tampilkan(i);
    }

    // Menghapus semua objek kontak (memanggil destructor)
    for (int i = 0; i < jumlahKontak; i++) {
        delete daftarKontak[i];
    }

    return 0;
}


#include <iostream>
using namespace std;

class Perpustakaan {
private:
    string nama, npm;
    string bukuDipinjam[5]; // Maksimal 5 buku
    int jumlahBuku = 0;

public:
    // Konstruktor
    void setMahasiswa(string n, string np) {
        nama = n;
        npm = np;
    }

    // Metode untuk meminjam buku
    void pinjamBuku(string buku) {
        if (jumlahBuku < 5) {
            bukuDipinjam[jumlahBuku] = buku;
            jumlahBuku++;
        } else {
            cout << "? Maksimal hanya bisa meminjam 5 buku!\n";
        }
    }

    // Menampilkan data peminjam dan daftar buku
    void tampilkanData() {
        cout << "\n========== ?? DETAIL PEMINJAMAN ?? ==========\n";
        cout << "Nama Mahasiswa : " << nama << "\n";
        cout << "NPM            : " << npm << "\n";
        cout << "--------------------------------------------\n";
        
        if (jumlahBuku == 0) {
            cout << "? Anda belum meminjam buku apapun.\n";
        } else {
            cout << "Buku yang dipinjam:\n";
            for (int i = 0; i < jumlahBuku; i++) {
                cout << "?? " << bukuDipinjam[i] << "\n";
            }
            cout << "\n?? Ingat untuk mengembalikan sebelum batas waktu!\n";
        }
        cout << "============================================\n";
    }
};

int main() {
    Perpustakaan peminjam;
    string nama, npm, buku;
    int jumlah;

    cout << "Masukkan Nama: ";
    getline(cin, nama);
    cout << "Masukkan NPM : ";
    getline(cin, npm);
    
    peminjam.setMahasiswa(nama, npm);

    cout << "\nBerapa buku yang ingin dipinjam? (Max 5): ";
    cin >> jumlah;
    cin.ignore();

    for (int i = 0; i < jumlah; i++) {
        cout << "\n?? Masukkan judul buku ke-" << i + 1 << ": ";
        getline(cin, buku);
        peminjam.pinjamBuku(buku);
    }

    peminjam.tampilkanData();
    return 0;
}

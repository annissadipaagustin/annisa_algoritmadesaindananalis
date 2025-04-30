#include <iostream>
using namespace std;

// Class Buku
class Buku {
public:
    string judul;
    int tahunTerbit;

    // Constructor default dan parameter
    Buku() {
        judul = "";
        tahunTerbit = 0;
    }

    Buku(string j, int t) {
        judul = j;
        tahunTerbit = t;
    }

    void tampilkan() {
        cout << "Judul: " << judul << ", Tahun Terbit: " << tahunTerbit << endl;
    }
};

// Fungsi untuk menukar dua objek Buku
void tukar(Buku &a, Buku &b) {
    Buku temp = a;
    a = b;
    b = temp;
}

// Fungsi untuk mengurutkan array Buku berdasarkan tahunTerbit (ascending)
void urutkanBuku(Buku arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].tahunTerbit > arr[j + 1].tahunTerbit) {
                tukar(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    const int jumlahBuku = 4;

    // Array objek Buku
    Buku koleksi[jumlahBuku] = {
        Buku("Belajar C++", 2018),
        Buku("Algoritma Dasar", 2015),
        Buku("Struktur Data", 2020),
        Buku("Pemrograman Lanjut", 2016)
    };

    // Urutkan array
    urutkanBuku(koleksi, jumlahBuku);

    // Tampilkan hasil
    cout << "Daftar buku setelah diurutkan berdasarkan tahun terbit:\n";
    for (int i = 0; i < jumlahBuku; i++) {
        koleksi[i].tampilkan();
    }

    return 0;
}

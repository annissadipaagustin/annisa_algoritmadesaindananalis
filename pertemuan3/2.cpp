#include <iostream>
using namespace std;

class Mahasiswa {
protected:
    string nama;
    int umur;
    string jurusan;
    string fakultas;
    string id;
public:
    Mahasiswa() {}  // Constructor default

    Mahasiswa(string i, string n, int u, string j, string f)
        : id(i), nama(n), umur(u), jurusan(j), fakultas(f) {}

    virtual void tampilkan() {
        cout << "Data Mahasiswa" << endl;
    }
};

class MahasiswaAktif : public Mahasiswa {
public:
    MahasiswaAktif(string i, string n, int u, string j, string f)
        : Mahasiswa(i, n, u, j, f) {}

    void tampilkan() override {
        cout << "\033[1;32m=== Mahasiswa Aktif ===\033[0m" << endl;  // Warna hijau
        cout << "ID      : " << id << endl;
        cout << "Nama    : " << nama << endl;
        cout << "Umur    : " << umur << " tahun" << endl;
        cout << "Jurusan : " << jurusan << endl;
        cout << "Fakultas: " << fakultas << endl << endl;
    }
};

class Alumni : public Mahasiswa {
public:
    Alumni(string i, string n, int u, string j, string f)
        : Mahasiswa(i, n, u, j, f) {}

    void tampilkan() override {
        cout << "\033[1;34m=== Alumni ===\033[0m" << endl;  // Warna biru
        cout << "ID      : " << id << endl;
        cout << "Nama    : " << nama << endl;
        cout << "Umur    : " << umur << " tahun" << endl;
        cout << "Jurusan : " << jurusan << endl;
        cout << "Fakultas: " << fakultas << endl << endl;
    }
};

int main() {
    Mahasiswa* mhs1 = new MahasiswaAktif("A1023", "Sari", 21, "Teknik Elektro", "Fakultas Teknik");
    Mahasiswa* mhs2 = new Alumni("B2098", "Andi", 27, "Teknik Mesin", "Fakultas Teknik");

    mhs1->tampilkan();
    mhs2->tampilkan();

    delete mhs1;
    delete mhs2;

    return 0;
}

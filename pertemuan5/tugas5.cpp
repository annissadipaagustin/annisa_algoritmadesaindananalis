#include <iostream>
using namespace std;

int main() {
    int jumlah;
    cout << "Masukkan jumlah nama: ";
    cin >> jumlah;
    cin.ignore();

    string nama[jumlah];

    for (int i = 0; i < jumlah; i++) {
        cout << "Nama ke-" << i + 1 << ": ";
        getline(cin, nama[i]);
    }

    cout << "\nSebelum diurutkan:\n";
    for (int i = 0; i < jumlah; i++) {
        cout << nama[i] << " ";
    }
    cout << endl;

    // Insertion Sort berdasarkan urutan alfabet
    for (int i = 1; i < jumlah; i++) {
        string key = nama[i];
        int j = i - 1;
        while (j >= 0 && nama[j] > key) {
            nama[j + 1] = nama[j];
            j--;
        }
        nama[j + 1] = key;
    }

    cout << "\nSetelah diurutkan berdasarkan abjad:\n";
    for (int i = 0; i < jumlah; i++) {
        cout << nama[i] << " ";
    }
    cout << endl;

    return 0;
}


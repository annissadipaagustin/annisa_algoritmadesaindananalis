#include <iostream>
using namespace std;

// Fungsi binary search
int binarySearch(int data[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (data[mid] == target) {
            return mid; // ditemukan, kembalikan indeks
        } else if (data[mid] < target) {
            left = mid + 1; // cari di sebelah kanan
        } else {
            right = mid - 1; // cari di sebelah kiri
        }
    }

    return -1; // tidak ditemukan
}

int main() {
    int data[] = {11, 22, 33, 44, 55, 66, 77};
    int size = sizeof(data) / sizeof(data[0]);
    int cari;

    cout << "Masukkan angka yang ingin dicari: ";
    cin >> cari;

    int hasil = binarySearch(data, size, cari);

    if (hasil != -1) {
        cout << "Angka ditemukan di index ke-" << hasil << endl;
    } else {
        cout << "Data tidak ditemukan" << endl;
    }

    return 0;
}

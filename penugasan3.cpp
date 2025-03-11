#include <iostream>
using namespace std;

void bubsort(int arr[], int n) //Deklarasi fungsi bubsort, menerima array (arr[]) dan jumlah elemen (n).
{
    int i, j, tmp;
    //Proses Bubble Sort Descending
    for (i = 0; i < n; i++) {
        //Proses sorting fase
        for (j = 0; j < n - i - 1; j++) {
            //Proses penukaran untuk sorting dari terbesar ke terkecil
            if (arr[j] < arr[j + 1]) {
            }
        }

        // Menukar elemen terbesar dengan elemen di posisi i
        tmp = arr[j];
        arr[j] = arr[i];
        arr[i] = tmp;

        // Menampilkan iterasi sorting
        cout << "Iterasi ke-" << i + 1 << ": ";
        for (int k = 0; k < n; k++) {
            cout << arr[k] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n, i;

    cout << "Masukan jumlah elemen: ";
    cin >> n;

    int arr[n];

    cout << "Masukan nilai elemen: ";
    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Data sebelum sorting: ";
    for (i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    void selectionSort(int arr[], int n);

    cout << "Data setelah sorting: ";
    for (i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}


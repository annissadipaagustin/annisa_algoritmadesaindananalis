#include <iostream>
using namespace std;

const int MAX = 100;

struct Queue {
    string data[MAX];
    int front, rear;

    Queue() {
        front = rear = -1;
    }

    void enqueue(string nama) {
        if (rear == MAX - 1) {
            cout << "Antrian penuh!\n";
            return;
        }
        if (front == -1) front = 0;
        data[++rear] = nama;
        cout << nama << " masuk antrian.\n";
    }

    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Antrian kosong.\n";
            return;
        }
        cout << data[front++] << " keluar dari antrian.\n";
        if (front > rear) front = rear = -1;
    }

    void tampil() {
        if (front == -1) {
            cout << "Antrian kosong.\n";
            return;
        }
        cout << "Antrian saat ini: ";
        for (int i = front; i <= rear; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    int pilihan;
    string nama;

    do {
        cout << "\nMenu:\n1. Tambah Antrian\n2. Hapus Antrian\n3. Tampil Antrian\n4. Keluar\nPilihan: ";
        cin >> pilihan;
        cin.ignore(); // hapus newline

        switch (pilihan) {
            case 1:
                cout << "Masukkan nama: ";
                getline(cin, nama);
                q.enqueue(nama);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.tampil();
                break;
            case 4:
                cout << "Terima kasih!\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 4);

    return 0;
}


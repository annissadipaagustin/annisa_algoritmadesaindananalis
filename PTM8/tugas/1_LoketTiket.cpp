#include <iostream>
using namespace std;

// Struktur Node untuk Linked List
struct Node {
    string nama;
    Node* next;
};

// Queue dengan Linked List
struct Queue {
    Node* front;
    Node* rear;

    Queue() {
        front = rear = NULL;
    }

    void enqueue(string nama) {
        Node* baru = new Node();
        baru->nama = nama;
        baru->next = NULL;

        if (rear == NULL) {
            front = rear = baru;
        } else {
            rear->next = baru;
            rear = baru;
        }
        cout << nama << " masuk antrian.\n";
    }

    void dequeue() {
        if (front == NULL) {
            cout << "Antrian kosong.\n";
            return;
        }

        Node* hapus = front;
        cout << hapus->nama << " keluar dari antrian.\n";
        front = front->next;

        if (front == NULL) rear = NULL;
        delete hapus;
    }

    void tampil() {
        if (front == NULL) {
            cout << "Antrian kosong.\n";
            return;
        }

        cout << "Antrian saat ini: ";
        Node* temp = front;
        while (temp != NULL) {
            cout << temp->nama << " ";
            temp = temp->next;
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
        cin.ignore(); // untuk menghapus newline

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


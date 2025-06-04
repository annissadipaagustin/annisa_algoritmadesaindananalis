#include <iostream>
using namespace std;

const int MAX_NODES = 100;
int tree[MAX_NODES];
int n;

// Fungsi untuk menyisipkan node ke binary search tree
void insertNode(int x) {
    int curr = 0;
    while (tree[curr] != -1) {
        if (x < tree[curr])
            curr = 2 * curr + 1;
        else
            curr = 2 * curr + 2;
    }
    tree[curr] = x;
    n++;
}

// Pre-order traversal: Root -> Left -> Right
void preorderTraversal(int curr) {
    if (tree[curr] != -1) {
        cout << tree[curr] << " ";
        preorderTraversal(2 * curr + 1);
        preorderTraversal(2 * curr + 2);
    }
}

// In-order traversal: Left -> Root -> Right
void inorderTraversal(int curr) {
    if (tree[curr] != -1) {
        inorderTraversal(2 * curr + 1);
        cout << tree[curr] << " ";
        inorderTraversal(2 * curr + 2);
    }
}

// Post-order traversal: Left -> Right -> Root
void postorderTraversal(int curr) {
    if (tree[curr] != -1) {
        postorderTraversal(2 * curr + 1);
        postorderTraversal(2 * curr + 2);
        cout << tree[curr] << " ";
    }
}

int main() {
    for (int i = 0; i < MAX_NODES; i++) {
        tree[i] = -1;
    }

    n = 0;

    // Input sesuai soal
    int values[] = {12, 16, 20, 24, 32};
    int size = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < size; i++) {
        insertNode(values[i]);
    }

    cout << "Pre-order traversal: ";
    preorderTraversal(0);
    cout << endl;

    cout << "In-order traversal: ";
    inorderTraversal(0);
    cout << endl;

    cout << "Post-order traversal: ";
    postorderTraversal(0);
    cout << endl;

    return 0;
}

#include <iostream>
#include <queue>

using namespace std;

// Struktur node untuk binary tree
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

// Fungsi untuk memasukkan node baru ke dalam tree
Node* insertNode(Node* root, int value) {
    if (root == NULL) {
        return new Node(value);
    }

    if (value < root->data) {
        root->left = insertNode(root->left, value);
    } else if (value > root->data) {
        root->right = insertNode(root->right, value);
    }

    return root;
}

// Fungsi untuk melakukan traversal inorder (kiri-root-kanan)
void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

// Fungsi untuk melakukan traversal preorder (root-kiri-kanan)
void preorderTraversal(Node* root) {
    if (root != NULL) {
        cout << root->data << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Fungsi untuk melakukan traversal postorder (kiri-kanan-root)
void postorderTraversal(Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout << root->data << " ";
    }
}

// Fungsi untuk melakukan level order traversal (BFS)
void levelOrderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        cout << current->data << " ";

        if (current->left != NULL) {
            q.push(current->left);
        }
        if (current->right != NULL) {
            q.push(current->right);
        }
    }
}


int main() {
    Node* root = NULL;
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);

    cout << "Inorder traversal: ";
    inorderTraversal(root);
    cout << endl;

    cout << "Preorder traversal: ";
    preorderTraversal(root);
    cout << endl;

    cout << "Postorder traversal: ";
    postorderTraversal(root);
    cout << endl;

    cout << "Level order traversal: ";
    levelOrderTraversal(root);
    cout << endl;
    return 0;
}

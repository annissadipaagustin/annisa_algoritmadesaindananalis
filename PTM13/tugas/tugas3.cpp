#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

const int INF = 1000000000;

// Fungsi membuat daftar node
vector<string> getNodes() {
    vector<string> temp;
    temp.push_back("Kyanka");
    temp.push_back("Dava");
    temp.push_back("Doni");
    temp.push_back("Wildan");
    temp.push_back("Haikal");
    temp.push_back("Agus");
    temp.push_back("Abrar");
    temp.push_back("Azizah");
    temp.push_back("Annisa");
    temp.push_back("Jonathan");
    temp.push_back("Rofii");
    temp.push_back("Steven");
    temp.push_back("Yunita");
    temp.push_back("Nanda");
    temp.push_back("Martin");
    temp.push_back("Sudrajat");
    temp.push_back("Ale");
    temp.push_back("Agung");
    return temp;
}

// Konversi nama ke indeks
int getIndex(map<string, int>& nodeIndex, string name) {
    return nodeIndex[name];
}

// Bangun jalur dari matriks next
vector<string> constructPath(int u, int v, vector<vector<int> >& next, vector<string>& nodes) {
    vector<string> path;
    if (next[u][v] == -1) return path;
    path.push_back(nodes[u]);
    while (u != v) {
        u = next[u][v];
        path.push_back(nodes[u]);
    }
    return path;
}

// Tambahkan edge
void addEdge(vector<vector<int> >& dist, vector<vector<int> >& next, map<string, int>& nodeIndex, string u, string v, int w) {
    int i = getIndex(nodeIndex, u);
    int j = getIndex(nodeIndex, v);
    dist[i][j] = w;
    dist[j][i] = w;
    next[i][j] = j;
    next[j][i] = i;
}

int main() {
    vector<string> nodes = getNodes();
    int n = nodes.size();

    map<string, int> nodeIndex;
    for (int i = 0; i < n; i++) nodeIndex[nodes[i]] = i;

    // Inisialisasi
    vector<vector<int> > dist(n, vector<int>(n, INF));
    vector<vector<int> > next(n, vector<int>(n, -1));
    for (int i = 0; i < n; ++i) dist[i][i] = 0;

    // Tambahkan edge dari graf
    addEdge(dist, next, nodeIndex, "Kyanka", "Dava", 1);
    addEdge(dist, next, nodeIndex, "Kyanka", "Abrar", 3);
    addEdge(dist, next, nodeIndex, "Abrar", "Azizah", 1);
    addEdge(dist, next, nodeIndex, "Abrar", "Steven", 2);
    addEdge(dist, next, nodeIndex, "Azizah", "Steven", 1);
    addEdge(dist, next, nodeIndex, "Dava", "Doni", 1);
    addEdge(dist, next, nodeIndex, "Dava", "Azizah", 1);
    addEdge(dist, next, nodeIndex, "Azizah", "Annisa", 2);
    addEdge(dist, next, nodeIndex, "Doni", "Annisa", 4);
    addEdge(dist, next, nodeIndex, "Doni", "Wildan", 2);
    addEdge(dist, next, nodeIndex, "Wildan", "Jonathan", 1);
    addEdge(dist, next, nodeIndex, "Wildan", "Haikal", 4);
    addEdge(dist, next, nodeIndex, "Haikal", "Agus", 4);
    addEdge(dist, next, nodeIndex, "Jonathan", "Annisa", 1);
    addEdge(dist, next, nodeIndex, "Jonathan", "Rofii", 2);
    addEdge(dist, next, nodeIndex, "Rofii", "Agus", 2);
    addEdge(dist, next, nodeIndex, "Annisa", "Yunita", 2);
    addEdge(dist, next, nodeIndex, "Yunita", "Nanda", 2);
    addEdge(dist, next, nodeIndex, "Nanda", "Martin", 1);
    addEdge(dist, next, nodeIndex, "Martin", "Sudrajat", 3);
    addEdge(dist, next, nodeIndex, "Nanda", "Sudrajat", 4);
    addEdge(dist, next, nodeIndex, "Nanda", "Ale", 2);
    addEdge(dist, next, nodeIndex, "Rofii", "Ale", 2);
    addEdge(dist, next, nodeIndex, "Rofii", "Agung", 2);
    addEdge(dist, next, nodeIndex, "Ale", "Agung", 1);

    // Floyd-Warshall
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    next[i][j] = next[i][k];
                }

    // CETAK JALUR DARI ANNISA KE ROFII
    int from = nodeIndex["Annisa"];
    int to = nodeIndex["Rofii"];

    cout << "==========================================" << endl;
    cout << "    Hasil Pengiriman Pesan Annisa -> Rofii" << endl;
    cout << "==========================================" << endl;

    if (dist[from][to] == INF) {
        cout << "Tidak ada jalur yang tersedia" << endl;
    } else {
        cout << "Jarak terpendek (waktu): " << dist[from][to] << endl;
        vector<string> path = constructPath(from, to, next, nodes);
        cout << "Jalur: ";
        for (int i = 0; i < path.size(); ++i) {
            cout << path[i];
            if (i != path.size() - 1) cout << " -> ";
        }
        cout << endl;
    }

    // TANYA PENGGUNA: CETAK SEMUA MATRKS JARAK?
    char cetak;
    cout << "\nCetak Matriks Jarak Terpendek (Y/T)? ";
    cin >> cetak;

    if (cetak == 'Y' || cetak == 'y') {
        cout << "\nMatriks Jarak Terpendek (dalam satuan waktu):\n\n";
        // Cetak header
        cout << "\t";
        for (int j = 0; j < n; ++j)
            cout << nodes[j].substr(0, 3) << "\t";
        cout << endl;

        // Cetak isi
        for (int i = 0; i < n; ++i) {
            cout << nodes[i].substr(0, 3) << "\t";
            for (int j = 0; j < n; ++j) {
                if (dist[i][j] == INF)
                    cout << "-\t";
                else
                    cout << dist[i][j] << "\t";
            }
            cout << endl;
        }
    }

    return 0;
}


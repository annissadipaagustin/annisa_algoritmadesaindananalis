#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <map>
#include <string>
using namespace std;

const int INF = INT_MAX;
const int N = 18; // Jumlah siswa

map<string, int> namaToIndex = {
    {"Kyanka", 0}, {"Dava", 1}, {"Doni", 2}, {"Wildan", 3}, {"Haikal", 4},
    {"Agus", 5}, {"Abrar", 6}, {"Azizah", 7}, {"Annisa", 8}, {"Jonathan", 9},
    {"Rofii", 10}, {"Steven", 11}, {"Yunita", 12}, {"Nanda", 13}, {"Ale", 14},
    {"Agung", 15}, {"Martin", 16}, {"Sudrajat", 17}
};

string indexToNama[N] = {
    "Kyanka", "Dava", "Doni", "Wildan", "Haikal", "Agus", "Abrar", "Azizah", "Annisa",
    "Jonathan", "Rofii", "Steven", "Yunita", "Nanda", "Ale", "Agung", "Martin", "Sudrajat"
};

int graph[N][N];

void addEdge(string a, string b, int w) {
    int u = namaToIndex[a];
    int v = namaToIndex[b];
    graph[u][v] = w;
    graph[v][u] = w;
}

void inisialisasiGraph() {
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            graph[i][j] = (i == j) ? 0 : INF;

    addEdge("Kyanka", "Dava", 1);
    addEdge("Dava", "Doni", 1);
    addEdge("Doni", "Annisa", 4);
    addEdge("Doni", "Wildan", 2);
    addEdge("Wildan", "Haikal", 4);
    addEdge("Haikal", "Agus", 4);
    addEdge("Agus", "Rofii", 2);
    addEdge("Rofii", "Jonathan", 2);
    addEdge("Jonathan", "Annisa", 1);
    addEdge("Jonathan", "Wildan", 1);
    addEdge("Rofii", "Agung", 2);
    addEdge("Agung", "Ale", 1);
    addEdge("Ale", "Nanda", 2);
    addEdge("Nanda", "Sudrajat", 4);
    addEdge("Nanda", "Martin", 1);
    addEdge("Martin", "Sudrajat", 3);
    addEdge("Martin", "Yunita", 2);
    addEdge("Yunita", "Annisa", 2);
    addEdge("Azizah", "Annisa", 2);
    addEdge("Dava", "Azizah", 2);
    addEdge("Azizah", "Abrar", 1);
    addEdge("Azizah", "Steven", 1);
    addEdge("Abrar", "Kyanka", 3);
    addEdge("Steven", "Abrar", 2);
}

void dijkstra(int src) {
    vector<int> dist(N, INF), prev(N, -1);
    dist[src] = 0;
    priority_queue< pair<int, int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
    pq.push(make_pair(0, src));

    while(!pq.empty()) {
        int u = pq.top().second; pq.pop();
        for(int v = 0; v < N; v++) {
            if(graph[u][v] != INF) {
                int alt = dist[u] + graph[u][v];
                if(alt < dist[v]) {
                    dist[v] = alt;
                    prev[v] = u;
                    pq.push(make_pair(alt, v));
                }
            }
        }
    }

    string tujuan;
    cout << "Masukkan siswa tujuan: ";
    cin >> tujuan;
    int dest = namaToIndex[tujuan];

    if(dist[dest] == INF) {
        cout << "Tidak ada jalur yang tersedia\n";
    } else {
        cout << "Jalur tercepat: ";
        vector<int> path;
        for(int at = dest; at != -1; at = prev[at])
            path.push_back(at);
        for(int i = path.size()-1; i >= 0; i--) {
            cout << indexToNama[path[i]];
            if(i > 0) cout << " -> ";
        }
        cout << "\nTotal waktu: " << dist[dest] << endl;
    }
}

void floydWarshall() {
    int dist[N][N];
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            dist[i][j] = graph[i][j];

    for(int k = 0; k < N; k++)
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                if(dist[i][k] != INF && dist[k][j] != INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    cout << "\nMatriks Jarak Terpendek (Floyd-Warshall):\n";
    for(int i = 0; i < N; i++) {
        cout << indexToNama[i] << ":\n";
        for(int j = 0; j < N; j++) {
            if(dist[i][j] == INF)
                cout << "   -> " << indexToNama[j] << ": Tidak ada jalur\n";
            else
                cout << "   -> " << indexToNama[j] << ": " << dist[i][j] << " satuan waktu\n";
        }
        cout << endl;
    }
}

int main() {
    inisialisasiGraph();

    cout << "FITUR 1: Jalur Tercepat\n";
    string asal;
    cout << "Masukkan siswa asal: ";
    cin >> asal;
    dijkstra(namaToIndex[asal]);

    char jawab;
    cout << "\nFITUR 2: Cetak Matriks Jarak Terpendek (Y/T)? ";
    cin >> jawab;
    if(jawab == 'Y' || jawab == 'y') {
        floydWarshall();
    }

    return 0;
}

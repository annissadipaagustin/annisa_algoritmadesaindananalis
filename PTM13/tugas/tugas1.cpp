#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <string>
using namespace std;


struct Edge {
    int to;
    int weight;
};


const int N = 18;
const int INF = INT_MAX;
vector<string> names;


void initNames() {
    names.push_back("Kyanka");
    names.push_back("Dava");
    names.push_back("Doni");
    names.push_back("Wildan");
    names.push_back("Haikal");
    names.push_back("Agus");
    names.push_back("Abrar");
    names.push_back("Azizah");
    names.push_back("Annisa");
    names.push_back("Jonathan");
    names.push_back("Rofii");
    names.push_back("Steven");
    names.push_back("Yunita");
    names.push_back("Nanda");
    names.push_back("Ale");
    names.push_back("Agung");
    names.push_back("Martin");
    names.push_back("Sudrajat");
}


int getIndex(string name) {
    for (int i = 0; i < names.size(); i++) {
        if (names[i] == name) return i;
    }
    return -1;
}


void add(vector<vector<Edge> >& graph, string a, string b, int w) {
    int u = getIndex(a);
    int v = getIndex(b);
    graph[u].push_back((Edge){v, w});
    graph[v].push_back((Edge){u, w});
}

int main() {
    initNames(); 
    vector<vector<Edge> > graph(N);

    
    add(graph, "Kyanka", "Dava", 1);
    add(graph, "Kyanka", "Abrar", 3);
    add(graph, "Abrar", "Steven", 2);
    add(graph, "Abrar", "Azizah", 1);
    add(graph, "Steven", "Azizah", 1);
    add(graph, "Dava", "Doni", 1);
    add(graph, "Dava", "Azizah", 2);
    add(graph, "Doni", "Annisa", 4);
    add(graph, "Doni", "Wildan", 2);
    add(graph, "Wildan", "Haikal", 4);
    add(graph, "Wildan", "Jonathan", 1);
    add(graph, "Haikal", "Agus", 4);
    add(graph, "Agus", "Rofii", 2);
    add(graph, "Azizah", "Annisa", 1);
    add(graph, "Annisa", "Yunita", 2);
    add(graph, "Annisa", "Jonathan", 1);
    add(graph, "Jonathan", "Rofii", 2);
    add(graph, "Rofii", "Ale", 2);
    add(graph, "Ale", "Agung", 1);
    add(graph, "Yunita", "Nanda", 2);
    add(graph, "Nanda", "Jonathan", 2);
    add(graph, "Nanda", "Ale", 2);
    add(graph, "Nanda", "Martin", 1);
    add(graph, "Nanda", "Sudrajat", 4);
    add(graph, "Martin", "Sudrajat", 3);

    
    string asal = "Annisa";
    string tujuan = "Rofii";
    int start = getIndex(asal);
    int end = getIndex(tujuan);

    
    vector<int> dist(N, INF);
    vector<int> prev(N, -1);
    priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;

    dist[start] = 0;
    pq.push(make_pair(0, start));

    while (!pq.empty()) {
        pair<int, int> current = pq.top();
        pq.pop();
        int d = current.first;
        int u = current.second;

        if (d > dist[u]) continue;

        for (int i = 0; i < graph[u].size(); i++) {
            Edge e = graph[u][i];
            int v = e.to;
            int w = e.weight;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                prev[v] = u;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    
    if (dist[end] == INF) {
        cout << "Tidak ada jalur dari " << asal << " ke " << tujuan << "." << endl;
    } else {
        cout << "Waktu tercepat dari " << asal << " ke " << tujuan << ": " << dist[end] << endl;
        cout << "Jalur: ";
        vector<int> path;
        for (int at = end; at != -1; at = prev[at]) {
            path.insert(path.begin(), at);
        }
        for (int i = 0; i < path.size(); i++) {
            cout << names[path[i]];
            if (i + 1 < path.size()) cout << " -> ";
        }
        cout << endl;
    }

    return 0;
}


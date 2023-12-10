#include "processor.h"

processor::processor(int a1, int a2, int b1, int b2, rover& tr) {
    A1 = a1;
    A2 = a2;
    B1 = b1;
    B2 = b2;
    truck = tr;
}

processor::processor() {
    A1 = 0;
    A2 = 0;
    B1 = 0;
    B2 = 0;
}

void processor::route() {
    ofstream file("route.txt");
    int i, j, k, l, m;
    int n = 120 * 120;
    int s = A1 * 119 + A2;
    int t = B1 * 119 + B2;
    vector<vector<int>> bi_vect(n); 
    vector<int> dist(n, n); 
    vector<int> vert(n, -1); 
    dist[s] = 0;
    queue<int> q;
    q.push(s);
    for (i = 0; i < 120; i++) {
        for (j = 0; j < 120; j++) {
            for (k = i - 1; k < i + 2; k++) {
                for (l = j - 1; l < j + 2; l++) {
                    if (k > 0 && k < 120 && l > 0 && l < 120  && !(k == i && l == j)) {
                        if (truck.sensor(i, j, k, l) && truck.angles(i, j, k, l)) {
                            m = 119 * i + j;
                            bi_vect[m].push_back(119 * k + l);
                        }
                    }
                }
            }
        }
    }
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : bi_vect[v]) {
            if (dist[u] > dist[v] + 1) {
                vert[u] = v;
                dist[u] = dist[v] + 1;
                q.push(u);
            }
        }
    }
    if (dist[t] == n) {
        cout << "The rover can't get from point A to point B" << endl;
    }
    vector<int> path;
    while (t != -1) {
        path.push_back(t);
        t = vert[t];
    }
    for (i = path.size() - 1; i > -1; i--) {
        k = path[i] / 119;
        l = path[i] % 119;
        file << double(k * 10) / 120 << " " << double(l * 10) / 120 << " " << double(truck.top.Pixel[k][l] * 10) / 120 << endl;
    }
}
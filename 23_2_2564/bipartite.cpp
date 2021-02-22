#include <iostream>
#include <queue>
#include <vector>
const int MAX_N = 100010;

using namespace std;

int k, n, m;
vector<int> adj[MAX_N];
int deg[MAX_N];

void read_input() {
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        deg[i] = 0;
        adj[i].clear();
    }
    for(int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        u--;v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;deg[v]++;
    }
}

bool isBipartite() {
    int colorArr[m];
    for(int i=0; i<m; i++) {
        colorArr[i] = -1;
    }
    colorArr[0] = 1;
    queue<int> q;
    q.push(0);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int d=0; d<deg[u]; d++) {
            int v = adj[u][d];
            if(colorArr[v] == -1) {
                colorArr[v] = 1 - colorArr[u];
                q.push(v);
            }else if(colorArr[v] == colorArr[u]) {
                return false;
            }
        }
    }
    return true;
}

int main(void) {
    cin >> k;
    while(k--) {
        read_input();
        if(isBipartite()) {
            cout << "true" << endl;
        }else {
            cout << "false" << endl;
        }
    }
}
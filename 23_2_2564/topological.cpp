#include <iostream>
#include <vector>
#include <stack>
const int MAX_N = 100100;

using namespace std;

vector<int> adj[MAX_N];
int deg[MAX_N];
int n,m;
bool discovered[MAX_N], mark[MAX_N];

void read_input() {
    int u, v;
    cin >> n >> m;
    for(int i=0; i<MAX_N; i++) {
        discovered[i] = false;
        mark[i] = false;
    }
    for(int i=0; i<m; i++) {
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        deg[u]++;
    }
}

int cycle = 0;
stack<int> topo_order;

void dfs(int u) {
    discovered[u] = true;
    for(int d=0; d<deg[u]; d++) {
        int v = adj[u][d];
        if(!discovered[v]) {
            dfs(v);
        }
        if(!mark[v]) {
            cycle = 1;
        }
    }
    topo_order.push(u);
    mark[u] = true;
}

int main(){
    read_input();
    for(int i=0; i<n; i++) {
        if(!discovered[i]) {
            dfs(i);
        }
    }
    if(cycle) {
        cout << "no";
    }
    else{
        while(!topo_order.empty()) {
            cout << topo_order.top()+1 << "\n";
            topo_order.pop();
        }
    }
    return 0;
}
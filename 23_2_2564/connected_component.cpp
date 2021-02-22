#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 100010;

int n, m;
vector<int> adj[MAX_N];
int deg[MAX_N];

void read_input() {
    scanf("%d%d", &n, &m);
    for(int i=0; i<n; i++) {
        deg[i] = 0;        
    }
    for(int i=0; i<m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a); // keep back
        deg[a]++;deg[b]++; //Update
    }
}

int discover[MAX_N];

void init() {
    for(int i=0; i<n; i++) {
        discover[i] = 0;
    }
}

void bfs(int s) {
    list<int> current_layer;
    list<int> next_layer;
    current_layer.push_back(s);
    while(!current_layer.empty()) {
        for(list<int>::iterator i=current_layer.begin(); 
            i!=current_layer.end(); i++) {
            int a = *i;
            for(int j=0; j<deg[a]; j++) {
                int b = adj[a][j];
                if(!discover[b]) {
                    next_layer.push_back(b);
                    discover[b] = 1;
                }
            }
        }
        current_layer = next_layer;
        next_layer.clear();
    }
}

int main(void) {
    read_input();
    init();
    int count = 0;
    for(int i=0; i<n; i++) {
        if(!discover[i]) {
            discover[i] = 1;
            bfs(i);
            count++;
        }
    }
    printf("%d", count);
    return 0;
}
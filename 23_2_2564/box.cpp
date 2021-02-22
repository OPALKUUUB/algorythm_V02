#include <iostream>
const int MAX_N = 35;

using namespace std;

int n, m;
char table[MAX_N][MAX_N], newTable[MAX_N][MAX_N];
bool discovered[MAX_N][MAX_N];
bool box = false;


void read_input() {
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            char c;
            cin >> c;
            table[i][j] = c;
            discovered[i][j] = false;
        }
    }
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<m-1; j++) {
            if(table[i][j] == '.' && table[i][j+1] == '.' && table[i+1][j] == '.' && table[i+1][j+1] == '.') {
                newTable[i][j] = '.';
            }else {
                newTable[i][j] = '#';
            }
        }
    }
}

void dfs(int i, int j) {
    discovered[i][j] = true;
    if(i+1 < n-1 && !discovered[i+1][j] && newTable[i+1][j] == '.') {
        dfs(i+1, j);
    }
    if(j+1 < m-1 && !discovered[i][j+1] && newTable[i][j+1] == '.') {
        dfs(i, j+1);
    }
    if(i-1 > -1 && !discovered[i-1][j] && newTable[i-1][j] == '.') {
        dfs(i-1, j);
    }
    if(j-1> -1 && !discovered[i][j-1] && newTable[i][j-1] == '.') {
        dfs(i, j-1);
    }
}


int main(){
    read_input();
    for(int i=0; i<m-1; i++) {
        if(!discovered[0][i] && newTable[0][i] == '.') {
            dfs(0, i);
        }
        else {
            discovered[0][i] = true;
        }
    }
    for(int i=0; i<m-1; i++) {
        if(discovered[n-2][i] == true) {
            box = true;
            break;
        }
    }
    box ? cout << "yes" : cout << "no";
    return 0;
}
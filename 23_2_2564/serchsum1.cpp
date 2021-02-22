#include <iostream>
#include <map>

using namespace std;

int n, k, temp;
map<int, int> buy; 
map<int, int>::iterator it;



int main(void) {
    cin >> n >> k;
    buy[0] = 0;
    it = buy.begin();
    for(int i=0; i<n; i++) {
        cin >> temp;
        temp+=it->first;
        buy[temp] = i+1;
        it++;
    }
    for(int i=0; i<k; i++) {
        cin >> temp;
        it = buy.upper_bound(temp);
        it--;
        cout << it->second << "\n";
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> adj[100005];
bool visited[100005];
int n, k;

int dfs(int u, int blocked) {
    visited[u] = true;
    int size = 1;
    for (int v : adj[u]) {
        if (v != blocked && !visited[v]) {
            size += dfs(v, blocked);
        }
    }
    return size;
}

bool isValid(int u) {
    for (int i = 1; i <= n; i++) {
        visited[i] = false;
    }
    visited[u] = true;
    
    for (int v : adj[u]) {
        int componentSize = dfs(v, u);
        if (componentSize > k) {
            return false;
        }
        for (int i = 1; i <= n; i++) {
            visited[i] = false;
        }
        visited[u] = true;
    }
    return true;
}

int main() {
    cin >> n >> k;
    
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    vector<int> result;
    for (int u = 1; u <= n; u++) {
        if (isValid(u)) {
            result.push_back(u);
        }
    }
    
    if (result.empty()) {
        cout << "None" << endl;
    } else {
        sort(result.begin(), result.end(), greater<int>());
        for (int i = 0; i < result.size(); i++) {
            if (i > 0) cout << " ";
            cout << result[i];
        }
        cout << endl;
    }
    
    return 0;
}

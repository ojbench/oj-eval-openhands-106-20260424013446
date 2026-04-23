#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> adj[100005];
int subtree_size[100005];
int parent_node[100005];
int n, k;

void dfs(int u, int p) {
    parent_node[u] = p;
    subtree_size[u] = 1;
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u);
            subtree_size[u] += subtree_size[v];
        }
    }
}

bool isValid(int u) {
    int maxComponentSize = 0;
    
    // Check each neighbor of u
    for (int v : adj[u]) {
        int componentSize;
        if (parent_node[u] == v) {
            // v is parent of u, so component is everything except u's subtree
            componentSize = n - subtree_size[u];
        } else {
            // v is child of u, so component is v's subtree
            componentSize = subtree_size[v];
        }
        if (componentSize > k) {
            return false;
        }
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
    
    // Root the tree at node 1 and compute subtree sizes
    dfs(1, 0);
    
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

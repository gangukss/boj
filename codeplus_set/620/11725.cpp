#include <iostream>
#include <vector>
using namespace std;

const int M = 1e5 + 1;
int n;
vector<vector<int>> input(M);
int ans[M];

void dfs(int node) {
    for (auto nextNode : input[node]) {
        if (!ans[nextNode]) {
            ans[nextNode] = node;
            dfs(nextNode);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        input[a].emplace_back(b);
        input[b].emplace_back(a);
    }
    ans[1] = -1;
    dfs(1);
    for (int i = 2; i <= n; ++i)
        cout << ans[i] << "\n";
}



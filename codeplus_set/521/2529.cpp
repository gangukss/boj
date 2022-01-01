#include <iostream>
#include <vector>
using namespace std;

int k;
char input[9];
bool visit[10];
vector<int> buf;
vector<int> ansMin;
vector<int> ansMax;

void dfs(int depth) {
    if (depth > k) {
        if (ansMin.empty())
            ansMin = buf;
        else
            ansMax = buf;
        return ;
    }
    for (int i = 0; i < 10; ++i) {
        if (!visit[i]) {
            buf.emplace_back(i);
            visit[i] = 1;
            if (depth == 0) {
                dfs(depth + 1);
            } else if (((input[depth - 1] == '<' && buf[depth - 1] < buf[depth])
                || (input[depth - 1] == '>' && buf[depth - 1] > buf[depth]))) {
                dfs(depth + 1);
            }
            buf.pop_back();
            visit[i] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> k;
    for (int i = 0; i < k; ++i)
        cin >> input[i];
    dfs(0);
    for (auto x : ansMax)
        cout << x;
    cout << "\n";
    for (auto x : ansMin)
        cout << x;
}

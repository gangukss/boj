#include <iostream>
#include <vector>
using namespace std;

int k;
char input[9];
vector<int> ansMin;
vector<int> ansMax;
vector<int> v;
bool visit[10];

void dfs(int depth) {
	if (depth >= k) {
		ansMin = min(ansMin, v);
		ansMax = max(ansMax, v);
		return ;
	}
	for (int i = 0; i < 10; ++i) {
		if (!visit[i] && input[depth] == '<' && v.back() < i) {
			visit[i] = 1;
			v.emplace_back(i);
			dfs(depth + 1);
			visit[i] = 0;
			v.pop_back();
		} else if (!visit[i] && input[depth] == '>' && v.back() > i) {
			visit[i] = 1;
			v.emplace_back(i);
			dfs(depth + 1);
			visit[i] = 0;
			v.pop_back();
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
	for (int i = 0; i < 10; ++i)
		ansMin.emplace_back(9);
	for (int i = 0; i < 10; ++i) {
		visit[i] = 1;
		v.emplace_back(i);
		dfs(0);
		visit[i] = 0;
		v.pop_back();
	}
	for (int x : ansMax)
		cout << (char)(x + '0');
	cout << "\n";
	for (char x : ansMin)
		cout << (char)(x + '0');
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int l, c;
char input[15];
vector<char> ans;

bool isVowels(char x) {
	return x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u';
}

void dfs(int idx, int cntVowels, int cntConsonants) {
	if (ans.size() >= (size_t)l) {
		if (cntVowels >= 1 && cntConsonants >= 2) {
			for (auto x : ans)
				cout << x;
			cout << "\n";
		}
		return ;
	}
	for (int i = idx; i < c; ++i) {
		ans.emplace_back(input[i]);
		if (isVowels(input[i]))
			dfs(i + 1, cntVowels + 1, cntConsonants);
		else
			dfs(i + 1, cntVowels, cntConsonants + 1);
		ans.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> l >> c;
	for (int i = 0; i < c; ++i)
		cin >> input[i];
	sort(input, input + c);
	dfs(0, 0, 0);
}
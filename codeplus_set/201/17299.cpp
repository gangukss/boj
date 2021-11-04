#include <iostream>
#include <vector>
using namespace std;

#define M 1000001

int n;
int input[M];
int F[M];
int NGF[M];
vector<int> v;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> input[i];
		++F[input[i]];
	}
	for (int i = n - 1; i >= 0; --i) {
		while (!v.empty() && F[input[i]] >= F[v.back()])
			v.pop_back();
		if (v.empty())
			NGF[i] = -1;
		else
			NGF[i] = v.back();
		v.emplace_back(input[i]);
	}
	for (int i = 0; i < n; ++i)
		cout << NGF[i] << " ";
}

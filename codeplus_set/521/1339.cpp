#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n, ans, num = 9;
string input[10];
int alpha[26];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> input[i];
    for (int i = 0; i < n; ++i) {
        int pow = 1;
        for (int j = (int)input[i].size() - 1; j >= 0; --j) {
            alpha[input[i][j] - 'A'] += pow;
            pow *= 10;
        }
    }
    sort(alpha, alpha + 26);
    for (int i = 25; i > 0; --i) {
        if (!alpha[i])
            break ;
        ans += alpha[i] * num--;
    }
    cout << ans;
}

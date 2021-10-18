#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> v;
    vector<int> st;
    vector<char> ans;
    for (int i = n; i > 0; --i)
        v.emplace_back(i);
    int curIdx = 0;
    for (int i = 0; i < n; ++i) {
        int inputNum;
        cin >> inputNum;
        // push
        for (int j = curIdx; j < inputNum; curIdx = ++j) {
            st.emplace_back(j + 1);
            ans.emplace_back('+');
        }
        // pop
        if (st.size() && st.back() == inputNum) {
            st.pop_back();
            ans.emplace_back('-');
        } else {
            cout << "NO\n";
            return 0;
        }
    }
    for (size_t i = 0; i < ans.size(); ++i)
        cout << ans[i] << "\n";
}

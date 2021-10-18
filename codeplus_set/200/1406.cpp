#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<char> leftStack;
    vector<char> rightStack;
    string input;
    int m;

    cin >> input;
    for (size_t i = 0; i < input.size(); ++i)
        leftStack.emplace_back(input[i]);
    cin >> m;
    cin.ignore();
    while (m--) {
        string cmd;
        getline(cin, cmd);
        if (cmd[0] == 'L') {
            if (leftStack.size()) {
                rightStack.emplace_back(leftStack.back());
                leftStack.pop_back();
            }
        } else if (cmd[0] == 'D') {
            if (rightStack.size()) {
                leftStack.emplace_back(rightStack.back());
                rightStack.pop_back();
            }
        } else if (cmd[0] == 'B') {
            if (leftStack.size())
                leftStack.pop_back();
        } else if (cmd[0] == 'P') {
            leftStack.emplace_back(cmd[2]);
        }
    }
    for (size_t i = 0; i < leftStack.size(); ++i)
        cout << leftStack[i];
    for (int i = static_cast<int>(rightStack.size()) - 1; i >= 0; --i)
        cout << rightStack[i];
}

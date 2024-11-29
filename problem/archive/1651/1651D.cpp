#include <iostream>
#include <cstdio>
#include <climits>
#include <cmath>
#include <cstring>
#include <string>
#include <array>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <algorithm>
#include <functional>

using namespace std;

#define ll long long
#define vi vector<int>
#define ssz(a) (int)((a).size())

#define endl '\n'
template <class T> void in(vector<T>& a) { for (int i = 0; i < ssz(a); i++) cin >> a[i]; }
template <class T> void out(const vector<T>& a) { for (int i = 0; i < ssz(a); i++) cout << a[i] << " \n"[i + 1 == ssz(a)]; }

const int dirs4[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    set<pair<int, int>> s;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
        s.emplace(a[i]);
    }

    map<pair<int, int>, pair<int, int>> ans;
    queue<pair<int, int>> q;
    for (auto [r, c]: s) {
        for (int i = 0; i < 4; i++) {
            int nr = r + dirs4[i][0], nc = c + dirs4[i][1];
            if (!s.count({nr, nc})) {
                ans[{r, c}] = {nr, nc};
                q.emplace(r, c);
                break;
            }
        }
    }

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nr = r + dirs4[i][0], nc = c + dirs4[i][1];
            if (s.count({nr, nc}) && !ans.count({nr, nc})) {
                ans[{nr, nc}] = ans[{r, c}];
                q.emplace(nr, nc);
            }
        }
    }

    for (auto [x, y]: a) {
        cout << ans[{x, y}].first << " " << ans[{x, y}].second << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
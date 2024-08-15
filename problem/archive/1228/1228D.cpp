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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<set<int>> e(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        e[u].insert(v);
        e[v].insert(u);
    }

    vi label(n, -1);
    for (int i = 0; i < 3; i++) {
        int first;
        for (first = 0; first < n; first++) {
            if (label[first] == -1) {
                break;
            }
        }
        if (first == n) {
            cout << -1 << endl;
            return;
        }
        label[first] = i;
        for (int second = 0; second < n; second++) {
            if (second == first || label[second] != -1) continue;
            if (e[first].find(second) != e[first].end()) continue;
            label[second] = i;
        }
    }

    vector<vi> group(3);
    for (int i = 0; i < n; i++) {
        if (label[i] == -1) {
            cout << -1 << endl;
            return;
        }
        group[label[i]].push_back(i);
    }

    int tot = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 3; j++) {
            for (auto u: group[i]) {
                for (auto v: group[j]) {
                    if (e[u].find(v) == e[u].end()) {
                        cout << -1 << endl;
                        return;
                    } else {
                        tot++;
                    }
                }
            }
        }
    }

    if (tot != m) {
        cout << -1 << endl;
        return;
    }

    for (int i = 0; i < n; i++) {
        cout << label[i] + 1 << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
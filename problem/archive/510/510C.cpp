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
    int n; cin >> n;
    vector<string> a(n);
    in(a);

    vector<vi> e(26);
    vi deg(26, 0);
    for (int i = 0; i < n - 1; i++) {
        int m = min(ssz(a[i]), ssz(a[i + 1]));
        bool ok = false;
        for (int j = 0; j < m; j++) {
            if (a[i][j] != a[i + 1][j]) {
                int u = a[i][j] - 'a';
                int v = a[i + 1][j] - 'a';
                e[u].push_back(v);
                deg[v]++;
                ok = true;
                break;
            }
        }
        if (!ok && ssz(a[i]) > ssz(a[i + 1])) {
            cout << "Impossible\n";
            return;
        }
    }

    string ans;
    queue<int> q;
    for (int i = 0; i < 26; i++) {
        if (deg[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        ans += (char)(u + 'a');
        for (auto v: e[u]) {
            deg[v]--;
            if (deg[v] == 0) {
                q.push(v);
            }
        }
    }

    cout << (ssz(ans) == 26 ? ans : "Impossible") << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
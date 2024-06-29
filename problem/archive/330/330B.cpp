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
    set<int> s;
    while (m--) {
        int u, v;
        cin >> u >> v;
        s.insert(u);
        s.insert(v);
    }

    int x = 0;
    for (int i = 1; i <= n; i++) {
        if (!s.count(i)) {
            x = i;
            break;
        }
    }

    cout << n - 1 << endl;
    for (int i = 0; i < n; i++) {
        if (i + 1 == x) continue;
        cout << x << " " << i + 1 << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
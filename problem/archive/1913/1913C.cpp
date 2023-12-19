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
    int m; cin >> m;
    vi cnt(30, 0);
    while (m--) {
        int t, v;
        cin >> t >> v;
        if (t == 1) {
            cnt[v]++;
        } else {
            int cur = 0;
            for (int i = 29; i >= 0; i--) {
                if (v >> i & 1) cur++;
                cur = max(0, cur - cnt[i]);
                cur *= 2;
            }
            if (cur) cout << "NO\n";
            else cout << "YES\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
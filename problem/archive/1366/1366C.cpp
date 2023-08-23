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
    int n, m; cin >> n >> m;
    vector<vi> a(n, vi(m));
    for (int i = 0; i < n; i++) {
        in(a[i]);
    }

    map<int, int> cnt1, cnt;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int k = i + j;
            if ((n + m - 2) % 2 == 0 && k == (n + m - 2) / 2) {
                continue;
            }
            if (k > (n + m - 2) / 2) {
                k = n + m - 2 - k;
            }
            if (a[i][j]) cnt1[k]++;
            cnt[k]++;
        }
    }
    
    int ans = 0;
    for (auto [k, v]: cnt) {
        ans += min(cnt1[k], v - cnt1[k]);
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
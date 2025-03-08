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
    int n;
    cin >> n;
    vi a(n);
    in(a);

    vi suf(30, n);
    vector<vector<pair<int, int>>> nxt(n);
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < 30; j++) {
            if (!(a[i] >> j & 1)) {
                suf[j] = i;
            } else {
                nxt[i].emplace_back(suf[j], j);
            }
        }
        sort(begin(nxt[i]), end(nxt[i]));
    }

    int q;
    cin >> q;
    while (q--) {
        int l, k;
        cin >> l >> k;

        l--;
        int x = a[l], ans = n - 1;
        if (x < k) {
            cout << -1 << " ";
            continue;
        }
        for (auto [r, j]: nxt[l]) {
            x ^= 1 << j;
            if (x < k) {
                ans = r - 1;
                break;
            }
        }
        cout << ans + 1 << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
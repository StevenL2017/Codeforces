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
    vector<pair<int, int>> a1, a2;
    for (int i = 0; i < m; i++) {
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 1) {
            a1.emplace_back(l - 1, r - 1);
        } else {
            a2.emplace_back(l - 1, r - 1);
        }
    }

    vi ans(n);
    iota(ans.begin(), ans.end(), 1);
    reverse(ans.begin(), ans.end());

    sort(a1.begin(), a1.end());
    for (int i = 0, j = 0; i < ssz(a1); ) {
        int end = a1[i].second;
        while (j < ssz(a1) && a1[j].first <= end) {
            end = max(end, a1[j].second);
            j++;
        }
        for (int k = a1[i].first + 1; k <= end; k++) {
            ans[k] = ans[k - 1];
        }
        i = j;
    }

    for (auto [l, r]: a2) {
        bool ok = false;
        for (int i = l + 1; i <= r; i++) {
            if (ans[i] < ans[i - 1]) {
                ok = true;
                break;
            }
        }
        if (!ok) {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
    out(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
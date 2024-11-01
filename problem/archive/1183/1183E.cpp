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

const ll INF = 1e12;

void solve() {
    int n;
    ll k;
    string s;
    cin >> n >> k >> s;

    vector<vi> lst(n, vi(26, -1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 26; j++) {
            if (i > 0) lst[i][j] = lst[i - 1][j];
        }
        lst[i][s[i] - 'a'] = i;
    }

    vector<vector<ll>> f(n + 1, vector<ll>(n + 1));
    for (int i = 0; i < n; i++) {
        f[i][1] = 1;
    }

    for (int len = 2; len < n; len++) {
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < 26; j++) {
                if (lst[i - 1][j] == -1) continue;
                f[i][len] = min(INF, f[i][len] + f[lst[i - 1][j]][len - 1]);
            }
        }
    }

    ll ans = 0;
    k--;
    for (int len = n - 1; len > 0; len--) {
        ll cnt = 0;
        for (int j = 0; j < 26; j++) {
            if (lst[n - 1][j] != -1) {
                cnt += f[lst[n - 1][j]][len];
            }
        }
        if (cnt < k) {
            ans += cnt * (n - len);
            k -= cnt;
        } else {
            ans += k * (n - len);
            k = 0;
            break;
        }
    }

    if (k == 1) {
        ans += n;
        k--;
    }

    cout << (k > 0 ? -1 : ans) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
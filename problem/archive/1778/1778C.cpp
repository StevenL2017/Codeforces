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

#define ssz(x)              (int)((x).size())
#define sorta(v)            sort(v.begin(), v.end())
#define sortd(v)            sort(v.rbegin(), v.rend())

#define rep(i, n)           for (int i = 0; i < n; i++)
#define repa(i, a, n)       for (int i = a; i < n; i++)
#define repd(i, a, n)       for (int i = a; i > n; i--)

#define endl '\n'
template <class T> void in(vector<T>& a) { rep(i, ssz(a)) cin >> a[i]; }
template <class T> void out(const vector<T>& a) { rep(i, ssz(a)) cout << a[i] << " \n"[i + 1 == ssz(a)]; }

ll calc(string s, string b) {
    int n = ssz(s);
    ll ans = 0;
    for (int i = 0, j = 0; i < n; ) {
        if (s[i] != b[i]) {
            i++;
            j = i;
            continue;
        }
        while (j < n && s[j] == b[j]) {
            j++;
        }
        ans += (j - i) * 1ll * (j - i + 1) / 2;
        i = j;
    }
    return ans;
}

void solve() {
    int n, k; cin >> n >> k;
    string a, b; cin >> a >> b;

    map<char, int> mc;
    int cnt = 0;
    for (auto& c: a) {
        if (!mc.count(c)) {
            mc[c] = cnt++;
        }
    }
    
    ll ans = 0;
    rep(mask, 1 << (cnt + 1)) {
        if (__builtin_popcount(mask) > k) continue;
        string s;
        rep(i, n) {
            int j = mc[a[i]];
            if (mask >> j & 1) {
                s += b[i];
            } else {
                s += a[i];
            }
        }
        ans = max(ans, calc(s, b));
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
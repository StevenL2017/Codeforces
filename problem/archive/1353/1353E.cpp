#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <array>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <algorithm>
#include <functional>
#include <random>
using namespace std;

#define ll long long
#define vi vector<int>

#define ssz(x)              (int)((x).size())
#define sorta(v)            sort(v.begin(), v.end())
#define sortd(v)            sort(v.rbegin(), v.rend())

#define rep(i, n)           for (int i = 0; i < n; ++i)
#define repa(i, a, n)       for (int i = a; i < n; ++i)
#define repd(i, a, n)       for (int i = a; i > n; --i)

#define endl '\n'
template <class T> void in(vector<T>& a) { rep(i, ssz(a)) cin >> a[i]; }
template <class T> void out(const vector<T>& a) { rep(i, ssz(a)) cout << a[i] << " \n"[i + 1 == ssz(a)]; }

const int MOD = 1e9 + 7;
const int INF = 2e9 + 7;
const long long INF_LL = 9e18 + 7;

void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;

    int tot = 0;
    vector<int> ones(k, 0);
    rep(i, n) {
        if (s[i] == '1') {
            tot++;
            ones[i % k]++;
        }
    }

    if (tot <= 1) {
        cout << 0 << endl;
        return;
    }

    vector<vi> f(k, vi(3, 0));
    rep(i, n) {
        int fs = f[i % k][0], fm = f[i % k][1], fe = f[i % k][2];
        int nfs, nfm, nfe;
        if (s[i] == '1') {
            nfs = fs + 1;
            nfm = min(fs, fm);
            nfe = min(fm, fe) + 1;
        } else {
            nfs = fs;
            nfm = min(fs, fm) + 1;
            nfe = min(fm, fe);
        }
        f[i % k][0] = nfs, f[i % k][1] = nfm, f[i % k][2] = nfe;
    }

    int ans = tot - 1;
    rep(i, k) {
        ans = min(ans, *min_element(f[i].begin(), f[i].end()) + tot - ones[i]);
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
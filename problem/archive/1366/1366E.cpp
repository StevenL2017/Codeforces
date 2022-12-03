#include <iostream>
#include <cstdio>
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
#include <random>

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

const int MOD = 998244353;
const int INF = 2e9 + 7;
const long long INF_LL = 9e18 + 7;

void solve() {
    int n, m; cin >> n >> m;
    vi a(n), b(m); in(a), in(b);

    if (m > n) {
        cout << 0 << endl;
        return;
    }

    ll ans = 1;
    int i = n - 1;
    repd(k, m - 1, -1) {
        while (i >= 0 && a[i] > b[k]) {
            i--;
        }
        if (i < 0 || a[i] < b[k]) {
            cout << 0 << endl;
            return;
        }

        int j = i, cnt = 0;
        while (j >= k && a[j] >= b[k]) {
            j--;
            cnt++;
        }
        if (k == 0) {
            if (j >= 0) {
                cout << 0 << endl;
                return;
            }
            break;
        }
        ans *= 1ll * cnt;
        ans %= MOD;
        i--;
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
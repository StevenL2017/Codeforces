#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <tuple>
#include <numeric>
#include <algorithm>
#include <functional>
#include <utility>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

const int MAXN = 1e6 + 7;
const int MOD = 1e9 + 7;
const int INF = 2e9 + 7; // const ll INF = 9e18 + 7;

#define _  %  MOD
#define __ %= MOD

#define sortA(v)               sort(v.begin(), v.end())
#define sortD(v)               sort(v.rbegin(), v.rend())

#define rep(i, n)              for (int i = 0; i < n; ++i)
#define repA(i, a, n)          for (int i = a; i < n; ++i)
#define repD(i, a, n)          for (int i = a; i > n; --i)
#define loop(i, start, end)    for (auto i = start; (start<end)?i<end:i>end; (start<end)?i++:i--)

void solve() {
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    ll even_tot = 0ll, odd_tot = 0ll;
    ll even_cnt = 0ll, odd_cnt = 0ll;
    rep(i, n) {
        cin >> a[i];
        if (a[i] & 1) {
            odd_tot += a[i];
            odd_cnt++;
        } else {
            even_tot += a[i];
            even_cnt++;
        }
    }

    while (q--) {
        int t;
        ll x;
        cin >> t >> x;
        if (t == 0) {
            if (x & 1) {
                odd_tot += even_tot + x * even_cnt;
                even_tot = 0ll;
                odd_cnt += even_cnt;
                even_cnt = 0ll;
            } else {
                even_tot += x * even_cnt;
            }
        } else {
            if (x & 1) {
                even_tot += odd_tot + x * odd_cnt;
                odd_tot = 0ll;
                even_cnt += odd_cnt;
                odd_cnt = 0ll;
            } else {
                odd_tot += x * odd_cnt;
            }
        }
        cout << even_tot + odd_tot << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
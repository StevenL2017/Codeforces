#include <iostream>
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
#include <bitset>
#include <numeric>
#include <algorithm>
#include <functional>
#include <utility>

using namespace std;

const int MAXN = 1e6 + 7;
const int MOD = 1e9 + 7;
const int INF = 2e9 + 7; // const ll INF = 9e18 + 7;

#define _  %  MOD
#define __ %= MOD
#define endl '\n'

#define ll long long
#define vi vector<int>

#define sortA(v)               sort(v.begin(), v.end())
#define sortD(v)               sort(v.rbegin(), v.rend())

#define rep(i, n)              for (int i = 0; i < n; ++i)
#define repA(i, a, n)          for (int i = a; i < n; ++i)
#define repD(i, a, n)          for (int i = a; i > n; --i)

void solve() {
    ll n, k, b, s;
    cin >> n >> k >> b >> s;

    if (s < b * k || s > b * k + n * (k - 1)) {
        cout << -1 << endl;
        return;
    }

    ll diff = s - b * k;
    ll cnt = k > 1 ? (diff / (k - 1)) : 0;
    ll remain = k > 1 ? (diff % (k - 1)) : diff;
    rep(i, n - 1) {
        if (cnt > 0) {
            cout << k - 1 << " ";
            cnt--;
        } else {
            cout << 0 << " ";
        }
    }
    cout << b * k + remain + (cnt > 0 ? k - 1 : 0) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
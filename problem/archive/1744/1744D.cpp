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
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    int cnt = 0;
    vi idx(n, 0);
    rep(i, n) {
        rep(j, 32) {
            if (a[i] & (1 << j)) {
                cnt += j;
                break;
            }
        }
        rep(j, 32) {
            if ((i + 1) & (1 << j)) {
                idx[i] += j;
                break;
            }
        }
    }
    
    sortD(idx);
    int ans = 0;
    for (auto& c: idx) {
        if (cnt >= n) {
            cout << ans << endl;
            return;
        }
        cnt += c;
        ans++;
    }
    if (cnt >= n) {
        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
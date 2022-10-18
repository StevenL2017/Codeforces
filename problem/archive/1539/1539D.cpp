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

const int MAXN = 1e6 + 3;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

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
    vector<ll> a(n), b(n);
    ll tot = 0LL;
    rep(i, n) {
        cin >> a[i] >> b[i];
        tot += a[i];
    }

    ll ans = 0LL, cnt = 0LL;
    vi idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int i, int j) { return b[i] < b[j]; });
    int right = n - 1;
    rep(left, n) {
        if (cnt < b[idx[left]]) {
            while (left < right && cnt < b[idx[left]]) {
                ll d = b[idx[left]] - cnt;
                if (a[idx[right]] <= d) {
                    ans += a[idx[right]] * 2;
                    cnt += a[idx[right]];
                    right--;
                } else {
                    ans += d * 2;
                    cnt += d;
                    a[idx[right]] -= d;
                }
            }
            if (cnt < b[idx[left]]) {
                ll d = b[idx[left]] - cnt;
                ans += min(d, a[idx[left]]) * 2 + a[idx[left]] - min(d, a[idx[left]]);
            } else {
                ans += a[idx[left]];
            }
        } else {
            ans += a[idx[left]];
        }
        cnt += a[idx[left]];
        if (left == right) break;
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
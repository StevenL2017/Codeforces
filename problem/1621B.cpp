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
typedef long double ld;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<ll> vll;
typedef vector<ld> vld;
typedef vector<char> vc;
typedef vector<string> vs;
typedef pair<int, int> ii;

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 3;

#define _  %  MOD
#define __ %= MOD

#define pq(T)                  priority_queue<T, vector<T>>
#define rpq(T)                 priority_queue<T, vector<T>, greater<T>>

#define sortA(v)               sort(v.begin(), v.end())
#define sortD(v)               sort(v.rbegin(), v.rend())

#define rep(i, n)              for(int i = 0; i < n; ++i)
#define repA(i, a, n)          for(int i = a; i < n; ++i)
#define repD(i, a, n)          for(int i = a; i > n; --i)
#define loop(i, start, end)    for(auto i = start; (start<end)?i<end:i>end; (start<end)?i++:i--)

void solve() {
    int n;
    cin >> n;
    int minl = INF, maxr = 0, max_len = 0;
    int lc = INF, rc = INF, lrc = INF;
    int tot = INF;
    rep(i, n) {
        int l, r, c;
        cin >> l >> r >> c;

        if (l < minl) {
            minl = l;
            lc = c;
        } else if (l == minl) {
            lc = min(lc, c);
        }

        if (r > maxr) {
            maxr = r;
            rc = c;
        } else if (r == maxr) {
            rc = min(rc, c);
        }

        if (max_len < r - l + 1) {
            max_len = r - l + 1;
            lrc = c;
        } else if (max_len == r - l + 1) {
            lrc = min(lrc, c);
        }

        int tot = lc + rc;
        if (max_len == maxr - minl + 1) {
            tot = min(tot, lrc);
        }
        cout << tot << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
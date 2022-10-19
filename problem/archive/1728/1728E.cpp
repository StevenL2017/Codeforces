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

long long gcd(long long a, long long b, long long& x, long long& y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	long long x1, y1;
	long long d = gcd(b, a % b, x1, y1);
	x = y1;
	y = x1 - y1 * (a / b);
	return d;
}

bool find_any_solution(long long a, long long b, long long m, long long& x, long long& y, long long& g) {
	g = gcd(abs(a), abs(b), x, y);
	if (m % g) {
		return false;
	}
	x *= m / g;
	y *= m / g;
	if (a < 0) x = -x;
	if (b < 0) y = -y;
	return true;
}

void solve() {
    int n;
    cin >> n;
    vector<vi> dish(n, vi(2));
    ll red = 0;
    vi diff(n);
    rep(i, n) {
        rep(j, 2) {
            cin >> dish[i][j];
            if (j == 0) {
                red += dish[i][j] * 1ll;
            } else {
                diff[i] = dish[i][1] - dish[i][0];
            }
        }
    }
    int m;
    cin >> m;
    vector<vi> shop(m, vi(2));
    rep(i, m) {
        rep(j, 2) {
            cin >> shop[i][j];
        }
    }

    vector<ll> value(n + 1);
    value[0] = red;
    sortD(diff);
    ll pre = 0;
    int max_black_cnt = 0;
    rep(i, n) {
        pre += diff[i] * 1ll;
        value[i + 1] = red + pre;
        if (diff[i] >= 0) {
            max_black_cnt = i + 1;
        }
    }

    rep(i, m) {
        int x = shop[i][0], y = shop[i][1];
        ll x0, y0, g;
        if (!find_any_solution(x, y, n, x0, y0, g)) {
            cout << -1 << endl;
            continue;
        }

        ll ans = -1;
        ll lxy = 1ll * x * y / g;
        ll black = y0 * y;
        black += (max(0ll, max_black_cnt - y0 * y) + lxy - 1) / lxy * lxy;
        black -= (max(0ll, black - max_black_cnt) / lxy * lxy);
        if (0 <= black && black <= n) {
            ans = max(ans, value[black]);
        }
        black -= lxy;
        if (0 <= black && black <= n) {
            ans = max(ans, value[black]);
        }
        cout << ans << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
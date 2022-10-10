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
    ll n;
    cin >> n;

    map<ll, int> cnt;
    ll x = 2, y = n;
    while (x * x <= y) {
        while (y % x == 0) {
            cnt[x]++;
            y /= x;
        }
        x++;
    }

    if (cnt.empty()) {
        cout << 1 << endl;
        cout << n << endl;
        return;
    }

    ll c = 2, maxc = 0;
    for (auto&& [k, v]: cnt) {
        if (v > maxc) {
            maxc = v;
            c = k;
        } else if (v == maxc) {
            c = min(c, k);
        }
    }

    ll tot = 1LL;
    cout << maxc << endl;
    rep(i, maxc - 1) {
        cout << c << " ";
        tot *= c;
    }
    cout << n / tot << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
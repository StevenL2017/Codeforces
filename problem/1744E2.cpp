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

vector<int> factor(int num) {
    vector<int> ans;
    for (int i = 1; i * i <= num; i++) {
        if (num % i == 0) {
            ans.push_back(i);
            if (num / i != i) {
                ans.push_back(num / i);
            }
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    vi fa = factor(a);
    vi fb = factor(b);
    set<ll> fab;
    for (auto& x: fa) {
        for (auto& y: fb) {
            fab.insert((ll)x * y);
        }
    }

    int x = -1, y = -1;
    for (auto& f: fab) {
        ll g = 1ll * a * b / f;
        ll p = f * (a / f + 1);
        ll q = g * (b / g + 1);
        if (p <= c && q <= d) {
            x = p;
            y = q;
        }
    }
    cout << x << " " << y << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
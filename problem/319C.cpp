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

const int MOD = 1e9 + 7;
const int INF = 2e9 + 7;
const long long INF_LL = 9e18 + 7;

long long n_div(long long a, long long b) {
    long long r = (a % b + b) % b;
    return (a - r) / b;
}

long long c_div(long long a, long long b) {
    return n_div(a + b - 1, b);
}

// 求最小值：直线按斜率降序添加，二分求最小值
struct CHT {
private:
    struct line {
        long long k, b;

        long long operator() (long long x) const {
            return k * x + b;
        }

        long long operator& (const line& o) const {
            long long v1 = b - o.b, v2 = o.k - k;
            if (v2 < 0) {
                v1 *= -1;
                v2 *= -1;
            }
            return c_div(v1, v2);
        }
    };

    vector<line> f;
    vector<long long> g;

public:
    void add_line(const line& l) {
        while (!f.empty() && (f.back() & l) <= g.back()) {
            f.pop_back();
            g.pop_back();
        }
        if (f.empty()) g.push_back(-INF_LL);
        else g.push_back(f.back() & l);
        f.push_back(l);
    }

    long long get_min(long long x) {
        int l = 0, r = (int)g.size();
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (g[m] <= x) {
                l = m;
            } else {
                r = m;
            }
        }
        return f[l](x);
    }
};

void solve() {
    int n; cin >> n;
    vector<ll> a(n), b(n);
    in(a), in(b);
    
    vector<ll> f(n, 0);
    CHT cht;
    cht.add_line({b[0], f[0]});

    repa(i, 1, n) {
        f[i] = cht.get_min(a[i]);
        cht.add_line({b[i], f[i]});
    }

    cout << f[n - 1] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
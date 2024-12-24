#include <iostream>
#include <cstdio>
#include <climits>
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

using namespace std;

#define ll long long
#define vi vector<int>
#define ssz(a) (int)((a).size())

#define endl '\n'
template <class T> void in(vector<T>& a) { for (int i = 0; i < ssz(a); i++) cin >> a[i]; }
template <class T> void out(const vector<T>& a) { for (int i = 0; i < ssz(a); i++) cout << a[i] << " \n"[i + 1 == ssz(a)]; }

class BIT {
public:
    int minv, maxv, N;
    long long all;
    long long *tr;

    // 给定定义域 [minv, maxv], 初始化一个树状数组
    BIT(int minv, int maxv) :
        minv(minv), maxv(maxv), N(maxv - minv + 2), all(0) {
        if (minv > maxv) {
            cout << "BIT Init: Value Range Invalid!" << endl;
        } else {
            tr = new long long[N]();
        }
    }

    ~BIT() {
        delete[] tr;
    }

    void add(int x, long long v) {
        if (x < minv || x > maxv) {
            cout << "Add: Index Invalid!" << endl;
        } else {
            all += v;
            x = x - minv + 1;
            while (x < N) {
                tr[x] += v;
                x += x & -x;
            }
        }
    }

    // 求小于等于 x 的值的和
    // 如果求小于，那么用 query_LE(x - 1)
    long long query_LE(int x) {
        x = max(0, min(x - minv + 1, N - 1));
        long long ret = 0;
        while (x) {
            ret += tr[x];
            x -= x & -x;
        }
        return ret;
    }

    // 求大于等于 x 的值的和
    // 如果求大于，那么用 query_BE(x + 1)
    long long query_BE(int x) {
        return all - query_LE(x - 1);
    }
};

void solve() {
    int n;
    cin >> n;
    vi a(n), b(n);
    in(a);
    in(b);

    vi x = a, y = b;
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    for (int i = 0; i < n; i++) {
        if (x[i] != y[i]) {
            cout << "NO" << endl;
            return;
        }
    }

    auto calc = [&] (vi& c, vi& z) -> ll {
        ll ans = 0;
        BIT tree(0, n - 1);
        for (int i = 0; i < n; i++) {
            ans += tree.query_BE(lower_bound(z.begin(), z.end(), c[i]) - z.begin());
            tree.add(lower_bound(z.begin(), z.end(), c[i]) - z.begin(), 1);
        }
        return ans & 1;
    };
    cout << (calc(a, x) == calc(b, y) ? "YES" : "NO") << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
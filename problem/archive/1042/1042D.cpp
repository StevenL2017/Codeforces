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
    ll t;
    cin >> n >> t;
    vi a(n);
    in(a);

    vector<ll> b(1);
    ll pre = 0;
    for (int i = 0; i < n; i++) {
        pre += a[i];
        b.push_back(pre);
        b.push_back(pre - t);
    }
    sort(begin(b), end(b));

    ll ans = 0;
    pre = 0;
    BIT tree(0, ssz(b));
    for (int i = 0; i < n; i++) {
        tree.add(lower_bound(begin(b), end(b), pre) - begin(b), 1);
        pre += a[i];
        ans += tree.query_BE(upper_bound(begin(b), end(b), pre - t) - begin(b));
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
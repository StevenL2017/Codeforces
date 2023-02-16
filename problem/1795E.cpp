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

#define ssz(x)              (int)((x).size())
#define sorta(v)            sort(v.begin(), v.end())
#define sortd(v)            sort(v.rbegin(), v.rend())

#define rep(i, n)           for (int i = 0; i < n; i++)
#define repa(i, a, n)       for (int i = a; i < n; i++)
#define repd(i, a, n)       for (int i = a; i > n; i--)

#define endl '\n'
template <class T> void in(vector<T>& a) { rep(i, ssz(a)) cin >> a[i]; }
template <class T> void out(const vector<T>& a) { rep(i, ssz(a)) cout << a[i] << " \n"[i + 1 == ssz(a)]; }

class BIT {
private:
    int minv, maxv, N;
    long long all;
    long long *tr;
    
public:
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
        x = max(0, min(x - minv + 1, N - 1));
        return all - query_LE(x - 1);
    }
};

void solve() {
    int n; cin >> n;
    vi h(n); in(h);

    int mn = INT_MAX, mx = INT_MIN;
    rep(i, n) {
        mn = min(mn, h[i] - i);
        mx = max(mx, h[i] - i);
    }
    BIT pre_tree(mn, mx), pre_cnt(mn, mx);
    vector<ll> pre(n, 0);
    rep(i, n) {
        int cur = h[i] - i;
        pre[i] = max(0ll, pre_tree.query_BE(cur) - cur * pre_cnt.query_BE(cur));
        pre_tree.add(cur, cur);
        pre_cnt.add(cur, 1);
    }
    mn = INT_MAX, mx = INT_MIN;
    repd(i, n - 1, -1) {
        mn = min(mn, h[i] - (n - 1 - i));
        mx = max(mx, h[i] - (n - 1 - i));
    }
    BIT suf_tree(mn, mx), suf_cnt(mn, mx);
    vector<ll> suf(n, 0);
    repd(i, n - 1, -1) {
        int cur = h[i] - (n - 1 - i);
        suf[i] = max(0ll, suf_tree.query_BE(cur) - cur * suf_cnt.query_BE(cur));
        suf_tree.add(cur, cur);
        suf_cnt.add(cur, 1);
    }
    // out(pre);
    // out(suf);

    ll ans = LLONG_MAX;
    rep(i, n) {
        ans = min(ans, pre[i] + suf[i] + h[i]);
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
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

int cnt[1000010];

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
    int n, m; cin >> n >> m;
    vi a(n); in(a);
    vi b(m); in(b);

    vi v = a;
    for (auto x : b) v.push_back(x);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (auto& x : a) {
        x = lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
    }
    for (auto& x : b) {
        x = lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
    }

    vi pos(m);
    function<void(int, int, int, int)> dfs = [&] (int l, int r, int pl, int pr) {
        int mid = (l + r) / 2;
        int tot = 0;
        for (int i = pl; i <= pr; i++) {
            cnt[i] = tot;
            if (i < n && a[i] > b[mid]) tot++;
        }
        tot = 0;
        for (int i = min(n - 1, pr); i >= pl; i--) {
            if (i < n && a[i] < b[mid]) tot++;
            cnt[i] += tot;
        }

        pos[mid] = pl;
        for (int i = pl; i <= pr; i++) {
            if (cnt[pos[mid]] > cnt[i]) {
                pos[mid] = i;
            }
        }

        if (l < mid) dfs(l, mid - 1, pl, pos[mid]);
        if (mid < r) dfs(mid + 1, r, pos[mid], pr);
    };
    sort(b.begin(), b.end());
    dfs(0, m - 1, 0, n);

    vi c;
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j < m && pos[j] <= i) {
            c.push_back(b[j++]);
        }
        c.push_back(a[i]);
    }
    while (j < m) {
        c.push_back(b[j++]);
    }

    ll ans = 0;
    BIT bit(1, ssz(v));
    for (auto x : c) {
        ans += bit.query_BE(x + 1);
        bit.add(x, 1);
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
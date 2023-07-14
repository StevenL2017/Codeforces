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
    int *tr;

    // 给定定义域 [minv, maxv], 初始化一个树状数组
    BIT(int minv, int maxv) :
        minv(minv), maxv(maxv), N(maxv - minv + 2), all(0) {
        if (minv > maxv) {
            cout << "BIT Init: Value Range Invalid!" << endl;
        } else {
            tr = new int[N]();
            for (int i = 0; i < N; i++) {
                tr[i] = INT_MIN;
            }
        }
    }

    ~BIT() {
        delete[] tr;
    }

    void add(int x, int v) {
        if (x < minv || x > maxv) {
            cout << "Add: Index Invalid!" << endl;
        } else {
            all += v;
            x = x - minv + 1;
            while (x < N) {
                tr[x] = max(tr[x], v);
                x += x & -x;
            }
        }
    }

    int query(int x) {
        x = max(0, min(x - minv + 1, N - 1));
        int ret = INT_MIN;
        while (x) {
            ret = max(ret, tr[x]);
            x -= x & -x;
        }
        return ret;
    }
};

void solve() {
    int n; cin >> n;
    vi a(n); in(a);

    vector<ll> pre(n + 1, 0);
    vector<pair<ll, int>> v;
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + a[i];
        v.emplace_back(pre[i + 1], -(i + 1));
    }

    sort(v.begin(), v.end());
    vi ord(n + 1, 0);
    for (int i = 0; i < n; i++) {
        ord[-v[i].second] = i + 1;
    }

    vi f(n + 1, INT_MIN);
    f[0] = 0;
    BIT tree(1, n);
    for (int i = 1; i <= n; i++) {
        f[i] = max(f[i], f[i - 1] + (a[i - 1] > 0 ? 1 : a[i - 1] < 0 ? -1 : 0));
        if (pre[i] > 0) f[i] = max(f[i], i);
        f[i] = max(f[i], tree.query(ord[i]) + i);
        tree.add(ord[i], f[i] - i);
    }

    cout << f[n] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
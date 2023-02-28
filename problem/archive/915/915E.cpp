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

struct Node {
    int val = 0, lazy = -1;
};

vi x;
vector<Node> s;

void push(int o, int l, int r) {
    if (s[o].lazy != -1) {
        auto m = l + (r - l) / 2;
        s[o * 2].val = (x[m] - x[l]) * s[o].lazy;
        s[o * 2].lazy = s[o].lazy;
        s[o * 2 + 1].val = (x[r] - x[m]) * s[o].lazy;
        s[o * 2 + 1].lazy = s[o].lazy;
        s[o].lazy = -1;
    }
}

void merge(int o) {
    s[o].val = s[o * 2].val + s[o * 2 + 1].val;
}

void update(int o, int l, int r, int L, int R, int k) {
    if (l >= R || r <= L) {
        return;
    }
    if (L <= l && r <= R) {
        s[o].val = (x[r] - x[l]) * k;
        s[o].lazy = k;
        return;
    }
    push(o, l, r);
    int m = l + (r - l) / 2;
    update(o * 2, l, m, L, R, k);
    update(o * 2 + 1, m, r, L, R, k);
    merge(o);
}

void solve() {
    int n, q; cin >> n >> q;

    vi l(q), r(q), k(q);
    x = {0, n};
    rep(i, q) {
        cin >> l[i] >> r[i] >> k[i];
        l[i]--; k[i]--;
        x.push_back(l[i]);
        x.push_back(r[i]);
    }

    sorta(x);
    x.erase(unique(x.begin(), x.end()), x.end());
    int m = ssz(x);
    s.resize(m * 4);
    s[1].val = n;
    s[1].lazy = 1;

    rep(i, q) {
        auto L = lower_bound(x.begin(), x.end(), l[i]) - x.begin();
        auto R = lower_bound(x.begin(), x.end(), r[i]) - x.begin();
        update(1, 0, m - 1, L, R, k[i]);
        cout << s[1].val << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
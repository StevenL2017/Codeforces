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
    int l = 0, r = 0;
    int val = 0, lazy = 0;
};

class SegmentTree {
private:
    vector<Node> s;

public:
    SegmentTree() {}

    SegmentTree(int n) {
        s.resize(n * 4);
        build(1, 1, n);
    }

    int combine(int o1, int o2) {
        if (!o2) return o1;
        if (!o1 || o2 == 1 || o2 == 2) return o2;
        if (o1 == 1) return 2;
        if (o1 == 2) return 1;
        return 0;
    }

    void push(int root) {
        auto l = s[root].l, r = s[root].r;
        if (s[root].lazy) {
            if (s[root].lazy == 1) {
                s[root].val = r - l + 1;
            }
            else if (s[root].lazy == 2) {
                s[root].val = 0;
            }
            else {
                s[root].val = r - l + 1 - s[root].val;
            }
            if (l != r) {
                s[root * 2].lazy = combine(s[root * 2].lazy, s[root].lazy);
                s[root * 2 + 1].lazy = combine(s[root * 2 + 1].lazy, s[root].lazy);
            }
        }
        s[root].lazy = 0;
    }

    void merge(int root) {
        s[root].val = s[root * 2].val + s[root * 2 + 1].val;
    }

    void build(int root, int l, int r) {
        s[root].l = l, s[root].r = r;
        if (l == r) {
            return;
        }
        int m = l + (r - l) / 2;
        build(root * 2, l, m);
        build(root * 2 + 1, m + 1, r);
    }
    
    void update(int root, int L, int R, int val) {
        auto l = s[root].l, r = s[root].r;
        push(root);
        if (l > R || r < L) return;
        if (L <= l && r <= R) {
            s[root].lazy = val;
            push(root);
            return;
        }
        int m = l + (r - l) / 2;
        update(root * 2, L, R, val);
        update(root * 2 + 1, L, R, val);
        merge(root);
    }
    
    int query(int root) {
        auto l = s[root].l, r = s[root].r;
        push(root);
        if (l == r) {
            return l;
        }
        int ans = 0;
        int m = l + (r - l) / 2;
        push(root * 2);
        if (s[root * 2].val < m - l + 1) ans = query(root * 2);
        else ans = query(root * 2 + 1);
        return ans;
    }
};

struct Q {
    int op;
    ll l, r;
};

void solve() {
    int n; cin >> n;
    vector<Q> qs(n);
    map<ll, int> mp;
    mp[1] = 1;
    rep(i, n) {
        cin >> qs[i].op >> qs[i].l >> qs[i].r;
        mp[qs[i].l] = mp[qs[i].r + 1] = 1;
    }

    int m = 0;
    vector<ll> a;
    for (auto& item: mp) {
        mp[item.first] = ++m;
        a.push_back(item.first);
    }

    SegmentTree tree(m);
    for (auto& q: qs) {
        tree.update(1, mp[q.l], mp[q.r + 1] - 1, q.op);
        cout << a[tree.query(1) - 1] << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
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

const int N = 2e5 + 3;

int a[N];

struct Node {
    int l = 0, r = 0;
    long long val = LLONG_MAX, lazy = 0;
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

    void push(int root) {
        auto l = s[root].l, r = s[root].r;
        if (l != r && s[root].lazy != 0) {
            auto m = l + (r - l) / 2;
            s[root * 2].val +=  (m - l + 1) * s[root].lazy;
            s[root * 2].lazy = s[root].lazy;
            s[root * 2 + 1].val += (r - m) * s[root].lazy;
            s[root * 2 + 1].lazy = s[root].lazy;
            s[root].lazy = 0;
        }
    }

    void merge(int root) {
        s[root].val = min(s[root * 2].val, s[root * 2 + 1].val);
    }

    void build(int root, int l, int r) {
        s[root].l = l, s[root].r = r;
        if (l == r) {
            s[root].val = a[l];
            return;
        }
        int m = l + (r - l) / 2;
        build(root * 2, l, m);
        build(root * 2 + 1, m + 1, r);
        merge(root);
    }
    
    void update(int root, int L, int R, int val) {
        auto l = s[root].l, r = s[root].r;
        if (L <= l && r <= R) {
            s[root].val += (r - l + 1) * val;
            s[root].lazy = val;
            return;
        }
        push(root);
        int m = l + (r - l) / 2;
        if (L <= m) update(root * 2, L, R, val);
        if (R > m) update(root * 2 + 1, L, R, val);
        merge(root);
    }
    
    long long query(int root, int L, int R) {
        auto l = s[root].l, r = s[root].r;
        if (L <= l && r <= R) {
            return s[root].val;
        }
        push(root);
        long long ans = LLONG_MAX;
        int m = l + (r - l) / 2;
        if (L <= m) ans = min(ans, query(root * 2, L, R));
        if (R > m) ans = min(ans, query(root * 2 + 1, L, R));
        return ans;
    }
};

void solve() {
    int n, q; cin >> n >> q;
    string s; cin >> s;

    set<int> pre, suf;
    for (int i = 1; i < n; i++) {
        if (s[i - 1] == '(' && s[i] == '(') {
            pre.insert(i);
        }
        if (s[i - 1] == ')' && s[i] == ')') {
            suf.insert(i - 1);
        }
    }

    for (int i = 0; i < n; i++) {
        a[i + 1] = a[i];
        if (s[i] == '(') {
            a[i + 1]++;
        } else {
            a[i + 1]--;
        }
    }

    SegmentTree tree(n);

    while (q--) {
        int idx; cin >> idx;
        idx--;
        
        if (s[idx] == '(') {
            if (idx > 0) {
                if (s[idx - 1] == '(') pre.erase(idx);
                else suf.insert(idx - 1);
            }
            if (idx < n - 1) {
                if (s[idx + 1] == '(') pre.erase(idx + 1);
                else suf.insert(idx);
            }
            tree.update(1, idx + 1, n, -2);
            s[idx] = ')';
        } else {
            if (idx > 0) {
                if (s[idx - 1] == ')') suf.erase(idx - 1);
                else pre.insert(idx);
            }
            if (idx < n - 1) {
                if (s[idx + 1] == ')') suf.erase(idx);
                else pre.insert(idx + 1);
            }
            tree.update(1, idx + 1, n, 2);
            s[idx] = '(';
        }

        if (s.front() != '(' || s.back() != ')') {
            cout << "NO\n";
            continue;
        }

        if (pre.empty() && suf.empty()) {
            auto mn = tree.query(1, 1, n);
            if (mn != 0) {
                cout << "NO\n";
                continue;
            }
        }
        if (!pre.empty()) {
            auto mn1 = tree.query(1, 1, *pre.begin());
            auto mn2 = tree.query(1, *pre.begin() + 1, n);
            if (mn1 != 0 || mn2 > 0 || mn2 < 0 && -mn2 % 2 == 1) {
                cout << "NO\n";
                continue;
            }
        }
        if (!suf.empty()) {
            auto mn1 = tree.query(1, 1, *suf.rbegin());
            auto mn2 = tree.query(1, *suf.rbegin() + 1, n);
            if (mn2 != 0 || mn1 < 0 || mn1 > 0 && mn1 % 2 == 1) {
                cout << "NO\n";
                continue;
            }
        }
        cout << "YES\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
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

const int N = 3e5 + 3;

int a[N];
vector<int> b[N];

class SegmentTree {
private:
    vector<int> s;

public:
    SegmentTree() {}

    SegmentTree(int n) {
        s.resize(n * 4);
        build(1, 1, n);
    }

    int count(int l, int r, int x) {
        return upper_bound(b[x].begin(), b[x].end(), r) - lower_bound(b[x].begin(), b[x].end(), l);
    }

    void build(int root, int l, int r) {
        if (l == r) {
            s[root] = a[l];
            return;
        }
        int m = l + (r - l) / 2;
        build(root * 2, l, m);
        build(root * 2 + 1, m + 1, r);
        s[root] = count(l, r, s[root * 2]) > count(l, r, s[root * 2 + 1]) ? s[root * 2] : s[root * 2 + 1];
    }
    
    int query(int root, int l, int r, int L, int R) {
        if (L <= l && r <= R) {
            return count(L, R, s[root]);
        }
        int m = l + (r - l) / 2;
        if (R <= m) {
            return query(root * 2, l, m, L, R);
        }
        if (L > m) {
            return query(root * 2 + 1, m + 1, r, L, R);
        }
        return max(query(root * 2, l, m, L, R), query(root * 2 + 1, m + 1, r, L, R));
    }
};

void solve() {
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[a[i]].push_back(i);
    }

    SegmentTree tree(n);

    while (q--) {
        int l, r; cin >> l >> r;

        cout << max(1, 2 * tree.query(1, 1, n, l, r) - (r - l + 1)) << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
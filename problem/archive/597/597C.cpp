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

class SegmentTree {
private:
    vector<ll> sum;

public:
    SegmentTree(int n) {
        sum.resize(n * 4, 0);
    }
    
    void update(int root, int l, int r, int idx, ll val) {
        if (l == r) {
            sum[root] += val;
            return;
        }
        int m = l + (r - l) / 2;
        if (idx <= m) {
            update(root * 2, l, m, idx, val);
        } else {
            update(root * 2 + 1, m + 1, r, idx, val);
        }
        sum[root] = sum[root * 2] + sum[root * 2 + 1];
    }
    
    long long query(int root, int l, int r, int L, int R) {
        if (L <= l && r <= R) {
            return sum[root];
        }
        long long tot = 0LL;
        int m = l + (r - l) / 2;
        if (L <= m) {
            tot += query(root * 2, l, m, L, R);
        }
        if (R > m) {
            tot += query(root * 2 + 1, m + 1, r, L, R);
        }
        return tot;
    }
};

void solve() {
    int n, k;
    cin >> n >> k;
    vi a(n);
    in(a);

    vector<SegmentTree> trees(k + 1, SegmentTree(n));
    for (int i = 0; i < n; i++) {
        for (int j = k; j > 0; j--) {
            auto pre = trees[j - 1].query(1, 1, n, 1, a[i]);
            trees[j].update(1, 1, n, a[i], pre);
        }
        trees[0].update(1, 1, n, a[i], 1);
    }
    cout << trees[k].query(1, 1, n, 1, n) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
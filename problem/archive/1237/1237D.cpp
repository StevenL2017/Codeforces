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
    vector<int> mn;

public:
    SegmentTree(int n) {
        mn.resize(n * 4, 2e9);
    }
    
    void update(int root, int l, int r, int idx, int val) {
        if (l == r) {
            mn[root] = val;
            return;
        }
        int m = l + (r - l) / 2;
        if (idx <= m) {
            update(root * 2, l, m, idx, val);
        } else {
            update(root * 2 + 1, m + 1, r, idx, val);
        }
        mn[root] = min(mn[root * 2], mn[root * 2 + 1]);
    }
    
    int query(int root, int l, int r, int L, int R) {
        if (L <= l && r <= R) {
            return mn[root];
        }
        int ans = 2e9;
        int m = l + (r - l) / 2;
        if (L <= m) {
            ans = query(root * 2, l, m, L, R);
        }
        if (R > m) {
            ans = min(ans, query(root * 2 + 1, m + 1, r, L, R));
        }
        return ans;
    }
};

void solve() {
    int n;
    cin >> n;
    vi a(n);
    in(a);

    vi ans(n, -1);
    int mn = *min_element(a.begin(), a.end());
    int mx = *max_element(a.begin(), a.end());
    if (2 * mn >= mx) {
        out(ans);
        return;
    }

    int m = 3 * n;
    SegmentTree tree(m);
    for (int i = 0; i < m; i++) {
        tree.update(1, 1, m, i + 1, a[i % n]);
    }
    int idx_mx = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == mx) {
            idx_mx = i + n;
            break;
        }
    }
    stack<int> s;
    for (int i = idx_mx; i > idx_mx - n; i--) {
        int left = i + 1, right = m;
        int cur = right;
        while (left <= right) {
            int mid = (left + right) / 2;
            int q = tree.query(1, 1, m, i + 1, mid + 1);
            if (2 * q < a[i % n]) {
                right = mid - 1;
                cur = mid;
            } else {
                left = mid + 1;
            }
        }
        while (!s.empty() && a[s.top() % n] < a[i % n]) {
            s.pop();
        }
        if (s.empty()) {
            ans[i % n] = cur - i;
        } else {
            ans[i % n] = min(cur - i, ans[s.top() % n] + s.top() - i);
        }
        s.push(i);
    }

    out(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
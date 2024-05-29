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

// 枚举极小值的贡献，探索每个元素作为极值时两侧的边界
// 左边界严格大于当前元素，右边界大于等于当前元素
vector<vector<int>> min_range(vector<int>& nums){
    int n = nums.size();
    stack<int> st;
    vector<int> left(n, -1), right(n, n);
    for (int i = 0; i < n; i++) {
        while (!st.empty() && nums[i] <= nums[st.top()]) {
            right[st.top()] = i;
            st.pop();
        }
        if (!st.empty()) {
            left[i] = st.top();
        }
        st.push(i);
    }

    vector<vector<int>> ans;
    ans.push_back(left);
    ans.push_back(right);
    return ans;
}

// 枚举极大值的贡献，探索每个元素作为极值时两侧的边界
// 左边界严格小于当前元素，右边界小于等于当前元素
vector<vector<int>> max_range(vector<int>& nums){
    int n = nums.size();
    stack<int> st;
    vector<int> left(n, -1), right(n, n);
    for (int i = 0; i < n; i++) {
        while (!st.empty() && nums[i] >= nums[st.top()]) {
            right[st.top()] = i;
            st.pop();
        }
        if (!st.empty()) {
            left[i] = st.top();
        }
        st.push(i);
    }

    vector<vector<int>> ans;
    ans.push_back(left);
    ans.push_back(right);
    return ans;
}

class SegmentTree {
private:
    vector<int> mn;
    vector<int> mx;

public:
    SegmentTree(int n) {
        mn.resize(n * 4, 2e9);
        mx.resize(n * 4, -2e9);
    }
    
    void update(int root, int l, int r, int idx, int val) {
        if (l == r) {
            mn[root] = mx[root] = val;
            return;
        }
        int m = l + (r - l) / 2;
        if (idx <= m) {
            update(root * 2, l, m, idx, val);
        } else {
            update(root * 2 + 1, m + 1, r, idx, val);
        }
        mn[root] = min(mn[root * 2], mn[root * 2 + 1]);
        mx[root] = max(mx[root * 2], mx[root * 2 + 1]);
    }
    
    int query_mn(int root, int l, int r, int L, int R) {
        if (L <= l && r <= R) {
            return mn[root];
        }
        int ans = 2e9;
        int m = l + (r - l) / 2;
        if (L <= m) {
            ans = query_mn(root * 2, l, m, L, R);
        }
        if (R > m) {
            ans = min(ans, query_mn(root * 2 + 1, m + 1, r, L, R));
        }
        return ans;
    }

    int query_mx(int root, int l, int r, int L, int R) {
        if (L <= l && r <= R) {
            return mx[root];
        }
        int ans = -2e9;
        int m = l + (r - l) / 2;
        if (L <= m) {
            ans = query_mx(root * 2, l, m, L, R);
        }
        if (R > m) {
            ans = max(ans, query_mx(root * 2 + 1, m + 1, r, L, R));
        }
        return ans;
    }
};

void solve() {
    int n; cin >> n;
    vi a(n); in(a);

    auto mn_right = min_range(a)[1];
    auto mx_right = max_range(a)[1];

    vi idx(n);
    SegmentTree tree(n);
    for (int i = 0; i < n; i++) {
        idx[a[i] - 1] = i;
        tree.update(1, 1, n, i + 1, a[i] - 1);
    }

    int ans = 0, i = 0;
    while (i < n - 1) {
        ans++;
        if (a[i] < a[i + 1]) {
            int cur_mx = tree.query_mx(1, 1, n, i + 1, mn_right[i]);
            i = idx[cur_mx];
        } else {
            int cur_mn = tree.query_mn(1, 1, n, i + 1, mx_right[i]);
            i = idx[cur_mn];
        }
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
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <tuple>
#include <algorithm>
#include <functional>
#include <utility>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<ll> vll;
typedef vector<ld> vld;
typedef vector<char> vc;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 3;

#define _  %  MOD
#define __ %= MOD

#define pq(T)                  priority_queue<T, vector<T>>
#define rpq(T)                 priority_queue<T, vector<T>, greater<T>>

#define sortA(v)               sort(v.begin(), v.end())
#define sortD(v)               sort(v.rbegin(), v.rend())

#define rep(i, n)              for(int i = 0; i < n; ++i)
#define repA(i, a, n)          for(int i = a; i < n; ++i)
#define repD(i, a, n)          for(int i = a; i > n; --i)
#define loop(i, start, end)    for(auto i = start; (start<end)?i<end:i>end; (start<end)?i++:i--)

const ll NINF = -1e15;

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
    vll mx;

public:
    SegmentTree(int n) {
        mx.resize(n * 4, NINF);
    }
    
    void update(int root, int l, int r, int idx, ll val) {
        if (l == r) {
            mx[root] = val;
            return;
        }
        int m = l + (r - l) / 2;
        if (idx <= m) {
            update(root * 2, l, m, idx, val);
        } else {
            update(root * 2 + 1, m + 1, r, idx, val);
        }
        mx[root] = max(mx[root * 2], mx[root * 2 + 1]);
    }
    
    ll query(int root, int l, int r, int L, int R) {
        if (L <= l && r <= R) {
            return mx[root];
        }
        ll ans = 0LL;
        int m = l + (r - l) / 2;
        if (L <= m) {
            ans = query(root * 2, l, m, L, R);
        }
        if (R > m) {
            ans = max(ans, query(root * 2 + 1, m + 1, r, L, R));
        }
        return ans;
    }
};

void solve() {
    int n;
    cin >> n;
    vi nums(n);
    for (auto &x : nums) cin >> x;

    vll pre(n), suf(n);
    pre[0] = nums[0];
    repA(i, 1, n) {
        pre[i] = pre[i - 1] + nums[i];
    }
    suf[n - 1] = nums[n - 1];
    repD(i, n - 2, -1) {
        suf[i] = suf[i + 1] + nums[i];
    }

    vector<vi> maxlr = max_range(nums);
    vector<int> maxl = maxlr[0];
    vector<int> maxr = maxlr[1];

    SegmentTree pre_tree(n), suf_tree(n);
    rep(i, n) {
        pre_tree.update(1, 1, n, i + 1, pre[i]);
        suf_tree.update(1, 1, n, i + 1, suf[i]);
    }

    rep(i, n) {
        ll left_max = 0LL, right_max = 0LL;
        if (i > 0 && maxl[i] + 1 <= i - 1) {
            left_max = suf_tree.query(1, 1, n, maxl[i] + 1 + 1, i - 1 + 1) - suf[i];
        }
        if (i < n - 1 && i + 1 <= maxr[i] - 1) {
            right_max = pre_tree.query(1, 1, n, i + 1 + 1, maxr[i] - 1 + 1) - pre[i];
        }
        if (left_max > 0 || right_max > 0) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
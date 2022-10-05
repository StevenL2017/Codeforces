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

ll query(vector<ll> &tree, int node, int ns, int ne, int qs, int qe) {
    if (qe < ns || qs > ne) return NINF;
    if (qs <= ns && ne <= qe) return tree[node];
 
    int mid = ns + (ne - ns) / 2;
    ll leftQuery = query(tree, 2 * node, ns, mid, qs, qe);
    ll rightQuery = query(tree, 2 * node + 1, mid + 1, ne, qs, qe);
    return max(leftQuery, rightQuery);
}

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

    // Round off n to next power of 2
    int _n = n;
    while (__builtin_popcount(_n) != 1) _n++;

    // Two max-segtrees, one on the prefix sums, one on the suffix sums
    vector<ll> pre_tree(2 * _n, NINF), suf_tree(2 * _n, NINF);

    for (int i = 0; i < n; i++) {
        pre_tree[_n + i] = pre[i];
        suf_tree[_n + i] = suf[i];
    }

    for (int i = _n - 1; i >= 1; i--) {
        pre_tree[i] = max(pre_tree[2 * i], pre_tree[2 * i + 1]);
        suf_tree[i] = max(suf_tree[2 * i], suf_tree[2 * i + 1]);
    }

    rep(i, n) {
        ll right_max = query(pre_tree, 1, 0, _n - 1, i + 1, maxr[i] - 1) - pre[i];
        ll left_max = query(suf_tree, 1, 0, _n - 1, maxl[i] + 1, i - 1) - suf[i];
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
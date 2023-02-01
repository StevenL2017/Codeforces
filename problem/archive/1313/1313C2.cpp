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

void solve() {
    int n; cin >> n;
    vi m(n); in(m);

    auto range = min_range(m);
    auto left = range[0], right = range[1];

    vector<ll> pre(n, 0);
    rep(i, n) {
        if (left[i] == -1) {
            pre[i] = (i + 1) * 1ll * m[i];
        } else {
            pre[i] = pre[left[i]] + (i - left[i]) * 1ll * m[i];
        }
    }
    
    vector<ll> suf(n, 0);
    repd(i, n - 1, -1) {
        if (right[i] == n) {
            suf[i] = (n - i) * 1ll * m[i];
        } else {
            suf[i] = suf[right[i]] + (right[i] - i) * 1ll * m[i];
        }
    }
    
    int idx = -1;
    ll mx = 0;
    rep(i, n) {
        ll cur = pre[i] + suf[i] - m[i];
        if (cur > mx) {
            idx = i;
            mx = cur;
        }
    }

    vi ans(n, 0);
    int cur = m[idx];
    repd(i, idx, -1) {
        cur = min(cur, m[i]);
        ans[i] = cur;
    }
    cur = m[idx];
    repa(i, idx, n) {
        cur = min(cur, m[i]);
        ans[i] = cur;
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
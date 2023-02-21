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
    vi a(n); in(a);

    vector<vector<ll>> f(2, vector<ll>(n, 0));
    rep(i, 2) {
        vi b(n);
        rep(i, n) b[i] = a[i] - i;
        auto range = min_range(b);
        auto left = range[0], right = range[1];
        rep(j, n) {
            int k = max(left[j], j - a[j]);
            auto x = j - k;
            f[i][j] = x * 1ll * a[j] - x * 1ll * (x - 1) / 2;
            if (k >= 0 && x < a[j]) {
                f[i][j] += f[i][k];
            }
        }
        reverse(a.begin(), a.end());
    }
    reverse(f[1].begin(), f[1].end());

    ll ans = LLONG_MAX, tot = 0;
    rep(i, n) {
        tot += a[i];
    }
    rep(i, n) {
        ans = min(ans, tot - f[0][i] - f[1][i] + 2ll * a[i]);
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
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

void solve() {
    ll n, s, x;
    cin >> n >> s >> x;
    vi a(n);
    in(a);

    auto r = max_range(a);
    auto left = r[0], right = r[1];

    vector<ll> pre(n + 1);
    vector<pair<int, int>> cand;
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + a[i];
        if (a[i] == x) {
            if (cand.empty() || cand.back().second <= left[i]) {
                cand.emplace_back(left[i], right[i]);
            } else {
                cand.back().second = max(cand.back().second, right[i]);
            }
        }
    }

    ll ans = 0;
    for (auto [l, r]: cand) {
        map<ll, int> cnt;
        int idx = n;
        for (int i = l + 1, j = l + 1; i <= r; i++) {
            if (i > idx) {
                ans += cnt[pre[i] - s];
            }
            if (i < n && a[i] == x) {
                while (j <= i) {
                    cnt[pre[j]]++;
                    j++;
                }
                idx = i;
            }
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
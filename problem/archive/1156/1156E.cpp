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
    int n; cin >> n;
    vi a(n); in(a);

    vi b(n);
    rep(i, n) {
        b[a[i] - 1] = i;
    }

    auto range = max_range(a);
    auto left = range[0], right = range[1];

    int ans = 0;
    rep(i, n) {
        int left_len = i - left[i], right_len = right[i] - i;
        if (left_len < right_len) {
            repd(j, i - 1, left[i]) {
                int l = a[j], r = a[i] - l;
                if (r >= 1 && r <= n && b[r - 1] > i && b[r - 1] < right[i]) {
                    ans++;
                }
            }
        } else {
            repa(j, i + 1, right[i]) {
                int r = a[j], l = a[i] - r;
                if (l >= 1 && l <= n && b[l - 1] > left[i] && b[l - 1] < i) {
                    ans++;
                }
            }
        }
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
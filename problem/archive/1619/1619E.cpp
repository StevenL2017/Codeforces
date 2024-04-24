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

void solve() {
    int n; cin >> n;
    vi a(n); in(a);

    vi cnt(n + 1);
    for (auto x: a) {
        cnt[x]++;
    }

    sort(a.begin(), a.end());
    ll s = 0;
    stack<int> st;
    vector<ll> ans(n + 1, -1);
    for (int i = 0; i <= n; i++) {
        if (i > 0 && cnt[i - 1] == 0) {
            if (st.empty()) {
                break;
            }
            int j = st.top();
            st.pop();
            s += i - j - 1;
        }

        ans[i] = s + cnt[i];

        while (i > 0 && cnt[i - 1] > 1) {
            cnt[i - 1]--;
            st.push(i - 1);
        }
    }

    out(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
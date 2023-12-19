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

const int MOD = 998244353;

void solve() {
    int n; cin >> n;
    vi a(n); in(a);

    vi f(n), pre(n + 1);
    stack<int> st;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && a[st.top()] > a[i]) {
            ans -= f[st.top()];
            st.pop();
        }
        int j = st.empty() ? 0 : st.top() + 1;
        f[i] = (ans + pre[i] - pre[j] + st.empty()) % MOD;
        pre[i + 1] = (pre[i] + f[i]) % MOD;
        ans = (ans + f[i]) % MOD;
        st.push(i);
    }
    cout << (ans + MOD) % MOD << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
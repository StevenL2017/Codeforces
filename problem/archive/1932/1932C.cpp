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
    int n, m;
    cin >> n >> m;
    vi a(n);
    in(a);
    string s;
    cin >> s;

    vi st;
    for (int i = 0, j = 0, k = n - 1; i < n; i++) {
        if (s[i] == 'L') {
            st.push_back(a[j++]);
        } else {
            st.push_back(a[k--]);
        }
    }

    vi ans;
    int mul = 1;
    while (!st.empty()) {
        int x = st.back();
        st.pop_back();
        mul = (mul * 1ll * x) % m;
        ans.push_back(mul);
    }
    reverse(ans.begin(), ans.end());

    out(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
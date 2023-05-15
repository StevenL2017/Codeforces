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

const int N = 3e5 + 3;
const int K = 19;

int a[N], r[N], rmq[K][N];

void solve() {
    int n; cin >> n;
    ll ans = 0;
    a[0] = a[n + 1] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        rmq[0][i] = a[i];
        ans += i * 1ll * (i - 1) / 2;
    }

    vi st;
    st.push_back(n + 1);
    for (int i = n; i > 0; i--) {
        while (!st.empty() && a[st.back()] > a[i]) {
            st.pop_back();
        }
        r[i] = st.back();
        st.push_back(i);
    }

    for (int k = 1; k < K; k++) {
        for (int i = 1; i <= n; i++) {
            rmq[k][i] = max(rmq[k - 1][i], rmq[k - 1][i - (1 << (k - 1))]);
        }
    }

    st.clear();
    st.push_back(0);
    for (int i = 1; i <= n; i++) {
        while (!st.empty() && a[st.back()] > a[i]) {
            st.pop_back();
        }
        int j = st.back();
        for (int k = K - 1; k >= 0; k--) {
            if (j >= (1 << k) && rmq[k][j] < a[i]) {
                j -= 1 << k;
            }
        }
        ans -= (r[i] - i) * 1ll * (st.back() - j);
        st.push_back(i);
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
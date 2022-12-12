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

void solve() {
    int n; cin >> n;
    vi h(n); in(h);

    vi lgt(n, -1), llt(n, -1);
    vi rgt(n, -1), rlt(n, -1);
    vi st;
    rep(i, n) {
        while (!st.empty() && h[st.back()] < h[i]) {
            st.pop_back();
        }
        if (!st.empty()) {
            lgt[i] = st.back();
        }
        st.push_back(i);
    }
    st.clear();
    rep(i, n) {
        while (!st.empty() && h[st.back()] > h[i]) {
            st.pop_back();
        }
        if (!st.empty()) {
            llt[i] = st.back();
        }
        st.push_back(i);
    }
    st.clear();
    repd(i, n - 1, -1) {
        while (!st.empty() && h[st.back()] < h[i]) {
            st.pop_back();
        }
        if (!st.empty()) {
            rgt[i] = st.back();
        }
        st.push_back(i);
    }
    st.clear();
    repd(i, n - 1, -1) {
        while (!st.empty() && h[st.back()] > h[i]) {
            st.pop_back();
        }
        if (!st.empty()) {
            rlt[i] = st.back();
        }
        st.push_back(i);
    }

    vector<vi> graph(n);
    rep(i, n) {
        if (lgt[i] != -1) graph[lgt[i]].push_back(i);
        if (llt[i] != -1) graph[llt[i]].push_back(i);
        if (rgt[i] != -1) graph[i].push_back(rgt[i]);
        if (rlt[i] != -1) graph[i].push_back(rlt[i]);
    }

    vi f(n, n + 1);
    f[0] = 0;
    rep(i, n) {
        for (auto& nxt: graph[i]) {
            f[nxt] = min(f[nxt], f[i] + 1);
        }
    }
    cout << f.back() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
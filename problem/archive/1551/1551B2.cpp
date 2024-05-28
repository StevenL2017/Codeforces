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
    int n, k;
    cin >> n >> k;
    vi a(n);
    in(a);

    vi cnt(n + 1);
    vector<vi> idx(n + 1);
    for (int i = 0; i < n; i++) {
        cnt[a[i]]++;
        idx[a[i]].push_back(i);
    }

    vi st(n + 1);
    iota(st.begin(), st.end(), 0);
    sort(st.begin(), st.end(), [&] (int i, int j) { return cnt[i] > cnt[j]; });

    int j = 0, s = n;
    while (j < n && cnt[st[j]] >= k) {
        s -= cnt[st[j++]];
    }
    int tot = k * j + s / k * k;

    vi ans(n);
    for (int i = 0, j = 0; i < n && j < tot; i++) {
        for (int z = 0; z < min(k, ssz(idx[st[i]])) && j < tot; z++) {
            ans[idx[st[i]][z]] = j % k + 1;
            j++;
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
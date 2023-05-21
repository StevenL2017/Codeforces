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
    int n, k; cin >> n >> k;
    vi a(n); in(a);
    vi b(n); in(b);

    vi idx1(n), idx2(n);
    iota(idx1.begin(), idx1.end(), 0);
    sort(idx1.begin(), idx1.end(), [&] (int i, int j) { return a[i] < a[j]; });
    iota(idx2.begin(), idx2.end(), 0);
    sort(idx2.begin(), idx2.end(), [&] (int i, int j) { return b[i] < b[j]; });

    vi ans(n);
    for (int i = 0; i < n; i++) {
        ans[idx1[i]] = b[idx2[i]];
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
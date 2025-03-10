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

    int mx = *max_element(begin(a), end(a)), tot = 0, len = 0;
    vi cnt(mx + 1), ans(2);
    for (int l = 0, r = 0; r < n; r++) {
        if (cnt[a[r]] == 0) {
            tot++;
        }
        cnt[a[r]]++;
        while (l < r && tot > k) {
            cnt[a[l]]--;
            if (cnt[a[l]] == 0) {
                tot--;
            }
            l++;
        }
        int cur = r - l + 1;
        if (cur > len) {
            len = cur;
            ans = {l + 1, r + 1};
        }
    }
    out(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
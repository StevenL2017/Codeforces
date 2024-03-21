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

int calc(vector<string>& a, char c) {
    int n = ssz(a), tot = 0, cnt = 0;
    vi d(n);
    for (int i = 0; i < n; i++) {
        for (auto ch: a[i]) {
            tot++;
            if (ch == c) {
                cnt++;
                d[i]++;
            } else {
                d[i]--;
            }
        }
    }
    vi idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&] (int i, int j) { return d[i] < d[j]; });
    for (int i = 0; i < n; i++) {
        if (cnt * 2 > tot) {
            return n - i;
        }
        int j = idx[i];
        cnt -= (ssz(a[j]) + d[j]) / 2;
        tot -= ssz(a[j]);
    }
    return 0;
}

void solve() {
    int n;
    cin >> n;
    vector<string> a(n);
    in(a);

    int ans = 0;
    for (int i = 0; i < 5; i++) {
        ans = max(ans, calc(a, i + 'a'));
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
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
    string s; cin >> s;

    vi lower(26, 0), upper(26, 0);
    for (auto c : s) {
        if (islower(c)) {
            lower[c - 'a']++;
        } else {
            upper[c - 'A']++;
        }
    }

    int ans = 0;
    for (int i = 0; i < 26; i++) {
        int d = abs(lower[i] - upper[i]) / 2;
        ans += min(lower[i], upper[i]) + min(k, d);
        k = max(0, k - d);
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
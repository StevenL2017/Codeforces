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
    string s; cin >> s;

    vi cnt;
    int i = 0;
    while (i < n) {
        int i0 = i++;
        while (i < n && s[i] == s[i0]) {
            i++;
        }
        if (!cnt.empty() && i == n && s[i0] == s[0]) {
            cnt[0] += i - i0;
        } else {
            cnt.push_back(i - i0);
        }
    }

    if (ssz(cnt) == 1) {
        cout << (cnt[0] + 2) / 3 << endl;
        return;
    }

    int ans = 0;
    for (auto x : cnt) {
        ans += x / 3;
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
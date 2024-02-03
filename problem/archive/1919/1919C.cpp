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
    vi a(n); in(a);

    int ans = 0;
    vi s(1, INT_MAX), t(1, INT_MAX);
    for (int i = 0; i < n; i++) {
        if (s.back() < a[i] && t.back() < a[i]) {
            if (s.back() < t.back()) {
                s.push_back(a[i]);
            } else {
                t.push_back(a[i]);
            }
            ans++;
        } else if (s.back() >= a[i] && t.back() >= a[i]) {
            if (s.back() < t.back()) {
                s.push_back(a[i]);
            } else {
                t.push_back(a[i]);
            }
        } else {
            if (s.back() <= t.back()) {
                t.push_back(a[i]);
            } else {
                s.push_back(a[i]);
            }
        }
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
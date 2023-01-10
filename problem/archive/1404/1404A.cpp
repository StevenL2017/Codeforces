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
    int n, k; cin >> n >> k;
    string s; cin >> s;

    int c0 = 0, c1 = 0;
    rep(i, k) {
        bool has0 = false, has1 = false;
        for (int j = i; j < n; j += k) {
            if (s[j] == '0') has0 = true;
            else if (s[j] == '1') has1 = true;
        }
        if (has0 && has1) {
            cout << "NO\n";
            return;
        }
        else if (has0) {
            s[i] = '0';
        }
        else if (has1) {
            s[i] = '1';
        }
        if (s[i] == '0') c0++;
        else if (s[i] == '1') c1++;
    }

    if (c0 > k / 2 || c1 > k / 2) cout << "NO\n";
    else cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
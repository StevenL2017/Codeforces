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
    int n;
    cin >> n;
    vi a(n), c(n);
    in(a);
    in(c);

    int ans = 1e9;
    for (int i = 1; i < n - 1; i++) {
        int pre = 1e9;
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i] && c[j] < pre) {
                pre = c[j];
            }
        }
        int suf = 1e9;
        for (int j = i + 1; j < n; j++) {
            if (a[j] > a[i] && c[j] < suf) {
                suf = c[j];
            }
        }
        ans = min(ans, pre + c[i] + suf);
    }
    cout << (ans < 1e9 ? ans : -1) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
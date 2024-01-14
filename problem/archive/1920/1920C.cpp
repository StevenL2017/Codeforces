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
    for (int i = 1; i * i <= n; i++) {
        if (n % i != 0) continue;
        int g = 0;
        for (int j = 0; j < i; j++) {
            for (int k = j + i; k < n; k += i) {
                g = gcd(g, abs(a[k] - a[k - i]));
            }
        }
        if (g != 1) ans++;
        if (i * i == n) continue;
        g = 0;
        for (int j = 0; j < n / i; j++) {
            for (int k = j + n / i; k < n; k += n / i) {
                g = gcd(g, abs(a[k] - a[k - n / i]));
            }
        }
        if (g != 1) ans++;
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
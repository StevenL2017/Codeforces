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

const int MAXN = 1e7 + 1;

int mn_prime[MAXN];

void eratosthenes_mn(int n) {
    mn_prime[0] = mn_prime[1] = 1;
    for (int i = 2; i <= n; i++) {
        mn_prime[i] = n + 1;
    }
    for (int i = 2; i <= n; i++) {
        if (mn_prime[i] == n + 1) {
            mn_prime[i] = 1;
            for (int j = i + i; j <= n; j += i) {
                mn_prime[j] = min(mn_prime[j], i);
            }
        }
    }
}

void solve() {
    int x, y; cin >> x >> y;
 
    auto g = gcd(x, y);
    if (g != 1) {
        cout << 0 << endl;
        return;
    }
    
    if ((x & 1) && (y & 1)) {
        cout << 1 << endl;
        return;
    }
 
    if (x + 1 == y) {
        cout << -1 << endl;
        return;
    }
 
    auto d = y - x;
    int ans = d - x % d, z = mn_prime[d];
    while (z != 1) {
        ans = min(ans, z - x % z);
        d /= z;
        z = mn_prime[d];
        ans = min(ans, d - x % d);
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    eratosthenes_mn(MAXN);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
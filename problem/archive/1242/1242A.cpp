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
    ll n;
    cin >> n;

    int mn_prime = 1;
    ll x = 2;
    while (x * x <= n) {
        if (n % x == 0) {
            mn_prime = x;
            break;
        }
        x++;
    }

    if (mn_prime == 1) {
        cout << n << endl;
        return;
    }

    while (n % x == 0) {
        n /= mn_prime;
    }

    if (n == 1) {
        cout << mn_prime << endl;
        return;
    }

    cout << 1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
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
    vi a(n);
    in(a);

    vi idx(n), b(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&] (int i, int j) { return a[i] < a[j]; });
    for (int i = 0; i < n; i += 2) {
        if (i == n - 3) {
            if (a[idx[i + 1]] + a[idx[i + 2]] != 0) {
                int x = a[idx[i]], y = a[idx[i + 1]] + a[idx[i + 2]];
                int g = gcd(x, y);
                b[idx[i]] = -y / g;
                b[idx[i + 1]] = x / g;
                b[idx[i + 2]] = x / g;
            } else {
                int x = a[idx[i]] + a[idx[i + 1]], y = a[idx[i + 2]];
                int g = gcd(x, y);
                b[idx[i]] = -y / g;
                b[idx[i + 1]] = -y / g;
                b[idx[i + 2]] = x / g;
            }
            break;
        }
        int x = a[idx[i]], y = a[idx[i + 1]];
        int g = gcd(x, y);
        b[idx[i]] = -y / g;
        b[idx[i + 1]] = x / g;
    }

    out(b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
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
    ll k;
    cin >> n >> k;
    vi a(n);
    in(a);

    int i = 0, j = n - 1;
    while (i <= j && k > 0) {
        if (i == j) {
            if (k >= a[i]) {
                cout << n << endl;
            } else {
                cout << n - 1 << endl;
            }
            return;
        }
        int d = min(a[i], a[j]);
        if (k >= 2 * d) {
            a[i] -= d;
            a[j] -= d;
            k -= 2 * d;
        } else {
            a[i] -= k / 2 + k % 2;
            a[j] -= k / 2;
            k = 0;
        }
        if (!a[i]) i++;
        if (!a[j]) j--;
    }
    if (a[i] && k >= a[i]) i++;
    cout << i + n - j - 1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
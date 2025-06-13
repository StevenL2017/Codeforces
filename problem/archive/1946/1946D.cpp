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
    int n, x;
    cin >> n >> x;
    vi a(n);
    in(a);

    int ans = -1;
    x++;
    for (int i = 30; i >= 0; i--) {
        vi b;
        bool odd = false;
        for (auto z: a) {
            if (!odd) {
                b.push_back(z);
            } else {
                b.back() ^= z;
            }
            if (z >> i & 1) {
                odd = !odd;
            }
        }
        if (x >> i & 1) {
            if (!odd) {
                ans = max(ans, ssz(b));
            }
        } else {
            if (odd) {
                cout << ans << endl;
                return;
            }
            a = b;
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
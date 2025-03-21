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

ll calc(int r) {
    ll ans = 0;
    int y = r;
    for (int x = 0; x <= r; x++) {
        while (y > 0 && x * 1ll * x + y * 1ll * y >= r * 1ll * r) {
            y--;
        }
        if (y == 0) {
            break;
        }
        ans += y;
    }
    return ans * 4;
}

void solve() {
    int r;
    cin >> r;

    cout << calc(r + 1) - calc(r) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
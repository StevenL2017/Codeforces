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

    int ans = 0, p1 = 0, p2 = 0;
    for (int i = 0; i < n; i++) {
        if (!p1 && !p2) {
            if (a[i] == 0) continue;
            ans++;
            if (a[i] <= 2) p1 = 1;
        } else if (p1) {
            p1 = 0;
            if (a[i] <= 2) continue;
            ans++;
            if (a[i] <= 4) p2 = 1;
        } else if (p2) {
            p2 = 0;
            if (a[i] == 0) continue;
            ans++;
            if (a[i] <= 4) p1 = 1;
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
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
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = i; j < n; j++) {
            if (!a[j]) cnt++;
            int i0 = i, j0 = j, c = cnt;
            while (i0 - 1 >= 0) {
                i0--;
                if (a[i0]) c++;
            }
            while (j0 + 1 < n) {
                j0++;
                if (a[j0]) c++;
            }
            ans = max(ans, c);
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
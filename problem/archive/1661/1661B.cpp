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

const int N = 32768;

void solve() {
    int n; cin >> n;
    vi a(n); in(a);

    for (auto x: a) {
        int ans = 15;
        for (int cnt_mul = 0; cnt_mul <= 15; cnt_mul++) {
            for (int cnt_add = 0; cnt_add <= 15; cnt_add++) {
                if ((x + cnt_add) * (int)(pow(2, cnt_mul)) % N == 0) {
                    ans = min(ans, cnt_mul + cnt_add);
                }
            }
        }
        cout << ans << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
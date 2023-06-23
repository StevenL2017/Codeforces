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
    int n, U, R, D, L;
    cin >> n >> U >> R >> D >> L;
    
    auto check = [&] (int mask) -> bool {
        int u = 0, r = 0, d = 0, l = 0;
        for (int i = 0; i < 4; i++) {
            if (mask >> i & 1) {
                if (i == 0) {
                    u++; l++;
                }
                else if (i == 1) {
                    u++; r++;
                }
                else if (i == 2) {
                    l++; d++;
                }
                else {
                    r++; d++;
                }
            }
        }
        return u <= U && r <= R && d <= D && l <= L && U - u <= n - 2 && R - r <= n - 2 && D - d <= n - 2 && L - l <= n - 2;
    };

    for (int i = 0; i < (1 << 4); i++) {
        if (check(i)) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
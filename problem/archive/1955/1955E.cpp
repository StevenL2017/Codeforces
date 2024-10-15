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
    string s;
    cin >> s;

    vi a(n);
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') a[i] = 1;
    }

    for (int k = n; k > 0; k--) {
        vi b = a, d(n + 1);
        int i = 0, cur = 0;
        while (i < n) {
            cur += d[i];
            if (b[i] ^ (cur & 1) == 0) {
                if (i + k > n) break;
                d[i + k]--;
                cur++;
            }
            i++;
        }
        if (i == n) {
            cout << k << endl;
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
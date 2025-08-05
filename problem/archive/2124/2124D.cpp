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
    int n, k;
    cin >> n >> k;
    vi a(n);
    in(a);

    if (k == 1) {
        cout << "YES" << endl;
        return;
    }

    vi b = a;
    sort(begin(b), end(b));
    int target = b[k - 2];

    vi c;
    for (auto x: a) {
        if (x <= target) {
            c.push_back(x);
        }
    }

    bool ok = true;
    int l = 0, r = ssz(c) - 1, m = ssz(c);
    while (l < r) {
        if (c[l] != c[r]) {
            if (m < k) {
                ok = false;
                break;
            }
            if (c[l] != target && c[r] != target) {
                ok = false;
                break;
            } else if (c[l] == target) {
                l++;
                m--;
            } else if (c[r] == target) {
                r--;
                m--;
            }
            continue;
        }
        l++;
        r--;
    }

    if (ok) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
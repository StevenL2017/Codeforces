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
    vi a(n), b(n);
    in(a);
    in(b);

    int x = 0, y = 0, pos = 0, neg = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 1 && b[i] == 1) {
            pos++;
        }
        else if (a[i] == -1 && b[i] == -1) {
            neg++;
        }
        else {
            if (a[i] >= b[i]) x += a[i];
            else y += b[i];
        }
    }

    while (pos) {
        if (x > y) y++;
        else x++;
        pos--;
    }
    while (neg) {
        if (x > y) x--;
        else y--;
        neg--;
    }

    cout << min(x, y) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
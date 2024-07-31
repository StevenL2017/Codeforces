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
    int a, b, c;
    cin >> a >> b >> c;

    if (a != c - 1) {
        cout << -1 << endl;
        return;
    }
    if (a + b + c == 1) {
        cout << 0 << endl;
        return;
    }

    int ans = 1, cur = 1, nxt = 0;
    for (int i = 0; i < a + b; i++) {
        if (!cur) {
            swap(cur, nxt);
            ans++;
        }
        cur--;
        nxt++;
        if (i < a) nxt++;
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
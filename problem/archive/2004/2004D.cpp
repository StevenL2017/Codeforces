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

const int INF = 1e9;
const string portal[] = {"BG", "BR", "BY", "GR", "GY", "RY"};

void solve() {
    int n, q;
    cin >> n >> q;
    vi a(n);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        a[i] = find(portal, portal + 6, s) - portal;
    }

    vector<vi> left(n), right(n);
    for (int op = 0; op < 2; op++) {
        vi prev(6, -INF);
        for (int i = 0; i < n; i++) {
            prev[a[i]] = (op == 0 ? i : n - 1 - i);
            (op == 0 ? left[i] : right[n - 1 - i]) = prev;
        }
        reverse(a.begin(), a.end());
    }

    while (q--) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        int ans = INF;
        for (int i = 0; i < 6; i++) {
            if (a[x] + i != 5 && a[y] + i != 5) {
                ans = min(ans, abs(x - left[x][i]) + abs(y - left[x][i]));
                ans = min(ans, abs(x - right[x][i]) + abs(y - right[x][i]));
            }
        }
        if (ans > INF / 2) ans = -1;
        cout << ans << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
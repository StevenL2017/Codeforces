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

#define ssz(x)              (int)((x).size())
#define sorta(v)            sort(v.begin(), v.end())
#define sortd(v)            sort(v.rbegin(), v.rend())

#define rep(i, n)           for (int i = 0; i < n; i++)
#define repa(i, a, n)       for (int i = a; i < n; i++)
#define repd(i, a, n)       for (int i = a; i > n; i--)

#define endl '\n'
template <class T> void in(vector<T>& a) { rep(i, ssz(a)) cin >> a[i]; }
template <class T> void out(const vector<T>& a) { rep(i, ssz(a)) cout << a[i] << " \n"[i + 1 == ssz(a)]; }

int query(int op, int i, int j) {
    if (op == 1) {
        cout << "AND " << i << " " << j << endl;
    }
    else if (op == 2) {
        cout << "OR " << i << " " << j << endl;
    }
    else {
        cout << "XOR " << i << " " << j << endl;
    }
    cout.flush();
    int ans; cin >> ans;
    return ans;
}

void solve() {
    int n; cin >> n;
 
    vi a(n, -1), b(n, -1);
    int s1 = -1, s2 = -1;
    repa(i, 2, n + 1) {
        a[i - 1] = query(3, 1, i);
        if (b[a[i - 1]] != -1) {
            s1 = b[a[i - 1]];
            s2 = i;
        }
        b[a[i - 1]] = i;
    }
 
    if (b[0] != -1) {
        int x = query(1, 1, b[0]);
        a[0] = (a[b[0] - 1] + 2 * x) / 2;
    }
    else if (s1 != -1) {
        int x = query(1, s1, s2);
        a[0] = a[s1 - 1] ^ (((a[s1 - 1] ^ a[s2 - 1]) + 2 * x) / 2);
    }
    else {
        int x = query(1, 1, b[1]);
        int x1 = (a[b[1] - 1] + 2 * x - 1) / 2, x2 = x1 + 1;
        repa(i, 2, n + 1) {
            int y1 = a[i - 1] ^ x1, y2 = a[i - 1] ^ x2;
            if ((x1 & y1) != (x2 & y2)) {
                int z = query(1, 1, i);
                if (z == (x1 & y1)) a[0] = x1;
                else a[0] = x2;
                break;
            }
        }
    }
    repa(i, 1, n) {
        a[i] ^= a[0];
    }
 
    cout << "! ";
    out(a);
    cout.flush();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
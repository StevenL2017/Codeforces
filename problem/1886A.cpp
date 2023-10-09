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

    if (n % 3 == 0) {
        if (n < 12) {
            cout << "NO\n";
            return;
        }
        cout << "YES\n";
        cout << 1 << " " << 4 << " " << n - 5 << endl;
    } else if (n % 3 == 1) {
        if (n < 7) {
            cout << "NO\n";
            return;
        }
        cout << "YES\n";
        cout << 1 << " " << 4 << " " << n - 5 << endl;
    } else {
        if (n < 8) {
            cout << "NO\n";
            return;
        }
        cout << "YES\n";
        cout << 2 << " " << 5 << " " << n - 7 << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
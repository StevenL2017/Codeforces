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

bool is_prime(int x) {
    int y = 2;
    while (y * y <= x) {
        if (x % y == 0) {
            return false;
        }
        y++;
    }
    return true;
}

void solve() {
    int n; cin >> n;

    if (is_prime(n)) {
        cout << 1 << endl;
    } else if ((n % 2 == 0) || is_prime(n - 2)) {
        cout << 2 << endl;
    } else {
        cout << 3 << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
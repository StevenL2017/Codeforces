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
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

void solve() {
    int n; cin >> n;

    int x = n;
    while (!is_prime(x)) {
        x--;
    }

    if (x == n) {
        cout << 1 << endl;
        cout << n << endl;
        return;
    }

    int y = n - x;
    if (is_prime(y)) {
        cout << 2 << endl;
        cout << x << " " << y << endl;
        return;
    }

    for (int z = 2; z <= y - 2; z++) {
        if (is_prime(z) && is_prime(y - z)) {
            cout << 3 << endl;
            cout << x << " " << y - z << " " << z << endl;
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <array>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <algorithm>
#include <functional>
#include <random>
using namespace std;

#define ll long long
#define vi vector<int>

#define ssz(x)              (int)((x).size())
#define sorta(v)            sort(v.begin(), v.end())
#define sortd(v)            sort(v.rbegin(), v.rend())

#define rep(i, n)           for (int i = 0; i < n; ++i)
#define repa(i, a, n)       for (int i = a; i < n; ++i)
#define repd(i, a, n)       for (int i = a; i > n; --i)

#define endl '\n'
template <class T> void in(vector<T>& a) { rep(i, ssz(a)) cin >> a[i]; }
template <class T> void out(const vector<T>& a) { rep(i, ssz(a)) cout << a[i] << " \n"[i + 1 == ssz(a)]; }

const int MOD = 1e9 + 7;
const int INF = 2e9 + 7;
const long long INF_LL = 9e18 + 7;

void solve() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;

    if (n * a != m * b) {
        cout << "NO" << endl;
        return;
    }

    int d = 0;
    repa(i, 1, m) {
        if ((i * n) % m == 0) {
            d = i;
            break;
        }
    }

    vector<vector<char>> mat(n, vector<char>(m, '0'));
    for (int r = 0, dc = 0; r < n; r++, dc += d) {
        for (int c = 0; c < a; c++) {
            mat[r][(c + dc) % m] = '1';
        }
    }

    cout << "YES" << endl;
    for (auto& row: mat) {
        for (auto& c: row) {
            cout << c;
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
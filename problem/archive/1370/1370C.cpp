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
    int n; cin >> n;

    if (n == 1) {
        cout << "FastestFinger\n";
    } else if (n == 2 || n % 2 == 1) {
        cout << "Ashishgup\n";
    } else {
        int y = n;
        while (y % 2 == 0) {
            y /= 2;
        }

        int x = 2;
        bool is_prime = true;
        while (x * x <= y) {
            if (y % x == 0) {
                is_prime = false;
                break;
            }
            x++;
        }

        if ((n / 2) % 2 == 1) {
            if (!is_prime) cout << "Ashishgup\n";
            else cout << "FastestFinger\n";
        } else {
            if (y > 1) cout << "Ashishgup\n";
            else cout << "FastestFinger\n";
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
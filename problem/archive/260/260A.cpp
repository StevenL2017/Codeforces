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
    int a, b, n;
    cin >> a >> b >> n;

    string s;
    int x = a;
    while (x) {
        s = (char)(x % 10 + '0') + s;
        x /= 10;
    }

    while (n--) {
        bool ok = false;
        a = (a * 10) % b;
        for (int i = 0; i < 10; i++) {
            int x = (a + i) % b;
            if (x == 0) {
                s += (char)(i + '0');
                a += i;
                ok = true;
                break;
            }
        }
        if (!ok) {
            cout << -1 << endl;
            return;
        }
    }
    cout << s << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
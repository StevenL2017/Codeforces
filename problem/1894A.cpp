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
    string s; cin >> s;

    bool a = false, b = false;
    for (int i = 1; i <= n; i++) {
        int ca = 0, cb = 0;
        int pa = 0, pb = 0;
        int j = 0;
        bool ok = true;
        while (j < n) {
            pa = 0; pb = 0;
            while (j < n && pa < i && pb < i) {
                if (s[j] == 'A') pa++;
                else pb++;
                j++;
            }
            if (pa < i && pb < i) {
                ok = false;
                break;
            }
            if (pa == i) ca++;
            else cb++;
        }
        if (ok) {
            if (ca > cb && pa == i) {
                a = true;
            }
            else if (cb > ca && pb == i) {
                b = true;
            }
        }
    }

    if (a && !b) {
        cout << "A\n";
    } else if (!a && b) {
        cout << "B\n";
    } else {
        cout << "?\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
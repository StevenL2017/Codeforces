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
    vi a(n); in(a);

    int start = -1, end = n - 1;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) {
            start = i;
            for (int j = i + 1; j < n - 1; j++) {
                if (a[j] < a[j + 1]) {
                    end = j;
                    for (int k = j + 1; k < n - 1; k++) {
                        if (a[k] > a[k + 1]) {
                            cout << "no\n";
                            return;
                        }
                    }
                    break;
                }
            }
            break;
        }
    }

    if (start == -1) {
        cout << "yes\n";
        cout << 1 << " " << 1 << endl;
        return;
    }

    if ((start == 0 || a[start - 1] < a[end]) && (end == n - 1 || a[start] < a[end + 1])) {
        cout << "yes\n";
        cout << start + 1 << " " << end + 1 << endl;
    } else {
        cout << "no\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
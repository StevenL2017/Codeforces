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
    int n;
    cin >> n;

    if (n == 1) {
        cout << "1" << endl;
        cout << "1" << endl;
    } else if (n == 2) {
        cout << "2" << endl;
        cout << "1 2" << endl;
    } else if (n == 3) {
        cout << "2" << endl;
        cout << "1 2 2" << endl;
    } else if (n == 4) {
        cout << "3" << endl;
        cout << "1 2 2 3" << endl;
    } else if (n == 5) {
        cout << "3" << endl;
        cout << "1 2 2 3 3" << endl;
    } else {
        cout << "4" << endl;
        for (int i = 1; i <= n; i++) {
            cout << (i % 4 + 1) << " ";
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
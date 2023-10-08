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

const int dirs4[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> a(n);
    in(a);

    int sr, sc, cnt = 0;
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            if (a[r][c] == '.') {
                sr = r;
                sc = c;
                cnt++;
            }
        }
    }

    vector<string> ans(n, string(m, '#'));
    queue<int> q;
    if (cnt > k) {
        q.push(sr * m + sc);
        ans[sr][sc] = '.';
        cnt--;
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        int r = u / m, c = u % m;
        for (int i = 0; i < 4; i++) {
            int nr = r + dirs4[i][0], nc = c + dirs4[i][1];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && a[nr][nc] == '.' && ans[nr][nc] == '#' && cnt > k) {
                q.push(nr * m + nc);
                ans[nr][nc] = '.';
                cnt--;
            }
        }
    }

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            if (a[r][c] == '.' && ans[r][c] == '#') {
                ans[r][c] = 'X';
            }
            cout << ans[r][c];
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
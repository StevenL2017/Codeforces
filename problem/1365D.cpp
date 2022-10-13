#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <tuple>
#include <numeric>
#include <algorithm>
#include <functional>
#include <utility>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

const int MAXN = 1e6 + 3;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

#define _  %  MOD
#define __ %= MOD

#define sortA(v)               sort(v.begin(), v.end())
#define sortD(v)               sort(v.rbegin(), v.rend())

#define rep(i, n)              for (int i = 0; i < n; ++i)
#define repA(i, a, n)          for (int i = a; i < n; ++i)
#define repD(i, a, n)          for (int i = a; i > n; --i)
#define loop(i, start, end)    for (auto i = start; (start<end)?i<end:i>end; (start<end)?i++:i--)

const int dirs2[2][2] = {{1, 0}, {0, 1}};
const int dirs4[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

class UnionFind {
private:
    int N;
    int *f;
    int *sz;
    int count;

public:
    UnionFind(int n) :
        N(n), count(n) {
        f = new int[N]();
        sz = new int[N]();
        for (int i = 0; i < N; i++) {
            f[i] = i;
            sz[i] = 1;
        }
    }
    
    ~UnionFind() {
        delete[] f;
        delete[] sz;
    }

    int find(int x) {
        if (x != f[x]) f[x] = find(f[x]);
        return f[x];
    }

    bool merge(int x, int y) {
        int x_ = find(x), y_ = find(y);
        if (x_ == y_) return false;
        if (sz[x_] < sz[y_]) {
            int temp = y_; y_ = x_; x_ = temp;
        }
        f[y_] = x_;
        sz[x_] += sz[y_];
        count--;
        return true;
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> mat(n);
    rep(i, n) cin >> mat[i];

    int cnt_good = 0;
    rep(r, n) {
        rep(c, m) {
            if (mat[r][c] == 'G') {
                cnt_good++;
            }
            else if (mat[r][c] == 'B') {
                for (int i = 0; i < 4; i++) {
                    int nr = r + dirs4[i][0], nc = c + dirs4[i][1];
                    if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                        if (mat[nr][nc] == 'G') {
                            cout << "No" << endl;
                            return;
                        }
                        else if (mat[nr][nc] == '.') {
                            mat[nr][nc] = '#';
                        }
                    }
                }
            }
        }
    }
    if (cnt_good == 0) {
        cout << "Yes" << endl;
        return;
    }

    UnionFind uf(n * m);
    rep(r, n) {
        rep(c, m) {
            for (int i = 0; i < 2; i++) {
                int nr = r + dirs2[i][0], nc = c + dirs2[i][1];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                    if (mat[r][c] != '#' && mat[nr][nc] != '#') {
                        uf.merge(r * m + c, nr * m + nc);
                    }
                }
            }
        }
    }

    rep(r, n) {
        rep(c, m) {
            if (mat[r][c] == 'G' && !uf.same(r * m + c, n * m - 1)) {
                cout << "No" << endl;
                return;
            }
        }
    }
    cout << "Yes" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
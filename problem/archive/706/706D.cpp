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

const int K = 31;

class Trie {
public:
    vector<Trie*> children;
    int cnt;

    Trie() : children(2), cnt(0) {}

    void insert(int val) {
        Trie* node = this;
        for (int i = K; i >= 0; i--) {
            int bit = val >> i & 1;
            if (node->children[bit] == nullptr) {
                node->children[bit] = new Trie();
            }
            node = node->children[bit];
            node->cnt++;
        }
    }

    int query_maxor(int val) {
        int ans = 0;
        Trie* node = this;
        for (int i = K; i >= 0; i--) {
            int bit = val >> i & 1;
            if (node->children[bit ^ 1] != nullptr) {
                ans |= 1 << i;
                bit ^= 1;
            }
            if (node->children[bit] == nullptr) {
                return ans;
            }
            node = node->children[bit];
        }
        return ans;
    }

    // 小于等于limit的数对异或值数量
    int query_le(int val, int limit) {
        int ans = 0;
        Trie* node = this;
        for (int i = K; i >= 0; i--) {
            int bit = val >> i & 1;
            if (limit >> i & 1) {
                if (node->children[bit] != nullptr) {
                    ans += node->children[bit]->cnt;
                }
                if (node->children[bit ^ 1] == nullptr) {
                    return ans;
                }
                node = node->children[bit ^ 1];
            } else {
                if (node->children[bit] == nullptr) {
                    return ans;
                }
                node = node->children[bit];
            }
        }
        ans += node->cnt; // 等于的情况
        return ans;
    }

    void remove(int val) {
        Trie* node = this;
        for (int i = K; i >= 0; i--) {
            int bit = val >> i & 1;
            node->children[bit]->cnt--;
            if (node->children[bit]->cnt == 0) {
                node->children[bit] = nullptr;
                break;
            }
            node = node->children[bit];
        }
    }
};

void solve() {
    int q; cin >> q;

    Trie* tree = new Trie();
    tree->insert(0);

    while (q--) {
        char op;
        int x;
        cin >> op >> x;
        if (op == '+') {
            tree->insert(x);
        } else if (op == '-') {
            tree->remove(x);
        } else {
            cout << tree->query_maxor(x) << endl;
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
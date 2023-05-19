#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define ii pair<int, int>
#define dbg(x) cout << #x << " = " << x << endl
#define FOR(i, a, n) for(int i = a; i < n; i++)

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

using namespace std;
 
struct dinic {
    struct edge {
        int to, cap, rev, flow;
        bool res;
        edge(int to_, int cap_, int rev_, bool res_)
            : to(to_), cap(cap_), rev(rev_), flow(0), res(res_) {}
    };
 
    vector<vector<edge>> g;
    vector<int> lev, beg;
    long long F;
    dinic(int n) : g(n), F(0) {}
 
    void add(int a, int b, int c) {
        g[a].emplace_back(b, c, g[b].size(), false);
        g[b].emplace_back(a, 0, g[a].size()-1, true);
    }
    bool bfs(int s, int t) {
        lev = vector<int>(g.size(), -1); lev[s] = 0;
        beg = vector<int>(g.size(), 0);
        queue<int> q; q.push(s);
        while (q.size()) {
            int u = q.front(); q.pop();
            for (auto& i : g[u]) {
                if (lev[i.to] != -1 or (i.flow == i.cap)) continue;
                lev[i.to] = lev[u] + 1;
                q.push(i.to);
            }
        }
        return lev[t] != -1;
    }
    int dfs(int v, int s, int f = 0x3f3f3f3f) {
        if (!f or v == s) return f;
        for (int& i = beg[v]; i < g[v].size(); i++) {
            auto& e = g[v][i];
            if (lev[e.to] != lev[v] + 1) continue;
            int foi = dfs(e.to, s, min(f, e.cap - e.flow));
            if (!foi) continue;
            e.flow += foi, g[e.to][e.rev].flow -= foi;
            return foi;
        }
        return 0;
    }
    long long max_flow(int s, int t) {
        while (bfs(s, t)) while (int ff = dfs(s, t)) F += ff;
        return F;
    }
};

void solve(){

    int n, m; cin >> n >> m;
    dinic D(m + 8);
    D.add(m + 1, m + 7, n/6);
    D.add(m + 2, m + 7, n/6);
    D.add(m + 3, m + 7, n/6);
    D.add(m + 4, m + 7, n/6);
    D.add(m + 5, m + 7, n/6);
    D.add(m + 6, m + 7, n/6);
    for (int i = 1; i <= m; i++)
    {
        D.add(0, i, 1);
        string c;
        for (int j = 0; j < 2; j++)
        {
            cin >> c;
            if (c == "XXL")
                D.add(i, m + 1, 1);
            else if (c == "XL")
                D.add(i, m + 2, 1);
            else if (c == "L")
                D.add(i, m + 3, 1);
            else if (c == "M")
                D.add(i, m + 4, 1);
            else if (c == "S")
                D.add(i, m + 5, 1);
            else if (c == "XS")
                D.add(i, m + 6, 1);
        }
    }
    if (D.max_flow(0, m + 7) == m)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int main(){ _
    int t; cin >> t;
    while(t--)
        solve();
}

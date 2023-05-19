#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define ii pair<int, int>
#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<vector<int>> mx(1001, vector<int>(1001));
vector<int> d(1001, INF);
vector<int> shooters(1001, 0);

void djikstra(int n, int start){

    priority_queue<ii, vector<ii>, greater<ii>> q;

    d[start] = shooters[start];
    q.emplace(d[start], start); // {distance, index}

    while(!q.empty())
    {
        auto [vd, v] = q.top();
        q.pop();

        if (vd > d[v])
            continue;

        for (int i = 1; i <= n; i++)
        {
            if (!mx[v][i])
                continue;
            if (d[i] > d[v] + shooters[i])
            {
                d[i] = d[v] + shooters[i];
                q.emplace(d[i], i);
            }
        }
    }
}

int main(){ 
    
    int n, m, k; // strategic points, strategic roads, bullets
    double p; // probability
    while (cin >> n >> m >> k >> p)
    {
        fill(d.begin(), d.end(), INF);

        for (int i = 1; i <= n; i++)
            fill(mx[i].begin(), mx[i].end(), 0);
        for (int i = 0; i < m; i++)
        {
            int a, b; cin >> a >> b;
            mx[a][b] = 1;
            mx[b][a] = 1;
        }

        int a; cin >> a; // number of shooters
        fill (shooters.begin(), shooters.end(), 0);
        for (int i = 0; i < a; i++)
        {
            int x; cin >> x;
            shooters[x]++; // where the shooters are
        }

        int start, end; cin >> start >> end;
        djikstra(n, start);

        
        double chance;
        if (k < d[end])
            chance = 0;
        else
            chance = pow(p, d[end]);

        cout << setprecision(3) << fixed;
        cout << chance << endl;
    }
}

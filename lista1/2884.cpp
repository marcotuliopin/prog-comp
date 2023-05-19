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

vector<vector<int>> in(1000);
vector<bool> e(1000, false);
vector<bool> eo(1000, false);

bool il(int m){

    for (int i = 1; i <= m; i++)
    {
        if (e[i] != eo[i])
            return false;
    }
    return true;
}

void me(int x){

    for (int i = 0; i < in[x].size(); i++)
    {
        if (e[in[x][i]])
            e[in[x][i]] = false;
        else
            e[in[x][i]] = true;
    }
}

bool check(int m){

    for (int i = 1; i < m + 1; i++)
    {
        if (e[i])
            return false;
    }
    return true;
}

int main(){ _
    
    int n, m; cin >> n >> m;
    int l; cin >> l;
    for (int i = 0; i < l; i++)
    {
        int tmp; cin >> tmp;
        e[tmp] = true;
        eo[tmp] = true;
    }    
    for (int i = 0; i < n; i++)
    {
        int k; cin >> k;
        for (int j = 0; j < k; j++)
        {
            int tmp; cin >> tmp;
            in[i].pb(tmp);
        }
    }

    int c = 0;
    while(true)
    {
        for (int i = 0; i < n; i++)
        {
            me(i);
            c++;
            if(check(m))
            {
                cout << c << endl;
                exit(0);
            }
        }
        if(il(m))
            break;
    }
    cout << "-1" << endl;
}

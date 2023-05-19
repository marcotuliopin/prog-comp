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

bool solve(){

    int n; cin >> n;

    bool p[n][6];
    memset(p, false, sizeof p);

    int v[n];

    for (int i = 0; i < n; i++)
        cin >> v[i];

    if (v[0] > 5)
        return false;

    p[0][v[0]] = true;

    for (int i = 1; i < n; i++)
    {
        bool c = false;
        for (int j = 0; j < 6; j++)
        {
            if (abs(v[i] - j) < 5)
            {
                if (p[i - 1][abs(v[i] - j)])
                {
                    p[i][j] = true;
                    c = true;
                }
            }
            if (v[i] + j < 5)
            {
                if (p[i - 1][v[i] + j])
                {
                    p[i][j] = true;
                    c = true;
                }
            }
        }
        if (!c)
            return false;
    }
    return true;
}

int main(){ _

    int t; cin >> t;
    while (t--)
    {
        if (solve())
            cout << "Feliz Natal!" << endl;
        else
            cout << "Ho Ho Ho!" << endl;
    }
}

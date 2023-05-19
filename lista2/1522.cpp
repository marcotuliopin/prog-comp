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

int n;
int m[110][110][110]; // matriz de tirar cartas
int p[3][110]; // pilha

void tira_carta(int i, int j, int k)
{
    if (i > n || j > n || k > n || m[i][j][k])
        return;

    m[i][j][k] = 1;

    if (p[0][i] % 3 == 0)
        tira_carta(i + 1, j, k);
    if (p[1][j] % 3 == 0)
        tira_carta(i, j + 1, k);
    if (p[2][k] % 3 == 0)
        tira_carta(i, j, k + 1);
    if ((p[0][i] + p[1][j]) % 3 == 0)
        tira_carta(i + 1, j + 1, k);
    if ((p[0][i] + p[2][k]) % 3 == 0)
        tira_carta(i + 1, j, k + 1);
    if ((p[1][j] + p[2][k]) % 3 == 0)
        tira_carta(i, j + 1, k + 1);
    if ((p[0][i] + p[1][j] + p[2][k]) % 3 == 0)
        tira_carta(i + 1, j + 1, k + 1);
}

void solve()
{
    for (int i = 0; i < n; i++)
        cin >> p[0][i] >> p[1][i] >> p[2][i];
    memset(m, 0, sizeof m);
    tira_carta(0, 0, 0);
    if (m[n][n][n])
        cout << "1" << endl;
    else
        cout << "0" << endl;
};

int main()
{ _
    while (true)
    {
        cin >> n;
        if (!n)
            break;

        solve();
    }
}

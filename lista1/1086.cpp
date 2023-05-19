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

int n, m, l, k;

void solve(){
    cin >> l;
    cin >> k;

    vector<int> tabuas(k);
    for (int i = 0; i < k; i++)
        cin >> tabuas[i];
    sort(tabuas.begin(), tabuas.end());

    int minn = INF, minm = INF;
    
    if ((m*100) % l == 0)
    {
        int count = 0;
        minn = 0;
        for (int dir = k - 1, esq = 0; dir >= esq; )
        {
            if (count == (m*100)/l)
                break;

            if (tabuas[dir] > n)
            {
                dir--;
                continue;
            }

            if (tabuas[dir] == n)
            {
                dir--;
                count++;
                minn++;
            }
            else if (tabuas[dir] + tabuas[esq] == n && dir != esq)
            {
                esq++;
                dir--;
                count++;
                minn += 2;
            }
            else if (tabuas[dir] + tabuas[esq] < n)
                esq++;
            else if (tabuas[dir] + tabuas[esq] > n)
                dir--;
            else if (tabuas[dir] + tabuas[esq] == n && dir == esq)
                break;
        }
        if (count < (m*100)/l)
            minn = INF;
    }
    if ((n*100) % l == 0)
    {
        int count = 0;
        minm = 0;
        for (int dir = k - 1, esq = 0; dir >= esq; )
        {
            if (count == (n*100)/l)
                break;
            if (tabuas[dir] > m)
            {
                dir--;
                continue;
            }

            if (tabuas[dir] == m)
            {
                dir--;
                count++;
                minm++;
            }
            else if (tabuas[dir] + tabuas[esq] == m && dir != esq)
            {
                esq++;
                dir--;
                count++;
                minm += 2;
            }
            else if (tabuas[dir] + tabuas[esq] < m)
                esq++;
            else if (tabuas[dir] + tabuas[esq] > m)
                dir--;
            else if (tabuas[dir] + tabuas[esq] == m && dir == esq)
                break;
        }
        if (count < (n*100)/l)
            minm = INF;
    }
    int resp = min(minn, minm);
    if (resp == INF)
        cout << "impossivel" << endl;
    else
        cout << resp << endl;
}

int main(){ _

    cin >> n >> m;
    while (n) 
    {
        solve();
        cin >> n >> m;
    }
}

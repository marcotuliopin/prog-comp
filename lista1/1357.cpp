#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define dbg(x) cout << #x << " = " << x << endl
#define FOR(i, a, n) for(int i = a; i < n; i++)

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

char dict[10][6] = {{'.', '*', '*', '*', '.', '.'}, {'*', '.', '.', '.', '.', '.'}, {'*', '.', '*', '.', '.', '.'},
{'*', '*', '.', '.', '.', '.'}, {'*', '*', '.', '*', '.', '.'}, {'*', '.', '.', '*', '.', '.'},
{'*', '*', '*', '.', '.', '.'}, {'*', '*', '*', '*', '.', '.'}, {'*', '.', '*', '*', '.', '.'},  
{'.', '*', '*', '.', '.', '.'}};

void todigit(int x){

    vector<vector<char>> vct(x, vector<char>(6));
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            char c; cin >> c;
            vct[i][j] = c;
        }
    }
    for (int i = 0; i < x; i++)
    {
        for (int j = 2; j < 4; j++)
        {
            char c; cin >> c;
            vct[i][j] = c;
        }
    }
    for (int i = 0; i < x; i++)
    {
        for (int j = 4; j < 6; j++)
        {
            char c; cin >> c;
            vct[i][j] = c;
        }
    }
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            bool match = true;
            for (int k = 0; k < 6; k++)
            {
                if (vct[i][k] != dict[j][k])
                {
                    match = false;
                    break;
                }
            }
            if (match)
            {
                cout << j;
                break;
            }
        }
    }
    cout << endl;
}

void tobraile(int x){

    vector<int> vct(x);
    string s; cin >> s;
    for (int i = 0; i < x; i++)
        vct[i] = s[i] - 48;

    for (int i = 0; i < x; i++)
    {
        cout << dict[vct[i]][0] << dict[vct[i]][1];
        if (i != x - 1)
            cout << " ";
    }
    cout << endl;
    for (int i = 0; i < x; i++)
    {
        cout << dict[vct[i]][2] << dict[vct[i]][3];
        if (i != x - 1)
            cout << " ";
    }
    cout << endl;
    for (int i = 0; i < x; i++)
    {
        cout << dict[vct[i]][4] << dict[vct[i]][5];
        if (i != x - 1)
            cout << " ";
    }
    cout << endl;
}

int main(){ _

    while (true)
    {
        int x; cin >> x;
        if (x == 0) break;
        char t; cin >> t;

        if (t == 'S')
            tobraile(x);
        else
            todigit(x);
    }
    return 0;
}

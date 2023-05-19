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

//vector<float> vct = {100, 50, 20, 10, 5, 2, 1, 0.5, 0.25, 0.1, 0.05, 0.01};

void solve(float x){
    dbg(x);
    x += 0.001;
    int i = 0, q;
    int X = x;

    cout << setprecision(2) << fixed;

    int tmp = X;
    q = X / 100;
    X = X % 100;
    cout << "NOTAS:" << endl;
    cout << q << " nota(s) de R$ 100.00" << endl;
    q = X / 50;
    X = X % 50;
    cout << q << " nota(s) de R$ 50.00" << endl;
    q = X / 20;
    X = X % 20;
    cout << q << " nota(s) de R$ 20.00" << endl;
    q = X / 10;
    X = X % 10;
    cout << q << " nota(s) de R$ 10.00" << endl;
    q = X / 5;
    X = X % 5;
    cout << q << " nota(s) de R$ 5.00" << endl;
    q = X / 2;
    X = X % 2;
    cout << q << " nota(s) de R$ 2.00" << endl;
    cout << "MOEDAS:" << endl;
    cout << X << " moeda(s) de R$ 1.00" << endl;
    int d = (x - tmp) * 100;
    q = d / 50;
    d = d % 50;
    cout << q << " moeda(s) de R$ 0.50" << endl;
    q = d / 25;
    d = d % 25;
    cout << q << " moeda(s) de R$ 0.25" << endl;
    q = d / 10;
    d = d % 10;
    cout << q << " moeda(s) de R$ 0.10" << endl;
    q = d / 5;
    d = d % 5;
    cout << q << " moeda(s) de R$ 0.05" << endl;
    cout << d << " moeda(s) de R$ 0.01" << endl;

    //while (i < 12)
    //{
        //int q = 0;
        //int v = vct[i] * 100;

        //while (X >= v)
        //{
            //q += X / v;
            //X = X % v;
        //}

        //if (i == 0)
            //cout << "NOTAS:" << endl;
        //else if (i == 6)
            //cout << "MOEDAS:" << endl;

        //if (i <= 5)
            //cout << q << " nota(s) de R$ " << vct[i] << endl;
        //else
            //cout << q << " moeda(s) de R$ " << vct[i] << endl;

        //i++;
    //}
    return;
}

int main(){ 
    float x;
    while (cin >> x)
    {
        solve(x);
    }
}

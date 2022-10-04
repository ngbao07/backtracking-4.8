#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, a[15], d = 1;
ll x[1000005], sum[1000005];

void search()
{
    for (int i = 1; i <= d - 1; i++)
    {
        //if (sum[i] == 0 && sum[i + 1] == 0) continue;
        if (sum[i + 1] - sum[i] > 1) 
        {
            cout << sum[i] + 1;
            return;
        }
    }
    cout << sum[d] + 1 << endl;
}

ll sumarr(int z)
{
    int s = 0;
    for (int i = 1; i <= z; i++)
    {
        s = s + a[x[i]];
    }
    return s;
}

void giai(int i)
{
    for (int j = x[i - 1] + 1; j <= n; j++)
    {
        x[i] = j;
        sum[d] = sumarr(i);
        // for (int k = 1; k <= i; k++) cout << x[k] << " ";
        // cout << endl;
        // cout << sum[d]  << endl;
        d++;
        if (i < n) giai(i + 1);
    }
}

 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen("input.inp","r")){
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    }
    cin >> n;
    x[0] = 0;
    for (int i = 1; i <= n; i++) cin >> a[i];
    giai(1);
    sort(sum + 1, sum + d + 1);
    //for (int i = 1; i <= d; i++) cout << sum[i] << endl;
    search();
}
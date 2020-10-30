#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

ll target, n;
ll dp [1000][1000];
ll rec(vector<ll> &v, ll i, ll sum)
{
    if(dp[i][sum] != -1) return dp[i][sum];

    if(sum==target)
    {
        return  dp[i][sum] = 1;
    }
    if(sum > target || i >= n) return  dp[i][sum] = 0;

    return dp[i][sum] = rec(v, i, sum+v[i]) + rec(v, i+1, sum);

}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    memset(dp, -1, sizeof(dp));
    cin>>target>>n;
    vector<ll> v;
    for(int i=0; i<n; i++)
    {
        ll x; cin>>x;
        v.push_back(x);
    }

    cout<<rec(v, 0, 0)<<endl;
}

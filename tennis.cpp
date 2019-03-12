#include<bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define ll long long
#define all(a) a.begin(),a.end()
#define endl '\n'
#define y1 y123132123
using namespace std;
const int inf=1e9+3;
const int md=1e9+7;
const int N=2e2+3;
int n,m,t,x,y,d;
vector<int> a[N];
int dp[N][N][3];
int sz[N];
int c[3];
void dfs(int v,int pr = 0)
{
    int dp1[N+N][4],dp2[N+N][4];
    for(int i=0;i<=n+n;++i)
    {
        for(int j=0;j<4;++j)
        {
            dp1[i][j] = dp2[i][j] = inf;
        }
    }
    dp1[n][0] = 0;
    sz[v] = 1;
    for(int i=0;i<a[v].size();++i)
    {
        int to = a[v][i];
        if(to==pr)
        continue;
        dfs(to,v);
        sz[v] += sz[to];
    }
    for(int i=0;i<a[v].size();++i)
    {
        int to = a[v][i];
        if(to==pr)
        continue;
        for(int j=-n;j<=n;++j)
        {
            for(int v=0;v<4;++v)
            {
                if(dp1[j+n][v]==inf)
                continue;
                for(int k=-n;k<=n;++k)
                {
                    for(int p=0;p<3;++p)
                    {
                        if(dp[to][k+n][p]==inf)
                        continue;
                        int k1;
                        if(p==1)
                        k1 = 0;
                        else if(p==0)
                        k1 = 1;
                        else
                        k1 = 2;
                        dp2[j+k+n][k1|v] = min(dp2[j+k+n][k1|v],dp1[j+n][v]+dp[to][k+n][p]);
                    }
                }
            }
        }
        for(int j=0;j<=n+n;++j)
        {
            for(int v=0;v<4;++v)
            {
                dp1[j][v] = dp2[j][v];
                dp2[j][v] = inf;
            }
        }
    }
    for(int j=0;j<=n+n;++j)
    {
        for(int vv=0;vv<4;++vv)
        {
            if(dp1[j][vv] == inf)
            continue;
            if(!(vv&(1<<0)))
            {
                dp[v][j-1][2] = min(dp[v][j-1][2],dp1[j][vv]);
            }
            if(!(vv&(1<<1)))
            {
                dp[v][j+1][0] = min(dp[v][j+1][0],dp1[j][vv]);
            }
            dp[v][j][1] = min(dp[v][j][1],dp1[j][vv]+1);
        }
    }
    for(int j = 0;j<=n+n;++j)
    {
        for(int vv=0;vv<3;++vv)
        {
            if(dp[v][j][vv] == inf)
            continue;
        }
    }
}
main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n;
        memset(c,0,sizeof(c));
        for(int i=1;i<=n;++i)
        {
            cin>>x;
            c[x]++;
        }
        for(int i=1;i<=n;++i)
        a[i].clear();
        for(int i=1;i<n;++i)
        {
            cin>>x>>y;
            a[x].pb(y);
            a[y].pb(x);
        }
        if(max(max(c[0],c[1]),c[2])==n)
        {
            cout<<0<<endl;
            continue;
        }
        if(min(min(c[0],c[1]),c[2])==0)
        {
            if(c[2]==0)
            {
                cout<<1<<endl;
                continue;
            }
            else
            {
                cout<<2<<endl;
                continue;
            }
        }
        d = n;
        for(int i=1;i<=n;++i)
        {
            for(int j=0;j<=n+n;++j)
            {
                for(int v=0;v<3;++v)
                    dp[i][j][v] = inf;
            }
        }
        dfs(1);
        bool f = false;
        for(int j=-n;j<=n;++j)
        {
            for(int k=0;k<3;++k)
            {
                int res = dp[1][j+n][k];
                if(res<=c[1])
                {
                    int sm = n-res;
                    if((sm-j)%2!=0)
                        continue;
                    int B = (sm-j)/2;
                    int A = sm-B;
                    int C = res;
                    if(A>c[0]||B>c[2])
                        continue;
                    f = true;
                }
            }
        }
        if(f)
        {
            cout<<1<<endl;
        }
        else
        {
            cout<<2<<endl;
        }
    }
}
#include <bits/stdc++.h>

#define int         long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,l[55],v[55],b[55],c[55];
long double f(long double tim){
    long double dis=0;
    rep(i,1,n+1) dis+=1.0l*(b[i]+v[i]*tim-c[i])*(b[i]+v[i]*tim-c[i])/(tim*tim);
    return dis;
}
void solve(){
    cin>>n;
    rep(i,1,n+1) cin>>l[i];
    rep(i,1,n+1) cin>>b[i];
    rep(i,1,n+1) cin>>v[i];
    rep(i,1,n+1) cin>>c[i];
    long double tim=1e9;
    bool flag=1;
    rep(i,1,n+1){
        if(v[i]<0) tim=min(tim,1.0l*b[i]/(-v[i]));
        else if(v[i]>0) tim=min(tim,1.0l*(l[i]-b[i])/v[i]);
        if(b[i]!=c[i]) flag=0;
    }
    if(flag){
        cout<<0.0<<endl;
        return;
    }
    long double lo=0,hi=tim;
    rep(i,0,200){
        long double mid1=lo+(hi-lo)/3,mid2=hi-(hi-lo)/3;
        if(f(mid1)<f(mid2)) hi=mid2;
        else lo=mid1;
    }
    cout<<fixed<<setprecision(10)<<sqrtl(f(lo))<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
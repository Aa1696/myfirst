#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define repi(i, a, b) for(int i=(a); i>(b); i--)
#define db(x) (cerr << #x << ": " << (x) << '\n')
#define sync ios_base::sync_with_stdio(false), cin.tie(NULL)
#define tests(t) int t; cin >> t; while(t--)
#define iceil(n, x) (((n) + (x) - 1) / (x))
#define ll long long
#define gcd __gcd
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define sz size()
#define all(v) (v).begin(), (v).end()
#define uni(v) sort(all(v)); (v).erase(unique(all(v)), (v).end());
#define pii pair<int, int>
#define vi vector<int>
#define vpii vector<pii>
#define vvi vector<vi>
#define fi first
#define se second
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define si(a) scanf("%d", &a)
#define sll(a) scanf("%lld", &a)
#define bitcount(x) __builtin_popcount(x)
#define cps CLOCKS_PER_SEC
#define PI acos(-1.0)
#define EPS 1e-9
#define mod 1000000007
#define MOD 1000000007
#define N 100005
using namespace std;

#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cerr << name << " : " << arg1 << '\n';
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T>
using maxpq = priority_queue<T>;

//All indexing is 0-based
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update> ordered_set;
//methods: find_by_order(k); & order_of_key(k);
//To make it an ordered_multiset, use pairs of (value, time_of_insertion)
//to distinguish values which are similar.

template<class key, class value, class cmp = std::less<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
//ordered_map<int, int> my_map;


//Returns no. of values x for which ceil(n / x) == y (y must be > 1).
inline ll CC(ll n, ll y) { return iceil(n, y-1) - iceil(n, y); }

//Returns no. of values x for which floor(n / x) == y
inline ll FF(ll n, ll y) { return n / y - n / (y+1); }

//a and b are assumed to be taken modulo p
inline int add(int a, int b, int p = mod){ int c = a + b; if(c >= p) c -= p; return c; }
inline int sub(int a, int b, int p = mod){ int c = a - b; if(c < 0) c += p; return c; }
inline int mul(int a, int b, int p = mod){ return (a * 1ll * b) % p; }

// #define int ll
// #define trace(...) 42

int n, l[N], b[N], c[N], v[N];
double texit;
int p, q, r;

double velocity(double t) {
    return sqrt(max(0., p/t/t + q/t + r));
}

main()
{   
    #ifndef ONLINE_JUDGE
        freopen("/home/tarun/Desktop/input.txt", "r", stdin);
     // freopen("/home/tarun/Desktop/output.txt", "w", stdout);
    #endif
    sync;
    clock_t clk = clock();
    cerr << "I will return...\n";

    cout << fixed << setprecision(12);
    tests(tt) {
        cin >> n;
        rep(i, 0, n) cin >> l[i];
        rep(i, 0, n) cin >> b[i];
        rep(i, 0, n) cin >> v[i];
        rep(i, 0, n) cin >> c[i];

        bool ok = 1;
        rep(i, 0, n) ok &= c[i] == b[i];

        if(ok) cout << 0 << '\n';
        else {
            texit = 1e300;
            p = r = q = 0;
            rep(i, 0, n) {
                p += (b[i] - c[i]) * (b[i] - c[i]);
                r += v[i] * v[i];
                q += (b[i] - c[i]) * 2 * v[i];
                if(!v[i]) continue;
                else if(v[i] > 0) {
                    texit = min(texit, 1.*(l[i]-b[i])/v[i]);
                }
                else {
                    texit = min(texit, 1.*b[i]/-v[i]);
                }
            }
            if(q < 0)   cout << velocity(min(-2.*p/q, texit)) << '\n';
            else        cout << velocity(texit) << '\n';
        }
    }

    cerr << "...don't you ever hang your head.\n";
    cerr << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << '\n';
}

//Compile using:
//g++ -o filename.exe --std=c++11 filename.cpp
//Use -D CP for defining a macro CP in the local environment






// LC: 1106a Another Puzzle From Papyrus
// Title: Another Puzzle From Papyrus
// Difficulty: Easy
// Date: 01 July 2026

#include <bits/stdc++.h>
using namespace std;

// ---------- types ----------
using ll = long long;
using ull = unsigned long long;
using ld = long double;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;

// ---------- macros ----------
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define pb push_back
#define eb emplace_back
#define fi first
#define se second

// loops
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define ROF(i, a, b) for (int i = (a); i >= (b); --i)

// ---------- debug (compile with -DLOCAL) ----------
#ifdef LOCAL
template <typename T>
void _print(const T &x) { cerr << x; }
template <typename A, typename B>
void _print(const pair<A, B> &p)
{
    cerr << "(";
    _print(p.first);
    cerr << ", ";
    _print(p.second);
    cerr << ")";
}
template <typename T>
void _print(const vector<T> &v)
{
    cerr << "[";
    for (int i = 0; i < (int)v.size(); ++i)
    {
        if (i)
            cerr << ", ";
        _print(v[i]);
    }
    cerr << "]";
}
template <typename T>
void _print(const set<T> &s)
{
    cerr << "{";
    bool f = 0;
    for (auto &x : s)
    {
        if (f)
            cerr << ", ";
        f = 1;
        _print(x);
    }
    cerr << "}";
}
template <typename K, typename V>
void _print(const map<K, V> &m)
{
    cerr << "{";
    bool f = 0;
    for (auto &kv : m)
    {
        if (f)
            cerr << ", ";
        f = 1;
        _print(kv);
    }
    cerr << "}";
}

#define dbg(x) cerr << #x << " = ", _print(x), cerr << "\n"
#else
#define dbg(x) ((void)0)
#endif

// ---------- constants ----------
const ll INFLL = (ll)4e18;
const int INF = (int)2e9;

// ---------- math helpers ----------
ll gcdll(ll a, ll b) { return std::gcd(a, b); }
ll lcmll(ll a, ll b) { return a / gcdll(a, b) * b; }

ll modpow(ll a, ll e, ll mod)
{
    ll r = 1 % mod;
    a %= mod;
    while (e > 0)
    {
        if (e & 1)
            r = (__int128)r * a % mod;
        a = (__int128)a * a % mod;
        e >>= 1;
    }
    return r;
}

// ---------- IO helpers ----------
template <typename T>
void read_vec(vector<T> &v)
{
    for (auto &x : v)
        cin >> x;
}

template <typename T>
void print_vec(const vector<T> &v, char sep = ' ')
{
    for (int i = 0; i < (int)v.size(); ++i)
    {
        if (i)
            cout << sep;
        cout << v[i];
    }
    cout << "\n";
}

// ---------- solve ----------
ll func2(vector<ll>& a, vector<ll>& b){
    sort(a.begin(),a.end());
    sort(b.begin(), b.end());
    ll n = a.size();
    ll ans = 0;

    for(ll i=0; i <n; i++){

        if(a[i] < b[i]){
            return INT_MAX;
        }

        ans += (a[i] - b[i]);
    }

    return ans;
}


ll func1(vector<ll>& a, vector<ll>& b, ll c){
    ll n = a.size();

    ll ans = 0;

    for(ll i=0; i <n; i++){

        if(a[i] < b[i]){
            ll val2 = func2(a,b);
                if(val2 == INT_MAX){
                    val2 = -1;
                }else{
                    val2 += c;
                }
            return val2;
        }

        ans += (a[i] - b[i]);
    }

    ll val2 = func2(a,b);

    if(val2 == INT_MAX){
        val2 = -1;
    }

    return min(ans, c+ val2);

}

void solve()
{
    ll n,c;
    cin>>n>>c;

    vector<ll> a(n), b(n);
    read_vec(a);
    read_vec(b);

    ll ans = func1(a,b,c);
    if(ans == INT_MAX){
        ans = -1;
    }
    cout<<ans<<endl;
}

// ---------- main ----------
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    
    cin >> T;
    
    while (T--)
        solve();

    return 0;
}

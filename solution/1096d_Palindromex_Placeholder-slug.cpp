// LC: 1096d Palindromex Placeholder-slug
// Title: Palindromex Placeholder-slug
// Difficulty: Medium
// Date: 09 May 2026

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

ll get_mex(set<ll>& st, ll& n){
    for(ll i=0; i <= n;i++){
        if(st.find(i) == st.end()){
            return i;
        }
    }
    //unreachable
    return -1;
}

ll func(vector<ll>& s, ll l,ll r, ll n,set<ll>& st){
   
    while(l >= 0 && r < s.size() && s[l] == s[r]){
        st.insert(s[l]);
        st.insert(s[r]);
        l--;
        r++;
    }

    return get_mex(st,n);


}


bool palindrome(vector<long long>& v, int l , int r){
    while(l <= r){
        if(v[l] != v[r]) return false;
    l++;
    r--;
    }

    return true;

}
void solve()
{

    ll n;
    cin>>n;
    vector<ll> v(n+n);
    ll l = -1;
    ll r = -1;
    for(ll i=0; i < (n*2); i++){
        cin>>v[i];

       
        if(v[i] == 0){
            if(l == -1){
                l = i;
            }
            r = i;
        }
    }
    set<ll> st1,st2,st3;
    ll ans = func(v, l,l,n,st1);
    ans = max(ans, func(v,r,r,n,st2));

    // cout<<rev<<" "<<og<<endl;

    if(palindrome(v,l,r)){

        for(ll i=l+1; i < r; i++){
            st3.insert(v[i]);
        }

        ans = max(ans,func(v, l,r,n,st3));
    }

    cout<<ans<<endl;
    // print_vec(v);
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

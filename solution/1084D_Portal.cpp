// LC: 1084D Portal
// Title: Portal
// Difficulty: Medium
// Date: 07 March 2026

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

void func(vector<int>& v, int index){
    int n = v.size();
    
    vector<int> temp(v.begin(), v.end());
    
    for(int i=0; i < n; i++){
        v[i] = temp[(index + i)%n];
    }
    
}

void solve()
{
   
    int n,x,y;
    cin>>n>>x>>y;
    vector<int> v(n);
    read_vec(v);
    vector<int> mid,side;
    int midi = -1;
    int sidei = -1;
    
    
    for(int i = 1; i <=x; i++){
       
        side.push_back(v[i-1]);
        
        if(sidei == -1 || side[sidei] > side[side.size()-1]){
            sidei = side.size()-1;
        }
    }
    for(int i = y+1; i <= n; i++){
         
        side.push_back(v[i-1]);
        
        if(sidei == -1 || side[sidei] > side[side.size()-1]){
            sidei = side.size()-1;
        }
    }

    for(int i=x+1; i <= y;i++){
        
        mid.push_back(v[i-1]);    
        if(midi == -1 || mid[midi] > mid[mid.size()-1]){
            midi = mid.size()-1;
        }
    }
    
    func(mid, midi);
    // func(side,sidei);
    
    // for(auto i: mid){
    //     cout<<i<<")";
    // }
    // cout<<endl;
    // for(auto i: side){
    //     cout<<i<<"(";
    // }
    // cout<<endl;
    bool flag = true;
    if(side.size() == 0){
        for(auto j: mid){
                cout<<j<<" ";
            }
    }else{
    for(auto i: side){
        
        if(i > mid.front() && flag){
            flag = false;
            for(auto j: mid){
                cout<<j<<" ";
            }
        }
        cout<<i<<" ";
    }
        if(flag){
            for(auto j: mid){
                cout<<j<<" ";
            }
        }
        
    }
    cout<<endl;
    
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

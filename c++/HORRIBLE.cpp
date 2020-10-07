#include <bits/stdc++.h>
using namespace std;
#define fastIO          ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define ll              long long
#define rep(i,a)        for(ll i = 0 ; i < a ; i++)

// Approach - Use segment tree with lazy propagation.

const int NN = 1e5 + 5;
vector<ll> tree(4*NN+1), lazy(4*NN+1);
 
void updaterange(ll index, ll rs, ll re, ll s, ll e, ll val)
{
	if(lazy[index]!=0)
	{
		tree[index] += ((e-s+1) * lazy[index]);
		if(s!=e)
		{
			lazy[2*index] += lazy[index];
			lazy[2*index+1] += lazy[index]; 
		}
		lazy[index] = 0;
	}
	
	if(rs>e or re<s) return;
	
	if(rs<=s and re>=e)
	{
		tree[index] += ((e-s+1) * val);
		if(s!=e)
		{
			lazy[2*index] += val;
			lazy[2*index+1] += val;
		}
		return;
	}
	
	ll mid = (s+e)/2;
	updaterange(2*index,rs,re,s,mid,val);
	updaterange(2*index+1,rs,re,mid+1,e,val);
	
	tree[index] = tree[2*index] + tree[2*index+1];
}
 
ll queryans(ll index, ll qs, ll qe, ll s, ll e)
{
	if(lazy[index]!=0)
	{
		tree[index] += ((e-s+1) * lazy[index]);
		if(s!=e)
		{
			lazy[2*index] += lazy[index];
			lazy[2*index+1] += lazy[index];
		}
		lazy[index] = 0;
	}
	
	if(qs>e or qe<s) return 0;
	
	if(qs<=s and qe>=e)
	{
		return tree[index];
	}
	
	ll mid = (s+e)/2;
	return queryans(2*index,qs,qe,s,mid) + queryans(2*index+1,qs,qe,mid+1,e);
}
 
int main()
{
	fastIO;
	int tt = 1;
	cin>>tt;
	
	while(tt--)
	{
		int n,q;
	    cin>>n>>q;
	
	    rep(i,4*n+2) tree[i] = 0, lazy[i] = 0;
		 
	    int start = 0, end = n-1;
	
	    while(q--)
	    {
		    int type;
		    cin>>type;
		
		    if(type==0)
		    {
			    ll l,r,val;
			    cin>>l>>r>>val;
			
			    updaterange(1,l-1,r-1,start,end,val);
		    }
		    else
		    {
			    ll l,r;
			    cin>>l>>r;
			    cout<< queryans(1,l-1,r-1,start,end) <<endl;
		    }
	    }
		
	}
	
	return 0;
} 

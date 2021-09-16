#include <bits/stdc++.h>
using namespace std;

void buildTree(vector<int>&v, vector<int>&tree, int st, int en, int p)
{
    if(st>en)return ;
    if(st==en){tree[p]=v[st];return;}
    int mid=(st+en)/2;
    //build left tree
    buildTree(v, tree, st, mid, 2*p);
    buildTree(v, tree, mid+1, en, 2*p+1);
    tree[p]=min(tree[2*p+1], tree[2*p]);
    return;
}

int querry(int r1, int r2, vector<int>&tree, int st, int en, int p)
{
    if(r1<=st && r2>=en)return tree[p];
    
    else if( r2<st || r1>en )return INT_MAX;
    else
    {
        int mid=(st+en)/2;
        int a=querry(r1, r2, tree, mid+1, en, 2*p+1);
        int b=querry(r1, r2, tree, st,  mid, 2*p );
        return min(a, b);
    }
}


void nodeUpdate(int a, int pos, int st, int en, vector<int>&tree)
{
    int i=1;
    while(st<en)
    {
        int mid=(st+en)/2;
        if(pos<=mid) {en=mid; i=2*i;}
        else {st=mid+1;  i=2*i+1; }
    }
    tree[i]=a;
    while(i)
    {
        int k=i/2;if(k==0)break;
        tree[k]=min(tree[2*k+1], tree[2*k]);
        i=k;
    }
    return;
}

void rangeUpdate(int a, int left, int right, int st, int en, vector<int>&tree, int pos)
{
    if(right<st || left>en)return;
    else if(st==en){tree[pos]+=a; return;}
    else{
        int mid= (st+en)/2;
        rangeUpdate(a, left, right, st,   mid, tree,  2*pos);
        rangeUpdate(a, left, right, mid+1, en, tree, 2*pos+1);
        tree[pos]=min(tree[2*pos], tree[2*pos +1]);
    }
    return ;
}


int main()
{
    int n; cin>>n;
    vector<int>v;
    for(int i=0; i<n; i++)
    {
        int k; cin>>k; v.push_back(k);
    }
    vector<int>tree(4*n+1, 0);
    buildTree(v, tree, 0, v.size()-1, 1);
    int t;
    cin>>t; 

    while(t--){
    int a, pos; cin>>a>>pos;
    nodeUpdate(a, pos, 0, v.size()-1 , tree);
    }

    cin>>t;
    while(t--)
    {
        int left, right, val; cin>>left>>right>>val;
        rangeUpdate(val, left, right, 0, v.size()-1, tree, 1);
    }

    cin>>t;
    while(t--){
    int r1, r2; cin>>r1>>r2;
    int res= querry(r1, r2, tree, 0, n-1, 1);
    cout<<res<<" ";}
    return 0;
}

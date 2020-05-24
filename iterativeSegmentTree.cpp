#include<bits/stdc++.h>
using namespace std;
#define mx 100001
#define INF -100000005
typedef pair<int ,int> PII;
PII Tree[mx*3];
PII combine(PII p1,PII p2){
    if(p1.first>p2.first)
        return p1;
    if(p2.first>p1.first)
        return p2;
    return make_pair(p1.first,p1.second+p2.second);
}
void build(int node,int L,int R,int a[]){
    if(L==R){
        Tree[node]=make_pair(a[L-1],1);
        return;
    }
    int mid=(L+R)/2;
    build(node*2,L,mid,a);
    build(node*2+1,mid+1,R,a);
    Tree[node]=combine(Tree[node*2],Tree[node*2+1]);
}
void updateTree(int node,int L,int R,int pos,int val){
    if(L>pos || R<pos)
        return;
    if(L>=pos && R<=pos){
        Tree[node]=make_pair(val,1);
        return;
    }
    int mid=(L+R)/2;
    updateTree(node*2,L,mid,pos,val);
    updateTree(node*2+1,mid+1,R,pos,val);
    Tree[node]=combine(Tree[node*2],Tree[node*2+1]);
}
PII query(int node,int L,int R,int l,int r){
    if(L>r || R<l)
        return make_pair(INF,0);
    if(L>=l && R<=r){
        return Tree[node];
    }
    int mid=(L+R)/2;
    return combine(query(node*2,L,mid,l,r),query(node*2+1,mid+1,R,l,r));
}
int main(){
    int a[]={7,5,7,5,7,6,4,4,2,1,7,9,10,54,1,8,5};
    int n=sizeof(a)/sizeof(a[0]);
    build(1,1,n,a);
    PII ans=query(1,1,n,1,11);
    cout<<ans.first<<" "<<ans.second;
    return 0;
}

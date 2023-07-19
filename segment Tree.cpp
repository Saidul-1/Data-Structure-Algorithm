/* 2 types of query:
1 a b: change array[a]:=b
0 a b c: print number of elements >= c in  the range[a,b] 
*/
#include <iostream>
#include<vector>
using namespace std;

vector<int>mn(1000000),mx(1000000);
int query(int index, int l, int r, int a, int b, int c){
    if(mn[index]>=c && l>=a && r<=b){return r-l+1;}
    if(l>b || r<a || mx[index]<c){return 0;}
    int mid=(l+r)/2;
    return query(index*2,l,mid,a,b,c)+query(index*2+1,mid+1,r,a,b,c);
}
void update(int index, int l, int r, int pos, int val){
    if(l>pos || r<pos){return;}
    if(l==r){
        mn[index]=mx[index]=val;
    }
    else{
        int mid=(l+r)/2;
        update(index*2,l,mid,pos,val),update(index*2+1,mid+1,r,pos,val);
        mn[index]=min(mn[index*2],mn[index*2+1]);
        mx[index]=max(mx[index*2],mx[index*2+1]);
    }
}
void build(int index, int l, int r){
    int x;
    if(l==r){cin>>x;mn[index]=mx[index]=x;}
    else{
        int mid=(l+r)/2;
        build(index*2,l,mid),build(index*2+1,mid+1,r);
        mn[index]=min(mn[index*2],mn[index*2+1]);
        mx[index]=max(mx[index*2],mx[index*2+1]);
    }
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    int a,b,c,f,i,n,q;
    cin>>n;
    build(1,1,n);
    cin>>q;
    while(q--){
        cin>>f;
        if(f){
            cin>>a>>b;
            update(1,1,n,a,b);
        }
        else{
            cin>>a>>b>>c;
            cout<<query(1,1,n,a,b,c)<<"\n";
        }  
    }
    return 0;
}

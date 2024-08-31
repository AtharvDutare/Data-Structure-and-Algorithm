#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(), x.end()
// vector<int> segTree;
// void build(vector<int>&arr,int start,int end,int index){
//     ///time complexcityO(N)
//     if(start==end){
//         segTree[index]=arr[start];
//         return ;
//     }
//     int mid=(start+end)>>1;
//     int left=2*index;
//     int right=2*index+1;
//     build(arr,start,mid,left);
//     build(arr,mid+1,end,right);
//     segTree[index]=segTree[left]+segTree[right]; 
// }
// void update(vector<int>&arr,int start,int end,int index,int pos ,int val){
//     if(start==end){
//         arr[pos]=value;
//         segTree[index]=arr[pos];
//         return ;
//     }
//     int mid=(start+end)>>2;
//     if(mid<=pos){
//         update(arr,start,mid,2*index,pos,value);
//     }
//     else{
//         update(arr,mid+1,end,2*index+1,pos,value);
//     }
//     segTree[index]=segTree[2*index]+segTree[2*index+1];
// }
// int query(int start,int end,int index,int l,int r){
//     //complete overlap
//     if(start>=l&&r<=end){
//         return segTree[index];
//     }
//     //disJoint
//     if(l>end||r<start){
//         return 0;
//     }
//     int mid=(start+end)>>2;
//     int leftAnswer=query(start,mid,2*index,l,r);
//     int rightAnswer=query(mid+1,end,2*index+1,l,r);
//     return rightAnswer+leftAnswer;


// }
// void solve(){
//     int n;
//     cin>>n;
//     segTree.resize(4*n,-1);
//     vector<int> arr;
//     for(int &i:arr){
//         cin>>i;
//     }
//     build(arr,0,n-1,1);
//     update(arr,0,n-1,1,1,3);
// }
template<typename Node, typename Update>
struct SegTree {
	vector<Node> tree;
	vector<ll> arr; // type may change
	int n;
	int s;
	SegTree(int a_len, vector<ll> &a) { // change if type updated
		arr = a;
		n = a_len;
		s = 1;
		while(s < 2 * n){
			s = s << 1;
		}
		tree.resize(s); fill(all(tree), Node());
		build(0, n - 1, 1);
	}
	void build(int start, int end, int index)  // Never change this
	{
		if (start == end)	{
			tree[index] = Node(arr[start]);
			return;
		}
		int mid = (start + end) / 2;
		build(start, mid, 2 * index);
		build(mid + 1, end, 2 * index + 1);
		tree[index].merge(tree[2 * index], tree[2 * index + 1]);
	}
	void update(int start, int end, int index, int query_index, Update &u)  // Never Change this
	{
		//index of query_index in segment tree
		//query_index is index in our array
		if (start == end) {
			u.apply(tree[index]);//update the node(segment tree at index) with new value(from u node)
			return;
		}
		int mid = (start + end) / 2;
		if (mid >= query_index)
			update(start, mid, 2 * index, query_index, u);
		else
			update(mid + 1, end, 2 * index + 1, query_index, u);
		tree[index].merge(tree[2 * index], tree[2 * index + 1]);
		//after update the leaf node we need to update the node which affect due to change(take log n time)
	}
	Node query(int start, int end, int index, int left, int right) { // Never change this
		if (start > right || end < left)
			return Node();
		if (start >= left && end <= right)
			return tree[index];
		int mid = (start + end) / 2;
		Node l, r, ans;
		l = query(start, mid, 2 * index, left, right);
		r = query(mid + 1, end, 2 * index + 1, left, right);
		ans.merge(l, r);
		return ans;
	}
	void make_update(int index, ll val) {  // pass in as many parameters as required
		Update new_update = Update(val); // may change
		update(0, n - 1, 1, index, new_update);
	}
	Node make_query(int left, int right) {
		return query(0, n - 1, 1, left, right);
	}
};

struct Node1 {
	ll val; // may change
	// only for safety check
	Node1() { // Identity element
		val = 0;	// may change
	}
	Node1(ll p1) {  // Actual Node
		val = p1; // may change
	}
	void merge(Node1 &l, Node1 &r) { // Merge two child nodes
		val = l.val + r.val;  // may change
	}
};

struct Update1 {
	ll val; // may change
	Update1(ll p1) { // Actual Update
		val = p1; // may change
	}
	void apply(Node1 &a) { // apply update to given node
		a.val = val; // may change
	}
};

int main(){
	vector<ll> arr={1,2,4,5,4,5};
    SegTree<Node1,Update1> segTree=SegTree<Node1,Update1>(arr.size(),arr);
	segTree.make_update(1,5);
	Node1 node=segTree.make_query(0,2);
	cout<<node.val<<endl;

}
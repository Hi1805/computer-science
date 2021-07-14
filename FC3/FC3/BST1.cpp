#include<bits/stdc++.h>
using namespace std;
struct TNode{
	int data;
	TNode *left,*right;
	TNode (int x){data = x;left = right = NULL;	}
	TNode (int x, TNode *ll, TNode *rr)
	{data = x; left =ll; right =rr;}
};
class MyBST{
	TNode *root;
	public:
	TNode *chen(TNode *&T, int x){
			if(T== NULL) T = new TNode(x);
			else if(T->data == x) cout<<"da co trong cay"<<endl;
				else if(T->data < x) T->right = chen(T->right, x);
					else T->left = chen(T->left,x);
		return T;
	}
	void chen(int x){
		root = chen(root,x);
	}
	void taocayBST(){
		root = NULL;
		int x;
		while(true){
			cout<<"nhap x: ";cin>>x;
			if(x == 0) break;
			chen(x);
		}
	}
	void chieurong(){
		queue<TNode *>Q;
		if(root!=NULL) Q.push(root);
		else{
			cout<<"cay rong";
			return;
		}
		while(!Q.empty()){
			TNode *x = Q.front();
			Q.pop();
			cout<<x->data<<" ";
			if(x->left != NULL)Q.push(x->left);
			if(x->right != NULL) Q.push(x->right);
		}
	}
	int getmax(){
		if(root == NULL)return 0;
			else{
				TNode *p = root;
				while(p->right != NULL)p = p->right;
				return p->data;
		}
	}
	int getmin(){
		if(root == NULL)return 0;
			else{
				TNode *p = root;
				while(p->left != NULL)p = p->left;
				return p->data;
		}
	}
	bool timx(TNode *T, int x){
		if(T == NULL)return false;
		else if(T->data == x) return true;
			else if(T->data < x) return timx(T->right,x);
				else return timx(T->left,x);
	}
	void timX(int x){
		if(timx(root,x) == true)cout<<"x co trong cay"<<endl;
			else cout<<"X khong co trong cay"<<endl;
	}
	void get_parent(int x){
		if(root == NULL) cout<<"Cay rong";
		else if(x == root->data) cout<<"Day la goc, ko co bo";
			else if(timx(root, x) == false) cout<<"Khong co x";
				else{
					TNode *p = root;
					while(p!= NULL){
						if(x < root->data){
							if(p->left->data==x){
								cout<<"Bo cua x: "<<p->data;
								break;
							}	
							p = p->left;
						}
						if(x > root->data){
							if(p->right->data==x){
								cout<<"Bo cua x: "<<p->data;
								break;
							}	
							p = p->right;
						}
					}
				}
	}
//	void get_sib(int x){
//		if(root == NULL) cout<<"Cay rong";
//		else if(x == root->data) cout<<"Day la goc, ko co anh em";
//			else if(timx(root, x) == false) cout<<"Khong co x";
//			else{
//				TNode *p = root;
//				while(p!=NULL){
//					if(x< root->data){
//						
//					}
//				}
//			}
//	}
int get_sib(int x){
		if(root  == NULL){
			return 0;
		}
			TNode *q = root;
		if(root->data == x){
			cout<<"farther";
			return 0;
		
		}
		TNode *tmp;
		while(q != NULL){
			if(q->data == x){
				tmp = q;
				break;
			}
			if(q->data > x){
				q = q->left;
			}
			else q = q->right;
		}
		if(q == NULL){
			cout<<"khong anh em";
			return 0;
		}
		return tmp->left != NULL ? tmp->left->data : tmp->right->data;
	}
	//tim xoa
	TNode *tx(TNode *&T, int x){
		if(T == NULL) cout<<"cay khong chua "<<x<<"!!";
		else if(x < T->data) T->left = tx(T->left,x);
			else if(x > T->data) T->right = tx(T->right,x);
				else{
					if(T->left == NULL && T->right == NULL){
						TNode *q=T;
						T=NULL;
						delete q;
					}
					else if(T->left == NULL){
						TNode *q = T; T = T->right;
						delete q;
					}
						else if(T->right == NULL){
							TNode *q = T;T= T->left;
							delete q;
						}
							else{
								TNode *q = T->left;
								while(q->right != NULL) q = q->right;
								T->data = q->data;
								T->left=tx(T->left,q->data);
							}
				}
			return T;
	}
	void xoa(int x){
		root = tx(root,x);
	}
};
int main(){
	int x = 18;
	MyBST T;
	T.taocayBST();
	cout<<"Duyet chieu rong: ";
	T.chieurong();
//	cout<<"Max = "<<T.getmax();
//	cout<<"Min = "<<T.getmin();
//	T.timX(x);
//	T.get_parent(9);
	//get_sib
	T.xoa(27);
	cout<<"\nSau khi xoa: ";
	T.chieurong();//19 3 5 28 27 16 20 9 18

	return 0;
}

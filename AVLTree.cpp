#include<bits/stdc++.h>
using namespace std;
struct TNode{
	int data;
	TNode *left,*right;
	TNode (int x){data = x;left = right = NULL;	}
	TNode (int x, TNode *ll, TNode *rr)
	{data = x; left =ll; right =rr;}
};
class MyAVL{
	TNode *root;
	public:
	
//	int cao(){
//		return height(root);
//	}
	
	TNode *qL(TNode *&T){
		TNode *x = T;
		TNode *y = x->left;
		x->left = y->right;
		y -> right = x;
		T = y;
		cout<<"qL->";
		return T;
	}
	TNode* qLR(TNode *&T){ 
		TNode *x= T; 
		TNode *y= x->left; 
		TNode *z= y->right; 
		y->right= z->left; 
		x->left = z->right; 
		z->left= y; 
		z->right=x; 
		T = z;; 
		cout<<"qLR->";
		return T;
	}
	TNode* qR(TNode *&T){
		TNode *x = T;
		TNode *y = x->right;
		x->right = y->left;
		y->left = x;
		T=y;
		cout<<"qR->";
		return T;
	}
	TNode* qRL(TNode *&T){ 
		TNode *x= T; 
		TNode *y= x->right; 
		TNode *z= y->left; 
		y->left= z->right; 
		x->right = z->left; 
		z->right= y; 
		z->left=x; 
		T = z;; 
		cout<<"qRL->";
		return T;
	}
	int cao(TNode *T){
		if(T ==NULL)return 0;
		return 1 + max(cao(T->left), cao(T->right));
	}
	
	TNode *chenx(TNode *&T, int x){
		if(T == NULL)T =new TNode(x);
		else if(x == T->data) cout<<"da co trong cay!";
			else{
				if(x < T->data) T->left = chenx(T->left,x);
				else T->right = chenx(T->right,x);
				int h1 = cao(T->left);
				int h2 = cao(T->right);
				if(h1>h2+1){
					int h11 = cao(T->left->left);
					int h12 = cao(T->left->right);
					if(h11 > h12)T = qL(T);
					else T = qLR(T);
				}
				else if(h2 > h1+1){
					int h22 = cao(T->right->right);
					int h21 = cao (T->right->left);
					if(h22 > h21)T = qR(T);
					else T = qRL(T);
				}
			}
			return T;
	}
	void chenx(int x){
		root = chenx(root,x);
	}
	void taocayAVL(){
		root = NULL;	
		int x;
		while(true){
			cout<<"nhap x: ";
			cin>>x;
			if(x == 0) break;
			chenx(x);
		}
	}
	
	void chieurong(){
		queue<TNode *>Q;
		if(root != NULL) Q.push(root);
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
};

int main(){
	MyAVL T;
	T.taocayAVL();//27 11 5 29 24 26 3 4 10 16 13
	//4 10 7 8 33 9 2
	T.chieurong();
	return 0;
}

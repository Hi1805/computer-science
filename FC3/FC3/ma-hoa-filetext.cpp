#include<bits/stdc++.h>
using namespace std;

int a[256] = {0};

void docfile(char*ten){
	ifstream fi (ten);
	if(fi == NULL){
		cout<<"file loi";
		return;
	}
	
	while(!fi.eof()){
		char k ;
		fi>>k;
		a[k]++;
		
	}
	for(int i = 0 ; i < 256 ; i++){
		if(a[i] > 0){
			cout<<char(i)<<" "<<a[i]<<endl;
		}
	}
	
}
struct TNode{
	int data;
	TNode * left, *right;
	TNode(int x){
		data = x;
		left = right = NULL;
	}
	TNode(int x, TNode* ll, TNode* rr){
		data = x;
		left = ll;
		right = rr;
	}
};

class MyBST{
	TNode *root;
	public:
	TNode *chenx(TNode *&T, int x){
			if(T==NULL)	T = new TNode(x);
			else if(T->data == x)	cout<<"da co trong cay\n";
				else if(T->data < x)	T->right = chenx(T->right,x);
					else T->left = chenx(T->left,x);
			return T;
	}
	void chen( int x){
		root = chenx(root,x);
	}
}



int main(){
	docfile("filetest.txt");
	return 0;
}

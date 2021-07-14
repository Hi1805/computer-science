
#include<iostream>
#include<fstream>
#include<queue>
#include<math.h>
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
	
	void readFile(){
		ifstream iff("tree.inp.txt");
		int x;
		if(iff.fail()){
			cout<<"file rong";
			return ;
		}
		while(!iff.eof()){
			iff>>x;
			chen(x);
		}
	}
	
	int height(TNode* T){
   		if(T == NULL )
      		return 0;
   		return 1+max(height(T->left), height(T->right));
	}
	//
	int height (){
		return height(root);
	}
	bool isLeafNode(TNode *l){
		return (l->left == NULL && l->right == NULL);
	}
	int countLeafNode(TNode *t){
		if (t == NULL) 
			return 0;
		if (isLeafNode(t)) 
			return 1;
		return countLeafNode(t->left) + countLeafNode(t->right);
	}
	int countleafNode(){
		return countLeafNode(root);
	}
	int sumOddNumber(TNode *T)
	{
	    if (T!=NULL)
	    {
	        int a = sumOddNumber(T->left);
	        int b = sumOddNumber(T->right);
	        if (T->data % 2 != 0)
	            return T->data + a + b;
	        return a + b;
	    }
	    return 0;
	}
	int sumOddNumber(){
		return sumOddNumber(root);
	}
	int countNodeHaveAChild(TNode *node){
        if(node == NULL) return 0;
        if((node->left == NULL && node->right != NULL) || (node->left != NULL && node->right == NULL)){
            return 1 + countNodeHaveAChild(node->left) + countNodeHaveAChild(node->right);
        }
        return countNodeHaveAChild(node->left) + countNodeHaveAChild(node->right);
    }
	int countNodeHaveAChild(){
		return countNodeHaveAChild(root);
	}
	int countEvenNumber(TNode *T){
		 if (T!=NULL)
		 { 	int a = countEvenNumber(T->left);
	        int b = countEvenNumber(T->right);
	        if (T->data %2 == 0)
	            return 1 + a + b;
	        return a + b;
	    }
	    return 0;
	}
	int sumEvenNumber(TNode* T){
		 if (T!=NULL)
	    {
	        int a = sumEvenNumber(T->left);
	        int b = sumEvenNumber(T->right);
	        if (T->data % 2 == 0)
	            return T->data + a + b;
	        return a + b;
	    }
	    return 0;
	}
	double averageOfEvenNumbers()
	{	double result = 1.0*sumEvenNumber(root)/countEvenNumber(root);
	   	return roundf(result * 100)/ 100;
	}
	int countNode(TNode *node){
        if(node == NULL) return 0;
        return 1 + countNode(node->left) + countNode(node->right);
    }
    int countNode(){
        return countNode(root);
    }
    
	int checkAVLTree(TNode* T){
		 int NodeR = height(T->right);
		 int NodeL = height(T->left);
		 if (abs(NodeR - NodeL) <= 1)  
		        return 1;
		 else
		 	return 0;
	}
	int checkAVLTree(){
		return checkAVLTree(root);
	}
    int get_parent(int x){
        TNode *p = root;
        if(p->data == x){return p->data;}
        while(p != NULL){
            if(isLeafNode(p)) return -1;
            if(p ->left != NULL){
                 if(p->left->data == x) return p->data;
            }
            if(p ->right != NULL){
                if( p->right->data == x){
                    return p->data;
                }
            }
            if(p->data < x) p = p->right;
            else p = p->left;
        }
        return p->data;
    }
	bool writeFile(){
       ofstream fw("tree_out.txt", ios::out);
	    if(fw.fail()){
	        cout << "Failed to open file!";
	        return false;
	    }
	    fw << countNode(root) << endl;
	    fw << height(root) << endl;
	    fw << countLeafNode(root) << endl;
	    fw << sumOddNumber(root) << endl;
	    fw << countNodeHaveAChild(root) << endl;
	    fw << averageOfEvenNumbers() << endl;
	    fw << checkAVLTree()<<endl;
	    fw << get_parent(17)<<endl;
	    fw.close();
	    return true;
    }
};
int main(){
	MyBST m1;
	m1.readFile();
	m1.writeFile();
	return 0;
}

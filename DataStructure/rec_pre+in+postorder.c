#include <stdio.h>
typedef int element;
typedef struct TreeNode{
	element data;
	struct TreeNode *left, *right;
} TreeNode;
void preorder(TreeNode *T);
void inorder(TreeNode *T);
void postorder(TreeNode *T);

int main(){
	TreeNode n9 = {7, NULL, NULL};	//					(n1)2
	TreeNode n8 = {8, NULL, NULL};	//			(n2)0			(n3)1
	TreeNode n7 = {4, NULL, NULL};	//		(n4)5	(n5)1	(n6)3	(n7)4
	TreeNode n6 = {3, NULL, &n9};	//	  (n8)8				 (n9)7
	TreeNode n5 = {1, NULL, NULL};
	TreeNode n4 = {5, &n8, NULL};
	TreeNode n3 = {1, &n6, &n7};
	TreeNode n2 = {0, &n4, &n5};
	TreeNode n1 = {2, &n2, &n3};
	TreeNode *root = &n1;
	
	printf("Preorder with recursive: ");
	preorder(root);
	printf("\nInorder with recursive: ");
	inorder(root);
	printf("\nPostorder with recursive: "); 
	postorder(root);
	return 0;
}

void preorder(TreeNode *T){			// basic preorder traversal
	if (T){
		printf("%d ", T->data);
		preorder(T->left);
		preorder(T->right);
	}
}
void inorder(TreeNode *T){			// basic inorder traversal
	if (T){
		inorder(T->left);
		printf("%d ", T->data);
		inorder(T->right);
	}
}
void postorder(TreeNode *T){		// basic postorder traversal
	if (T){
		postorder(T->left);
		postorder(T->right);
		printf("%d ", T->data);
	}
}

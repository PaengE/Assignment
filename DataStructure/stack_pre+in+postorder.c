#include <stdio.h> 
#include <stdlib.h> 
  
#define MAX_SIZE 100 
typedef struct TreeNode{ 
    int data; 
    struct TreeNode *left, *right; 
} TreeNode; 
typedef struct StackType { 
    int top; 
    struct TreeNode* stack[MAX_SIZE]; 
} StackType;

void init(StackType *s){
	s->top = -1;
}
int isEmpty(struct StackType* s){
	return (s->top == -1);
} 
int isFull(struct StackType* s){
	return (s->top == (MAX_SIZE - 1));
} 
void push(struct StackType* s, struct TreeNode* t){ 
    if (isFull(s)) 
        return; 
    s->stack[++(s->top)] = t; 
} 
struct TreeNode* pop(struct StackType* s){ 
    if (isEmpty(s)) 
        return NULL; 
    return s->stack[(s->top)--]; 
} 
struct TreeNode* peek(struct StackType* s){ 
    if (isEmpty(s)) 
        return NULL; 
    return s->stack[s->top]; 
} 

void preorder(struct TreeNode* root){
	struct StackType* s = (struct StackType*) malloc(sizeof(struct StackType));
	init(s);
	push(s, root);
	while(!isEmpty(s)){
		root = pop(s);
		printf("%d ", root->data);
		if(root->right){
			push(s, root->right);
		}
		if(root->left){
			push(s, root->left);
		}
	}
	free(s);
}
void inorder(struct TreeNode* root){
	struct StackType* s = (struct StackType*) malloc(sizeof(struct StackType));
	init(s);
	while(1){
		if(root != NULL){
			push(s, root);
			root = root->left;
		} else {
			if(!isEmpty(s)){
				root = pop(s);
				printf("%d ", root->data);
				root = root->right;
			} else {
				break;
			}
		}
	}
}
void postorder(struct TreeNode* root){
    if (root == NULL) 
        return; 
    struct StackType* s = (struct StackType*) malloc(sizeof(struct StackType));
    init(s);
    do{
        while(root){
            if (root->right){
                push(s, root->right); 
			}
            push(s, root); 
            root = root->left; 
        } 
        root = pop(s); 
        if (root->right && peek(s) == root->right){ 
            pop(s);
            push(s, root);
            root = root->right;
        } else { 
            printf("%d ", root->data); 
            root = NULL; 
        } 
    } while(!isEmpty(s));
    free(s);
} 
  
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
	
	printf("Preorder with stack: "); 
    preorder(root); 
	printf("\nInorder with stack: "); 
    inorder(root); 
    printf("\nPostorder with stack: "); 
    postorder(root); 
    
    return 0; 
} 

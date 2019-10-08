#include <stdio.h>
#include <stdlib.h>
typedef int element;
typedef struct TreeNode{
	element data;
	struct TreeNode *left, *right;
} TreeNode;
typedef struct QueueNode{
	TreeNode *node;
	struct QueueNode *link;
} QueueNode;
typedef struct QueueType{
	QueueNode *front;
	QueueNode *rear;
} QueueType;

void initQueue(QueueType *q);
int isEmpty(QueueType *q);
void enqueue(QueueType *q, TreeNode *T);
TreeNode* dequeue(QueueType *q);
void levelorder(TreeNode *T);

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
	
	printf("Levelorder with linked-list queue : ");
	levelorder(root);
	return 0;
}
void initQueue(QueueType *q){
	q->front = NULL;
	q->rear = NULL;
}
int isEmpty(QueueType *q){
	return (q->front == NULL);
}
void enqueue(QueueType *q, TreeNode *T){
	QueueNode *temp = (QueueNode *)malloc(sizeof(QueueNode));
	if(temp == NULL){
		printf("메모리를 할당할 수 없습니다.\n");
	} else {
		temp->node = T;
		temp->link = NULL;
		if(isEmpty(q)){
			q->front = temp;
			q->rear = temp;
		} else {
			q->rear->link = temp;
			q->rear = temp;
		}
	}
}
TreeNode* dequeue(QueueType *q){
	if(isEmpty(q)){
		printf("큐가 비어 있습니다.\n");
	} else {
		QueueNode *temp = q->front;
		TreeNode *result = temp->node;
		q->front = q->front->link;
		if (q->front == NULL)
			q->rear = NULL;
		free(temp);
		return result;
	}
}
void levelorder(TreeNode *T){
	QueueType *queue = (QueueType *)malloc(sizeof(QueueType));
	initQueue(queue);
	enqueue(queue, T);
	while(!(isEmpty(queue))){
		TreeNode *node = dequeue(queue);
		printf("%d ", node->data);
		if(node->left)
			enqueue(queue, node->left);
		if(node->right)
			enqueue(queue, node->right);
	}
	free(queue);
}

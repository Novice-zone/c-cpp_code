#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int BTDataType;
typedef struct BinaryTreeNode {
	BTDataType data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
 }BTNode;

BTNode* BuyNode(BTDataType x) {
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	if (node == NULL) {
		perror("malloc node");
		return NULL;
	}
	node->data = x;
	node->left = NULL;
	node->right = NULL;
	
	return node;
}

BTNode* CreatTree() {
	BTNode* node1 = BuyNode(1);
	BTNode* node2 = BuyNode(2);
	BTNode* node3 = BuyNode(3);
	BTNode* node4 = BuyNode(4);
	BTNode* node5 = BuyNode(5);
	BTNode* node6 = BuyNode(6);

	node1->left = node2;
	node1->right = node4;
	
	node2->left = node3;

	node4->left = node5;
	node4->right = node6;

	return node1;
}

void PreOrder(BTNode* root) {
	if (root == NULL) {
		printf("NULL ");
		return;
	}
	//打印节点数据便于观察是否正确
	printf("%d ", root->data);
	PreOrder(root->left);
	PreOrder(root->right);
}

void InOrder(BTNode* root) {
	if (root == NULL) {
		printf("NULL ");
		return;
	}

	InOrder(root->left);
	printf("%d ", root->data);
	InOrder(root->right);
}

void PostOrder(BTNode* root) {
	if (root == NULL) {
		printf("NULL ");
		return;
	}

	PostOrder(root->left);
	PostOrder(root->right);
	printf("%d ", root->data);

}

//int size = 0;
//void TreeSize(BTNode* root) {
//	if (root == NULL) {
//		return;
//	}
//	size++;
//
//	TreeSize(root->left);
//	TreeSize(root->right );
//}

//void TreeSize(BTNode* root, int* psize) {
//	if (root == NULL) {
//		return;
//	}
//	(*psize)++;
//	TreeSize(root->left, psize);
//	TreeSize(root->right, psize);
//}
//
//int TreeHeight(BTNode* root);

int TreeSize(BTNode* root) {
	if (root == NULL) {
		return 0;
	}
	
	return TreeSize(root->left)+TreeSize(root->right)+1;
}

//int TreeHeight(BTNode* root)
//{
//	if (root == NULL)
//		return 0;
//
//	return TreeHeight(root->left) > TreeHeight(root->right)
//		? TreeHeight(root->left) + 1 : TreeHeight(root->right) + 1;
//}

int TreeHeight(BTNode* root)
{
	if (root == NULL)
		return 0;

	int leftHeight = TreeHeight(root->left);
	int rightHeight = TreeHeight(root->right);

	return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}

//求当前树第k层的节点个数=左子树第k-1层节点+右子树第k-1层节点
//int TreeKLevel(BTNode* root, int k) {
//	if (root == NULL || k == 0)
//		return 0;
//	if (root != NULL && k == 1) {
//		return 1;
//	}
// 
//	return TreeKLevel(root->left, k - 1)+TreeKLevel(root->right, k - 1);
//}
int TreeKLevel(BTNode* root, int k) {
	assert(k > 0);
	if (root == NULL) {
		return 0;
	}
	if (k == 1) {
		return 1;
	}
	//int leftK = TreeKLevel(root->left, k - 1);
	//int rightK = TreeKLevel(root->right, k - 1);
	//return leftK + rightK;
	return TreeKLevel(root->left, k - 1)
		+ TreeKLevel(root->right,k-1);
}

int main() {
	BTNode* root=CreatTree();
	PreOrder(root);

	printf("\n");
	InOrder(root);

	printf("\n");
	PostOrder(root);

	/*printf("\n");
	size = 0;
	TreeSize(root);
	printf("TreeSize:%d ", size);

	printf("\n");
	size = 0;
	TreeSize(root);
	printf("TreeSize:%d ", size);*/
	
	/*printf("\n");
	int size1 = 0;
	TreeSize(root, &size1);
	printf("TreeSize:%d\n", size1);

	int size2 = 0;
	TreeSize(root, &size2);
	printf("TreeSize:%d\n", size2); */

	/*printf("\n");
	printf("TreeSize:%d ", TreeSize(root));*/

	printf("\n");
	printf("TreeSize:%d ", TreeSize(root));

	printf("\n");
	printf("TreeHeight:%d ", TreeHeight(root));

	printf("\n");
	printf("TreeKLevel:%d\n", TreeKLevel(root, 2));

	printf("TreeKLevel:%d\n", TreeKLevel(root, 3));

	printf("TreeKLevel:%d\n", TreeKLevel(root, 4));
}
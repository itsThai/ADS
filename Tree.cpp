#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <time.h>

using namespace std;

typedef struct TreeNode {
	int value;
	TreeNode *parent;
	TreeNode *left;
	TreeNode *right;
} Branch;

int* initArray(int n) {
	int *array = (int*) malloc(n * sizeof(int));
	
	srand(time(NULL));
	printf("The array used is: ");
	for (int i = 0; i < n; i++) {
		array[i] = rand() % 100;
		printf("%d ", array[i]);
	}
	printf("\n");
	return array;	
}

void addLeftbranch(Branch* b, int val) {
	Branch *left_branch = (Branch *) malloc(sizeof(Branch));
	left_branch -> parent = b;
	left_branch -> left = NULL;
	left_branch -> right = NULL;
	left_branch -> value = val;
	
	b -> left = left_branch;
}

void addRightbranch(Branch* b, int val) {
	Branch *right_branch = (Branch *) malloc(sizeof(Branch));
	right_branch -> parent = b;
	right_branch -> left   = NULL;
	right_branch -> right  = NULL;
	right_branch -> value  = val;
	
	b -> right = right_branch;
}

Branch* initTree() {
	Branch *root = (Branch *) malloc(sizeof(Branch));
	root -> value = 0;
	root -> parent = NULL;
	root -> left   = NULL;
	root -> right  = NULL;
	return root;
}

Branch* createTree(Branch* root, int h) {
	if (h == 0) {
		return 0;
	}
	else {
		addLeftbranch( root, -1);
		root -> left -> parent = root;
		addRightbranch(root, -1);
		root -> right -> parent = root;
		
		createTree(root ->  left, h - 1);
		createTree(root -> right, h - 1);
	}
}

bool isLeaf(Branch* b) {
	if (b -> left == NULL || b -> right == NULL) {
		return true;
	}
	else {
		return false;
	}
}

int j = 0;
void initValue(int* arr, int n, Branch* root) {
	if (not isLeaf(root)) {
		initValue(arr, n, root -> left);
		initValue(arr, n, root -> right);
	}
	else {
		if (j < n) {
			root -> value = arr[j];	
        }
		else {
			root -> value = 101;		
		}
		j++;
	}
}
void arrange(Branch* root) {
	if (root == NULL) {
		printf("\n");
	}
	else {
		if (root -> left -> value == -1) {
			arrange(root -> left);
		}
		else if (root -> right -> value == -1) {
			arrange(root -> right);
		}
		else {
			if (root -> left -> value > root -> right -> value) {
				root -> value = root -> right -> value;
			}
			else {
				root -> value = root -> left -> value;
			}
			arrange(root -> parent);
		}
	}
}

void displayNLR(Branch* root) {
	if (root != NULL) {
		printf("%d ", root -> value);
		displayNLR(root -> left);
		displayNLR(root -> right);
	}
}
int search(int n, Branch* root) {
	if (root != NULL) {
		if (root -> value == n) {
			while (root != NULL) {
			    printf("%d <- ", root -> value);
				root = root -> parent;
			}
		}
		else {
			search(n, root -> left);
			search(n, root -> right);
		}
	}
	else {
		return -1;
	}
}

void add(int n, Branch* root) {
	if (root != NULL) {
		if (root -> value == 101) {
			root -> value = n;
		}
		else {
			add(n, root -> left);
			add(n, root -> right);
		}
	}
}

void remove(int n, Branch* root) {
	if (root != NULL) {
		if (root -> value == n) {
			root -> value = 101;
		}
		else {
			remove(n, root -> left);
			remove(n, root -> right);
		}
	}
}

int main() {
	int size;
	printf("Size of the array: ");
    if (scanf("%d", &size) != 1 || size < 1) {
        printf("Wrong input\n");
        exit(0);
    };
	int *array = initArray(size);
	
	int height = ceil(log2(size));
	printf("The height of the tree is: %d\n", height);
	Branch* Root = initTree();
	createTree(Root, height);
	
	initValue(array, size, Root);
	arrange(Root);
	printf("display arranged NLR:\n");
	displayNLR(Root);
	printf("\n\n");

	int addno =0;
	printf("Which number do you want to add: ");
	scanf("%d", &addno);
	add (addno, Root);
	printf("display inorder after adding %d\n", addno);
	displayNLR(Root); 
	printf("\n");
	
	search(addno, Root); 
	printf("\n");
	
	remove(addno, Root); 
	printf("\n");
	printf("display inorder after removing %d\n", addno);
	displayNLR(Root);
	printf("\n");
		
	return 0;
}
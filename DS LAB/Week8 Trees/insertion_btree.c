#include<stdio.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

typedef struct Node Node;

struct node{
	Node* data;
	struct node *next;
};
typedef struct node queue;
queue *ptr, *f=NULL, *r=NULL;

Node* root=NULL;

int count=0;
void enqueue(Node* r1)
{
	queue* newnode=(queue*)malloc(sizeof(queue));
	ptr=newnode;
	if(!ptr){
		printf("\nQueue Overflow! \nTry Again Later:( ");
	}
	else{
        ptr->data=r1;
        ptr->next=NULL;
        if(!f)
            f=ptr;
        else
        r->next=ptr;
        r=ptr;
        count++;
    }
}

void dequeue()
{
	ptr=f;
	if(!ptr){
		printf("\nQueue Underflow! \nTry Again Later:( ");
	}
	else
	{
	    f=f->next;
		ptr->next=NULL;
		count--;
	}
}

Node* front(){
    ptr=f->data;
    return ptr;
}

Node* rear()
{
    ptr=r->data;
    return ptr;
}

int isempty(){
    ptr=f;
    if(!ptr)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
Node* CreateNode(int d){
    Node* newNode=(Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data=d;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

/* Function to insert element in binary tree */

Node* InsertNode(Node* r, int data)
{
    // If the tree is empty, assign new node address to root
    if (root == NULL) {
        root = CreateNode(data);
        return root;
    }

    // Else, do level order traversal until we find an empty
    // place, i.e. either left child or right child of some
    // node is pointing to NULL.

    enqueue(r);

    while (!isempty()) {
        Node* temp=f->data;
        dequeue();

        if (temp->left!=NULL)
            enqueue(temp->left);
        else {
            temp->left = CreateNode(data);
            return root;
        }

        if (temp->right != NULL)
            enqueue(temp->right);
        else {
            temp->right=CreateNode(data);
            return root;
        }
    }
}
/* function to delete the given deepest node
(d_node) in binary tree */
void deletDeepest(struct Node* r1, struct Node* d_node){
    f=NULL;
    r=NULL;
    enqueue(r1);

    // Do level order traversal until last node
    struct Node* temp;
    while (!isempty()) {
        temp = front();
        dequeue();
        if (temp == d_node) {
            temp = NULL;
            free(d_node);
            return;
        }
        if (temp->right) {
            if (temp->right == d_node) {
                temp->right = NULL;
                free(d_node);
                return;
            }
            else
                enqueue(temp->right);
        }

        if (temp->left) {
            if (temp->left == d_node) {
                temp->left = NULL;
                free(d_node);
                return;
            }
            else
                enqueue(temp->left);
        }
    }
}

/* function to delete element in binary tree */
Node* deletion(struct Node* r1, int key){
    f=NULL;
    r=NULL;
    if (r1==NULL)
        return NULL;

    if (r1->left == NULL && r1->right == NULL) {
        if (r1->data == key)
            return NULL;
        else
            return r1;
    }
    enqueue(r1);

    Node* temp;
    Node* key_node = NULL;

    // Do level order traversal to find deepest
    // node(temp) and node to be deleted (key_node)
    while (!isempty()) {
        temp=front();
        dequeue();
        if ((temp->data)== key)
            key_node=temp;

        if (temp->left)
            enqueue(temp->left);

        if (temp->right)
            enqueue(temp->right);
    }

    if (key_node != NULL) {
        int x = temp->data;
        deletDeepest(root, temp);
        key_node->data = x;
    }
    return root;
}
/* Inorder traversal of a binary tree */
int max,min;
void inorder(Node* temp)
{
    if (temp == NULL)
        return;

    inorder(temp->left);
    printf("%d ",temp->data);
    inorder(temp->right);
}
void preorder(Node* temp)
{
    if (temp == NULL)
        return;

    printf("%d ",temp->data);
    preorder(temp->left);
    preorder(temp->right);
}
void postorder(Node* temp)
{
    if (temp == NULL)
        return;

    postorder(temp->left);
    postorder(temp->right);
    printf("%d ",temp->data);
}
void findmax(Node* temp){
    if(temp==root)
        max=root->data;
    if(temp==NULL)
        return;
    findmax(temp->left);
    if(temp->data>max)
        max=temp->data;
    findmax(temp->right);
}
void findmin(Node* temp){
    if(temp==root)
        min=root->data;
    if(temp==NULL)
        return;
    findmin(temp->left);
    if(temp->data<min)
        min=temp->data;
    findmin(temp->right);
}
int ifNodeExists(Node* temp, int key)
{
    if (temp == NULL)
        return 0;

    if (temp->data == key)
        return 1;

    /* then recur on left sutree */
    int res1 = ifNodeExists(temp->left, key);
    // node found, no need to look further
    if(res1) return 1;

    /* node is not found in left,
    so recur on right subtree */
    int res2 = ifNodeExists(temp->right, key);

    return res2;
}
// Driver code
int main()
{
    root = CreateNode(10);
    root->left = CreateNode(11);
    root->left->left = CreateNode(7);
    root->right = CreateNode(9);
    root->right->left = CreateNode(15);
    root->right->right = CreateNode(8);

    printf("\nInorder traversal before insertion: ");
    inorder(root);
    printf("\n");

    int key = 12;
    root=InsertNode(root, key);
    root=InsertNode(root,24);

    printf("\nInorder traversal after insertion: ");
    inorder(root);
    printf("\n");

    findmax(root);
    printf("\nMax element: %d\n",max);
    findmin(root);
    printf("Min element: %d\n",min);
    int n;
    printf("Enter a val: ");
    scanf("%d",&n);

    if(ifNodeExists(root,n))
    printf("\n%d exists!!\n",n);
    else
        printf("\n7 does not exist\n");
    printf("PreOrder Traversal: ");
    preorder(root);
    printf("\nPost Order Traversal: \n");
    postorder(root);
    key = 24;
    root = deletion(root, key);
    printf("\nInorder traversal after deletion: ");
    inorder(root);
    printf("\n");

    return 0;
}

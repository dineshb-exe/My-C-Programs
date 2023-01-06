#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node *left;
  struct node *right;
};

struct node *root = NULL;

//time complexity best case: O(log n) worst case: O(h)
int search(struct node *r,int x)
{
    int r1;
    if(r->data==x)
    {
        return 1;
    }
    else if(r==NULL){
        return 0;
    }

    else if(x>r->data)
    {
        r1=search(r->right,x);
    }
    else if(x<r->data)
    {
        r1=search(r->left,x);
    }
    return r1;
}

void insert(struct node *r,int x)
{
    if(r==NULL)
    {
        r = (struct node*)malloc(sizeof(struct node));
        r->data = x;
        r->left = NULL;
        r->right = NULL;
    }
    else if(x>r->data)
    {
        insert(r->right,x);
    }
    else
    {
        insert(r->left,x);
    }
}

int max,min;
void inorder(struct node* temp)
{
    if (temp == NULL)
        return;
    inorder(temp->left);
    printf("%d ",temp->data);
    inorder(temp->right);
}

void preorder(struct node* temp)
{
    if (temp == NULL)
        return;
    printf("%d ",temp->data);
    preorder(temp->left);
    preorder(temp->right);
}

void postorder(struct node* temp)
{
    if (temp == NULL)
        return;

    postorder(temp->left);
    postorder(temp->right);
    printf("%d ",temp->data);
}

void findmax(struct node* temp)
{
    if(temp==root)
        max=root->data;
    if(temp==NULL)
        return;
    else{
    findmax(temp->left);
    if(temp->data>max)
        max=temp->data;
    findmax(temp->right);
    }
}

struct node* findmin(struct node* temp)
{
    if(temp==root)
        min=root->data;
        return temp;
    if(temp==NULL)
        return 0;
    findmin(temp->left);
    if(temp->data<min)
        min=temp->data;
    findmin(temp->right);
}

void delnode(struct node *root, int x)
{
/*    if(root==NULL)
    {
        return;
    }
    if(x>root->data)
    {
        delnode(root->right,x);
    }
    else if(x<root->data)
    {
        delnode(root->left,x);
    }
    else
    {
        //no children
        if(root->left == NULL || root->right == NULL)
        {
            free(root);
            return NULL;
        }
        //one child
        else if(root->left == NULL || root->right == NULL)
        {
            struct node *temp;
            if(root->left == NULL)
            {
                temp = root->right;
            }
            else
            {
                temp = root->left;
            }
            free(root);
            return temp;
        }
        //two children
        else
        {
            struct node *temp = findmin(root->right);
            root->data = temp->data;
            root->right = delnode(root->right,temp->data);
        }
    }
    return root;
    */
}

void menu()
{
    int choice=0;
    do
    {
        printf("\n1. Insert Element.");
        printf("\n2. Delete Element.");
        printf("\n3. Search Element.");
        printf("\n4. Minimum Element.");
        printf("\n5. Maximum Element.");
        printf("\n6. Pre-Order.");
        printf("\n7. In-Order.");
        printf("\n8. Post-Order.");
        printf("\n9. Exit.");
        printf("\nEnter your choice: "); scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                {
                    int x;
                    printf("\nEnter the element to insert: ");
                    scanf("%d",&x);
                    insert(root,x);
                    printf("%d Entered into the BST!!\n",x);
                }
                break;
            case 2:
                {
                    int x;
                    printf("\nEnter the element to be deleted: ");
                    scanf("%d",&x);
                    delnode(root,x);
                }
                break;
            case 3:
                {
                    int x;
                    printf("\nEnter the element to search: ");
                    scanf("%d",&x);
                    int y = search(root,x);
                    if(y==1)
                    {
                        printf("\n%d exists in the tree.",x);
                    }
                    else
                    {
                        printf("\n%d does not exist.",x);
                    }
                }
                break;
            case 4:
                {
                    findmin(root);
                    printf("\nMinimum element: %d",min);
                }
                break;
            case 5:
                {
                    findmax(root);
                    printf("\nMaximum element: %d",max);
                }
                break;
            case 6:{ printf("\nPreorder traversal: ");
                     preorder(root);
            } break;
            case 7:{ printf("\nInorder traversal: "); inorder(root); }break;
            case 8: {printf("\nPostorder traversal: "); postorder(root); }break;
            case 9: exit(0); break;
        }
    }while(1);
}

int main()
{
    menu();
    return 0;
}

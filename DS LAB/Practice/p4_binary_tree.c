#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct tree_node
{
    int data;
    struct tree_node *left_child;
    struct tree_node *right_child;
};
typedef struct tree_node tnode;
void preorder (tnode *x);
void inorder (tnode *x);
void postorder (tnode *x);
void levelorder(tnode* x);
void insert_element2(int element, tnode **root);
int count(tnode *root);
tnode *search(int element, tnode *x, tnode *search_ptr);
tnode *delete_element(int element, tnode **parent);
int minimum_element(tnode *x);
int maximum_element(tnode *x);
char choices();
int main()
{
    printf("*****BINARY TREES*****\n");
    tnode *root=(tnode*)malloc(sizeof(tnode));
    tnode *search_ptr;
    root = NULL;
    int flag = 0, element;
    //root->left_child = root->right_child = NULL;
    while(flag==0)
    {
        switch(choices())
        {
        case '1':
            {
                printf("\nEnter data to be inserted: ");
                scanf("%d",&element);
                insert_element2(element, &root);
                break;
            }
        case '2':
            {
                printf("\nThe elements are: ");
                postorder(root);
                break;
            }
        case '3':
            {
                printf("\nThe elements are: ");
                inorder(root);
                break;
            }
        case '4':
            {
                printf("\nThe elements are: ");
                preorder(root);
                break;
            }
        case '5':
            {
                printf("\nEnter data to be deleted: ");
                scanf("%d",&element);
                tnode *return_ptr = (delete_element(element,&root));
                break;
            }
        case '6':
            {
                printf("\nEnter data to be searched: ");
                scanf("%d",&element);
                search_ptr = NULL;
                search_ptr = search(element,root, search_ptr);
                if(search_ptr!=NULL)
                printf("Searched element = %d",search_ptr->data);
                else printf("\nElement not found");
                break;
            }
        case '7':
            {
                printf("\nMinimum element = %d",minimum_element(root));
                break;
            }
        case '8':
            {
                printf("\nMaximum element = %d",maximum_element(root));
                break;
            }
        case '9':
            {
                printf("Count = %d",count(root)-1);
            }
        default:
            {
                flag=1;
                break;
            }
        }
    }
}
void insert_element2(int element, tnode **parent)
{
    if(*parent != NULL)
    {
        if(count((*parent)->left_child) > count((*parent)->right_child))
        insert_element2(element, &((*parent)->right_child));
        else
        insert_element2(element, &((*parent)->left_child));
    }
    else
    {
        tnode *new_node = (tnode*)malloc(sizeof(tnode));
        *parent = new_node; //linking (parent now hold address of new_node)
        (*parent)->data = element;
        (*parent)->left_child = (*parent)->right_child = NULL;
    }
}
int count(tnode *root)
{
    if(root!=NULL)
    {
        return count(root->left_child) + count(root->right_child);
    }
    else return 1;
}
void preorder (tnode *x)
{
    if(x!=NULL)
    {
        printf("\ndata = %d",x->data);
        preorder(x->left_child);
        preorder(x->right_child);
    }
}
void inorder (tnode *x)
{
    if(x!=NULL)
    {
        inorder(x->left_child);
        printf("\ndata = %d",x->data);
        inorder(x->right_child);
    }
}
void postorder (tnode *x)
{
    if(x!=NULL)
    {
        postorder(x->left_child);
        postorder(x->right_child);
        printf("\ndata = %d",x->data);
    }
}
void levelorder(tnode* c){

}
tnode *search(int element, tnode *x, tnode *search_ptr)
{
        if(x!=NULL)
    {
        if(x->data == element)
        {
            search_ptr = x;
            return search_ptr;
        }
        else
        {
            if(search_ptr==NULL) search_ptr = search(element, x->left_child, search_ptr);
            if(search_ptr==NULL) search_ptr = search(element, x->right_child, search_ptr);
        }
    }
    return search_ptr;
}
tnode *delete_element(int element, tnode **parent)
{
    if (*parent==NULL) return NULL;
    else if(element != (*parent)->data)
    {
        //similar to preorder traversal
        (*parent)->left_child = delete_element(element, &((*parent)->left_child));
        (*parent)->right_child = delete_element(element, &((*parent)->right_child));
    }
    else //element found
    {
        if((*parent)->left_child == NULL && (*parent)->right_child == NULL) {free(*parent); return NULL;} //only leaf node
        else if((*parent)->left_child == NULL || (*parent)->right_child == NULL) //one-child
        {
            tnode *replace_delete;
            if((*parent)->left_child == NULL) replace_delete = (*parent)->right_child;
            else replace_delete = (*parent)->left_child;
            free(*parent);
            return (replace_delete); //this is the value returned to the function having the pointer to the deleted node as 1 of its arguments
        }
        else //2-children
        {
            tnode *replace_delete = (*parent)->right_child;
            (*parent)->data = replace_delete->data;
            (*parent)->right_child = delete_element(replace_delete->data, &((*parent)->right_child));
//            free(parent);
//            return(replace_delete);
        }
    }
    return (*parent);
}
int minimum_element(tnode *x)
{
    int min_element = INT_MAX, temp;
    if (x!=NULL)
    {
        min_element = x->data;
        if(min_element > (temp = minimum_element(x->left_child))) min_element = temp;
        if(min_element > (temp = minimum_element(x->right_child))) min_element = temp;
    }
    return (min_element);
}
int maximum_element(tnode *x)
{
    int max_element = INT_MIN, temp;
    if (x!=NULL)
    {
        max_element = x->data;
        if(max_element < (temp = maximum_element(x->left_child))) max_element = temp;
        if(max_element < (temp = maximum_element(x->right_child))) max_element = temp;
    }
    return (max_element);
}
char choices()
{
    char choice;
    printf("\nWhat would you like to do? Choose the number corresponding to your choice");
    printf("\n1. Insert an element");
    printf("\n2. Display all elements - postorder traversal");
    printf("\n3. Display all elements - inorder traversal");
    printf("\n4. Display all elements - preorder traversal");
    printf("\n5. Delete an element");
    printf("\n6. Search an element");
    printf("\n7. Find the minimum element");
    printf("\n8. Find the maximum element");
    printf("\n9. Number of nodes in the tree");
    printf("\n(Enter any character to exit)");
    printf("\nEnter number: ");
    scanf(" %c",&choice);
    return choice;
}

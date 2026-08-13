#include<stdio.h>
#include<stdlib.h>

struct BST
{
    int data;
    struct BST *left;
    struct BST *right;
    struct BST *parent;

    
};
void preoder(struct BST *root){
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preoder(root->left);
        preoder(root->right);
    }
}
void postorder(struct BST *root)
{
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);

    }
}
void inorder(struct BST *root)
{
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
       

    }
}
struct BST* insert(struct BST*root,struct BST *Newnode)
{
    if(root==NULL)
    {
        root=Newnode;
    }
    else if(Newnode->data<=root->data)
    {
        root->left=insert(root->left,Newnode);
        (root->left)->parent=root;

    }
    else
    {
        root->right=insert(root->right,Newnode);
        (root->right)->parent=root;
    }
    return root;
    
}
struct BST* search(struct BST* root,int  key)
{
    if(root==NULL||key==root->data)
    return root;
    else if(key<root->data)
    return search(root->left,key);
    else
    return search(root->right,key);
    
}

struct BST* find_max(struct BST *root){
    
        while(root->right!=NULL)
        {
            root=root->right;
        }
        return root;
    
}
struct BST* find_min(struct BST *root)
{
    while(root->left!=NULL)
    {
        root=root->left;
    }
    return root;
}





int main()
{
    int choice, element;
    struct BST*root=NULL;
    struct BST *temp;
    do{
        printf("1.Insert\n2.Delete\n3.search\n4.Max\n5.Min\n6.Traverse\n7.EXit\n");
        printf("choice?");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
             printf("Element ?");
             scanf("%d",&element);
             struct BST *Newnode=(struct BST*)malloc(sizeof(struct BST));
             Newnode->data=element;
             Newnode->left=Newnode->right=Newnode->parent=NULL;
             root=insert(root,Newnode);


             break;
            case 2:
            
             break;
            case 3:
             printf("Element ?");
             scanf("%d",&element);
             temp=search(root,element);
             if (temp!=NULL)
              printf("element %d found\n",temp->data);
              else
              
              printf("search unsuccessfull");
              break;
            case 4:
             temp=find_max(root);
             if (temp!=NULL)
             printf("max element is %d",temp->data);
             else
             {
             printf("tree is empty\n");
             }
            
            


            
             break;

            case 5:
             temp=find_min(root);
             if (temp!=NULL)
             printf("min element is %d",temp->data);
             else
             printf("tree is empty");
                
             
             


             


             break;
            case 6:
             printf("Preorder\n");
             preoder(root);
             
             printf("\n");
             printf("Inorder\n");
             inorder(root);
             printf("\n");
             printf("postorder\n");
            
             postorder(root);
             printf("\n");

            
             break;
            case 7:

             printf("byy");


             break;

            default:
             printf("enter correct choice");

        }
    }
    while (choice!=7);
    return 0;

    
    
}    


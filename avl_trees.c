//works good
#include <stdio.h>
#include <stdlib.h>
struct avlnode{
    struct avlnode *left;
    struct avlnode *right;
    int key;
    int height;
};
struct avlnode* root=NULL;

int height(struct avlnode *node);
int max(int a, int b);
struct avlnode *create_node(int key);
struct avlnode *right_rotate(struct avlnode *node);
struct avlnode *left_rotate(struct avlnode *node);
int getbalance(struct avlnode *node);
struct avlnode *insert(struct avlnode *node, int key);
struct avlnode *minvalue_node(struct avlnode *node);
struct avlnode *delete(struct avlnode *root, int key);
void preorder(struct avlnode* root);
void inorder(struct avlnode* root);
void postorder(struct avlnode* root);

int main(){
    root=insert(root,21);
    root=insert(root,26);
    root=insert(root,30);
    root=insert(root,9);
    root=insert(root,4);
    root=insert(root,14);
    root=insert(root,28);
    root=insert(root,18);
    root=insert(root,15);
    root=insert(root,10);
    root=insert(root,2);
    root=insert(root,3);
    root=insert(root,7);
    inorder(root);printf("\n");
    root=delete(root,2);
    inorder(root);printf("\n");
    root=delete(root,15);
    inorder(root);printf("\n");
    root=delete(root,9);
    inorder(root);printf("\n");
    return 0;
}
int height(struct avlnode *node){
    if (node == NULL){
        return 0;
    }
    return node->height;
}
int max(int a, int b){
    return a > b ? a : b;
}
struct avlnode *create_node(int key){
    struct avlnode *node = malloc(sizeof(struct avlnode));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}
struct avlnode *right_rotate(struct avlnode *node){
    struct avlnode *x = node->left;
    struct avlnode *y = x->right;

    x->right = node;
    node->left = y;

    node->height = max(height(node->left), height(node->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}
struct avlnode *left_rotate(struct avlnode *node){
    struct avlnode *x = node->right;
    struct avlnode *y = x->left;

    x->left = node;
    node->right = y;

    node->height = max(height(node->left), height(node->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

int getbalance(struct avlnode *node){
    if (node == NULL){
        return 0;
    }
    return height(node->left)-height(node->right);
}

struct avlnode *insert(struct avlnode *node, int key){
    //1.basic insertion
    if (node == NULL){
        return create_node(key);
    }

    if (key < node->key){
        node->left = insert(node->left, key);
    }
    else if (key > node->key){
        node->right = insert(node->right, key);
    }
    else{
        // it is a duplicate key
        return node;
    }

    //2. update the height 
    node->height = 1 + max(height(node->left), height(node->right));

    //3. balance
    int balance = getbalance(node);

    // single rotation cases
    if (balance > 1 && key < node->left->key)
        return right_rotate(node);
    if (balance < -1 && key > node->right->key)
        return left_rotate(node);
    // double rotation cases
    if (balance > 1 && key > node->left->key){
        node->left = left_rotate(node->left);
        return right_rotate(node);
    }
    if (balance < -1 && key < node->right->key){
        node->right = right_rotate(node->right);
        return left_rotate(node);
    }
    return node;
}

struct avlnode *minvalue_node(struct avlnode *node){
    struct avlnode *current = node;
    while (current->left != NULL){
        current = current->left;
    }
    return current;
}
struct avlnode *delete(struct avlnode *root, int key){
    if(root==NULL)
        return root;
    
    if(key<root->key)
        root->left=delete(root->left,key);
    else if(key>root->key)
        root->right=delete(root->right,key);
    else{
        //element found
        if((root->left==NULL)||(root->right==NULL)){
            struct avlnode* temp=root->left?root->left:root->right;

            //no child case
            if(temp==NULL){
                temp=root;root=NULL;
            }
            //one child case
            else{
                *root=*temp;
            }
            free(temp);
        }
        //two children case
        else{
            struct avlnode* temp=minvalue_node(root->right);
            root->key=temp->key;
            root->right=delete(root->right,temp->key);
        }
    }
    if(root==NULL)
        return root;

    //balancing the tree
    root->height=1+max(height(root->left),height(root->right));
    int balance=getbalance(root);

    //left left
    if (balance > 1 && getbalance(root->left)>=0)
        return right_rotate(root);
    //right right
    if (balance < -1 && getbalance(root->right)<=0)
        return left_rotate(root);
    //left right
    if (balance > 1 && getbalance(root->left)<0){
        root->left = left_rotate(root->left);
        return right_rotate(root);
    }
    //right left
    if (balance < -1 && getbalance(root->right)>0){
        root->right = right_rotate(root->right);
        return left_rotate(root);
    }
    return root;
}
void preorder(struct avlnode *root){
    if (root){
        printf("%d---->", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct avlnode *root){
    if (root){
        postorder(root->left);
        postorder(root->right);
        printf("%d---->", root->key);
    }
}
void inorder(struct avlnode *root){
    if (root){
        inorder(root->left);
        printf("%d---->", root->key);
        inorder(root->right);
    }
}

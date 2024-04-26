#include<stdio.h>
#include<stdlib.h>
#define MAX_KEYS 4

struct node{
    int keys[MAX_KEYS];
    struct node* children[MAX_KEYS+1];
    int num_keys;
    int leaf;   //whether node is leaf or not
};
struct node* create_node(int leaf);
void split_child(struct node* parent,int index,struct node* child);
void insertNonFull(struct node* node,int key);
struct node* insert(struct node* root,int key);
void inorder(struct node* root);

int main(){
    struct node* root=create_node(1);   //initialize a b-tree with a leaf node
    root=insert(root,10);
    root=insert(root,20);
    root=insert(root,5);

    root=insert(root,30);
    root=insert(root,2);
    root=insert(root,15);
    inorder(root);
}

struct node* create_node(int leaf){
    struct node *new_node=malloc(sizeof(struct node));
    new_node->num_keys=0;
    new_node->leaf=leaf;
    for(int i=0;i<MAX_KEYS+1;i++){
        new_node->children[i]=NULL;
    }
    return new_node;
}


void split_child(struct node* parent,int index,struct node* child){
    struct node* newNode=create_node(child->leaf);
    newNode->num_keys=MAX_KEYS/2;


    //transfer keys to the new node: these many keys will be transferred
    for(int i=0;i<MAX_KEYS/2-1;i++){
        newNode->keys[i]=child->keys[i+MAX_KEYS/2+1];
    }
    //if child is not leaf, transfer child pointers
    if(!child->leaf){
        for(int i=0;i<MAX_KEYS/2+1;i++){
            newNode->children[i]=child->children[i+MAX_KEYS/2];
        }
    }
    child->num_keys=MAX_KEYS/2-1;


    //shift child pointers in parent node to make space for new node
    for(int i=parent->num_keys;i>index;i--){
        parent->children[i+1]=parent->children[i];
    }
    //link new node to parent node
    parent->children[index+1]=newNode;

    //shift keys in parent node to make space for median key from child
    for(int i=parent->num_keys-1;i>=index;i--){
        parent->keys[i+1]=parent->keys[i];
    }

    //move median key from child to parent 
    parent->keys[index]=child->keys[MAX_KEYS/2];
    parent->num_keys++;
}
void insertNonFull(struct node* node,int key){
    //start from the last key in the node
    int i=node->num_keys-1;

    //insertion is to be done in leaf node
    if(node->leaf){
        //shift each element already present one position to its right
        while(i>=0 && key< node->keys[i]){
            node->keys[i+1]=node->keys[i];
            i--;
        }
        //position found:insert element and update number of elements in node
        node->keys[i+1]=key;
        node->num_keys++;
    }
    else{
        //check between which two keys the element to be inserted lies
        while(i>=0 && key<node->keys[i]){
            i--;
        }
        i++;
        if(node->children[i]->num_keys==MAX_KEYS){
            split_child(node,i,node->children[i]);
            if(key>node->keys[i]){
                i++;
            }
        }
        insertNonFull(node->children[i],key);
    }
}
struct node* insert(struct node* root,int key){
    struct node* temp=root;
    //node is full
    if(temp->num_keys==MAX_KEYS){
        struct node* new_root=create_node(0);
        new_root->children[0]=temp;
        split_child(new_root,0,temp);
        insertNonFull(new_root,key);
        return new_root;
    }
    //node can accomodate elements
    else{
        insertNonFull(temp,key);
        return root;
    }
    
}

void inorder(struct node* root){
    if(root){
        int i;
        for(i=0;i<root->num_keys;i++){
            inorder(root->children[i]);
            printf("%d ",root->keys[i]);
        }
        inorder(root->children[i]);
    }
}
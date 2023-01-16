#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct treenode{
    int value;
    struct treenode *left;
    struct treenode *rigth;
} treenode;

treenode * createnode(int value){
    treenode * result = malloc(sizeof(treenode));
    if(result != NULL){
        result->left = NULL;
        result->rigth = NULL;
        result->value = value;
    }
    return result;
}

void printtabs(int numtabs){
    for (size_t i = 0; i < numtabs; i++)
    {
        printf("\t");
    }
    
}

void printtree_rec(treenode * root, int level){
    if(root != NULL){
        printtabs(level);
        printf("value = %d\n", root->value);
        printtabs(level);
        printf("left\n");
        printtree_rec(root->left,level+1);
        printtabs(level);
        printf("rigth\n");
        printtree_rec(root->rigth,level+1);
        printtabs(level);
        printf("done\n");
    }else{
        printtabs(level);
        printf("---<empty>---\n");
        return;
    }
}

void printtree(treenode* root){
    printtree_rec(root,0);
}

bool insertnumber(treenode ** rootptr, int value){
    treenode * root = *rootptr;
    if(root == NULL){
        (*rootptr) = createnode(value);
        return true;
    }
    if(value == (*rootptr)->value){
        return false;
    }
    if(value < root->value){
        return insertnumber(&(root->left),value);
    } else{
        return insertnumber(&(root->rigth),value);
    }
}

bool findnumber(treenode * root,int value){
    if(root == NULL) return false;
    if(value == root->value){
        return true;
    }
    if(value < root->value){
        return findnumber(root->left,value);
    }else{

        return findnumber(root->rigth,value);
    }
}

int main(){

    treenode *root = NULL;
    insertnumber(&root,15);
    insertnumber(&root,11);
    insertnumber(&root,24);
    insertnumber(&root,5);
    insertnumber(&root,16);
    insertnumber(&root,19);

    printtree(root);

    printf("%d (%d)\n", 16, findnumber(root,16));
    printf("%d (%d)\n", 15, findnumber(root,15));
    printf("%d (%d)\n", 5, findnumber(root,5));
    printf("%d (%d)\n", 156, findnumber(root,156));
    

    return 0;
}
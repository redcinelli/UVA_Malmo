#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    struct Node *left,*right;
    int dl,wl,dr,wr;
} Node,*TNode;

void Yolotree(TNode *Branche)
{
    *Branche=(TNode)malloc(sizeof(Node));
    scanf("%d%d%d%d", &(*Branche)->wl, &(*Branche)->dl, &(*Branche)->wr, &(*Branche)->dr);
    /*we build the tree and make sure to take care of the sub-Branche*/
    if((*Branche)->wl==0)
        Yolotree(&(*Branche)->left);
    else
        (*Branche)->left=NULL;
    if((*Branche)->wr==0)
        Yolotree(&(*Branche)->right);
    else
        (*Branche)->right=NULL;
}

int Calculus(TNode Branche)
{
    if(Branche->left!=NULL)
        Branche->wl=Calculus(Branche->left)?Branche->left->wl+Branche->left->wr:0;
    if(Branche->right!=NULL)
        Branche->wr=Calculus(Branche->right)?Branche->right->wl+Branche->right->wr:0;
    return Branche->wl*Branche->dl==Branche->wr*Branche->dr;
}
/*visit the tree and delete it by recur*/
void delTree(TNode Branche)
{
    if(Branche->left!=NULL)delTree(Branche->left);
    if(Branche->right!=NULL)delTree(Branche->right);


    free(Branche);
}

int main(void)
{
    int test_cases;
    TNode tree;
    scanf("%d", &test_cases);
    /*we get the tab size and look throught it*/
    while(test_cases--)
    {
        Yolotree(&tree);
        /*we make sue the tree is balanced or not if the return is not 0 it fail.*/
        if(Calculus(tree)&&tree->wl&&tree->wr) printf("YES");
        else printf("NO");

        /*printf("%s\n", Calculus(tree)&&tree->wl&&tree->wr?"YES":"NO");*/
        /*free the malloc*/
        delTree(tree);
        if(test_cases)
            printf("\n");
    }
    return 0;
}

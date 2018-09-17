#include <stdio.h>
#include <stdlib.h>


typedef struct Node 
{

    int valor;    
    struct Node *esq;
    struct Node *dir;

}Tree;


// Inserir na arvore
Tree* insertTree(Tree *root, int valor)
{
    if(root == NULL)  
    { 
        Tree *auxRoot = malloc(sizeof(Tree));
        auxRoot->valor = valor;
        auxRoot->esq = NULL;
        auxRoot->dir = NULL;
        root = auxRoot;
        
    }
    else if(valor <= root->valor)
    {
        root->esq = insertTree(root->esq, valor);
    }
    else
    {
        root->dir = insertTree(root->dir, valor);
    }
    
    return root;
}


void inOrdem(Tree *root)
{
    if(root != NULL)
    {
        inOrdem(root->esq);
        printf(" %d", root->valor);
        inOrdem(root->dir);
    }
}

void preOrdem(Tree *root)
{
    if(root != NULL)
    {
        printf(" %d", root->valor);
        preOrdem(root->esq);
        preOrdem(root->dir);
    }
}

void posOrdem(Tree *root)
{
    if(root != NULL)
    {
        posOrdem(root->esq);
        posOrdem(root->dir);
        printf(" %d", root->valor);
    }
}

int main(int argc, char const *argv[])
{
    
    int qtdTestes;
    int qtdNumeros;
    int valores;
    scanf("%d", &qtdTestes);
    for(int i = 0; i < qtdTestes; i++)
    {
        scanf("%d", &qtdNumeros);
        
        Tree * binaryTree = NULL;
        

        for(int j = 0; j < qtdNumeros; j++)
        {
            scanf("%d", &valores);
            binaryTree = insertTree(binaryTree, valores);
        }

        printf("Case %d:\n", i+1);

        printf("Pre.:");
        preOrdem(binaryTree);
        
        
        printf("\n");
        printf("In..:");
        inOrdem(binaryTree);
        
        
        printf("\n");
        printf("Post:");
        posOrdem(binaryTree);

        printf("\n\n");
    }


    return 0;
}

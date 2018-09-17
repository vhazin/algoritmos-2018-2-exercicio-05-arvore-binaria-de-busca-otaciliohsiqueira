#include <stdio.h>
#include <stdlib.h>


typedef struct Node 
{

    int valor;    
    struct Node *esq;
    struct Node *dir;

}Tree;


// Criando uma arvore
void createTree(Tree **root)
{
    *root = NULL;
}

// Inserir uma nova raiz
Tree* insertRoot(Tree *root, int valor)
{
    Tree *auxRoot = malloc(sizeof(Tree));
    auxRoot->valor = valor;
    auxRoot->esq = NULL;
    auxRoot->dir = NULL;

    return auxRoot;
}

// Inserir na arvore
int insertTree(Tree *root, int valor)
{
    if(root == NULL)  
    { 
        root = insertRoot(root, valor);
        return root;
    }
    else if(valor <= root->valor)
    {
        root->esq = insertTree(root->esq, valor);
    }
    else
    {
        root->dir = insertTree(root->dir, valor);
    }
}


void inOrdem(Tree *root)
{
    if(root != NULL)
    {
        inOrdem(root->esq);
        printf("\n%i", root->valor);
        inOrdem(root->dir);
    }
}

void preOrdem(Tree *root)
{
    if(root != NULL)
    {
        printf("\n%i", root->valor);
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
        printf("\n%i", root->valor);
    }
}

int main(int argc, char const *argv[])
{
    Tree *binaryTree = NULL;
    int qtdTestes;
    int qtdNumeros;
    int valores;
    scanf("%d", &qtdTestes);
    for(int i = 0; i < qtdTestes; i++)
    {
        scanf("%d", &qtdNumeros);
        Tree *aux = binaryTree;
        binaryTree = NULL;
        free(aux);

        for(int j = 0; j < qtdNumeros; j++)
        {
            scanf("%d ", &valores);
            binaryTree = insertTree(binaryTree, valores);
        }

        printf("Case %d:\n", i);

        printf("\nPre.: ");
        preOrdem(valores);

        printf("\nIn..: ");
        inOrdem(valores);

        printf("\nPost: ");
        posOrdem(valores);

        printf("\n\n");
    }


    return 0;
}

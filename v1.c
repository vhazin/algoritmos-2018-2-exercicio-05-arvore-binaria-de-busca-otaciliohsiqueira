


struct regNo	{	struct regNo *esq;
					int valor;
					struct regNo *dir;
				};
typedef struct regNo TArvore;


int ImprimeArvore(TArvore *r)
{
	if(r != NULL)
	{
		if(tipo == 1){
			printf(" %d", r->valor);
			ImprimeArvore(r->esq);
			ImprimeArvore(r->dir);
		}
		if(tipo == 2){
			ImprimeArvore(r->esq);
			printf(" %d", r->valor);
			ImprimeArvore(r->dir);
		}
		if(tipo == 3){
			ImprimeArvore(r->esq);
			ImprimeArvore(r->dir);
			printf(" %d", r->valor);
		}
	}

	return 0;
}

typedef struct NODE{
	int     valor;
	struct  NODE *proximo;
	struct  NODE *anterior;
	void    (*printNode)(struct NODE*);
}node;

typedef struct LISTA{
	node    *raiz;
	node	*folha;
	int     qtd;
	void    (*printListaTexto)(struct LISTA*);
	void    (*printListaBin)(struct LISTA*);
	void    (*addNodeInicio)(struct LISTA*, node*);
	void    (*addNodeFinal)(struct LISTA*, node*);
	void 	(*desconectaNode)(struct LISTA*, node*);
	node*   (*rmNodeFinal)(struct LISTA*);
	node*	(*swap)(struct LISTA*, node*, node*);
	int	(*verificar)(struct LISTA*);
}lista;


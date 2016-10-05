typedef struct NODE{
    void*   elemento;
    struct  NODE *proximo;
    struct  NODE *anterior;
}node;

typedef struct LISTA{
    node    *raiz;
    node	*folha;
    int     qtd;
    void    (*addNodeInicio)(struct LISTA*, node*);
    void    (*addNodeFinal)(struct LISTA*, node*);
    void 	(*desconectaNode)(struct LISTA*, node*);
    node*   (*rmNodeFinal)(struct LISTA*);
    node*	(*swap)(struct LISTA*, node*, node*);
    void    (*addListaFinal)(struct LISTA*, struct LISTA*);
}lista;

typedef struct ARCO{
    int     antecessor;
    int     sucessor;
    int     (*arcoEquals)(struct ARCO*, struct ARCO*);
}arco;

typedef struct GRAFO{
    lista   *arcos;
    void    (*insArco)(struct GRAFO*, int, int, int);
    void    (*elimArco)(struct GRAFO*, int, int);
    void    (*custoArco)(struct GRAFO*, int, int);
    lista   (*sucessores)(struct GRAFO*, int);
    lista   (*ordemGrafo)(struct GRAFO*);
    lista   (*destruirGrafo)(struct GRAFO*);
    lista   (*carregarGrafo)(FILE*);
    lista   (*salvarGrafo)(struct GRAFO*, FILE*);
    lista   (*marcarVertice)(struct GRAFO*, int);
    lista   (*desmarcarVertice)(struct GRAFO*, int);
    lista   (*desmarcarGrafo)(struct GRAFO*);
    lista   (*marcadoVertice)(struct GRAFO*, int v);

    int     (*existeCaminho)(struct GRAFO*, arco*);
    int     (*existeCiclo)(struct GRAFO*, int);
    void    (*exibeCaminhos)(struct GRAFO*, arco*);
}grafo;

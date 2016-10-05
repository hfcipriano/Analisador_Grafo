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
    int     custo;
    int     (*arcoEquals)(struct ARCO*, struct ARCO*);
}arco;

typedef struct GRAFO{
    lista           *arcos;
    void            (*insArco)(struct GRAFO*, int, int, int);
    void            (*elimArco)(struct GRAFO*, int, int);
    int             (*custoArco)(struct GRAFO*, int, int);
    lista*          (*obterSucessores)(lista*, int);
    lista*          (*obterAntecessores)(lista*, int);
    int             (*ordemGrafo)(struct GRAFO*);
    void            (*destruirGrafo)(struct GRAFO*);
    struct GRAFO*   (*carregarGrafo)(FILE*);
    void            (*salvarGrafo)(struct GRAFO*, FILE*);
    void            (*marcarVertice)(struct GRAFO*, int);
    void            (*desmarcarVertice)(struct GRAFO*, int);
    void            (*desmarcarGrafo)(struct GRAFO*);
    void            (*marcadoVertice)(struct GRAFO*, int v);

    int             (*existeCaminho)(struct GRAFO*, arco*);
    int             (*existeCiclo)(struct GRAFO*, int);
    void            (*exibeCaminhos)(struct GRAFO*, arco*);
}grafo;

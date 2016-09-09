typedef struct NODE{
    void  *elemento; //Ponteiro genérico para valores de Vertices e Arestas
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
    int	    (*verificar)(struct LISTA*);
}lista;

typedef struct VERTICE{
    char    *valor;
    int     (*verticeEquals)(struct VERTICE*, struct VERTICE*);
}vertice;


typedef struct ARESTA{
    char *valor;
    vertice *antecessor;
    vertice *sucessor;
    int     (*arestaEquals)(struct ARESTA*, struct ARESTA*);
}aresta;

typedef struct GRAFO{
    lista   *vertices;
    lista   *arestas;
    void    (*addVertice)(struct GRAFO*, node*);
    void    (*addAresta)(struct GRAFO*, node*);
    void    (*printVertices)(struct GRAFO*);
    void    (*printArestas)(struct GRAFO*);
    void    (*printGrafo)(struct GRAFO*);
    int     (*existeCaminho)(struct GRAFO*, aresta*);
}grafo;

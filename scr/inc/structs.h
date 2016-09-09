typedef struct NODE{
    void  *elemento; //Ponteiro genérico para valores de Vertices e Arestas
    struct  NODE *proximo;
    struct  NODE *anterior;
}node;

typedef struct LISTA{
    node    *raiz;
    node	*folha;
    int     qtd;
    void    (*printListaTexto)(struct LISTA*);
    void    (*addNodeInicio)(struct LISTA*, node*);
    void    (*addNodeFinal)(struct LISTA*, node*);
    void 	(*desconectaNode)(struct LISTA*, node*);
    node*   (*rmNodeFinal)(struct LISTA*);
    node*	(*swap)(struct LISTA*, node*, node*);
    int	    (*verificar)(struct LISTA*);
}lista;

typedef struct VERTICE{
    char *valor;
}vertice;


typedef struct ARESTA{
    char *valor;
    vertice *antecessor;
    vertice *sucessor;
}aresta;

typedef struct GRAFO{
    lista   *vertices;
    lista   *arestas;
    void    (*addVertice)(struct GRAFO*, node*);
    void    (*addAresta)(struct GRAFO*, node*);
    void    (*printVertices)(struct GRAFO*);
    void    (*printArestas)(struct GRAFO*);
    void    (*printGrafo)(struct GRAFO*);
}grafo;

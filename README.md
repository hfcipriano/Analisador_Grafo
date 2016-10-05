# Grafo_Analisador
Analisador de Grafos

Exemplo : {

    grafo *g = inicGrafo();

    g->addAresta(g, newNode(newAresta(newVertice("a"), newVertice("b"))));
    g->addAresta(g, newNode(newAresta(newVertice("b"), newVertice("c"))));
    g->addAresta(g, newNode(newAresta(newVertice("c"), newVertice("d"))));
    g->addAresta(g, newNode(newAresta(newVertice("d"), newVertice("a"))));

    aresta *aresta = newAresta(newVertice("a"), newVertice("d"));

    //Task 1-2
    printf("%d", g->existeCaminho(g, aresta)); //Retona 1 (Verdadeiro)

    //Task 3
    printf("\n%d", g->existeCiclo(g, newVertice("a"))); //Retona 1 (Verdadeiro)

    //Task 4
    g->exibeCaminhos(g, aresta); //Imprime "Caminhos = {(a, b) -> (b, c) -> (c, d)}"
}

Para compilar o projeto, deve se utilizar o cMake (https://cmake.org/install/) (Gera o Makefile do projeto)

Por: Henrique Cipriano
hfcipriano@gmail.com

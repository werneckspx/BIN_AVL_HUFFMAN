#ifndef ARVOREAVL_HPP
#define ARVOREAVL_HPP

#include "No.hpp"

class ArvoreAVL
{

public:
    No *raiz;

    int altura(No *no);
    int calcularbalanceador(No *no);

    No *rotacaoDireita(No *y);
    No *rotacaoEsquerda(No *x);

    No *inserirAux(No *no, string palavra, int quantidade);

    ArvoreAVL();

    void inserir(vector<No> &heap);

    void imprimirOrdem(No *no);
};

#endif

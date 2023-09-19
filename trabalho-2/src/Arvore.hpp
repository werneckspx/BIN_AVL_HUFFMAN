#ifndef ARVORE_HPP
#define ARVORE_HPP

#include "No.hpp"

class Arvore
{
public:
    No *raiz;
    Arvore();

    void inserir(vector<No> &heap);

    void inserirAux(No *no, string palavra, int quantidade);

    void imprimirOrdem(No *no);
};

#endif

#include "ArvoreAVL.hpp"

ArvoreAVL::ArvoreAVL()
{
    raiz = nullptr;
}

int ArvoreAVL::altura(No *no)
{
    if (no == nullptr)
    {
        return 0;
    }
    return max(altura(no->esquerdo), altura(no->direito)) + 1;
}

int ArvoreAVL::calcularbalanceador(No *no)
{
    if (no == nullptr)
    {
        return 0;
    }
    return altura(no->esquerdo) - altura(no->direito);
}

No *ArvoreAVL::rotacaoDireita(No *y)
{
    No *x = y->esquerdo;
    No *T2 = x->direito;

    x->direito = y;
    y->esquerdo = T2;

    y->balanceador = calcularbalanceador(y);
    x->balanceador = calcularbalanceador(x);

    return x;
}

No *ArvoreAVL::rotacaoEsquerda(No *x)
{
    No *y = x->direito;
    No *T2 = y->esquerdo;

    y->esquerdo = x;
    x->direito = T2;

    x->balanceador = calcularbalanceador(x);
    y->balanceador = calcularbalanceador(y);

    return y;
}

No *ArvoreAVL::inserirAux(No *no, string palavra, int quantidade)
{
    if (no == nullptr)
    {
        return new No(palavra, quantidade, nullptr, nullptr);
    }

    if (quantidade < no->quantidade)
    {
        no->esquerdo = inserirAux(no->esquerdo, palavra, quantidade);
    }
    else if (quantidade > no->quantidade)
    {
        no->direito = inserirAux(no->direito, palavra, quantidade);
    }
    else
    {
        // As palavras têm a mesma quantidade; use a ordem lexicográfica
        if (palavra < no->palavra)
        {
            no->esquerdo = inserirAux(no->esquerdo, palavra, quantidade);
        }
        else
        {
            no->direito = inserirAux(no->direito, palavra, quantidade);
        }
    }

    no->balanceador = calcularbalanceador(no);

    if (no->balanceador > 1 && quantidade < no->esquerdo->quantidade)
    {
        return rotacaoDireita(no);
    }
    if (no->balanceador < -1 && quantidade > no->direito->quantidade)
    {
        return rotacaoEsquerda(no);
    }
    if (no->balanceador > 1 && quantidade > no->esquerdo->quantidade)
    {
        no->esquerdo = rotacaoEsquerda(no->esquerdo);
        return rotacaoDireita(no);
    }
    if (no->balanceador < -1 && quantidade < no->direito->quantidade)
    {
        no->direito = rotacaoDireita(no->direito);
        return rotacaoEsquerda(no);
    }

    return no;
}

void ArvoreAVL::inserir(vector<No> &heap)
{
    for (const No &node : heap)
    {
        raiz = inserirAux(raiz, node.palavra, node.quantidade);
    }
    imprimirOrdem(raiz);
}

void ArvoreAVL::imprimirOrdem(No *no)
{
    if (no == nullptr)
    {
        return;
    }

    string arq = "dataset/output.txt";
    ofstream F(arq, std::ios::app);
    if (!(raiz == NULL))
    {
        imprimirOrdem(no->esquerdo);
        imprimirOrdem(no->direito);
        F << no->palavra << " " << no->quantidade << endl;
    }
    /*queue<No *> fila;
    fila.push(raiz);

    while (!fila.empty())
    {
        No *no = fila.front();
        fila.pop();
        F << no->palavra << " ";
        F << no->quantidade << " " << endl;

        if (no->esquerdo)
        {
            fila.push(no->esquerdo);
        }

        if (no->direito)
        {
            fila.push(no->direito);
        }
    }

    F<<endl;*/
}

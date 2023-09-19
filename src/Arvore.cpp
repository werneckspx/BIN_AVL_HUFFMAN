#include "Arvore.hpp"

Arvore::Arvore()
{
    this->raiz = nullptr;
}

void Arvore::inserirAux(No *no, string palavra, int quantidade)
{

    // Se a palavra é menor que a palavra do nó, insere no filho esquerdo
    if (quantidade < no->quantidade)
    {
        // Se o filho esquerdo é nulo, cria um novo nó como filho esquerdo
        if (no->esquerdo == nullptr)
        {
            no->esquerdo = new No(palavra, quantidade, nullptr, nullptr);
        }
        else
        {
            // Senão, chama o método recursivo para inserir no filho esquerdo
            inserirAux(no->esquerdo, palavra, quantidade);
        }
    }
    else if (quantidade > no->quantidade)
    {
        // Se a palavra é maior que a palavra do nó, insere no filho direito
        if (no->direito == nullptr)
        {
            no->direito = new No(palavra, quantidade, nullptr, nullptr);
        }
        else
        {
            // Senão, chama o método recursivo para inserir no filho direito
            inserirAux(no->direito, palavra, quantidade);
        }
    }
    else
    {
        // As palavras têm a mesma quantidade alfabetica
        if (palavra < no->palavra)
        {
            if (no->esquerdo == nullptr)
            {
                no->esquerdo = new No(palavra, quantidade, nullptr, nullptr);
            }
            else
            {
                // Senão, chama o método recursivo para inserir no filho esquerdo
                inserirAux(no->esquerdo, palavra, quantidade);
            }
        }
        else
        {
            // Se a palavra é maior que a palavra do nó, insere no filho direito
            if (no->direito == nullptr)
            {
                no->direito = new No(palavra, quantidade, nullptr, nullptr);
            }
            else
            {
                // Senão, chama o método recursivo para inserir no filho direito
                inserirAux(no->direito, palavra, quantidade);
            }
        }
    }
}

void Arvore::inserir(vector<No> &heap)
{
    for (const No &node : heap)
    {
        if (this->raiz == nullptr)
        {
            this->raiz = new No(node.palavra, node.quantidade, nullptr, nullptr);
        }
        else
        {
            // Chama o método auxiliar recursivo para inserir a palavra na subárvore apropriada
            inserirAux(this->raiz, node.palavra, node.quantidade);
        }
    }

    imprimirOrdem(raiz);
}

void Arvore::imprimirOrdem(No *no)
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
    }*/
}

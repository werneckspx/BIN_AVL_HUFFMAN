#include "No.hpp"

No::No(string palavra, int quantidade, No *esquerdo, No *direito)
{
    this->palavra = palavra;
    this->quantidade = quantidade;
    this->esquerdo = nullptr;
    this->direito = nullptr;
    this->balanceador = 0;
}

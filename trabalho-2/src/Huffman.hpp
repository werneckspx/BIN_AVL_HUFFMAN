#ifndef HUFFMAN_HPP
#define HUFFMAN_HPP

#include "No.hpp"
#define EMPTY_STRING ""

class Huffman
{
public:
    No *raiz;

    Huffman *esquerdo;
    Huffman *direito;
    Huffman();

    Huffman(No *wordInfo) : raiz(wordInfo), esquerdo(nullptr), direito(nullptr) {}
    void imprimirCodes(Huffman *rootH, int array[], int top);
    void HuffmanCodes(vector<No> &heap);
};

class Compare
{
public:
    bool operator()(Huffman *a, Huffman *b)
    {
        return a->raiz->quantidade > b->raiz->quantidade;
    }
};

#endif

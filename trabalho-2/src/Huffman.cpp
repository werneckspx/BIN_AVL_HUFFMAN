#include "Huffman.hpp"

Huffman::Huffman()
{
}

Huffman *generateHuffman(priority_queue<Huffman *, vector<Huffman *>, Compare> &huff)
{

    while (huff.size() != 1)
    {

        Huffman *esquerdo = huff.top();
        huff.pop();

        Huffman *direito = huff.top();
        huff.pop();

        No *h = new No{" ", esquerdo->raiz->quantidade + direito->raiz->quantidade, nullptr, nullptr};
        Huffman *node = new Huffman(h);
        node->esquerdo = esquerdo;
        node->direito = direito;

        huff.push(node);
    }

    return huff.top();
}

// imprimi as palavras e seus respectivos códigos

void Huffman::imprimirCodes(Huffman *rootH, int array[], int top)
{
    string arq = "dataset/output.txt";
    ofstream F(arq, std::ios::app);

    if (rootH->esquerdo)
    {
        array[top] = 0;
        imprimirCodes(rootH->esquerdo, array, top + 1);
    }

    if (rootH->direito)
    {
        array[top] = 1;
        imprimirCodes(rootH->direito, array, top + 1);
    }

    if (!rootH->esquerdo && !rootH->direito)
    {

        F << rootH->raiz->palavra << " ";

        for (int i = 0; i < top; i++)
            F << array[i];

        F << endl;
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

void Huffman::HuffmanCodes(vector<No> &heap)
{

    auto startH = chrono::steady_clock::now();

    priority_queue<Huffman *, vector<Huffman *>, Compare> huff;

    for (const No &wordInfo : heap)
    {
        Huffman *newNode = new Huffman(new No(wordInfo));
        huff.push(newNode);
    }

    Huffman *rootH = generateHuffman(huff);

    int array[constante], top = 0;

    imprimirCodes(rootH, array, top);
    cout << endl
         << endl;
    // outHuff(rootH, array, top);
    // clearHuffmanTree(rootH);

    // auto endH = chrono::steady_clock::now();
    // cout << "\nTEMPO HUFFMAN: " << chrono::duration_cast<chrono::nanoseconds>(endH - startH).count() << " ns" << endl << endl;
}

// imprimi a fila

/*void printPriorityQueue(priority_queue<Huffman *, vector<Huffman *>, Compare> &huff)
{

    cout << "\nPriority Queue: ";
    priority_queue<Huffman *, vector<Huffman *>, Compare> temphuff = huff;

    while (!temphuff.empty())
    {
        cout << temphuff.top()->raiz->palavra << "(" << temphuff.top()->raiz->quantidade << ") ";
        temphuff.pop();
    }
    cout << endl
         << endl;
}*/
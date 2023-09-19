#include "read.hpp"

void fn_principal()
{
    string filename("dataset/textos/Docs/filosofia.txt");
    string filename2("dataset/textos/Docs/filosofia2.txt");
    string filename3("dataset/textos/Docs/globalizacao.txt");
    string filename4("dataset/textos/Docs/politica.txt");
    string filename5("dataset/textos/Docs/ti.txt");
    string filename6("dataset/textos/Docs/ti2.txt");

    string arq = "dataset/output.txt";
    ofstream F(arq, std::ios::app);

    int k = 0;
    bool existeNoTexto = false;

    unordered_map<string, int> hash;
    unordered_map<string, int> stopWords;
    unordered_map<char, bool> pontos;

    vector<No> heap;
    unordered_map<string, int> words;

    readPalavras(words);
    readStopWords(stopWords);

    for (int i = 0; i < 6; i++)
    {
        F << "TEXTO: " << filename << endl;
        for (auto j : words)
        {

            F << endl
              << "PALAVRA: " << j.first << endl;
            existeNoTexto = false;
            leitor_principal(hash, words, stopWords, pontos, filename, k, j.first, existeNoTexto);
            if (existeNoTexto)
            {
                Heap(hash, heap, words);
            }
            else
            {
                F << "ESSA PALAVRA NAO APARECE NESTE TEXTO!" << endl
                  << endl;
            }
            hash.clear();
        }

        if (i == 0)
        {
            filename.assign(filename2);
        }
        else if (i == 1)
        {
            filename.assign(filename3);
        }
        else if (i == 2)
        {
            filename.assign(filename4);
        }
        else if (i == 3)
        {
            filename.assign(filename5);
        }
        else if (i == 4)
        {
            filename.assign(filename6);
        }
    }
}

void leitor_principal(unordered_map<string, int> &hash, unordered_map<string, int> &words, unordered_map<string, int> &stopWords, unordered_map<char, bool> &pontos, string filename, int &k, string palavra_input, bool &existeNoTexto)
{
    ifstream input_file(filename, ios::in);
    string line;
    string palavra_analisada;
    preencheMapPontos(pontos);

    if (!input_file.is_open())
    {
        cout << "Nao foi possivel abrir o arquivo" << filename << " " << endl;
    }

    while (!input_file.eof())
    {
        while (getline(input_file, line, '\n'))
        {
            for (auto &c : line)
            {
                c = tolower(c);
            }
            line = converterAcentuadasParaMinusculas(line);
            line = removePontuacao(line, pontos);
            istringstream ln(line);

            if (line.size() > 1)
            {
                while (ln >> palavra_analisada)
                {
                    if (stopWords.count(palavra_analisada) == 0)
                    {
                        if (palavra_analisada != "")
                        {
                            if (!existe_numero(palavra_analisada))
                            {
                                auto it3 = hash.find(palavra_analisada);
                                if (it3 != hash.end())
                                {
                                    it3->second++;
                                }
                                else
                                {
                                    if (palavra_analisada != palavra_input)
                                    {
                                        hash.insert({palavra_analisada, 1});
                                        k = k + 1;
                                    }
                                    else
                                    {
                                        existeNoTexto = true;
                                    }
                                }
                            }
                        }
                    }
                }
                line.clear();
            }
        }
    }
}

void Heap(unordered_map<string, int> &hash, vector<No> &heap, unordered_map<string, int> &words)
{

    Arvore arvore;
    ArvoreAVL avl;
    Huffman huffman;
    map<string, string> codigos;
    map<string, int> frequencias;
    int contador = 1;
    string text;

    string arq = "dataset/output.txt";
    ofstream F(arq, std::ios::app);

    auto it = hash.begin();
    for (int i = 0; i < constante && it != hash.end(); ++i, ++it)
    {
        No newNode(it->first, it->second, nullptr, nullptr);
        heap.push_back(newNode);
    }

    make_heap(heap.begin(), heap.end(), [](const No &a, const No &b)
              { return a.quantidade > b.quantidade; });

    while (it != hash.end())
    {
        if (it->second > heap.front().quantidade)
        {
            pop_heap(heap.begin(), heap.end(), [](const No &a, const No &b)
                     { return a.quantidade > b.quantidade; });
            heap.pop_back();
            No newNode(it->first, it->second, nullptr, nullptr);
            heap.push_back(newNode);
            push_heap(heap.begin(), heap.end(), [](const No &a, const No &b)
                      { return a.quantidade > b.quantidade; });
        }
        ++it;
    }

    sort(heap.begin(), heap.end(), [](const No &a, const No &b)
         { return a.quantidade > b.quantidade; });

    F << endl
      << endl
      << "Codigo de Huffman" << endl;
    huffman.HuffmanCodes(heap);
    F << endl
      << endl;
    F << "Arvore Binaria" << endl;
    arvore.inserir(heap);
    F << endl
      << endl
      << "Arvore AVL" << endl;
    avl.inserir(heap);

    heap.clear();
}

void readPalavras(unordered_map<string, int> &words)
{
    string filename("dataset/input.data");
    ifstream input_file(filename, ios::in);
    string line;

    while (!input_file.eof())
    {
        while (getline(input_file, line, '\n'))
        {
            if (line.size() >= 1)
            {
                for (auto &c : line)
                {
                    c = tolower(c);
                }
                words.insert({line, 1});
            }
        }
    }
}

void readStopWords(unordered_map<string, int> &stopwords)
{
    string filename("dataset/stopwords.txt");
    ifstream input_file(filename, ios::in);
    string line;

    while (!input_file.eof())
    {
        while (getline(input_file, line, '\n'))
        {
            if (line.size() >= 1)
            {
                for (auto &c : line)
                {
                    c = tolower(c);
                }
                stopwords.insert({line, 1});
            }
        }
    }
}

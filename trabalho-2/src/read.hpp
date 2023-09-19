#ifndef READ_HPP
#define READ_HPP

#include <bits/stdc++.h>
#include <algorithm>
#include <cctype>
#include <iomanip>
#include <vector>
#include "No.hpp"
#include "Arvore.hpp"
#include "ArvoreAVL.hpp"
#include "corretor.hpp"
#include "Huffman.hpp"

void fn_principal();
void leitor_principal(unordered_map<string, int> &hash, unordered_map<string, int> &words, unordered_map<string, int> &stopWords, unordered_map<char, bool> &pontos, string filename, int &k, string palavra_input, bool &existeNoTexto);
void readStopWords(unordered_map<string, int> &stopwords);
void readPalavras(unordered_map<string, int> &words);
void Heap(unordered_map<string, int> &hash, vector<No> &heap, unordered_map<string, int> &words);

#endif
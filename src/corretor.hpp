#ifndef CORRETOR_HPP
#define CORRETOR_HPP

#include "No.hpp"
#include "Arvore.hpp"
#include "ArvoreAVL.hpp"

void preencheMapPontos(unordered_map<char, bool> &pontos);
bool existe_numero(string palavra);

string converterAcentuadasParaMinusculas(string num);
string removePontuacao(string num, unordered_map<char, bool> pontos);

#endif
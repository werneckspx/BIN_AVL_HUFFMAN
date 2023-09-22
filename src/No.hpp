#ifndef NO_HPP
#define NO_HPP

#include <bits/stdc++.h>
#include <algorithm>
#include <cctype>
#include <iomanip>
#include <vector>
#include <chrono>
#define constante 10

using namespace std;

class No
{
public:
	string palavra;
	int quantidade;
	int balanceador;

	No *esquerdo;
	No *direito;

	No(string palavra, int quantidade, No *esquerdo, No *direito);
};

#endif
#include "corretor.hpp"

string removePontuacao(string palavra, unordered_map<char, bool> pontos)
{ // remove pontuacao e char estranho para n aparacer no output
    string palavraSemPonto;

    for (char c : palavra)
    { // percorre cada char da palavar pra ver se eh um ponto
        auto it = pontos.find(c);
        if (it == pontos.end())
        { // se o char n for ponto, ele coloca na string palavraSemponto
            palavraSemPonto += c;
        }
    }
    return palavraSemPonto;
}

bool existe_numero(string palavra)
{ // verifica se tem numero
    for (int i = 0; i < palavra.size(); i++)
    {
        if (isdigit(palavra[i]))
            return true;
    }

    return false;
}

string converterAcentuadasParaMinusculas(string palavra)
{
    string maiuscula = "ÁÀÃÉÈÍÌÓÒÚÙ";
    string minuscula = "áàãéèíìóòúù";

    for (size_t i = 0; i < maiuscula.size(); i++)
    {
        replace(palavra.begin(), palavra.end(), maiuscula[i], minuscula[i]);
    }
    return palavra;
}

void preencheMapPontos(unordered_map<char, bool> &pontos)
{
    pontos.insert({
        {'-', false},
        {'.', false},
        {',', false},
        {';', false},
        {'"', false},
        {'/', false},
        {'(', false},
        {')', false},
        {'[', false},
        {']', false},
        {'+', false},
        {'-', false},
        {'=', false},
        {'$', false},
        {'%', false},
        {'&', false},
        {'*', false},
        {':', false},
        {'^', false},
        {'|', false},
        {'~', false},
        {'_', false},
    });
}

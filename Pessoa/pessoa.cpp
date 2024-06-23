#include "pessoa.h"
#include <sstream>
#include "../Excecoes/excecaoCsvIncorreto.h"

using namespace std;

Pessoa::Pessoa(std::string nome, std::string sobrenome)
    : nome(nome), sobrenome(sobrenome) {}

std::string Pessoa::getNome() const {
    return nome;
}

void Pessoa::setNome(std::string nome) {
    Pessoa::nome = nome;
}

std::string Pessoa::getSobrenome() const {
    return sobrenome;
}

void Pessoa::setSobrenome(std::string sobrenome) {
    Pessoa::sobrenome = sobrenome;
}

Pessoa Pessoa::criarPessoaPorConsole() {
    cout << ("------------------------------------BEM-VINDO--------------------------------------------------")
         << endl;
    string nome;
    string sobrenome;

    //NOME
    do {
        cout << "Escreva seu nome: " << endl; 
        getline(cin, nome);
        if (nome.length() <= 3 || nome.length() >= 15 || nome.empty())
            cout << "Por favor, tente novamente!" << endl;
    } while (nome.length() <= 3 || nombe.length() >= 15 || nome.empty());
    cout << "TENTATIVA BEM SUCEDIDA." << endl;

    //SOBRENOME
    do {
        cout << "Escreva seu sobrenome: " << endl;
        getline(cin, sobrenome);
        if (sobrenome.length() <= 3 || sobrenome.length() >= 25 || sobrenome.empty())
            cout << "Por favor, tente novamente!" << endl;
    } while (sobrenome.length() <= 3 || sobrenome.length() >= 25 || sobrenome.empty());
    cout << "TENTATIVA BEM SUCEDIDA." << endl;


    cout << "----------------------------DADOS-------------------------" << endl;
    cout << "Nome: " << nome << endl;
    cout << "Sobrenome: " << sobrenome << endl;

    Pessoa pessoa(nome, sobrenome);
    return pessoa;
}

std::string Pessoa::toCSV() {
    std::stringstream sstream;

    sstream << nome << ","
            << sobrenome;

    return sstream.str();
}

Pessoa Pessoa::fromCSV(const std::string &csv) {
    std::string fragmentos[2];
    int n = 0;

    for (char i : csv) {
        if (i == ',') {
            n++;
        } else {
            fragmentos[n] += i;
        }
    }

    Pessoa p{fragmentos[0], fragmentos[1]};
    return p;

}

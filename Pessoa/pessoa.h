#ifndef SISTEMABIBLIOTECA_PESSOA_H
#define SISTEMABIBLIOTECA_PESSOA_H

#include <iostream>

class Pessoa {
protected:
    std::string nome;
    std::string sobrenome;

public:
    Pessoa(std::string nome, std::string sobrenome);

    std::string getNome() const;

    void setNome(std::string nome);

    std::string getSobrenome() const;

    void setSobrenome(std::string sobrenome);

    static Pessoa criarPessoaPorConsole();

    virtual std::string toCSV();

    static Pessoa fromCSV(const std::string &csv);

};

#endif //SISTEMABIBLIOTECA_PESSOA_H

#ifndef SISTEMABIBLIOTECA_CLIENTE_H
#define SISTEMABIBLIOTECA_CLIENTE_H
#include "pessoa.h"

class Cliente: public Pessoa {
public:
    int matricula;
    int telefone;

    int getMatricula() const;

    void setMatricula(int matricula);

    int getTelefone() const;

    void setTelefone(int telefone);

    Cliente(const std::string &nome, const std::string &sobrenome, int matricula, int telefone);
    std::string toCSV() override;
    static Cliente fromCSV(const std::string &csv);
    static Cliente criarClientePorConsole();
};


#endif //SISTEMABIBLIOTECA_CLIENTE_H

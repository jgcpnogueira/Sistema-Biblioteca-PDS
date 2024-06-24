//
#ifndef SISTEMABIBLIOTECA_CATEGORIA_H
#define SISTEMABIBLIOTECA_CATEGORIA_H

#include "iostream"

class Categoria {
private:
    std::string nome;
    int id;

public:
    Categoria(std::string _nome, int _id);

    std::string getNome() const;

    void setNome(std::string nome);

    int getId() const;

    void setId(int id);

    std::string toCSV();

    static Categoria fromCSV(std::string csv);

    static Categoria criarCategoriaPorConsole();
};

#endif //SISTEMABIBLIOTECA_CATEGORIA_H

#ifndef SISTEMABIBLIOTECA_AUTOR_H
#define SISTEMABIBLIOTECA_AUTOR_H
#include "pessoa.h"
#include <sstream>

class Autor: public Pessoa {
private:
    int id;

public:
    Autor(int id, std::string nome, std::string sobrenome);
    std::string toCSV() override;
    static Autor fromCSV(const std::string &csv);
    static Autor criarAutorPorConsole(int idAutor);

    int getId() const;
};


#endif //SISTEMABIBLIOTECA_AUTOR_H

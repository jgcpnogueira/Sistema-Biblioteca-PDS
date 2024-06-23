#ifndef SISTEMABIBLIOTECA_LIVRO_H
#define SISTEMABIBLIOTECA_LIVRO_H
#include <iostream>
#include "Pessoa/autor.h"

class Livro {
private:
    int codigo;
    std::string nome;
    int codigoAutor;
    std::string fechaPublicacao;
    int codigoCategoria;  // Biologia/Matematica/etc

public:
    Livro(int codigo, std::string nome, int autor, std::string fechaPublicacao, int codigoCategoria);

    int getCodigoAutor() const;

    void setCodigoAutor(int codigoAutor);

    int getCodigo() const;

    void setCodigo(int codigo);

    std::string getNome() const;

    void setNome(std::string nome);

    std::string getFechaPublicacao() const;

    void setFechaPublicacao(std::string fechaPublicacao);

    void setFechaPublicacao(const std::string &fechaPublicacao);

    int getCodigoCategoria() const;

    void setCodigoCategoria(int codigoCategoria);

    static Livro crearLivroPorConsole(int codLib);

    std::string toCSV();

    static Libro fromCSV(std::string csv);
};


#endif //SISTEMABIBLIOTECA_LIVRO_H

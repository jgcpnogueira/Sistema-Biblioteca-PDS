#ifndef SISTEMABIBLIOTECA_ARMAZEM_H
#define SISTEMABIBLIOTECA_ARMAZEM_H

#include "livro.h"

class Armazem {
private:
    Livro* livros;          // Array de livros disponíveis.
    int quantidadeDeLivros;   // Para gerenciar o array de livros.

public:
    Livro* getLivros() const;

    void setLivros(Livro* livros);

    int getQuantidadeDeLivros() const;

    void setQuantidadeDeLivros(int quantidadeDeLivros);

public:
    Almacen(Livro* livros, int quantidadeDeLivros);

};

#endif //SISTEMABIBLIOTECA_ARMAZEM_H

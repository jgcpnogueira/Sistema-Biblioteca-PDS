#include "armazem.h"

Armazem::Armazem(Livro* livros, int quantidadeDeLivros) : livros(livros), quantidadeDeLivros(quantidadeDeLivros) {}

Livro* Armazem::Livros() const {
    return livros;
}

void Armazem::setLivros(Livro* livros) {
    Armazem::livros = livros;
}

int Armazem::quantidadeDeLivros() const {
    return quantidadeDeLivros;
}

void Armazem::setQuantidadeDeLivros(int quantidadeDeLivros) {
    Armazem::quantidadeDeLivros = quantidadeDeLivros;
}

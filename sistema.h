#ifndef SISTEMA_H
#define SISTEMA_H

#include <vector>
#include <string>
#include "Categoria.h"
#include "Livro.h"
#include "Emprestimo.h"

class Sistema {
public:
    std::vector<Categoria> categorias;
    std::vector<Livro> livros;
    std::vector<Emprestimo> emprestimos;

    void adicionarCategoria(std::string nome);
    void adicionarLivro(std::string titulo, std::string autor, std::string nomeCategoria);
    void registrarEmprestimo(std::string tituloLivro, std::string usuario, std::string dataEmprestimo);
    void listarLivrosPorCategoria(std::string nomeCategoria);
};

#endif // SISTEMA_H

#include "Sistema.h"
#include <iostream>

void Sistema::adicionarCategoria(std::string nome) {
    categorias.push_back(Categoria(nome));
}

void Sistema::adicionarLivro(std::string titulo, std::string autor, std::string nomeCategoria) {
    for (Categoria& categoria : categorias) {
        if (categoria.nome == nomeCategoria) {
            livros.push_back(Livro(titulo, autor, categoria));
            return;
        }
    }
    std::cout << "Categoria não encontrada!" << std::endl;
}

void Sistema::registrarEmprestimo(std::string tituloLivro, std::string usuario, std::string dataEmprestimo) {
    for (Livro& livro : livros) {
        if (livro.titulo == tituloLivro && livro.disponivel) {
            emprestimos.push_back(Emprestimo(livro, usuario, dataEmprestimo));
            std::cout << "Empréstimo registrado com sucesso!" << std::endl;
            return;
        }
    }
    std::cout << "Livro não encontrado ou não disponível!" << std::endl;
}

void Sistema::listarLivrosPorCategoria(std::string nomeCategoria) {
    for (Livro& livro : livros) {
        if (livro.categoria.nome == nomeCategoria) {
            std::cout << "Título: " << livro.titulo << ", Autor: " << livro.autor << ", Disponível: " << (livro.disponivel ? "Sim" : "Não") << std::endl;
        }
    }
}

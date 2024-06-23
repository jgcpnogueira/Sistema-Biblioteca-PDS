#include <sstream>
#include "livro.h"

Livro::Livro(int codigo, std::string nome, int autor, std::string fechaPublicacao, int codigoCat) :
        codigo(codigo), nome(nome), codigoAutor(autor), fechaPublicacao(fechaPublicacao),
        codigoCategoria(codigoCat) {}

int Livro::getCodigo() const {
    return codigo;
}

void Livro::setCodigo(int codigo) {
    Livro::codigo = codigo;
}

std::string Livro::getNome() const {
    return nome;
}

void Livro::setNome(std::string nome) {
    Livro::nome = nome;
}

int Livro::getCodigoAutor() const {
    return codigoAutor;
}

void Livro::setCodigoAutor(int codigoAutor) {
    Livro::codigoAutor = codigoAutor;
}

std::string Livro::getFechaPublicacao() const {
    return fechaPublicacao;
}

void Livro::setFechaPublicacao(const std::string &fechaPublicacao) {
    Livro::fechaPublicacao = fechaPublicacao;
}

int Livro::getCodigoCategoria() const {
    return codigoCategoria;
}

void Livro::setCodigoCategoria(int codigoCategoria) {
    Livro::codigoCategoria = codigoCategoria;
}

Livro Livro::crearLivroPorConsole(int codLivro) {
    std::cout << "Criando um Livro." << std::endl;

    std::string nomeLivro;
    do {
        std::cout << "Digite o nome do livro:" << std::endl;
        std::getline(std::cin, nomeLivro);
        if (!nomeLivro.empty()) break;

        std::cout << "Por favor, digite um nome." << std::endl;
    } while (true);

    std::string fechaPublicacao;
    do {
        std::cout << "Digite a data de publicacao do livro:" << std::endl;
        std::getline(std::cin, fechaPublicacao);
        if (!fechaPublicacao.empty()) break;

        std::cout << "Por favor, digite uma data." << std::endl;
    } while (true);

    std::string codAutorRaw;
    int codAutor;
    do {
        std::cout << "Digite o codigo do autor:" << std::endl;
        std::getline(std::cin, codAutorRaw);
        try {
            codAutor = std::stoi(codAutorRaw);
            break;
        } catch (...) {
            std::cout << "Por favor, digite um numero." << std::endl;
        }

    } while (true);

    std::string codCatRaw;
    int codCat;
    do {
        std::cout << "Digite o codigo da categoria:" << std::endl;
        std::getline(std::cin, codCatRaw);
        try {
            codCat = std::stoi(codCatRaw);
            break;
        } catch (...) {
            std::cout << "Por favor, digite um numero." << std::endl;
        }

    } while (true);

    Livro l(codLivro, nomeLivro, codAutor, fechaPublicacao, codCat);
    return l;
}

std::string Livro::toCSV() {
    std::stringstream gstream;
    gstream << getCodigo() << ",";
    gstream << nome << ",";
    gstream << codigoAutor << ",";
    gstream << fechaPublicacao << ",";
    gstream << codigoCategoria;
    return gstream.str();
}

Livro Livro::fromCSV(std::string csv) {
    std::stringstream ss(csv);
    std::string dados[5];
    int n = 0;

    while (std::getline(ss, dados[n], ',')) {
        n++;
        if (n >= 5) break;
    }

    if (n != 5) {
              throw std::runtime_error("Erro ao tentar converter dados CSV para Livro. Formato inválido.");
    }

    try {
        int codigo = std::stoi(dados[0]);
        std::string nome = dados[1];
        int idAutor = std::stoi(dados[2]);
        std::string fechaPublicacao = dados[3];
        int tema = std::stoi(dados[4]);

        return Livro(codigo, nome, idAutor, fechaPublicacao, tema);
    } catch (const std::exception& e) {
        throw std::runtime_error("Erro ao tentar converter dados CSV para Livro. " + std::string(e.what()));
    }
}

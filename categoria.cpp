//
#include "categoria.h"
#include <cstdlib>
#include <sstream>
#include "Excepciones/excepcionCsvIncorrecto.h"

Categoria::Categoria(std::string _nome, int _id) {
    nome = _nome;
    id = _id;
}

std::string Categoria::getNome() const {
    return nome;
}

void Categoria::setNome(std::string nome) {
    Categoria::nome = nome;
}

int Categoria::getId() const {
    return id;
}
/*
 * Método para a inserção de valores de Categoria nos arquivos excel
 */
std::string Categoria::toCSV() {
    std::string csv;
    std::stringstream gstream;

    gstream << getNome() << ",";
    gstream << getId();

    csv = gstream.str();
    return csv;
}
/**
 * Método que verificará os valores inseridos em toCSV
 * @param csv valor que contém os valores de Categoria
 * @return retornará o arquivo atualizado com a categoria inserida, caso contrário mostrará uma mensagem indicando o erro nos dados inseridos
 */
Categoria Categoria::fromCSV(std::string csv) {
    std::string dados[5];
    int id, n = 0;
    std::string nome;

    for (char i : csv) {
        if (i == ',') {
            n++;
        } else {
            dados[n] += i;
        }
    }

    try {
        nome = dados[0];
        id = std::stoi(dados[1]);

        Categoria novaCategoria(nome, id);
        return novaCategoria;
    } catch (std::invalid_argument&) {
        std::stringstream s;
        s << "Erro ao tentar converter dados CSV para Categoria. Argumento inválido." << std::endl
          << "O string causador é:" << std::endl
          << csv;
        throw ExcepcionCSVIncorrecto(s.str());
    } catch (std::out_of_range&) {
        std::stringstream s;
        s << "Erro ao tentar converter dados CSV para Categoria. Dados fora dos limites permitidos." << std::endl
          << "O string causador é:" << std::endl
          << csv;
        throw ExcepcionCSVIncorrecto(s.str());
    } catch (...) {
        std::stringstream s;
        s << "Erro ao tentar converter dados CSV para Categoria." << std::endl
          << "O string causador é:" << std::endl
          << csv;
        throw ExcepcionCSVIncorrecto(s.str());
    }
}

Categoria Categoria::criarCategoriaPorConsole() {
    std::cout << "Seção Categoria" << std::endl;
    std::string categoria;
    do {
        std::cout << "Insira a categoria do livro:" << std::endl;
        std::getline(std::cin, categoria);

        if (!categoria.empty()) break;

        std::cout << "Insira a categoria";
    } while (true);

    Categoria categoria1(categoria, 0);
    return categoria1;
}

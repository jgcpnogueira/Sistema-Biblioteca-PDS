#include "autor.h"
#include "Excecoes/excecaoCsvIncorreto.h"

Autor::Autor(int id, std::string nome, std::string sobrenome)
        : Pessoa(nome, sobrenome), id(id) {}

std::string Autor::toCSV() {
    std::stringstream sstream;

    sstream << id << ","
            << nome << ","
            << sobrenome;

    return sstream.str();
}

Autor Autor::fromCSV(const std::string &csv) {
    std::string fragmentos[5];
    int n = 0;

    for (char i : csv) {
        if (i == ',') {
            n++;
        } else {
            fragmentos[n] += i;
        }
    }

    try {
        int id = std::stoi(fragmentos[0]);
        Autor a{id, fragmentos[1], fragmentos[2]};
        return a;
    } catch (std::invalid_argument) {
        std::stringstream s;
        s << "Erro ao tentar converter dados CSV a Autor. Argumento invalido." << std::endl
          << "A string incorreta é:" << std::endl
          << csv;
        throw ExcecaoCSVIncorreto(s.str());
    } catch (std::out_of_range) {
        std::stringstream s;
        s << "Erro ao tentar converter dados CSV a Autor. Dados fora dos intervalos permitidos." << std::endl
          << "A string incorreta é:" << std::endl
          << csv;
        throw ExcecaoCSVIncorreto(s.str());
    } catch (...) {
        std::stringstream s;
        s << "Erro ao tentar converter dados CSV a Autor." << std::endl
          << "A string incorreta é:" << std::endl
          << csv;
        throw ExcecaoCSVIncorreto(s.str());
    }

}

int Autor::getId() const {
    return id;
}

Autor Autor::criarAutorPorConsole(int idAutor) {
    std::cout << "Criando un Autor." << std::endl;

    std::string nomeAutor;
    do {
        std::cout << "Escreva o nome do autor:" << std::endl;
        std::getline(std::cin, nomeAutor);

        if (!nomeAutor.empty()) break;

        std::cout << "Por favor, escreva um nome.";
    } while (true);

    std::string sobrenomeAutor;
    do {
        std::cout << "Escreva o sobrenome do autor:" << std::endl;
        std::getline(std::cin, sobrenomeAutor);

        if (!sobrenomeAutor.empty()) break;

        std::cout << "Por favor, escreva um sobrenome.";
    } while (true);

    Autor a(idAutor, nomeAutor, sobrenomeAutor);
    return a;
}

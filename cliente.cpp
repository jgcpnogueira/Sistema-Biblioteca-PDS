#include "cliente.h"
#include <sstream>
#include "../Excecoes/excecaoCsvIncorrecto.h"

Cliente::Cliente(const std::string &nome, const std::string &sobrenome, int matricula, int telefone,
                 const std::string &direcao) : Pessoa(nome, sobrenome),
                 direcao(direcao), matricula(matricula), telefone(telefone) {}

std::string Cliente::toCSV() {
    std::stringstream sstream;

    sstream << nome << ","
            << sobrenome << ","
            << matricula << ","
            << telefone;

    return sstream.str();
}

Cliente Cliente::fromCSV(const std::string &csv) {
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
        int matricula = std::stoi(fragmentos[1]);
        int telefone = std::stoi(fragmentos[2]);
        Cliente c{fragmentos[0], fragmentos[1], matricula, telefono, fragmentos[4]};
        return c;
    } catch (std::invalid_argument) {
        std::stringstream s;
        s << "Erro ao tentar converter dados CSV a Cliente. Argumento invalido." << std::endl
          << "A string errada é:" << std::endl
          << csv;
        throw ExcecaoCSVIncorreto(s.str());
    } catch (std::out_of_range) {
        std::stringstream s;
        s << "Erro ao tentar converter dados CSV a Cliente. Dados fora dos intervalos permitidos." << std::endl
          << "A string errada é:" << std::endl
          << csv;
        throw ExcecaoCSVIncorreto(s.str());
    } catch (...) {
        std::stringstream s;
        s << "Erro ao tentar converter dados CSV a Cliente." << std::endl
          << "A string errada é:" << std::endl
          << csv;
        throw ExcecaoCSVIncorreto(s.str());
    }
}

Cliente Cliente::criarClientePorConsole() {
    std::cout << "Criando un cliente." << std::endl;

    std::string matriculaRaw;
    int matricula;
    do {
        std::cout << "Escreva o nome do cliente:" << std::endl;
        std::getline(std::cin, matriculaRaw);
        try {

            matricula = std::stoi(matriculaRaw);
            break;

        } catch (...) {
            std::cout << "Por favor, escreva um numero.";
        }

    } while (true);

    std::string nomeCliente;
    do {
        std::cout << "Escreva o nome do cliente:" << std::endl;
        std::getline(std::cin, nomeCliente);

        if (!nomeCliente.empty()) break;

        std::cout << "Por favor, escreva um nome.";
    } while (true);

    std::string sobrenomeCliente;
    do {
        std::cout << "Escreva o sobrenome do cliente:" << std::endl;
        std::getline(std::cin, sobrenomeCliente);

        if (!sobrenomeCliente.empty()) break;

        std::cout << "Por favor, escreva um sobrenome.";
    } while (true);

    std::string telefoneRaw;
    int telefone;
    do {
        std::cout << "Escreva o telefone do cliente:" << std::endl;
        std::getline(std::cin, telefoneRaw);
        try {

            telefone = std::stoi(telefoneRaw);
            break;

        } catch (...) {
            std::cout << "Por favor, escreva um numero de telefone.";
        }

    } while (true);

    
    Cliente c(nomeCliente, sobrenomeCliente, matricula, telefone);
    return c;
}

int Cliente::getmatricula() const {
    return matricula;
}

void Cliente::setMatricula(int matricula) {
    Cliente::matricula = matricula;
}

int Cliente::getTelefone() const {
    return telefone;
}

void Cliente::setTelefone(int telefone) {
    Cliente::telefone = telefone;
}

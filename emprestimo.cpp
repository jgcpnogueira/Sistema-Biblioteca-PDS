#include <sstream>
#include "emprestimo.h"
#include <cstdlib>
#include "Excecoes/excecaoCsvIncorreto.h"

Emprestimo::Emprestimo(int codigoEmprestimo, int codigoLivro, int matriculaCliente, std::string dataEmprestimo,
                       std::string dataDevolucao, bool devolvido) :
        codigoEmprestimo(codigoEmprestimo), codigoLivro(codigoLivro), matriculaCliente(matriculaCliente), dataEmprestimo(dataEmprestimo),
        dataDevolucao(dataDevolucao), devolvido(devolvido) {
}

int Emprestimo::getCodigoLivro() const {
    return codigoLivro;
}

void Emprestimo::setCodigoLivro(int codigoLivro) {
    Emprestimo::codigoLivro = codigoLivro;
}

int Emprestimo::getMatriculaCliente() const {
    return matriculaCliente;
}

void Emprestimo::setMatriculaCliente(int matriculaCliente) {
    Emprestimo::matriculaCliente = matriculaCliente;
}

const std::string &Emprestimo::getDataEmprestimo() const {
    return dataEmprestimo;
}

void Emprestimo::setDataEmprestimo(const std::string &dataEmprestimo) {
    Emprestimo::dataEmprestimo = dataEmprestimo;
}

const std::string &Emprestimo::getDataDevolucao() const {
    return dataDevolucao;
}

void Emprestimo::setDataDevolucao(const std::string &dataDevolucao) {
    Emprestimo::dataDevolucao = dataDevolucao;
}

bool Emprestimo::foiDevolvido() const {
    return devolvido;
}

std::string Emprestimo::paraCSV() {
    std::string csv;
    std::stringstream gstream;

    gstream << getCodigoEmprestimo() << ","
            << getCodigoLivro() << ","
            << getMatriculaCliente() << ","
            << dataEmprestimo << ","
            << dataDevolucao << ","
            << foiDevolvido();

    csv = gstream.str();
    return csv;
}

Emprestimo Emprestimo::deCSV(std::string csv) {
    std::string dados[6];
    int codigoEmprestimo, codigoLivro, matricula, n = 0;
    bool devolvido = false;
    std::string dataEmprestimo, dataDevolucao;

    for (char i : csv) {
        if (i == ',') {
            n++;
        } else {
            dados[n] += i;
        }
    }

    try {
        codigoEmprestimo = std::stoi(dados[0]);
        codigoLivro = std::stoi(dados[1]);
        matricula = std::stoi(dados[2]);
        dataEmprestimo = dados[3];
        dataDevolucao = dados[4];
        if (std::stoi(dados[5]) == 1) devolvido = true;

        Emprestimo novoEmprestimo(codigoEmprestimo, codigoLivro, matricula, dataEmprestimo, dataDevolucao, devolvido);
        return novoEmprestimo;
    } catch (std::invalid_argument) {
        std::stringstream s;
        s << "Erro ao tentar converter dados CSV para Empréstimo. Argumento inválido." << std::endl
          << "A string causadora é:" << std::endl
          << csv;
        throw ExcecaoCsvIncorreto(s.str());
    } catch (std::out_of_range) {
        std::stringstream s;
        s << "Erro ao tentar converter dados CSV para Empréstimo. Dados fora dos limites permitidos." << std::endl
          << "A string causadora é:" << std::endl
          << csv;
        throw ExcecaoCsvIncorreto(s.str());
    } catch (...) {
        std::stringstream s;
        s << "Erro ao tentar converter dados CSV para Empréstimo." << std::endl
          << "A string causadora é:" << std::endl
          << csv;
        throw ExcecaoCsvIncorreto(s.str());
    }
}

int Emprestimo::getCodigoEmprestimo() const {
    return codigoEmprestimo;
}

void Emprestimo::setCodigoEmprestimo(int codigoEmprestimo) {
    Emprestimo::codigoEmprestimo = codigoEmprestimo;
}

void Emprestimo::setDevolvido(bool devolvido) {
    Emprestimo::devolvido = devolvido;
}

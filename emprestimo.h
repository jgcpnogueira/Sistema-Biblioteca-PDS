#ifndef SISTEMABIBLIOTECA_EMPRESTIMO_H
#define SISTEMABIBLIOTECA_EMPRESTIMO_H
#include <iostream>

class Emprestimo {
private:
    int codigoEmprestimo;
    int codigoLivro;
    int matriculaCliente;
    std::string dataEmprestimo;
    std::string dataDevolucao;
    bool devolvido;
    
public:
    int getCodigoEmprestimo() const;
    void setCodigoEmprestimo(int codigoEmprestimo);
    void setDevolvido(bool devolvido);

public:
    Emprestimo(int codigoEmprestimo, int codigoLivro, int matriculaCliente, std::string dataEmprestimo,
               std::string dataDevolucao, bool devolvido);

    int getCodigoLivro() const;
    void setCodigoLivro(int codigoLivro);

    int getMatriculaCliente() const;
    void setMatriculaCliente(int matriculaCliente);

    const std::string &getDataEmprestimo() const;
    void setDataEmprestimo(const std::string &dataEmprestimo);

    const std::string &getDataDevolucao() const;
    void setDataDevolucao(const std::string &dataDevolucao);

    bool foiDevolvido() const;

    std::string toCSV();

    static Emprestimo fromCSV(std::string csv);
};

#endif // SISTEMABIBLIOTECA_EMPRESTIMO_H

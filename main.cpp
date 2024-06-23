#include <iostream>
#include <string>
#include "sistema.h"

int main(int argc, char** argv) {

    bool esAdmin = false;
    unsigned int posPassword = -1;
    for (int i = 0; i < argc; i++) {
        std::string s = argv[i];
        if (s == "--password") {
            posPassword = i + 1;
        } else if (i == posPassword && s == "8k9e7b20bp2ld8b") {
            std::cout << "Iniciando sessão como administrador." << std::endl;
            esAdmin = true;
        }
    }

    Sistema s(esAdmin);
    try {
        s.run();
    } catch (std::exception &e) {
        std::cerr << "Foi encontrado um erro não tratado. As alterações serão salvas e o programa será encerrado." << std::endl;
        std::cerr << e.what();
        std::cout << "Pressione Enter para continuar.";
        std::cin.ignore();
        std::cout << std::endl;
    }

    return 0;
}

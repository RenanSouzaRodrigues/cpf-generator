#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

void generateCpf() {
    int y, i, dv1, dv2, total, cpfnum[10];

    // gera os numeros do cpf
    std::string first_part_cpf = "";

    srand(time(NULL));
    for (i = 0; i <= 8; i++) {
        cpfnum[i] = rand() % 9;
        // imprime os numeros
        std::cout <<  cpfnum[i] ;
        first_part_cpf += std::to_string(cpfnum[i]);
    }

    // primeiro digito verificador
    total = 0;
    y = 10;

    for (i = 0; i <= 8; i++) {
        total = total + (cpfnum[i] * y);
        y--;
    }

    if ((total % 11) < 2) {
        dv1 = 0;
    } else {
        dv1 = 11 - (total % 11);
    }

    // Segundo digito verificador
    y = 11;
    total = 0;

    for (i = 0; i <=8; i++) {
        total = total + (cpfnum[i] * y);
        y--;
    }

    total = total + (dv1 * y);

    if ((total % 11) < 2) {
        dv2 = 0;
    } else {
        dv2 = 11 - (total % 11);
    }

    std::cout << dv1 << dv2 << "\n" ;

    std::string cpf = first_part_cpf + std::to_string(dv1) + std::to_string(dv2);

    const char* output = cpf.c_str();
    const size_t len = strlen(output) + 1;
    HGLOBAL hMem =  GlobalAlloc(GMEM_MOVEABLE, len);
    memcpy(GlobalLock(hMem), output, len);
    GlobalUnlock(hMem);
    OpenClipboard(0);
    EmptyClipboard();
    SetClipboardData(CF_TEXT, hMem);
    CloseClipboard();
}

int main (int argc, char *argv[]) {
    generateCpf();

    return 0;
}
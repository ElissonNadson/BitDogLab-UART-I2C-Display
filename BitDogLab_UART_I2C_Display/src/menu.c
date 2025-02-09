#include "menu.h"
#include <stdio.h>
#include <locale.h>  // Necessário para configurar o locale e suportar Unicode

void main_menu() {
    // Configura o locale para que os caracteres Unicode sejam exibidos
    setlocale(LC_ALL, "");

    printf("════════════════════════════════════════════\n");
    printf("              MENU PRINCIPAL                \n");
    printf("════════════════════════════════════════════\n");
    printf("🟢  [PRESS BOTAO A]     Liga/desliga o LED Verde\n");
    printf("🔵  [PRESS BOTAO B]     Liga/desliga o LED Azul\n");
    printf("────────────────────────────────────────────\n");
    printf("🔤  [A-Z]               Exibe o caractere no display\n");
    printf("────────────────────────────────────────────\n");
    printf("0️⃣ [0] Exibe o número 0 na matriz\n");
    printf("1️⃣ [1] Exibe o número 1 na matriz\n");
    printf("2️⃣ [2] Exibe o número 2 na matriz\n");
    printf("3️⃣ [3] Exibe o número 3 na matriz\n");
    printf("4️⃣ [4] Exibe o número 4 na matriz\n");
    printf("5️⃣ [5] Exibe o número 5 na matriz\n");
    printf("6️⃣ [6] Exibe o número 6 na matriz\n");
    printf("7️⃣ [7] Exibe o número 7 na matriz\n");
    printf("8️⃣ [8] Exibe o número 8 na matriz\n");
    printf("9️⃣ [9] Exibe o número 9 na matriz\n");
    printf("────────────────────────────────────────────\n");
    printf("❌ [/] Sair do programa\n");
    printf("════════════════════════════════════════════\n");
}

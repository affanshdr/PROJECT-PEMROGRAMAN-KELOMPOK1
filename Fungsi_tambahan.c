#include "Header.h"

void Header(){
    printf("\n");
    printf("+--------------------------------------------------------+\n");
    printf("| \t\t Selamat Datang Di Program \t\t |\n");
    printf("| \t\t\t Perpustakaan \t\t\t |\n");
    printf("+--------------------------------------------------------+\n");
}

void Clear_System(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void Header_Admin(){
    printf("+----------------------------------------+\n");
    printf("| \t\t Login Admin \t\t |\n");
    printf("+----------------------------------------+\n");
}

void Header_User(){
    printf("+----------------------------------------+\n");
    printf("| \t\t Login User \t\t |\n");
    printf("+----------------------------------------+\n");
}
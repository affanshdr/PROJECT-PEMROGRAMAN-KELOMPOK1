#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
    unsigned int Id_buku;
    char Judul[100], Penulis[100], Penerbit[100];
    unsigned int Jumlah_halaman, Tahun_terbit, Jumlah_tersedia;
} Perpus;

void header();
void Clear_System();
void List_Buku();
void Create_Buku();
void Delete_Buku();
void Update_Buku();

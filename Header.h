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

typedef struct 
{
    char username[100];
    char password[100];
} User;


void Header();
void Clear_System();
void Header_Admin();
void Header_User();
void SignUp();
void Login(int);
void List_Buku();
void Create_Buku();
void Delete_Buku();
void Update_Buku();

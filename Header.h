#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define Max_char 50

typedef struct
{
    unsigned int Id_buku;
    char Judul[Max_char], Penulis[Max_char], Penerbit[Max_char];
    unsigned int Jumlah_halaman, Tahun_terbit, Jumlah_tersedia;
} Perpus;

typedef struct 
{
    char username[Max_char];
    char password[Max_char];
} User;


void Header();
void Clear_System();
void Header_Admin();
void Header_User();
void SignUp();
void Login(int);
void List_Buku();
void Display_List_Buku(int, int, int, Perpus[]);
void Create_Buku();
void Delete_Buku();
void Update_Buku();

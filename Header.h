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

typedef struct 
{
    char Judul[Max_char];
    int Jumlah;
} Borrow;

void Clear_System();
void Header();
void Header2();
void Header3();
void Header_Admin();
void Sign_Up();
void Log_In();
void Header_User();
void SignUpAdmin();
void LoginAdmin(int *, char *);
void SignUp();
void Login();
void List_Buku();
void Display_List_Buku(int, int, int, Perpus[]);
void Create_Buku();
void Update_Buku();
void hapusBuku(Perpus[], int *, int);
void Tulis_Buku(Perpus[], int);
void Pinjam_Buku(Perpus[], int, Borrow[], int *);
void Dipinjam(Borrow[], int , char[]);
void Read_Peminjaman(const char *);
void Kembalikan_Buku(Perpus[], int, Borrow[], int *, char[]);
int Baca_Buku(Perpus[]);
int Baca_Buku_H(Perpus[]);
int Baca_Dipinjam_H(Borrow[], char[]);
void Tulis_Dipinjam_H(Borrow[], int, char[]);
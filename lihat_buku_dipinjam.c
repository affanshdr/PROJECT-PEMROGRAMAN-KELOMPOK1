#include "Header.h"

void Read_Peminjaman(const char *namaFile) {
    // Buka file teks
    FILE *file = fopen(namaFile, "r");
    if (file == NULL) {
        printf("Gagal membuka file.\n");
        return;
    }

    printf("+------------------------------------------+\n");
    printf("|          Judul Buku        |   Jumlah   |\n");
    printf("+------------------------------------------+\n");

    // Variabel untuk menyimpan judul buku dan jumlah buku yang dipinjam
    Borrow dipinjam;

    // Baca setiap baris dari file
    while (fscanf(file, "\"%[^\"]\", %d\n", dipinjam.Judul, &dipinjam.Jumlah) != EOF) {
        printf("| %-27s | %-10d |\n", dipinjam.Judul, dipinjam.Jumlah);
    }

    printf("+------------------------------------------+\n");

    // Tutup file
    fclose(file);
}
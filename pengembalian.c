#include "Header.h"

// Fungsi untuk membaca data buku dari file teks
int Baca_Buku_H(Perpus daftar_buku[]) {
    FILE *file = fopen("Data_Buku.txt", "r");
    if (file == NULL) {
        printf("Gagal membuka file.\n");
        return 0;
    }

    int jumlah_buku = 0;
    while (fscanf(file, "%d, \"%[^\"]\", \"%[^\"]\", \"%[^\"]\", %d, %d, %d\n",
                  &daftar_buku[jumlah_buku].Id_buku,
                  daftar_buku[jumlah_buku].Judul,
                  daftar_buku[jumlah_buku].Penulis,
                  daftar_buku[jumlah_buku].Penerbit,
                  &daftar_buku[jumlah_buku].Jumlah_halaman,
                  &daftar_buku[jumlah_buku].Tahun_terbit,
                  &daftar_buku[jumlah_buku].Jumlah_tersedia) != EOF) {
        jumlah_buku++;
    }

    fclose(file);
    return jumlah_buku;
}

// Fungsi untuk membaca data buku yang dipinjam dari file teks
int Baca_Dipinjam_H(Borrow dipinjam[], char username[]) {
    FILE *file = fopen(username, "r");
    if (file == NULL) {
        printf("Gagal membuka file.\n");
        return 0;
    }

    int jumlah_dipinjam = 0;
    while (fscanf(file, "\"%[^\"]\", %d\n", dipinjam[jumlah_dipinjam].Judul, &dipinjam[jumlah_dipinjam].Jumlah) != EOF) {
        jumlah_dipinjam++;
    }

    fclose(file);
    return jumlah_dipinjam;
}

// Fungsi untuk menulis data buku yang dipinjam ke file teks baru
void Tulis_Dipinjam_H(Borrow dipinjam[], int jumlah_dipinjam, char username[]) {
    FILE *file = fopen(username, "w");
    if (file == NULL) {
        printf("Gagal membuka file.\n");
        return;
    }

    for (int i = 0; i < jumlah_dipinjam; i++) {
        fprintf(file, "\"%s\", %d\n", dipinjam[i].Judul, dipinjam[i].Jumlah);
    }

    fclose(file);
}

// Fungsi untuk mengembalikan buku
void Kembalikan_Buku(Perpus daftar_buku[], int jumlah_buku, Borrow dipinjam[], int *jumlah_dipinjam , char username[]) {
    char judul[100];
    int jumlah_kembali;
    printf("Masukkan judul buku yang ingin dikembalikan: ");
    scanf(" %[^\n]", judul);

    for (int i = 0; i < *jumlah_dipinjam; i++) {
        if (strcmp(judul, dipinjam[i].Judul) == 0) {
            for (int j = 0; j < jumlah_buku; j++) {
                if (strcmp(judul, daftar_buku[j].Judul) == 0) {
                    printf("Masukkan jumlah buku yang ingin dikembalikan: ");
                    scanf("%d", &jumlah_kembali);

                    if (jumlah_kembali <= dipinjam[i].Jumlah) {
                        // Menambah jumlah buku yang tersedia
                        daftar_buku[j].Jumlah_tersedia += jumlah_kembali;

                        // Mengurangi jumlah buku yang dipinjam
                        dipinjam[i].Jumlah -= jumlah_kembali;

                        // Jika tidak ada lagi buku yang dipinjam, hapus dari daftar
                        if (dipinjam[i].Jumlah == 0) {
                            for (int k = i; k < *jumlah_dipinjam - 1; k++) {
                                strcpy(dipinjam[k].Judul, dipinjam[k + 1].Judul);
                                dipinjam[k].Jumlah = dipinjam[k + 1].Jumlah;
                            }
                            (*jumlah_dipinjam)--;
                        }

                        printf("Buku berhasil dikembalikan.\n");
                        Tulis_Buku(daftar_buku, jumlah_buku);
                        Tulis_Dipinjam_H(dipinjam, *jumlah_dipinjam , username);
                        return;
                    } else {
                        printf("Jumlah buku yang ingin dikembalikan melebihi jumlah yang dipinjam.\n");
                        return;
                    }
                }
            }
        }
    }

    printf("Buku tidak ditemukan dalam daftar yang dipinjam.\n");
}
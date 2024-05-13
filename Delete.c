#include "Header.h"

void hapusBuku(Perpus Data_Buku[], int *jumlah_buku, int id) {
    for (int i = 0; i < *jumlah_buku; i++) {
        if (Data_Buku[i].Id_buku == id) {
            for (int j = i; j < *jumlah_buku - 1; j++) {
                Data_Buku[j] = Data_Buku[j + 1];
            }
            (*jumlah_buku)--;
            printf("Buku berhasil dihapus.\n");
            return;
        }
    }
    printf("Buku dengan ID tersebut tidak ditemukan.\n");
}

void Tulis_Buku(Perpus Data_Buku[], int jumlah_buku) {
    FILE *file = fopen("Data_Buku.txt", "w");
    if (file == NULL) {
        printf("Gagal membuka file.\n");
        return;
    }

    for (int i = 0; i < jumlah_buku; i++) {
        fprintf(file, "%d, \"%s\", \"%s\", \"%s\", %d, %d, %d\n",
                Data_Buku[i].Id_buku,
                Data_Buku[i].Judul,
                Data_Buku[i].Penulis,
                Data_Buku[i].Penerbit,
                Data_Buku[i].Jumlah_halaman,
                Data_Buku[i].Tahun_terbit,
                Data_Buku[i].Jumlah_tersedia);
    }

    fclose(file);
}

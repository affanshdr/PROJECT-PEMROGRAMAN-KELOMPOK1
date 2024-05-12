void hapusBuku(struct Buku Data_Buku[], int *jumlah_buku, int id) {
    for (int i = 0; i < *jumlah_buku; i++) {
        if (Data_Buku[i].id == id) {
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

void Tulis_Buku_Faris(struct Buku Data_Buku[], int jumlah_buku) {
    FILE *file = fopen("Data_Buku.txt", "w");
    if (file == NULL) {
        printf("Gagal membuka file.\n");
        return;
    }

    for (int i = 0; i < jumlah_buku; i++) {
        fprintf(file, "%d, \"%s\", \"%s\", \"%s\", %d, %d, %d\n",
                Data_Buku[i].id,
                Data_Buku[i].judul,
                Data_Buku[i].penulis,
                Data_Buku[i].penerbit,
                Data_Buku[i].halaman,
                Data_Buku[i].tahun,
                Data_Buku[i].jumlah);
    }

    fclose(file);
}

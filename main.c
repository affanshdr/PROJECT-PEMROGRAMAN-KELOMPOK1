#include "Header.h"

int main(){
    int Pilihan_Mode;
    int Pilihan_Log;
    int Pilihan_Opsi;
    int Berhasil = 0;
    int Berhasil2 = 0;
    int Berhasil3 = 0;
    char username[100]; // Variabel untuk menyimpan username yang berhasil login
    Perpus Data_Buku[Max_char];
    Borrow dipinjam[Max_char];
    int jumlah_buku = Baca_Buku(Data_Buku); 
    int jumlah_dipinjam = 0;
    
    Clear_System();
    Header();
    
    do {
        while (!Berhasil) {
            Clear_System();
            Header();
            printf("\n   Anda Login Sebagai ?\n");
            printf("\n   1. Admin \n   2. User\n   3. Keluar\n");
            printf("\n   Pilihan Anda ( 1 - 3 ) : ");
            scanf("%d", &Pilihan_Mode);
            while (getchar() != '\n');

            if (Pilihan_Mode < 1 || Pilihan_Mode > 3) {
                printf("\n   Pilihan tidak valid. Silakan masukkan 1, 2, atau 3.\n");
            } else {
                Berhasil = 1; 
            }
        }

        if (Pilihan_Mode == 1) {
            Berhasil = 0;
            do {
                Clear_System();
                Header_Admin();
                printf("\n  1. Sign-up\n  2. Login\n  3. Kembali\n");
                printf("\n  Pilihan Anda: ");
                scanf("%d", &Pilihan_Log);
                while (getchar() != '\n');
            
                if (Pilihan_Log == 1) {
                    Clear_System();
                    Sign_Up();
                    SignUpAdmin();
                    Pause();
                }
                if (Pilihan_Log == 2) {
                    Clear_System();
                    Log_In();
                    LoginAdmin(&Berhasil2, username); // Menyimpan username yang berhasil login
                    Pause();
                    if (Berhasil2 == 1) {
                        do{
                        //system("pause");
                        Clear_System();
                        Header2();
                        List_Buku();
                        printf("\n  Selamat datang, %s!\n", username);
                        Berhasil2 = 0; 
                        printf("\n\t ( Pilihan )\n");
                        printf("\n  1. Create \n  2. Delete\n  3. Update\n  4. Keluar\n");
                        printf("\n    Pilihan Anda: ");
                        scanf("%d", &Pilihan_Opsi);
                        while (getchar() != '\n');

                            switch(Pilihan_Opsi){
                                case 1:
                                Clear_System();
                                Header2();
                                List_Buku();
                                Create_Buku();
                                system("pause");
                                break;
                                case 2:
                                Clear_System();
                                Header2();
                                List_Buku();
                                printf("Masukkan ID buku yang ingin dihapus: ");
                                int id;
                                scanf("%d", &id);
                                hapusBuku(Data_Buku, &jumlah_buku, id);
                                Tulis_Buku(Data_Buku, jumlah_buku);
                                system("pause");
                                break;
                                case 3:
                                Clear_System();
                                Header2();
                                List_Buku();
                                Update_Buku();
                                system("pause");
                                    break;
                            }

                        } while (Pilihan_Opsi != 4);
                        
                        
                       
                    }
                }
            
            } while (Pilihan_Log != 3); 
        }

        if (Pilihan_Mode == 2) {
            Berhasil = 0;
            do {
                Clear_System();
                Header_User();
                printf("\n  1. Sign-up\n  2. Login\n  3. Kembali\n");
                printf("\n  Pilihan Anda: ");
                scanf("%d", &Pilihan_Log);
                while (getchar() != '\n');
            
                if (Pilihan_Log == 1) {
                    Clear_System();
                    Sign_Up();
                    SignUp();
                    Pause();
                }
                if (Pilihan_Log == 2) {
                    Clear_System();
                    Log_In();
                    Login(&Berhasil2, username); // Menyimpan username yang berhasil login
                    Pause();
                    if (Berhasil2 == 1) {
                        Berhasil2= 0; // Menampilkan pesan selamat datang dengan username
                        do{
                        printf("\n  Selamat datang, %s!\n", username);
                        printf("\n\t ( Pilihan )\n");
                        Berhasil2 = 0; 
                        printf("\n  1. List Buku yang tersedia \n  2. Pinjam Buku\n  3. List Buku yg dipinjam\n  4. Kembalikan Buku\n  5. Keluar\n");
                        printf("\n    Pilihan Anda: ");
                        scanf("%d", &Pilihan_Opsi);
                        while (getchar() != '\n');

                            switch(Pilihan_Opsi){
                                case 1:
                                Clear_System();
                                Header2();
                                List_Buku();
                                system("pause");
                                    break;
                                case 2:
                                Clear_System();
                                Header2();
                                List_Buku();
                                printf("\n  Pinjam Buku \n ");
                                if (jumlah_buku == 0) {
                                    printf("Tidak ada data buku.\n");
                                    return 1;
                                }
                                Pinjam_Buku(Data_Buku, jumlah_buku, dipinjam, &jumlah_dipinjam);
                                Tulis_Buku(Data_Buku, jumlah_buku);
                                Dipinjam(dipinjam, jumlah_dipinjam , username);
                                system("pause");
                                    break;
                                case 3:
                                Clear_System();
                                Header3();
                                Read_Peminjaman(username);
                                system("pause");
                                break;

                                case 4:
                                Clear_System();
                                Header3();
                                Read_Peminjaman(username);
                                int jumlah_buku = Baca_Buku_H(Data_Buku);
                                int jumlah_dipinjam = Baca_Dipinjam_H(dipinjam, username);
                                Kembalikan_Buku(Data_Buku, jumlah_buku, dipinjam, &jumlah_dipinjam , username);
                                system("pause");
                            }

                        } while (Pilihan_Opsi != 5);
                    }
                }
            } while (Pilihan_Log != 3); 
        }
    if(Pilihan_Mode){
        printf("\n  Terima Kasih Ngabs !!\n");
    }
    } while (Pilihan_Mode != 3);

    return EXIT_SUCCESS;
}

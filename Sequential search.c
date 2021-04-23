#include <stdio.h>
int main()
{
    // decklarasi
    int cari, alamat ;
    int flag = 0;
    int i= 0;
    int data[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26}; // kumpulan data

    // end decklarasi

    printf("masukan angka yang ingin dicari : ");
    scanf("%i", &cari);

    for(i; i <= 25; i++)
    {
        if (data[i] == cari) // membandingkan data[i] dengan data yang dicari
        {
            flag = 1; // flag menjadi satu jika data yang di cari ada yang sama
            alamat = i; // menyimpan alamat
        }
    } //end for
    printf("\n\n------------------------------------------ \n\n");
    if (flag == 1) // jika data yang dicari ditemukan, ditandai dengan flag == 1
    {
        printf(":: data %d ditemuka dengan alamat : %d  \n\n", cari, alamat);
    }
    else // jika flag masih 0 / data tidak ditemukan
    {
        printf(":: data %d tidak ditemuka  \n\n", cari);
    }
    return 0;
} // end menu

/* Algoritma sequential search adalah algoritma yang searching yang paling sederhana, 
dimana kita akan mencari sebuah nilai dari dalam list dengan cara membandingkannya 
satu per satu dari index ke 0 sampai index ke n */

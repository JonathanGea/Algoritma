#include <stdio.h>
#include <string.h>
#include <iostream>
#include <queue>
#include <stack>
#define MAX_N 1001

// uncomen code yang ditandai dengan tanda # jika ingin melihat proses kerja algoritma

using namespace std;
typedef long long lld;

int n, m;
string A, B;
int dp[MAX_N][MAX_N];


inline int LCS() // untuk mendpatakan panjang dari LCS
{
    for (int i=1; i<=n; i++)
    {

        for (int j=1; j<=m; j++)
        {
            if (A[i-1] == B[j-1]) //  Bila X sama dengan Y
            {
                dp[i][j] = dp[i-1][j-1] + 1; // . Bila X sama dengan Y, maka nilai pada kolom tersebut adalah (n,n) = (n-1,n-1) + 1

            }
            else
            {
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]); //   bila X tidak sama dengan Y, maka nilai yang menjadi input adalah nilai terbesar yang
                // terdapat pada kolom (n-1,n) atau pada kolom (n,n-1). Misalkan nilai X = B dan nilai Y = B

            }
  /* #          printf(" \n ------------------------------------ \n");
            for (int i=0; i<=m; i++)
            {
                for (int k=0; k<=n; k++)
                {
                    printf(" %d ", dp[k][i] );
                }
                printf("\n");
            } */
        }
    }
    // # printf(" \n\n--------------------------- hasil --------------------------- " );
    return dp[n][m];

}




inline string getLCS() //untuk mendapatkan LCS
{
    string ret;
    stack<char> S;
    int ii = n, jj = m;
    //-------------------------------------------------------------------------------------------------
   /* # printf("| %d  ++  %d |\n", ii, jj);
    printf("------------\n");
    printf("| ii ++ jj |\n");
    printf("------------\n"); */
    while (ii != 0 && jj != 0)
    {
        if (A[ii-1] == B[jj-1])
        {
            S.push(A[ii-1]);
            ii--;
            jj--;
        }
        else if (dp[ii-1][jj] > dp[ii][jj-1])
            ii--; // bergerak ke samping kiri (ii-1)
        else
            jj--; // bergerak ke atas (jj-1)

        printf("| %d  ++  %d |\n", ii, jj); // melihat proses
    }
    while (!S.empty())
    {
        ret += S.top();
        S.pop();

    }
    return ret;
}

int main()
{
    A = "BDCB";
    B = "BACDB";
    n = A.length();
    m = B.length();

    printf("\n\n>> panjang LCS dari kedua sequence adalah %d \n",LCS());
    printf(">> LCS dari kedua sequence adalah %s\n",getLCS().c_str());
    return 0;
}


/*  The longest common subsequence  (LCS) didefinisikan sebagai urutan terpanjang yang umum untuk semua urutan yang diberikan,
asalkan elemen urutan tidak diharuskan untuk menempati posisi berurutan dalam urutan asli. */

#include <stdio.h>


int loc_min(int i, int j, int k, int p)
{
    int a[i][j];
    if ( i ==0 || j == 0 || i == k-1 || j == p-1)
        return(0);

    int mval = a[i][j];
    for(int i1=i-1; i1<=i+i ; i1++)
       for(int j1=j-1;j1<=j+1;j1++)
          if (mval>=a[i1][j1]&& i1!=i && j1!=j )
                 return 0;        
    return 1; 
}

int main()
{
     int K;

     int P;
    scanf("P= %d", &P);
    scanf("K= %d", &K);
   
    int arr[K][P];
    int count = 0;
      for (int i = 0; i < K; i++) //проход столбцов
    {
        for (int j = 0; j < P; j++) //проход строк
            scanf("%d", &arr[K][P]);
                }

        for (int i=0;i<K;i++)
             for (int j=0;j<P;j++)
                 if ( loc_min (i, j, K, P) )
                      count++;

        printf("numbers of local min = %d", count);
}




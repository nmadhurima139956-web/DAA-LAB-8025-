#include <stdio.h>
#include <limits.h>

int main()
{
    int p[100], m[100][100];
    int n, i, j, k, length, q;

    printf("Enter number of matrices: ");
    scanf("%d", &n);

    printf("Enter matrix dimensions:\n");
    printf("For %d matrices, enter %d dimensions:\n", n, n + 1);

    for(i = 0; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }

    for(i = 1; i <= n; i++)
    {
        m[i][i] = 0;
    }

    /* Build the table */
    for(length = 2; length <= n; length++)
    {
        for(i = 1; i <= n - length + 1; i++)
        {
            j = i + length - 1;
            m[i][j] = INT_MAX;

            for(k = i; k < j; k++)
            {
                q = m[i][k] + m[k + 1][j]
                    + p[i - 1] * p[k] * p[j];

                if(q < m[i][j])
                {
                    m[i][j] = q;
                }
            }
        }
    }

    printf("Minimum number of multiplications = %d",
           m[1][n]);

    return 0;
}

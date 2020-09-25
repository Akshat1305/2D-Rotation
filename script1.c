#include<stdio.h>
#include<math.h>

void main()
{
    int m=3, n=4, p, q, c, d, k, h, ns, ch, i, j, r, rf;
    float th;
    float first[10][10], second[10][10], mult1[10][10], mult2[10][10], mult3[10][10], sum=0;
    float tx, ty;
    float trans[4][4], trans2[4][4], rot[4][4], mult[10][10], sum2=0, sum3=0;
    
    // Object Matrix
    printf("Enter the coordinates of object matrix:\n");

    for (d=0; d<n; d++)
    {
        for (c=0; c<m-1; c++)
        {
            scanf("%f",&first[c][d]);
            first[m-1][d]=1;
        }
    }
    for (c=0; c<m; c++)
    {
        for (d=0; d<n; d++)
        {
            
        }
    }

    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            if(i==j)
            {
                trans[i][j]=1;
            }
            else
            {
                trans[i][j]=0;
            }

            trans[0][2]=-1*first[0][3];
            trans[1][2]=-1*first[1][3];
        }
    }
    for (i=0; i<3; i++)
    {
        for (j=0; j<n; j++)
        {
            for (k=0; k<3; k++)
            {
                sum = sum + trans[i][k]*first[k][j];
            }
            mult1[i][j] = sum;
            sum=0;
        }
    }

    th = 3.1415*30/180;
    for (i=0; i<3; i++)
    {
        for (j=0; j<3; j++)
        {
            if (i==j)
            {
                rot[i][j]=cos(th);
            }
            else
            {
                rot[i][j]=0;
            }
            rot[0][1]=-sin(th);
            rot[1][0]=sin(th);
            rot[2][2]=1;
        }
    }

    for (i=0; i<3; i++)
    {
        for (j=0; j<n; j++)
        {
            for (k=0; k<3; k++)
            {
                sum2 = sum2 + rot[i][k]*mult1[k][j];
            }
        
            mult2[i][j]=sum2;
            sum2=0;
        }
    }

    for (i=0; i<3; i++)
    {
        for (j=0; j<3; j++)
        {
            if (i==j)
            {
                trans2[i][j]=1;
            }
            else
            {
                trans2[i][j]=0;
            }

            trans2[0][2]=first[0][3];
            trans2[1][2]=first[1][3]; 
        }
    }
    for (i=0; i<3; i++)
    {
        for (j=0; j<n; j++)
        {
            for (k=0; k<3; k++)
            {
                sum3 = sum3 + trans2[i][k]*mult2[k][j];
            }
        
            mult3[i][j]=sum3;
            sum3=0;
        }
    }

    for (i=0; i<n; i++)
    {
        for (j=0; j<3; j++)
        {   
            if (mult3[j][i] != 1)
            {
                printf("\n%0.2f",mult3[j][i]);
            }
            
        }
    }
}
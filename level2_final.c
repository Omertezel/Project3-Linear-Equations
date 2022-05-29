#include<stdio.h>
#include<conio.h>

void main()
{
	FILE *fp;
   fp = fopen("C:\\Users\\pc\\denemedosya.txt","r");

  int i,j,k,n;
  float A[20][20],c,x[10],sum;
  printf("\nEnter the order of matrix: ");
  scanf("%d",&n);
  printf("\nEnter the elements of augmented matrix row-wise:\n\n");
  for(i=1; i<=n; i++)
  {
    for(j=1; j<=(n+1); j++)
    {
   
      fscanf(fp,"%f",&A[i][j]);
    }
  }
  
  /* loop for the generation of upper triangular matrix*/
  for(i=1; i<=n; i++)
  {
    for(j=1; j<=n; j++)
    {
      if(j>i)
      {
        c=A[j][i]/A[i][i];
        for(k=1; k<=n+1; k++)
        {
          A[j][k]=A[j][k]-c*A[i][k];
        }
      }
    }
  }

  /* Upper Traingular matrix */
  printf("\nThe Upper Triangular matrix is: \n\n");
  for(i=1; i<=n; i++)
  {
    for(j=1; j<=(n+1); j++)
    {
      printf("%f ",A[i][j]);
    }
    printf("\n");
  }

  /* initializing x[i] to zeros */
  for(i=1; i<=n; i++)
  {
    x[i]=0;
  }

  /* loop is for backward substitution */
  printf("\nAfter applying Backward Substitution: \n");
  for(i=n; i>=1; i--)
  {
    sum=0;
    for(j=1; j<=n; j++)
    {
      if(i!=j)
        sum=sum+A[i][j]*x[j];
    }
    x[i]=(A[i][n+1]-sum)/A[i][i];
  }

  printf("\nThe solution is: \n");
  for(i=1; i<=n; i++)
  {
    printf("\nx%d=%f\t",i,x[i]);
    /* x1, x2, x3 are the required solutions */
  }
  getch();
}

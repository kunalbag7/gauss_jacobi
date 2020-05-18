#include<stdio.h>
#define SIZE 100
#include<math.h>
#include<stdlib.h>
//Uploading to github
//First add
//Second Commit and give a commit desciption
//Lastly Push to github
int main()
{
	float tar=0.000001, sum, diff=1;
	int cond=1,n,i,j;
	float matrix[SIZE][SIZE], row, R[n], Rnew[n];
	printf("Size of matrix-> ");
	scanf("%d",&n);
	printf("Enter the elements ?\n");
	for(i=0;i<n;i++)
		for(j=0;j<n+1;j++)
			scanf("%f",&matrix[i][j]);

	printf("The equations are:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n+1;j++)
		{
			if(j!=n)
			printf("%.2f X%d + ",matrix[i][j],j+1);
			else
			printf("\b\b=%.2f",matrix[i][j]);

		}
		printf("\n");
	}

	for(i=0;i<n;i++)
	{
		row=0;
		for(j=0;j<n;j++)
			row=row+fabs(matrix[i][j]);
		if(row>=2*fabs(matrix[i][i]))
		cond=0;
	}

	if(cond==0)
	{
		printf("\nThe matrix is not diagonally dominated.");
		exit(0);
	}

	for(i=0;i<n;i++)
		{
			R[i]=0;
			Rnew[i]=0;
		}
	while( diff>tar)
	{
		for(i=0;i<n;i++)
		{
			sum=matrix[i][n];
			for(j=0;j<n;j++)
				if(i!=j)
					sum=sum-matrix[i][j]*R[j];
			Rnew[i]=sum/matrix[i][i];
		}
		diff=0;
		for(i=0;i<n;i++)
			diff=diff+fabs(Rnew[i]-R[i]);
		for(i=0;i<n;i++)
			R[i]=Rnew[i];
	}
	printf("\nSolution: \n");
	for(i=0;i<n;i++)
	printf("X%d = %f\n",i+1,R[i]);
}

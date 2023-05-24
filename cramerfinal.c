#include <stdio.h>

int findDeterminant(int mat[10][10]);

// This functions finds the determinant of Matrix
int findDeterminant(int mat[10][10]){
	int ans;
    ans = mat[0][0] * (mat[1][1] * mat[2][2] - mat[2][1] * mat[1][2])
          - mat[0][1] * (mat[1][0] * mat[2][2] - mat[1][2] * mat[2][0])
          + mat[0][2] * (mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0]);
    return ans;
}

int main(){
	int m[10][10], mx[10][10], my[10][10], mz[10][10];
	int i, j;
	int d, dx, dy, dz;
	int x, y, z;
	
	//input coefficient matrix
	printf("Enter elements in coefficient matrix: \n");
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			scanf("%d", &m[i][j]);
		}
	}
	
	//input coefficient matrix substituting elements of x with constants
	printf("Enter elements in coefficient matrix replacing x: \n");
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			scanf("%d", &mx[i][j]);
		}
	}
	
	//input coefficient matrix substituting elements of y with constants
	printf("Enter elements in coefficient matrix replacing y: \n");
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			scanf("%d", &my[i][j]);
		}
	}
	
	//input coefficient matrix substituting elements of z with constants
	printf("Enter elements in coefficient matrix replacing z: \n");
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			scanf("%d", &mz[i][j]);
		}
	}
	
	// Calculating Determinant of Matrices m, mx, my, mz
	d = findDeterminant(m);
	dx = findDeterminant(mx);
	dy = findDeterminant(my);
	dz = findDeterminant(mz);
	
	//determinants output
	printf("\n");
	printf("D is : %d \n", d);
    printf("Dx is : %d \n", dx);
    printf("Dy is : %d \n", dy);
    printf("Dz is : %d \n", dz);
    
    // Case 1
    if (d != 0) {
        // Coeff have a unique solution. Apply Cramer's Rule.
        x = dx / d;
        y = dy / d;
        z = dz / d; 
		        
		printf("\n");        
		printf("Value of x is : %d\n", x);
        printf("Value of y is : %d\n", y);
        printf("Value of z is : %d\n", z);
    }
    // Case 2
    else {
        if (dx == 0 && dy == 0 && dz == 0)
            printf("Infinite solutions\n");
        else if (dx != 0 || dy != 0 || dz != 0)
            printf("No solutions\n");
    }
    
    return 0;
}



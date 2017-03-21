// Subset sums by dynamic programming
// CSE 2320 Notes 7
// Author professor weems (UTA)
// modifed by Graciela Aguilar
// modifed to compute subset for ALL POSSIBLE
// CARDINALITIES
//
//  compile-command in Omega:
//
//      gcc -o program 1000717478.c
//
//  Run-program command:
//
//      ./program < filename.txt
//
//  example:
//
//       I saved test inputs (separately)
//       in text files and used shell redirect
//       like this:
//
//           ./program < lab2a.c
//           ./program < lab2b.c
//           ./program < lab2c.c

#include <stdio.h>
#include <stdlib.h>

void readInput(int* n,int* m,int** S,int** C){
    
    int i;

    scanf("%d",n);
    scanf("%d",m);

    *S=(int*) malloc((*n+1)*sizeof(int));
    *C=(int*) malloc(((*m)*((*n)+1))*sizeof(int));

    if (!(*S) || !(*C)){
    
        printf("malloc failed %d\n",__LINE__);
        exit(0);
    }

    (*S)[0]=0;
    for (i=1;i<=*n;i++)
        scanf("%d",*S+i);
    }

void subsetSum(int n,int m,int* S,int* C, int card)
{
    int i, j, leftover, position;

    for (j=1;j<=n;j++)
    {
    
        leftover=m-S[j];
            
        if (card == 1){
                
            if(m == S[j]){
                break;
            }
            else{
                continue;
            }
        }
        position = (n * leftover) + (card-1);

        if(leftover>=0 && C[position]<j){
                
            break;
        }
    }
    position = (n * m) + card;
    C[position]=j;
}

void writeOutput(int n,int m,int* S,int* C){
    
    int i = 0 , j = 0, k = 0, h = 0;

    printf("m is %d\n", m);
    printf("  i   S\n");
    printf("-------\n");
    
    for (i=0;i<=n;i++){
        
        printf("%3d %3d\n",i,S[i]);
    }
    
        printf("   i   card  C\n");
        printf("-----------------\n");
    
        for (i=1;i<=(n * (m+1)); i++){
            if(j == n){
                j = 0;
                k++;
            }
            j++;
            printf("%4d %4d %4d\n",k, j, C[i]);
        }

    for( i=1; i<=n; i++){
        j = (m*n) + i;
        if (C[j]==n+1){
        
            printf("No solution with %d elements\n", i);
        }
        else{
            printf("Solution with %d elements\n", i);
            printf("  i   S\n");
            printf("-------\n");
            h=i;
            k = m;
            while(h){
                
                j = (k*n) + h;
                printf("%3d %3d\n", C[j],S[C[j]]);
                k -= (S[C[j]]);
                h--;
                
            }
        }
    }
}

int main(){

    int n=0, m=0, j=0, i=0;
    int *S;
    int *C;
    
    readInput(&n,&m,&S,&C);
    
    for(i = 0; i <=m; i++){
        
        for(j = 1; j <=n; j++){
            
            if( i == 0){
                
                C[j] = n+1;
            }
            else{
                subsetSum(n,i,S,C, j);
            }
        }
    }
    
    writeOutput(n,m,S,C);

    free(S);
    free(C);
}

//  compile-command in Omega:
//      gcc -o program lab1_gxa7478.c
//  Run-program command:
//      ./program < filename.txt
//  example:
//    
//       I saved test inputs (separately)
//       in text files and used shell redirect
//       like this:
//
//           ./program < lab1a.c
//           ./program < lab1b.c
//           ./program < lab1c.c
//
//  Created by graciela aguilar on 2/11/17.
//
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int *A, *X;
int A_size = 0, X_size = 0;

bool maxInterleaveFactor(int factor);
int binarysearch(int factor);

int main (int argc, char *argv[]){
    
    char buffer[256];
    int i = 0, j = -1, maxFactor = 0;
    char *tok;
    bool result;

    
    while(fgets(buffer, sizeof(buffer) , stdin) != NULL){
        if(j == X_size){
            break;
        }

        if (i == 0){
            tok = strtok(buffer, " ");
            A_size = atoi(tok);
            tok = strtok(NULL, "\n");
            X_size = atoi(tok);
            A = (int*) malloc(A_size * sizeof(int));
            X = (int*) malloc(X_size * sizeof(int));
            i++;
            continue;
            
        }
        if((strcmp("-999999999\n", buffer) == 0) && (i != -1)){
            j = 0;
            i = -1;
            continue;
        }
        if((i != -1)){
            A[i-1] = atoi(buffer);
            i++;
          
        }
        if(j != -1){
            X[j] = atoi(buffer);
            j++;
        }
        
    }
    result = maxInterleaveFactor(1);
    
    if(!result){
        
        printf("Subsequence does not exist.\nExiting...\n");
        exit(0);
    }
    maxFactor = binarysearch(A_size/X_size);
    
    printf("Maximum repeats is %d\n", maxFactor);
 
    return 0;
}
bool maxInterleaveFactor(int factor){
    
    
    int i = 0, j = 0, count = 0;
    
    for(i = 0; i < A_size; i ++){
        if((count == factor) && ((j+1) == X_size)){
            
            return true;
            
        }
        else if((count == factor) && ((j+1) != X_size)){
            count = 0;
            j++;
        }
        if(A[i] == X[j]){
            count++;
        }
        
        
    }
    return false;
}
int binarysearch(int factor){
    
    
    int high = factor, low = 0;
    int mid = (high+low)/2;
    
    while (low <= high) {
        
        if(low == high){
            if(maxInterleaveFactor(mid)){
                printf("low %d mid %d high %d passed\n", low, mid, high);
                return mid;
            }
            
            else{
                printf("low %d mid %d high %d failed\n", low, mid, high);
                return mid - 1;
            }
        }
        else if (maxInterleaveFactor(mid)){
            printf("low %d mid %d high %d passed\n", low, mid, high);
            low = mid + 1;
            mid = (high+low)/2;
        }
        
        else{
            printf("low %d mid %d high %d failed\n", low, mid, high);
            high = mid - 1;
            mid = (high+low)/2;
        
        }
    }
    free(A);
    free(X);
    return 0;
}

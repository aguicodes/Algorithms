
// Demonstration code to insert keys in range 0 . . 10*RADIX*RADIX-1
// and perform various tests
#include <stdlib.h>
#include <stdio.h>
#include "RB.h"

//#define RADIX (3)
#define RADIX (3)
#define OFFSET (3)  // Controls # of rounds of tracing

int main()
{
    int i,j,k;
    
    STinit();  // Initialize red-black tree
    verifyRBproperties();
    
    // Insert some keys that are multiples of 10
    for (i=0;i<RADIX-OFFSET;i++)
    {
        for (j=0;j<RADIX;j++)
        {
            STinsert(10*(j*RADIX+i));
            Item pt;
            
            pt=STsearch(10*(j*RADIX+i));
            if (pt==NULLitem)
            {
                printf("Key missing\n");
                exit(0);
            }
            verifyRBproperties();
        }
        
        for (k=0;k<=i;k++)
            for (j=0;j<RADIX;j++)
                if (STselect(STinvSelect(10*(j*RADIX+k)))!=10*(j*RADIX+k))
                {
                    printf("Error 1 with rank functions\n");
                    exit(0);
                }
        for (k=0;k<RADIX*(i+1);k++)
            if (STinvSelect(STselect(k+1))!=k+1)
            {
                printf("Error 2 with rank functions\n");
                exit(0);
            }
    }
    
    // Insert the rest of the keys that are multiples of 10
    STprintTree();
    extendedTraceOn();
    for (i=RADIX-OFFSET;i<RADIX;i++)
        for (j=0;j<RADIX;j++)
        {
            printf("Inserting %d\n",10*(j*RADIX+i));
            STinsert(10*(j*RADIX+i));
            STprintTree();
            verifyRBproperties();
        }
    
    // Saturate with inserts for keys that are not multiples of 10
    for (i=0;i<10*RADIX*RADIX;i++)
        if (i%10!=0)
        {
            printf("Inserting %d\n",i);
            STinsert(i);
            STprintTree();
            verifyRBproperties();
        }
}

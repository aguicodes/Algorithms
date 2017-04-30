
// Loads a red-black tree in ancestry order, then processes
// inserts with tracing
#include <stdlib.h>
#include <stdio.h>
#include "RB.h"

int main()
{
    link root=NULL;
    int n,i;
    Key t;
    int color;
    link x,p;
    
    STinit();  // Initialize red-black tree
    
    scanf("%d",&n);  // Number of keys in tree to load
    for (i=0;i<n;i++)
    {
        scanf("%d %d",&t,&color);     // color:  1=red, 0=black
        link x = malloc(sizeof *x);
        x->item = t;
        x->l = NULL;
        x->r = NULL;
        x->red = color;
        
        // Unbalanced insert as a leaf
        if (!root)
        {
            root=x;
            continue;
        }
        p=root;
        while (1)
            if (t < p->item)
                if (p->l)
                    p=p->l;  // Continue down
                else
                {
                    p->l=x;
                    break;
                }
                else if (p->r)
                    p=p->r;    // Continue down
                else
                {
                    p->r=x;
                    break;
                }
    }
    cleanUpUnbalanced(root);
    
    STprintTree();
    extendedTraceOn();
    //basicTraceOn();
    scanf("%d",&n);  // Number of inserts
    for (i=0;i<n;i++)
    {
        scanf("%d",&t);
        printf("Inserting %d\n",t);
        STinsert(t);
        STprintTree();
        verifyRBproperties();
    }
}

// Bottom-up red-black tree header file - lab 3 spring 2017

// These will have to change if data in node is more than just an int.
typedef int Key;
typedef int Tombstone;
typedef Key Item;
#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define eq(A, B) (key(A) == key(B))
#include <stdbool.h>
typedef struct STnode* link;
typedef struct Lnode* list;

struct STnode
{
    Item item;  // Data for this node
    link l, r;  // left & right links
    char red;   // RB color
    char tombstone; // 0 = live key, 1 = dead key
    int N;      // subtree size (counts only live nodes)
};

struct Lnode {
    
    Item item;  // Data for this node
    list next;
};


extern Item NULLitem;

void STinit();          // Initialize tree with just a sentinel

void freeMem();
void printRBTree(link h,int depth,int bhAbove);

list DeadList(Item item);
list LiveList(Item item);
void BuildList(link root);
void RebuildRBTree();
link load(int count);
Item STsearch(Key v);   // Find node for a key

void inorder( link root);

Item STselect(int k);   // Treat tree as flattened into an ordered array

int STinvSelect(Key v); // Inverse of STselect

void extendedTraceOn(); // Full tracing of intermediate trees

void basicTraceOn();    // Just trace down and up passes for insert

void traceOff();        // Run silent

void STinsert(Item item);     // Insert an item.  No uniqueness check

bool STdelete(Key v);         // Delete item for a key, if present.

int verifyRBproperties();    // Ensure that tree isn't damaged

void STprintTree();           // Dumps out tree

void printTree(link h,int depth,int bhAbove);

void cleanUpUnbalanced(link h);  // Includes subtree sizes and verifies a tree
// built without balancing


int getRecycled();  // Number of elements available from last removeDead()

void removeDead(int C);  // Rebuild tree and put tombstoned elements in recycling list.

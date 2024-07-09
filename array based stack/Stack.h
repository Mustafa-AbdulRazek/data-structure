// Stack.h

#define MAXSTACK 100
// #define STACKENTRY 
typedef void * StackEntry;

/* Array-based Impelementation.*/
// typedef struct stack{
//     int top;
//     StackEntry entry[MAXSTACK];
// } Stack;


/* Linked-based Impelementation.*/
typedef struct StackNode{
    StackEntry entry;
    struct StackNode *next;
}StackNode;

typedef struct stack{
    StackNode *top;
    int size;
    int max;
}Stack;





void	Push			(StackEntry, Stack *);
void	Pop				(StackEntry *, Stack *);
int		StackEmpty		(Stack *);
int		StackFull		(Stack *);
void	CreateStack		(Stack *);
void	StackTop		(StackEntry *, Stack *);
int		StackSize		(Stack *);
int     StackMax        (Stack *);
void	ClearStack		(Stack *);
void	TraverseStack	(Stack *, void (*)(StackEntry));



#define MAXSTACK 100

typedef struct stack
{
    int top;
    StackEntry entry[MAXSTACK];
} Stack;

void Push(StackEntry, Stack *);
void Pop(StackEntry *, Stack *);
int StackEmpty(Stack *);
int StackFull(Stack *);
void CreateStack(Stack *);
void StackTop(StackEntry *, Stack *);
int StackSize(Stack *) void ClearStack(Stack *);
void TraverseStack(Stack *, void (*)(StackEntry));
/*
 * Yousef Mahmoud
 * 2-4-22
 * Stack - Array based Implementation
 *
 */

// StackEntry is defined at the user level, because type is defined by the user, so the MAXSTACK
typedef struct stack
{
    int top;
    StackEntry entry[MAXSTACK]; // StackEntry to be Generic
} Stack;
void ReverseRead(void)
{
    StackEntry item; // StackEmpty should be defined as char
    Stack stack;
    InitializeStack(&stack); // Initialize the stack to be empty
    while (!StackFull(&stack) && (item = getchar()) != '\n')
        Push(item, &stack); // push item onto the stack
    while (!StackEmpty(&stack))
    {
        Pop(&item, &stack); // pop item from the stack
        putchar(item);
    }
    putchar('\n');
}
// the complexity time of this function is 0(1) it doesn't depend on n;
// top is the index of the first available place.
void InitializeStack(Stack *ptr_s)
{
    ptr_s->top = 0; // is equivalent to *ptr_s.top = 0;
}
/*
Pre: The stack is initialized and not full
Post: The element e has been stored at the top of the stack; and e doe not change*/
void Push(StackEntry e, Stack *ptr_s)
{
    ptr_s->entry[ptr_s->top++] = e;
    // is equivalent to
    ptr_s->entry[ptr _s->top] = e;
    ptr_s->top++;
    // if top was initilized with -1
    ptr_s->entry[++(ptr_s->top)] = e; // ++ has precendence over ->
    if (ptr_s->top == MAXSTACK)
        printf("Stack is Full");
    else
        ptr_s->entry[ptr_s->top++] = e;
}
int StackFull(Stack *ptr_s)
{
    if (ptr_s->top == MAXSTACK)
        return 1;
    else
        return 0;
    // if equivalent to
    return ptr_s->top == MAXSTACK
}
void Pop(StackEntry *ptr_e, Stack *ptr_s)
{
    ptr_s->top--;
    *ptr_e = ptr_s->entry[ptr_s->top];
    // is equivalent to
    *ptr_e = ptr_s->entry[--ptr_s->top];
}
int StackEmpty(Stack *ptr_s)
{
    if (ptr_s->top == 0)
        return 1;
    else
        return 0;
    // is equivalent
    return !ptr_s->top
}
/**
 * @brief Copy the top element of the Stack
 *
 * @param ptr_e
 * @param ptr_s
 */
void StackTop(StackEntry *ptr_e, Stack *ptr_s)
{
    *ptr_e = ptr_s->entry[ptr_s->top - 1];
}
int StackSize(*ptr_s)
{
    return ptr_s->top;
}
void ClearStack(Stack *ptr_s)
{
    ptr_s->top = 0;
}
void Display(StackEntry e)
{
    printf("e is: %d\n", e);
}
// Precondition: the stack is Just Initialized
void TraverseStack(Stack *ptr_s, void (*ptr_fn)(StackeEntry))
{
    for (int i = ptr_s->top; i > 0; i--)
    {
        (*ptr_fn)(ptr_s->entry[i - 1]);
    }
}

void StackTop(StackEntry *pe, Stack *ps)
{
    Pop(pe, ps);
}
int main()
{
    StackEntry e;
    Stack s;             // Stack s is created but not initialized;
    InitializeStack(&s); // we have to pass the stack by reference, so the function work will be  reflected
    if (!StackFull(s))
    {
        Push(e, &s);
    }
    /*if(!Push(e, &s)){

    }*/
    if (!StackEmpty(&s))
    {
        Pop(&e, &s);
    }
    StackTop(&e, &s);
    int x;
    x = StackSize(&s);

    ClearStack(&s);

    TraverseStack(&s, &Display);

    StackTop(&e, &s);
    return 0;
}

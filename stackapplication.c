#include <stdio.h>
#include <string.h>

#define MAX 100

// Stack structure
typedef struct {
    char pages[MAX][20];
    int top;
} Stack;

// Push function
void push(Stack *s, char page[]) {
    if (s->top < MAX - 1) {
        s->top++;
        strcpy(s->pages[s->top], page);
    }
}

// Pop function
char* pop(Stack *s) {
    if (s->top >= 0) {
        return s->pages[s->top--];
    }
    return NULL;
}

// Display stack
void displayStack(Stack s) {
    printf("[");
    for (int i = 0; i <= s.top; i++) {
        printf("%s", s.pages[i]);
        if (i < s.top) printf(", ");
    }
    printf("]");
}

int main() {
    Stack backStack = {.top = -1};
    Stack forwardStack = {.top = -1};
    char currentPage[20] = "Home";

    // Simulating: Visit A ? Visit B ? Visit C ? Back ? Back ? Forward

    // Visit A
    push(&backStack, currentPage);
    strcpy(currentPage, "A");
    forwardStack.top = -1;

    // Visit B
    push(&backStack, currentPage);
    strcpy(currentPage, "B");
    forwardStack.top = -1;

    // Visit C
    push(&backStack, currentPage);
    strcpy(currentPage, "C");
    forwardStack.top = -1;

    // Back
    push(&forwardStack, currentPage);
    strcpy(currentPage, pop(&backStack));

    // Back
    push(&forwardStack, currentPage);
    strcpy(currentPage, pop(&backStack));

    // Forward
    push(&backStack, currentPage);
    strcpy(currentPage, pop(&forwardStack));

    // Output
    printf("Current Page: %s\n", currentPage);
    printf("Back Stack: ");
    displayStack(backStack);
    printf("\nForward Stack: ");
    displayStack(forwardStack);
    printf("\n");

    return 0;
}

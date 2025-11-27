#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

char stackOp[MAX];
int topOp = -1;

int stackVal[MAX];
int topVal = -1;

void pushOp(char c) { stackOp[++topOp] = c; }
char popOp() { return stackOp[topOp--]; }
char peekOp() { return stackOp[topOp]; }

void pushVal(int v) { stackVal[++topVal] = v; }
int popVal() { return stackVal[topVal--]; }

int prec(char c) {
    if (c=='+'||c=='-') return 1;
    if (c=='*'||c=='/') return 2;
    return 0;
}

int isOp(char c) {
    return (c=='+'||c=='-'||c=='*'||c=='/');
}

void infixToPostfix(char in[], char post[]) {
    int i=0, k=0;
    while(in[i]) {
        if (isdigit(in[i])) {
            while(isdigit(in[i])) post[k++] = in[i++];
            post[k++]=' ';
            continue;
        }
        if (in[i]=='(') pushOp(in[i]);
        else if (in[i]==')') {
            while(peekOp()!='(') { post[k++]=popOp(); post[k++]=' '; }
            popOp();
        }
        else if (isOp(in[i])) {
            while(topOp!=-1 && prec(peekOp())>=prec(in[i])) {
                post[k++]=popOp(); post[k++]=' ';
            }
            pushOp(in[i]);
        }
        i++;
    }
    while(topOp!=-1) { post[k++]=popOp(); post[k++]=' '; }
    post[k]=0;
}

int evalPostfix(char post[]) {
    int i=0;
    while(post[i]) {
        if (isdigit(post[i])) {
            int val=0;
            while(isdigit(post[i])) val=val*10+(post[i++]-'0');
            pushVal(val);
        } else if (isOp(post[i])) {
            int b=popVal(), a=popVal();
            if (post[i]=='+') pushVal(a+b);
            if (post[i]=='-') pushVal(a-b);
            if (post[i]=='*') pushVal(a*b);
            if (post[i]=='/') pushVal(a/b);
        }
        i++;
    }
    return popVal();
}

int main() {
    char infix[200], postfix[200];

    printf("Enter Infix Expression: ");
    fgets(infix, sizeof(infix), stdin);

    infixToPostfix(infix, postfix);
    printf("Postfix: %s\n", postfix);
    printf("Result: %d\n", evalPostfix(postfix));

    return 0;
}

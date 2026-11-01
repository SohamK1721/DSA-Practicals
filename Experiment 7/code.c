#include <stdio.h>
#include <string.h>
#include <math.h>

#define SIZE 80

struct stack
{
    double s[SIZE];
    int top;
} st;

void push(double val);
double pop(void);
double post(char expr[]);

int main(void)
{
    char expr[SIZE];
    double result;

    printf("\nEnter a postfix expression: ");

    if (scanf("%79s", expr) != 1)
    {
        printf("Invalid input!\n");
        return 1;
    }

    result = post(expr);

    printf("\nThe value of the expression is %f\n", result);

    return 0;
}

double post(char expr[])
{
    char ch;
    double result = 0, op1, op2;
    int i;

    st.top = -1;
    i = 0;

    while (expr[i] != '\0')
    {
        ch = expr[i];

        if (ch >= '0' && ch <= '9')
        {
            push(ch - '0');
        }
        else if (ch == '+' || ch == '-' ||
                 ch == '*' || ch == '/' || ch == '^')
        {
            if (st.top < 1)
            {
                printf("\nInvalid postfix expression!\n");
                return 0;
            }

            op2 = pop();
            op1 = pop();

            switch (ch)
            {
                case '+':
                    result = op1 + op2;
                    break;

                case '-':
                    result = op1 - op2;
                    break;

                case '*':
                    result = op1 * op2;
                    break;

                case '/':
                    if (op2 == 0)
                    {
                        printf("\nDivision by zero is not allowed!\n");
                        return 0;
                    }
                    result = op1 / op2;
                    break;

                case '^':
                    result = pow(op1, op2);
                    break;
            }

            push(result);
        }
        else
        {
            printf("\nInvalid character in expression!\n");
            return 0;
        }

        i++;
    }

    if (st.top != 0)
    {
        printf("\nInvalid postfix expression!\n");
        return 0;
    }

    return pop();
}

void push(double val)
{
    if (st.top >= SIZE - 1)
    {
        printf("\nStack is full!\n");
        return;
    }

    st.top++;
    st.s[st.top] = val;
}

double pop(void)
{
    double val;

    if (st.top == -1)
    {
        printf("\nStack is empty!\n");
        return 0;
    }

    val = st.s[st.top];
    st.top--;

    return val;
}

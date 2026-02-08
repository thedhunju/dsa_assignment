1. Write a program to check if any given mathematical expression has balanced number of parentheses or not?
Run the program by testing following expression-
⇒a + (b − c) ∗ (d
⇒m + [a − b ∗ (c + d ∗ {m)]
⇒a + (b − c)
Hint: Use stack


ANSWER:

Data Structures
The program uses a stack to keep track of opening brackets. A stack works like a pile of plates - you add on top and remove from the top.

char stk[SIZE]: An array that holds up to 100 characters. It stores the opening brackets we find like (, [, and {.
int t: This keeps track of where the top of our stack is. It starts at -1 which means the stack is empty.

Functions Implemented
1. void add(char x)
This function adds an opening bracket to the stack. When we find brackets like (, [, or {, we push them onto the stack so we can match them later with their closing brackets.
2. char rem()
This function removes the top bracket from the stack. We use it when we find a closing bracket that matches an opening one. If the stack is empty, it returns '\0' to show there's nothing to remove.
3. int match(char a, char b)
This checks if two brackets are a matching pair. For example, ( matches with ), [ matches with ], and { matches with }. It returns 1 if they match and 0 if they don't.
4. int check(char *str)
This is the main function that checks the whole expression. It goes through each character one by one. If it finds an opening bracket, it pushes it to the stack. If it finds a closing bracket, it checks if there's a matching opening bracket on top of the stack. At the end, if the stack is empty, all brackets were balanced. If not, some brackets were left unmatched.
Main Method Organization
The main function tests three different expressions to see if their brackets are balanced:

First, it creates three test expressions as strings.
Then, for each expression it prints the expression and calls the check() function.
Based on what check() returns, it prints either "Balanced" or "Not Balanced".
Finally, it returns 0 to end the program.
**Input/Output**

![alt text](../Output/OUTPUT1.png)


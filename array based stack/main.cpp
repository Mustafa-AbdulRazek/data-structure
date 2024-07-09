#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"


void Display(StackEntry e){
    printf("e is: %d\n", e);
}

void menu(){
        puts("\nMenu:\n");
        puts("(a) Clear the stack.\n");
        puts("(b) Read the element then push it.\n");
        puts("(c) Pop the element then display it.\n");
        puts("(d) Waht is the stack size? \n");
        puts("(m) Waht is the stack Max? \n");
        puts("(e) Traverse and Display All the Stack Elements.\n");
        puts("(f) Exit!");
    }
    

int main(){

    Stack s;
    CreateStack(&s);
    StackEntry e = malloc(sizeof(int));
    char choice;

    do{
        menu();
        choice = getchar();
        getchar();  // to consume the newline character left in the buffer

        switch(choice){
            case 'a':
                ClearStack(&s);
                puts("Stack Cleared.\n");
                break;

            case 'b':
                printf("Enter the element to Push:\n");
                scanf("%d", &e);
                getchar();

                if(!StackFull(&s)){
                    Push(e, &s);
                    puts("Element Pushed.\n");
                } else{
                    puts("Stack is full. Can't Push.\n");
                }
                break;

            case 'c':
                if(!StackEmpty(&s)){
                    Pop(&e, &s);
                    printf("Poped element: %d\n", e);
                } else{
                    puts("Stack is empty. Can't Pop.\n");
                }
                break;

            case 'd':
                printf("Stack size is: %d\n", StackSize(&s));
                break;
            
            case 'm':
                printf("Stack max is: %d\n", StackMax(&s));
                break;
            
            case 'e':
                puts("Stack Elements after traverse: \n");
                TraverseStack(&s, Display);
                break;

            case 'f':
                puts("Exiting...\n");
                break;

            default:
                puts("Invalid choice. Please enter a, b, c, d, e, or f.\n");
                break;

        }
    }while(choice != 'f');

    return 0;
    }

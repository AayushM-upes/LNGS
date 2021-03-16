#include <stdio.h>

void user_g(){
    printf("This function is under development.");
}

void random_g(){
    printf("This function is under development.");
}

//Driver Function
int main() {
    int choice=0;
    printf("Enter 1 to manually generate a network\n");
    printf("Enter 2 to generate a random network\n");

    scanf("%d", &choice);

    while (choice!=3) {
        //Manual Network(Graph) Generation
        if (choice == 1) {
            user_g();
        }
        //Random Network(graph) Generation using Erdos-Renyl Model
        if (choice == 2) {
            random_g();
        }
        printf("Enter 1 to manually generate a network\n");
        printf("Enter 2 to generate a random network\n");
        printf("Enter 3 to exit of the program\n");

        scanf("%d", &choice);
    }
    printf("Thank you for using!");
    return 0;
}
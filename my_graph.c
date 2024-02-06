#include <stdio.h>
#include "my_mat.h"

int main()
{
    int adg[length][length] = {0}; // Initialize adjacency matrix with zeros
    char option = 'a'; // Variable to store the user's menu choice

    // Display the menu options to the user
    printf("\n");
    printf("List of commands : \n");
    printf("A- Enters new adjacency matrix \n");
    printf("B- Checks if a valid path is between i and j \n");
    printf("C- Shortest path between i and j if exists \n");
    printf("D- Exit the program \n");

    option = getchar(); // Read the first user option from standard input
    while(option != 'D') // Keep running until the user chooses to exit
    {
        switch(option) // Execute the user's action based on the input
        {
            case 'A':
                INITmat(adg); // Initializes the adjacency matrix with user input
                break;
            case 'B':
                Validpath(adg); // Checks and prints if there's a valid path between two nodes
                break;
            case 'C':
                Shortestpath(adg); // Computes and prints the shortest path length between two nodes, if it exists
                break;
            case 'D':
                // This case is technically unnecessary due to the while loop condition, but included for completeness
                break;
        }
        option = getchar(); // Read the next option, including newline characters which can be skipped if necessary
    }
    return 0; // Exit the program
}

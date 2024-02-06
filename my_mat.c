#include <stdio.h>
#include "my_mat.h"


void INITmat(int adg[length][length]){// Initialize the adjacency matrix with input values
    int i = 0, j = 0;

	for(i = 0; i < length; i++)
		for(j = 0; j < length; j++)
		{
			scanf("%d", &adg[i][j]); // Reads edge weight from standard input
			if (adg[i][j] == 0 && i != j) // Checks if there's no direct path between distinct vertices
            {// In Floyd Algo if i!=j we cant set the weight to be 0 so infinite number 
                adg[i][j] = INT_MA; // Sets the weight to INT_MAX for no direct path(as shown in the Video provided)
            }
        }
}

// Reads two vertex indices from input and prints the shortest path length between them, or -1 if no path exists.
void Shortestpath(int adg[length][length]){
	int i = 0, j = 0;
	scanf("%d %d", &i, &j); // Reads the start and end vertices for the path
	int ans = Floyd_Algo(adg, i, j); // Computes the shortest path using Floyd's algorithm

if (ans == 0 || ans == INT_MA) {
    printf("%d\n", -1); // If no path exists, prints -1
} else {
    printf("%d\n", ans); // Otherwise, prints the shortest path length
}
}

// Implements Floyd's algorithm to find the shortest paths between 2 vertices.
int Floyd_Algo(int adg[length][length],int v1,int v2) {
  int temp[length][length], i = 0, j = 0, k = 0;
 	for(i = 0; i < length; i++) // Initializes the temporary distance matrix
 		for(j = 0; j < length; j++)
 			temp[i][j] = adg[i][j]; // Copies the adjacency matrix to the temporary distance matrix
 	for(k = 0; k < length; k++) // Iterates over all vertices as intermediate points
 		for(i = 0; i < length; i++) // For each pair of vertices
 			for(j = 0; j < length; j++) // Checks if a shorter path exists by using vertex k
 				if (temp[i][j] != 0 && temp[i][k] != 0 && temp[k][j] != 0) {
                    temp[i][j] = minimum(temp[i][j], temp[i][k] + temp[k][j]); // Update the shortest path
                }
                if (i != j && temp[i][j] == 0 && temp[i][k] != 0 && temp[k][j] != 0) {
                    temp[i][j] = temp[i][k] + temp[k][j]; // update a path if it becomes unequal through k
                }
				return temp[v1][v2]; // Returns the shortest path length between v1 and v2
            }

// Checks if a valid path exists between two vertices and prints "True" or "False".
void Validpath(int adg[length][length]){
    int i=0, j=0;
	scanf("%d %d",&i,&j); 

    int valid = Floyd_Algo(adg, i, j); // Checks if a valid path exists using Floyd's algorithm

if (valid == 0 || valid == INT_MA) { 
    printf("%s\n", "False"); // If no valid path, prints "False"
} else {
    printf("%s\n", "True"); // Else "True"
}
}


int minimum(int v1,int v2){// Returns the minimum of two integers
    return (v1>v2) ? v2 : v1 ; 
}

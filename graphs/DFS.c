#include <stdio.h>
#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int n;

void createGraph() {
    int i, j, origin, destin;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("Is there an edge from %d to %d? (1 for yes, 0 for no): ", i, j);
            scanf("%d", &adj[i][j]);
        }
    }
}

void display() {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%4d", adj[i][j]);
        printf("\n");
    }
}

void DFS(int v) {
    int i;
    visited[v] = 1;
    printf("%d ", v);

    for (i = 0; i < n; i++) {
        if (adj[v][i] == 1 && visited[i] == 0)
            DFS(i);
    }
}

int main() {
    int choice, start;

    while(1) {
        printf("\nMenu\n");
        printf("1. Create graph\n");
        printf("2. Display adjacency matrix\n");
        printf("3. Depth First Search\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: 
                createGraph();
                break;
            case 2: 
                printf("Adjacency Matrix:\n");
                display();
                break;
            case 3: 
                printf("Enter starting vertex for Depth First Search: ");
                scanf("%d", &start);
                printf("DFS Traversal: ");
                DFS(start);
                printf("\n");
                break;
            case 4: 
                return 0;
            default: 
                printf("Invalid choice, please enter a valid choice.\n");
        }
    }

    return 0;
}
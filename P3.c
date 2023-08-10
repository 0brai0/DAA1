#include <stdio.h>
#include <limits.h>

#define MAX_CITIES 10

int graph[MAX_CITIES][MAX_CITIES];
int visited[MAX_CITIES];
int numCities;

int minTourCost = INT_MAX;

void findMinTour(int currentCity, int tourCost, int numVisited) {
    if (numVisited == numCities && graph[currentCity][0] != 0) {
        tourCost += graph[currentCity][0];
        if (tourCost < minTourCost) {
            minTourCost = tourCost;
        }
        return;
    }

    for (int nextCity = 0; nextCity < numCities; nextCity++) {
        if (!visited[nextCity] && graph[currentCity][nextCity] != 0) {
            visited[nextCity] = 1;
            findMinTour(nextCity, tourCost + graph[currentCity][nextCity], numVisited + 1);
            visited[nextCity] = 0;
        }
    }
}

int main() {
    printf("Enter the number of cities: ");
    scanf("%d", &numCities);

    printf("Enter the adjacency matrix (0 for no connection):\n");
    for (int i = 0; i < numCities; i++) {
        for (int j = 0; j < numCities; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    for (int i = 0; i < numCities; i++) {
        visited[i] = 0;
    }

    visited[0] = 1; // Start from the first city
    findMinTour(0, 0, 1); // Start with city 0

    printf("Minimum tour cost: %d\n", minTourCost);

    return 0;
}

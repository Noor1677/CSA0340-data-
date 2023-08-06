#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Edge {
    int src, dest, weight;
};
struct Subset {
    int parent, rank;
};

struct Edge* createEdge(int src, int dest, int weight) {
    struct Edge* edge = (struct Edge*)malloc(sizeof(struct Edge));
    edge->src = src;
    edge->dest = dest;
    edge->weight = weight;
    return edge;
}
int compareEdges(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}
int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}
void unionSets(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}
void kruskalMST(struct Edge* edges, int numEdges, int numVertices) {
    qsort(edges, numEdges, sizeof(struct Edge), compareEdges);
    struct Subset* subsets = (struct Subset*)malloc(numVertices * sizeof(struct Subset));
    for (int i = 0; i < numVertices; i++) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }
    struct Edge* mstEdges = (struct Edge*)malloc((numVertices - 1) * sizeof(struct Edge));
    int mstIndex = 0;
    int edgeIndex = 0;
    while (mstIndex < numVertices - 1 && edgeIndex < numEdges) {
        struct Edge nextEdge = edges[edgeIndex++];
        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);
        if (x != y) {
            mstEdges[mstIndex++] = nextEdge;
            unionSets(subsets, x, y);
        }
    }
    printf("Minimum Spanning Tree Edges:\n");
    for (int i = 0; i < mstIndex; i++) {
        printf("%d - %d : %d\n", mstEdges[i].src, mstEdges[i].dest, mstEdges[i].weight);
    }
    free(subsets);
    free(mstEdges);
}
int main() {
    int numVertices = 4;
    int numEdges = 5;
    struct Edge* edges = (struct Edge*)malloc(numEdges * sizeof(struct Edge));
    edges[0] = *createEdge(0, 1, 10);
    edges[1] = *createEdge(0, 2, 6);
    edges[2] = *createEdge(0, 3, 5);
    edges[3] = *createEdge(1, 3, 15);
    edges[4] = *createEdge(2, 3, 4);
    kruskalMST(edges, numEdges, numVertices);
    free(edges);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Graph {
    int numVertices;
    struct Node** adjLists;
    int* visited;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adjLists = (struct Node**)malloc(vertices * sizeof(struct Node*));
    graph->visited = (int*)malloc(vertices * sizeof(int));
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}
void BFS(struct Graph* graph, int startVertex) {
    struct Node* queue[graph->numVertices];
    int front = 0, rear = 0;
    graph->visited[startVertex] = 1;
    queue[rear++] = graph->adjLists[startVertex];
    while (front < rear) {
        struct Node* currentVertex = queue[front++];
        printf("%d ", currentVertex->data);
        struct Node* temp = currentVertex;
        while (temp != NULL) {
            int adjVertex = temp->data;
            if (graph->visited[adjVertex] == 0) {
                queue[rear++] = graph->adjLists[adjVertex];
                graph->visited[adjVertex] = 1;
            }
            temp = temp->next;
        }
    }
}
int main() {
    int vertices, edges, i, src, dest;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    struct Graph* graph = createGraph(vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    for (i = 0; i < edges; i++) {
        printf("Enter edge %d (src dest): ", i + 1);
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }
    int startVertex;
    printf("Enter the start vertex for BFS: ");
    scanf("%d", &startVertex);
    printf("Breadth First Traversal (starting from vertex %d):\n", startVertex);
    BFS(graph, startVertex);
    printf("\n");
    return 0;
}

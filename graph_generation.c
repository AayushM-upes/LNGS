#include <stdlib.h>
#include <stdio.h>
#include "graph_generation.h"

//This function to creates a new adjacency list node
struct Adj_List_node* newAdj_List_node(int dest, int length, int congestion)
{
    struct Adj_List_node* newNode = (struct Adj_List_node*) malloc(sizeof(struct Adj_List_node));
    newNode->dest = dest;
    newNode->length = length;
    newNode->congestion = congestion;
    newNode->next = NULL;
    return newNode;
}

//This function creates a network(graph) for V vertices
struct Graph* createGraph(int V)
{
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;

    graph->array = (struct Adj_List*) malloc(V * sizeof(struct Adj_List));

    int i;
    for (i = 0; i < V; ++i) {
        graph->array[i].head = NULL;
    }

    return graph;
}

//This function adds an edge between two vertices
void add_Edge(struct Graph* graph, int src, int dest, int length, int congestion)
{
    struct Adj_List_node* newNode = newAdj_List_node(dest, length, congestion);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    newNode = newAdj_List_node(src, length, congestion);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

//This function prints the created network(graph) as an adjacency list
void print_Graph(struct Graph* graph)
{
    int v;
    for (v = 0; v < graph->V; ++v)
    {
        struct Adj_List_node* pCrawl = graph->array[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (pCrawl)
        {
            printf("-> %d", pCrawl->dest);
            printf("(l=%d", pCrawl->length);
            printf(",c=%d)", pCrawl->congestion);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}

//User Generation
void user_g(){
    int V;  //no of vertices
    printf("Enter the number vertices you want in the network(graph):");
    scanf("%d", &V);

    struct Graph* graph = createGraph(V);      //creating a NULL network(graph)

    for (int i = 0; i < V; i++){
        int j = i+1;
        while (1){
            int conn;
            int len;
            int cong;
            if(j == V){
                break;
            }

            //providing user with a choice whether to create an edge or not
            printf("Enter 1 to put an edge or 0 to not put an edge between %d and %d:", i, j);
            scanf("%d", &conn);

            if(conn != 0 && conn != 1){
                printf("Invalid input\n");
            }
            else if(conn == 1) {
                printf("Enter the length of the edge: ");
                scanf("%d",&len);
                printf("Enter a value for congestion on this edge: ");
                scanf("%d", &cong);
                add_Edge(graph, i, j, len, cong);   //adding an edge if the user wants to add an edge
                j++;                    //then increment to move to the next vertex
            }
            else if(conn == 0){
                j++;                    //if users decides to not add an edge, increment to move to the next vertex
            }
        }
    }
    print_Graph(graph);
}
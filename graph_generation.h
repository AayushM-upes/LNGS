#ifndef LNGS_GRAPH_GENERATION_H
#define LNGS_GRAPH_GENERATION_H

//prototyping a structure for a node in adjacency list
struct Adj_List_node
{
    int dest;
    int length;
    int congestion;
    struct Adj_List_node* next;
};

//prototyping a structure for the adjacency list
struct Adj_List
{
    struct Adj_List_node *head;
};

//prototyping a structure for the network(graph)
//which is an basically an array of adjacency lists
struct Graph
{
    int V;
    struct Adj_List* array;
};

//Function prototype to creates a new adjacency list node
struct Adj_List_node* newAdj_List_node(int dest, int length, int congestion);

//Function prototype to create the graph
struct Graph* createGraph(int V);

//Function prototype to add a edge
void add_Edge(struct Graph* graph, int src, int dest, int length, int congestion);

//Function prototype to print the graph
void print_Graph(struct Graph* graph);

//User generated graph
void user_g();

#endif //LNGS_GRAPH_GENERATION_H

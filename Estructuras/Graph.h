#ifndef U07_GRAFOS_GRAFO_GRAPH_H_
#define U07_GRAFOS_GRAFO_GRAPH_H_

class Graph {
private:
  int **matriz;
  int node_count;

  void validate(int node_start, int node_end) {
    if (node_start < 0 && node_start >= node_count)
      throw 1;
    if (node_end < 0 && node_end >= node_count)
      throw 2;
  }

public:
  explicit Graph(int num_nodos) {
    node_count = num_nodos;

    matriz = new int *[num_nodos];

    for (int i = 0; i < num_nodos; ++i) {
      matriz[i] = new int[num_nodos];
      for (int j = 0; j < num_nodos; ++j) {
        matriz[i][j] = 0;
      }
    }
  }
  void setEdge(int node_start, int node_end, int weight) {
    validate(node_start, node_end);
    matriz[node_start][node_end] = weight;
  }

  void clearEdge(int node_start, int node_end) {
    setEdge(node_start, node_end, 0);
  }

  int getEdge(int node_start, int node_end) {
    validate(node_start, node_end);
    return matriz[node_start][node_end];
  }
};

#endif // U07_GRAFOS_GRAFO_GRAPH_H_

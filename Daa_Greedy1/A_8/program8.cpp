//Topological Sort Using DFS
#include<iostream>
#include<list>
#include<stack>
#include<cstring>
#include<iomanip> // for setting precision
#include<sys/time.h> //for implementing timeval
#include<cstring>
#include<chrono>
using namespace std::chrono;
using namespace std;

class Graph
{
public:
  int numV; //number of vertices in graph
  list<int> *prtArr;//pointer to an array of adjacency list
public:
  Graph(int numV);
  void insertEdge(int v, int w);
  void topologicalSort();
  void topologicalSortProcedure(int v, bool visited[], stack<int> &stack); //procedure which uses DFS
};

//initialize graph
Graph::Graph(int numV){
  this->numV = numV;
  prtArr = new list<int>[numV]; //array of adjacency list
}

void Graph::insertEdge(int v, int w){
  prtArr[v].push_back(w);
}

void Graph::topologicalSort()
{
  stack<int> stack;
  bool *visited = new bool[numV];
  for(int i=0;i<numV;i++){
    visited[i] = false;
  }
  for(int i=0;i<numV;i++){
    if(visited[i] == false){
      topologicalSortProcedure(i,visited,stack);
    }
  }
  while(stack.empty() == false){
    cout << stack.top() << " ";
    stack.pop();
  }
  cout << "\n";
}

void Graph::topologicalSortProcedure(int v, bool visited[], stack<int> &stack)
{
  visited[v] = true;
  list<int>::iterator itr;
  for(itr = prtArr[v].begin(); itr != prtArr[v].end(); itr++){
    if(visited[*itr] == false){
      topologicalSortProcedure(*itr, visited, stack);
    }
  }
  stack.push(v);//push the vertex only after applying topologicalSort on all its adjacent vertices
}


int main(void)
{
    
    	Graph G(5); 
  	G.insertEdge(4, 0); //add the edges to form adjacency list
  	G.insertEdge(4, 1);
  	G.insertEdge(0, 3);
  	G.insertEdge(1, 2);
  	G.insertEdge(2, 3);
  	G.insertEdge(1, 3);


    cout << "Topological Sort of the Given Graph \n";
    auto start1 = high_resolution_clock::now();
    G.topologicalSort();
    auto stop1 = high_resolution_clock::now(); 
    auto duration1 = duration_cast<microseconds>(stop1 - start1);
    cout << "\nTime taken by Normal quick sort: "<< duration1.count() << " Microseconds" << endl;
    return 0;
}

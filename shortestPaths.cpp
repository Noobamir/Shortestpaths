  #include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

struct Edge{
   int weight;
   char terminalNode;
};

struct InitialNode{
   char name;
   vector<Edge> adjacencyList;
};

struct Graph{
   bool graphType;
   vector<InitialNode> nodeList;
};


void Dijkstra(Graph g);


int main(int argc, char *argv[]){

   ifstream fin;
   char* fileName = argv[1];
   Graph graph;
   graph.graphType = false;
   bool gotGraphType = false;

   fin.open(fileName);
   if(fin.is_open()){
      cout << fileName << " opened successfully!" << endl;
   }
   else{
      cout << fileName << " failed to open." << endl;
   }

   fin.seekg(0, fin.end);
   int fileLength = fin.tellg();
   fin.seekg(0, fin.beg);

   while(fin.tellg() != fileLength){
      char c = fin.peek();

      if(c == '#'){
         fin.ignore(256, '\n');
      }
      else if(gotGraphType == false && c != '#'){
         if(c == 'D'){
            graph.graphType = true;
            fin.ignore(256, '\n');
            gotGraphType = true;
         }
         if(c == 'U'){
            graph.graphType = false;
            fin.ignore(256, '\n');
            gotGraphType = true;
         }
      }
      else{
         InitialNode tempNode;
         Edge tempEdge;
         fin >> tempNode.name;
         fin >> tempEdge.terminalNode;
         fin >> tempEdge.weight;

         if(graph.nodeList.empty()){
            tempNode.adjacencyList.push_back(tempEdge);
            graph.nodeList.push_back(tempNode);
         }
         else{
            bool duplicate = false;
            for(int i=0; i<graph.nodeList.size(); ++i){
               if(tempNode.name == graph.nodeList[i].name)
                  duplicate = true;
            }
            if(duplicate == false){
               tempNode.adjacencyList.push_back(tempEdge);
               graph.nodeList.push_back(tempNode);
            }
            else
               for(int i = 0; i<graph.nodeList.size(); ++i){
        
                  if(graph.nodeList[i].name == tempNode.name)
                     graph.nodeList[i].adjacencyList.push_back(tempEdge);
            }
         }
         fin.ignore(256, '\n');
      }
   }
   fin.close();

   if(graph.graphType == false)
      cout << "Undirected" << endl;
   if(graph.graphType == true)
      cout << "Directed" << endl;
   for(int i=0; i<graph.nodeList.size(); ++i){
      cout << graph.nodeList[i].name << ' ';
      for(int j=0; j<graph.nodeList[i].adjacencyList.size(); ++j){
         cout << graph.nodeList[i].adjacencyList[j].terminalNode << ' ';
         cout << graph.nodeList[i].adjacencyList[j].weight << endl;
      }

   }

   Dijkstra(graph);
   return 0;
}

void Dijkstra(Graph g){
   Node source = g.nodeList[0];
   Node nextNode;
   int currentMin;
   for(int i = 0; i < g.nodeList.size(); ++i){
      for(j = 0; j < g.nodeList[i].adjacencyList.size(); ++j)

   }
   cout << "Dijkstra" << endl;
   cout << "Source : " << source.name << endl;
   cout << "End Dijkstra" << endl;
}

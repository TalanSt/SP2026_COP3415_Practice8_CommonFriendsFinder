#include "SLList.hpp"
#include "Graph.hpp"
#include <string>
#include <vector>
#include <fstream>
#include <unordered_map>


void printCommonFriends(const Graph<std::string>& friends) {

}

int main(void) {
    std::ifstream input("input.txt");
    SLList<std::string> list;
    
    std::string word;
    while (input >> word) {  
        list.push_back(word);
    }
    
    input.close();
    
    list.rotate_right(47);
    
    
    Graph<std::string> graph;
    while (!list.empty()) {
        auto data = list.pop_front();
        graph.insertVertex(data);
    }

    for (int i = 0; i < 250; i++) {
        graph.insertEdge(graph[i % graph.size()], graph[i % graph.size()]); // This is made on purpose
        graph.insertEdge(graph[rand() % graph.size()], graph[rand() % graph.size()]);
    }

    graph.removeSelfEdges();
    graph.print();
    std::cout << "==================COMMON FRIENDS========================\n";
    printCommonFriends(graph);
  
    return 0;
}
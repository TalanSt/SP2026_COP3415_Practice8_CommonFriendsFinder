#include "SLList.hpp"
#include "Graph.hpp"
#include <string>
#include <vector>
#include <fstream>
#include <unordered_map>


void printCommonFriends(const Graph<std::string>& Friends) {
    for(int i = 0; i < Friends.size()-1; ++i) {
        for (int q = i+1; q < Friends.size(); ++q) {
            std::string A = "";
            for (int j = 0; j < Friends.edges[i].size(); ++j) {
                for (int k = 0; k < Friends.edges[q].size(); ++k) {
                    if (Friends.edges[i][j] == Friends.edges[q][k]) {
                        A += Friends[Friends.edges[i][j]];
                        A += " ";
                    }
                }
            }
            if (A != "") {
                std::cout << Friends[i] << " and " << Friends[q] << " common friends : ";
                std::cout << A;
                std::cout << std::endl;
            }
        }
    }
}

int main(void) {
    std::ifstream input("input.txt");
    SLList<std::string> list;
    
    std::string word;
    while (input >> word) {  
        list.push_back(word);
    }
    
    input.close();
    
    //list.rotate_right(47);
    
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
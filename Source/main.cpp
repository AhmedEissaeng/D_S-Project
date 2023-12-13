#include <iostream>
#include <fstream>
#include "visualization.h"

int main()
{
    std::vector<User> users = {
        {"1", "Ahmed Ali", {"2", "3"}},
        {"2", "Yasser Ahmed", {"1"}},
        {"3", "Mohamed Sherif", {"1"}},
        {"4", "Ahmed Khamis", {"1", "2", "3"}},
    };

    std::ofstream dotFile("graph.dot");
    generateDOT(users, dotFile);
    dotFile.close();

    system("dot -Tpng graph.dot -o graph.png");
    std::cout << "Graph visualization completed. Check the graph.png file." << std::endl;

    return 0;
}

#include "visualization.h"
#include <iostream>
using namespace std;

void generateDOT(const std::vector<User> &users, std::ofstream &dotFile)
{
    dotFile << "digraph myGraph {\n";

    for (const auto &user : users)
    {
        dotFile << "    " << user.id << " [label=\"" << user.name << "\"];\n";

        for (const auto &followerId : user.followers)
        {
            dotFile << "    " << followerId << " -> " << user.id << ";\n";
        }
    }

    dotFile << "}\n";
}

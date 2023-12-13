#ifndef VISUALIZATION_H
#define VISUALIZATION_H

#include <vector>
#include <string>
#include <fstream>

struct User
{
    std::string id;
    std::string name;
    std::vector<std::string> followers;
};

void generateDOT(const std::vector<User> &users, std::ofstream &dotFile);

#endif // VISUALIZATION_H

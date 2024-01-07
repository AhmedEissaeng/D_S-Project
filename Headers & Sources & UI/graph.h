#ifndef GRAPH_H
#define GRAPH_H

#include <QString>
#include <QTextStream>
#include <QFile>
#include <QMessageBox>
#include <QDebug>
#include <algorithm>
#include <vector>

#include "User.h"
#include "Post.h"

#define NULL_EDGE 0

using namespace std;

class Graph {
private:
    int userNum;
    int vertexNum;
    vector<User> vertices;
    vector<std::vector<bool>> edges;
    vector<bool> visited;

public:
    Graph(int userNum);
    ~Graph();

    void addUser(User user);
    int getIndex(QString id);
    int getUserNum();
    User getUser(int index);
    User getUser(QString id);
    void addEdge(QString fromId, QString toId);
    bool getWeight(QString fromId, QString toId);
    void markVertex(QString id);
    void clearMark(QString id);
    bool isMarked(QString id);
    void build_graph(QString filename);
    User mostInfluencerUser();
    User mostActiveUser();
    vector<User> mutualFollowers(QString idUser1, QString idUser2);
    vector<User> followSuggestion(QString iD);
    vector<Post> post_search(QString word);
    void generateDOT(QString fileName);
};

#endif

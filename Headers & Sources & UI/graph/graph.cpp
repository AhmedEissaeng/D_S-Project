#include "graph.h"


   Graph::Graph(int userNum){
        vertexNum = 0;
        this -> userNum = userNum;
        vertices.resize(userNum);
        edges.resize(userNum, vector<bool>(userNum));
        visited.resize(userNum);
        for(int i = 0; i < userNum; i++){
            visited[i] = NULL_EDGE;
        }
        for (int i = 0; i < userNum; i++) {
            for (int j = 0; j < userNum; j++) {
                edges[i][j] = NULL_EDGE;
            }
        }
    }

    Graph::~Graph(){
        vertices.clear();
        edges.clear();
        visited.clear();
    }

    void Graph::addUser(User user) {
        vertices[vertexNum] = user;
        //Initialize edges for the new user
        for (int index = 0; index < vertexNum; index++) {
            edges[vertexNum][index] = NULL_EDGE;
            edges[index][vertexNum] = NULL_EDGE;
        }
        vertexNum++;
    }

    int Graph::getIndex(QString id){
        for(int index = 0; index < vertexNum; index++){
            if(vertices[index].getId() == id)
                return index;
        }
        return -1;
    }

    int Graph::getUserNum(){
        return vertexNum;
    }

    User Graph::getUser(int index){
        return vertices[index];
    }

    User Graph::getUser(QString id){
        int index = getIndex(id);
        return vertices[index];

    }

    void Graph::addEdge(QString fromId, QString toId){
        int row = getIndex(fromId);
        int col = getIndex(toId);
        edges[row][col] = 1;

    }

    bool Graph::getWeight(QString fromId, QString toId){
        int row = getIndex(fromId);
        int col = getIndex(toId);
        return edges[row][col];
    }

    void Graph::markVertex(QString id){
        int index = getIndex(id);
        visited[index] = 1;
    }

    void Graph::clearMark(QString id){
        int index = getIndex(id);
        visited[index] = 0;
    }

    bool Graph::isMarked(QString id){
        int index = getIndex(id);
        return visited[index];
    }

    void Graph::build_graph(QString filename){
        QTextStream in(&filename);
        QString line;
        while(!in.atEnd())
        {
            line = in.readLine();
            if(line.contains("<user>"))
            {
                User user;
                line = in.readLine();
                if(line.contains("<id>"))
                {
                    line = in.readLine();
                    QString id = line;
                    user.setId(id);
                    line = in.readLine();
                    line = in.readLine();
                }
                if(line.contains("<name>"))
                {
                    line = in.readLine();
                    QString name = line;
                    user.setName(name);
                    line = in.readLine();
                    line = in.readLine();
                }
                if(line.contains("<posts>"))
                {
                    while(!(line.contains("</posts>")))
                    {
                        line = in.readLine();
                        if(line.contains("<post>"))
                        {
                            Post post;
                            line = in.readLine();
                            if(line.contains("<body>"))
                            {
                                line = in.readLine();
                                post.setBody(line);
                                line = in.readLine();
                                line = in.readLine();
                            }
                            if(line.contains("<topics>"))
                            {
                                while(!(line.contains("</topics>")))
                                {
                                    line = in.readLine();
                                    if(line.contains("<topic>"))
                                    {
                                        line = in.readLine();
                                        post.setTopic(line);
                                    }
                                }
                            }
                            user.setPosts(post);
                        }
                    }
                    line = in.readLine();
                }
                if(line.contains("<followers>"))
                {
                    while(!(line.contains("</followers>")))
                    {
                        line = in.readLine();
                        if(line.contains("<follower>"))
                        {
                            line = in.readLine();
                            if(line.contains("<id>"))
                            {
                                line = in.readLine();
                                user.setFollowers(line);
                            }
                        }
                    }
                }
                this -> addUser(user);
            }
        }
        for(int i = 0; i < userNum; i++)
        {
            vector<QString> follow = this -> getUser(i).getFollowers();
            for(int j = 0; j < userNum; j++)
            {
                for(int w = 0; w < follow.size(); w++)
                {
                    if(follow[w] == this->getUser(j).getId())
                        addEdge(this->getUser(i).getId(),this->getUser(j).getId());
                }
            }
        }
    }

    vector<Post> Graph::post_search(QString word) {
        vector<Post> all_posts;
        vector<Post> list_posts;
        for (int i = 0; i < userNum; i++) {
            for (auto po : this->getUser(i).getPosts()) {
                all_posts.push_back(po);
            }
        }
        for (auto p : all_posts) {
            if (word.isEmpty() || word.trimmed().isEmpty())
                continue;
            if (p.getBody().contains(word)) {
                list_posts.push_back(p);
                continue;
            }
            for (auto to : p.getTopic()) {
                if (to.contains(word)) {
                    list_posts.push_back(p);
                    break;
                }
            }
        }
        return list_posts;
    }

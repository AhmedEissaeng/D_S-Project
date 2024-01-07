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
User Graph::mostInfluencerUser(){
        int index=0;
        int MaxFollowerNum=0;
        for(int i = 0; i< vertexNum; i++){
            int followersNum = getUser(i).getFollowers().size();
            if( MaxFollowerNum < followersNum){
                MaxFollowerNum = followersNum;
                index = i;
            }
        }
        return getUser(index);
    }

    User Graph::mostActiveUser(){
        int index = 0, MaxNumOfAppeareance = 0;
        for(int i = 0; i < vertexNum; i++){
            int NumOfAppeareance=0;
            for(int j = 0; j < vertexNum; j++){
                NumOfAppeareance += edges[j][i];
            }
            if(MaxNumOfAppeareance < NumOfAppeareance){
                MaxNumOfAppeareance = NumOfAppeareance;
                index=i;
            }
        }
        return getUser(index);
    }

    vector<User> Graph::mutualFollowers(QString idUser1, QString idUser2){
        int index1 = getIndex(idUser1);
        int index2 = getIndex(idUser2);
        vector<User> mutualUsers;
        for(int i = 0; i < vertexNum; i++){
            if(i==index1 || i==index2)
                continue;
            if(edges[index1][i] && edges[index2][i])
                mutualUsers.push_back(getUser(i));
        }
        if(mutualUsers.size() == 0)
            qDebug() << "User:" << getUser(idUser1).getName() << " has no mutual followers with " << "User:" << getUser(idUser2).getName() << '\n';
        return mutualUsers;
    }

    vector<User> Graph::followSuggestion(QString iD){
        vector<QString> followers;
        vector<User> suggested_followers;
        User u = getUser(iD);
        vector<QString> u_followers = u.getFollowers();
        User temp;
        for (int i = 0; i < u_followers.size(); i++)
        {
            temp = getUser(u_followers[i]);
            vector<QString> temp_followers = temp.getFollowers();
            for (int j = 0; j < temp_followers.size(); j++)
            {
                if (u.getId() != temp_followers[j])
                    followers.push_back(temp_followers[j]);
            }
        }

        sort(followers.begin(), followers.end());
        followers.erase(unique(followers.begin(), followers.end()), followers.end());

        for (int i = 0; i < followers.size(); i++)
        {
            suggested_followers.push_back(getUser(followers[i]));
        }
        return suggested_followers;
    }
void Graph::generateDOT(QString fileName){
        QFile dotFile(fileName);
        if (!dotFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QMessageBox msgwarning;
            msgwarning.setText("Unable to open file for writing DOT representation.");
            msgwarning.setIcon(QMessageBox::Warning);
            msgwarning.setWindowTitle("Error");
            msgwarning.exec();
        }
        QTextStream out(&dotFile);
        out << "digraph myGraph {\n";
        // Write vertices
        for (int i = 0; i < vertexNum; ++i) {
            out << "  " << vertices[i].getId() << " [label=\"" << vertices[i].getId() << "\"];\n";
        }

        // Write edges
        for (int i = 0; i < vertexNum; ++i) {
            for (int j = 0; j < vertexNum; ++j) {
                if (edges[i][j] != NULL_EDGE) {
                    out << "  " << vertices[i].getId() << " -> " << vertices[j].getId() << ";\n";
                }
            }
        }
        out << "}\n";
        dotFile.close();
        qDebug() << "DOT representation generated in file: " << fileName << '\n';
    }

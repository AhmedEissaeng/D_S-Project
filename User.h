#ifndef USER_H
#define USER_H

#include <QString>
#include <vector>
#include "Post.h"

using namespace std;

class User {
private:
    QString id;
    QString name;
    vector<QString> followers;
    vector<Post> posts;

public:
    User(QString id, QString name, QString follower, Post post);

    User();

    QString getId();
    QString getName();
    vector<QString> getFollowers();
    vector<Post> getPosts();

    void setId(QString id);
    void setName(QString name);
    void setFollowers(QString follower);
    void setPosts(Post post);
};

#endif

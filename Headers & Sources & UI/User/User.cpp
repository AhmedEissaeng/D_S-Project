#include "User.h"
#include <vector>
#include <QString>
#include "Post.h"

using namespace std;

User::User(QString id, QString name, QString follower, Post post) {
    this->id = id;
    this->name = name;
    this->followers.push_back(follower);
    this->posts.push_back(post);
}

User::User() {
    this->id = "";
    this->name = "";
}

QString User::getId() {
    return this->id;
}

QString User::getName() {
    return this->name;
}

vector<QString> User::getFollowers() {
    return this->followers;
}

vector<Post> User::getPosts() {
    return this->posts;
}

void User::setId(QString id) {
    this->id = id;
}

void User::setName(QString name) {
    this->name = name;
}

void User::setFollowers(QString follower) {
    this->followers.push_back(follower);
}

void User::setPosts(Post post) {
    this->posts.push_back(post);
}

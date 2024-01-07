#include "Post.h"
#include <vector>
#include <QString>

using namespace std;

Post::Post(QString body, QString topic) {
    this->body = body;
    this->topic.push_back(topic);
}

Post::Post() {
    this->body = "";
}

QString Post::getBody() {
    return this->body;
}

vector<QString> Post::getTopic() {
    return this->topic;
}

void Post::setBody(QString body) {
    this->body = body;
}

void Post::setTopic(QString topic) {
    this->topic.push_back(topic);
}

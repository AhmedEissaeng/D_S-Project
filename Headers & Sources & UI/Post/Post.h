#ifndef POST_H
#define POST_H

#include <QString>
#include <vector>

class Post {
private:
    QString body;
    std::vector<QString> topic;

public:
    Post(QString body, QString topic);
    Post();
    QString getBody();
    std::vector<QString> getTopic();
    void setBody(QString body);
    void setTopic(QString topic);
};

#endif


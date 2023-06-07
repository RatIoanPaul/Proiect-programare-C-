#ifndef POST_H
#define POST_H

#include <string>

class Post {
protected:
    int id;
    std::string author;
    std::string content;

public:
    Post(int id, const std::string& author, const std::string& content);
    virtual ~Post() = default;

    int getId() const;
    std::string getAuthor() const;
    std::string getContent() const;
    virtual void display() const = 0;
};

#endif

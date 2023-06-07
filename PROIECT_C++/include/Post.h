#ifndef POST_H
#define POST_H

#include <string>

class Post {
protected:
    int id;
    std::string author;
    std::string content;
    std::string title;

public:
    Post(const int id, const std::string& author, const std::string& content,const std::string& title);
    Post(int id, const std::string& author, const std::string& content);
    virtual ~Post() = default;

    int getId() const;
    std::string getAuthor() const;
    std::string getContent() const;
    std::string getTitle() const;
    void setTitle(std::string&);
    void setAuthor(std::string&);
    void setContent(std::string&);
    virtual void display() const = 0;
};

#endif

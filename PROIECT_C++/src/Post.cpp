#include "post.h"

Post::Post(const int id, const std::string& author, const std::string& content,const std::string& title)
    : id(id), author(author), content(content), title(title){}

Post::Post(int id, const std::string& author, const std::string& content) 
    : id(id), author(author), content(content) {}
int Post::getId() const {
    return id;
}

std::string Post::getAuthor() const {
    return author;
}

std::string Post::getContent() const {
    return content;
}

std::string Post::getTitle() const {
    return title;
}

void Post::setAuthor(std::string& author) {
    this->author = author;
}

void Post::setContent(std::string& content) {
    this->content = content;
}

void Post::setTitle(std::string& title) {
    this->title = title;
}

#include "post.h"

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

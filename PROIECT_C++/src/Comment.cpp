#include "comment.h"
#include <iostream>

Comment::Comment(int id, const std::string& author, const std::string& content, int articleId)
    : Post(id, author, content), articleId(articleId) {}

int Comment::getArticleId() const {
    return articleId;
}

void Comment::display() const {
    std::cout << "ID: " << getId() << std::endl;
    std::cout << "Author: " << getAuthor() << std::endl;
    std::cout << "Content: " << getContent() << std::endl;
    std::cout << "Article ID: " << getArticleId() << std::endl;
}

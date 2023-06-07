#include "article.h"
#include <iostream>

Article::Article(const int id, const std::string& author, const std::string& content, const std::string& title,
                 int like, int love, int dislike)
    : Post(id, author, content, title), like(like), love(love), dislike(dislike) {}

int Article::getLike() const {
    return like;
}

int Article::getLove() const {
    return love;
}

int Article::getDislike() const {
    return dislike;
}

void Article::setLike(int like) {
    this->like = like;
}

void Article::setLove(int love) {
    this->love = love;
}

void Article::setDislike(int dislike) {
    this->dislike = dislike;
}

void Article::display() const {
    std::cout << "ID: " << getId() << std::endl;
    std::cout << "Title: " << getTitle() << std::endl;
    std::cout << "Author: " << getAuthor() << std::endl;
    std::cout << "Content: " << getContent() << std::endl;
    std::cout << "Likes: " << getLike() << std::endl;
    std::cout << "Love: " << getLove() << std::endl;
    std::cout << "Dislikes: " << getDislike() << std::endl;
}

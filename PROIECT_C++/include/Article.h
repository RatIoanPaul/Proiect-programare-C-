#ifndef ARTICLE_H
#define ARTICLE_H

#include "post.h"

class Article : public Post {
private:
    int like;
    int love;
    int dislike;

public:
    Article(const int id, const std::string& author, const std::string& content, const std::string& title,
            int like, int love, int dislike);

    int getLike() const;
    int getLove() const;
    int getDislike() const;

    void setLike(int like);
    void setLove(int love);
    void setDislike(int dislike);

    void display() const override;
};

#endif

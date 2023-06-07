#ifndef COMMENT_H
#define COMMENT_H

#include "post.h"

class Comment : public Post {
private:
    int articleId;

public:
    Comment(int id, const std::string& author, const std::string& content, int articleId);

    int getArticleId() const;

    void display() const override;
};

#endif

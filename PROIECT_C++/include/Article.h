#include <Post.h>

#ifndef ARTICLE_H
#define ARTICLE_H


class Article : Post
{
    public:
        Article();
        Article(int like, int love, int dislike, Post post);
        virtual ~Article();
        setLike(int like);
        getLike();

    protected:

    private:
        int like;
        int love;
        int dislike;
        Post post;
};

#endif // ARTICLE_H

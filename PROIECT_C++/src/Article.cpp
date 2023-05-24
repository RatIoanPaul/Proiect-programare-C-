#include "Article.h"

Article::Article()
{
    //ctor
}

Article::Article(int like, int love, int dislike, Post post)
{
    this->like = like;
    this->love = love;
    this->dislike = dislike;
    this->post = post;
}

Article::~Article()
{
    //dtor
}

Article::setLike(int like)
{
    this->like = like;
}

Article::getLike()
{
    return this->like;
}

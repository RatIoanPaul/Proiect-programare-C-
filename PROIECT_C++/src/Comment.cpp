#include "Comment.h"
#include "Comment.h"

Comment::Comment()
{
    //ctor
}

Comment::~Comment()
{
    //dtor
}

Comment::Comment(int articleId, Post post)
{
    this->articleId = articleId;
    this->post = post;
}

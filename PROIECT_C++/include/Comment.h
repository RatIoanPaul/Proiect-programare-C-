#ifndef COMMENT_H
#define COMMENT_H


class Comment
{
    public:
        Comment();
        Comment(int articleId, Post post);
        virtual ~Comment();

    protected:

    private:
        int articleId;
        Post post;
};

#endif 

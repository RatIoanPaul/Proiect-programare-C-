#include <string>

#ifndef POST_H
#define POST_H

class Post
{
    public:
        virtual ~Post();
        

    protected:

    private:
        int id;
        std::string author;
        std::string content;
};

#endif

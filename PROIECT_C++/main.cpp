#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <windows.h>
#include <sstream>

#include "Article.h"
#include "Comment.h"

static std::vector<Article> articles;
static std::vector<Comment> comments;

void updateArticleFile(std::vector<Article> newArticles)
{
    std::ofstream file("data/article_data.txt");
    if (file.is_open())
    {
        for (int i = 0; i < newArticles.size(); i++)
        {
            file << newArticles[i].getId() << std::endl;
            file << newArticles[i].getAuthor() << std::endl;
            file << newArticles[i].getTitle() << std::endl;
            file << newArticles[i].getContent() << std::endl;
            file << newArticles[i].getLike() << std::endl;
            file << newArticles[i].getLove() << std::endl;
            file << newArticles[i].getDislike() << std::endl;
        }
        file.close();
    }
    else
    {
        std::cerr << "Error opening the file." << std::endl;
        return;
    }
}

void updateCommentFile() {
    std::ofstream file("data/comment_data.txt");
    
}

void addArticle()
{
    std::string author, title, content;
    std::cout << "title: " << std::endl;
    std::cin >> title;

    std::cout << "content: " << std::endl;
    std::cin >> content;

    std::cout << "author: " << std::endl;
    std::cin >> author;

    int id = 0;
    for (int i = 0; i < articles.size(); i++)
    {
        if (articles[i].getId() >= id)
        {
            id = articles[i].getId() + 1;
        }
    }
    Article article(id, author, title, content, 0, 0, 0); // Swap title and content arguments
    articles.push_back(article);
    updateArticleFile(articles);
}

void deleteArticle(const int id)
{
    std::vector<Article> copyArticles;
    std::cout << "deleting article begin" << std::endl;
    for (int i = 0; i < articles.size(); i++)
    {
        if (articles[i].getId() == id)
        {
            continue;
        }
        copyArticles.push_back(articles[i]);
    }
    std::cout << "deleting article end" << std::endl;
    updateArticleFile(copyArticles);
}

void editArticle(int id)
{
    std::cout << "editing article begin" << std::endl;
    std::string author, title, content;
    std::cout << "title: " << std::endl;
    std::cin >> title;

    std::cout << "content: " << std::endl;
    std::cin >> content;

    std::cout << "author: " << std::endl;
    std::cin >> author;

    for (int i = 0; i < articles.size(); i++)
    {
        if (articles[i].getId() == id)
        {
            articles[i].setAuthor(author);
            articles[i].setTitle(title);
            articles[i].setContent(content);
            break;
        }
    }
    std::cout << "editing article end" << std::endl;
    updateArticleFile(articles);
}

void viewArticle()
{
    for (int i = 0; i < articles.size(); i++)
    {
        articles[i].display();
    }
}

void addComment(int id) {
    std::cout << "enter comment content" << std::endl;
    std::string content;
    std::cin >> content;

    std::cout << "enter comment author" << std::endl;
    std::string author;
    std::cin >> author;

    int maxId = 0;
    for (int i = 0; i < comments.size(); i++) {
        if (comments[i].getId() > maxId) {
            maxId = comments[i].getId() + 1;
        }
    }
    Comment comment = Comment(maxId, content, author, id);
    comments.push_back(comment);

}

void performCommand(std::string command)
{
    if (command == "add_article")
    {
        addArticle();
    }
    else if (command == "delete_article")
    {
        std::cout << "provide an article id to delete" << std::endl;
        int id;
        std::cin >> id;
        deleteArticle(id);
    }
    else if (command == "edit_article")
    {
        std::cout << "provide an article id to edit" << std::endl;
        int id;
        std::cin >> id;
        editArticle(id);
    }
    else if (command == "view_article")
    {
        viewArticle();
    } else if (command == "add_comment") {
        std::cout << "provide an article id to add comment" << std::endl;
        int id;
        std::cin >> id;
        addComment(id);
    }
}
// Include the <sstream> header for stringstream

void initArticle()
{
    std::vector<std::string> lines;
    std::ifstream file("data/article_data.txt");
    std::string line;
    if (file.is_open())
    {
        while (std::getline(file, line))
        {
            lines.push_back(line);
        }
        file.close();
    }
    else
    {
        std::cerr << "Error opening the file." << std::endl;
        return;
    }
    for (int i = 0; i < lines.size(); i += 7)
    {
        int id;
        std::stringstream(lines[i]) >> id;
        std::string author = lines[i + 1];
        std::string title = lines[i + 2];
        std::string content = lines[i + 3];
        int like, love, dislike;
        std::stringstream(lines[i + 4]) >> like;
        std::stringstream(lines[i + 5]) >> love;
        std::stringstream(lines[i + 6]) >> dislike;

        Article article = Article(id, author, title, content, like, love, dislike);
        articles.push_back(article);
    }
}

void initComment() {
    std::vector<std::string> lines;
    std::ifstream file("data/comment_data.txt");
    std::string line;
    if (file.is_open())
    {
        while (std::getline(file, line))
        {
            lines.push_back(line);
        }
        file.close();
    }
    else
    {
        std::cerr << "Error opening the file." << std::endl;
        return;
    }

    for (int i = 0; i < lines.size(); i += 4)
    {

        int id;
        std::stringstream(lines[i]) >> id;
        std::string content = lines[i + 1];
        std::string author = lines[i + 2];

        int articleId;
        std::stringstream(lines[i + 3]) >> articleId;
        Comment comment = Comment(id, content, author, articleId);
        comments.push_back(comment);
    }
}

int main(int argc, char **argv)
{
    initArticle();
    initComment();
    std::string command;
    std::cout << "Enter command:" << std::endl;
    std::cin >> command;
    performCommand(command);
    return 0;
}

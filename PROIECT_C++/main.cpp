#include <iostream>
#include <string>
#include <vector>
#include <fstream>


void addArticle(std::string author, std::string content, std::string title) {
    std::ofstream file;
    file.open("article_data.txt");
    file << author << std::endl;
    file << content << std::endl;
    file << title << std::endl;
    file << "0" << std::endl;
    file << "0" << std::endl;
    file << "0" << std::endl;
    file.close();
}
void performCommand(std::string command, std::vector<std::string> args) {
    if (command == "add_article") {
        if (args.size() < 3) {
            std::cout << "Not enough arguments" << std::endl;
        }
        else {
            addArticle(args[0], args[1], args[2]);
        }
    }
}

int main(int argc, char** argv) {
    std::cout << argc << argv[0] << std::endl;
    if (argc < 2) {
        std::cout << "No arguments provided" << std::endl;
    }
    else {
        std::string command = argv[2];
        std::vector<std::string> args;
        for (int i = 3; i < argc; i++) {
            args.push_back(argv[i]);
        }
        performCommand(command, args);
    }
    return 0;
}

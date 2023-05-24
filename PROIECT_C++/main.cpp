#include <iostream>
#include <Article.h>

using namespace std;

int main(){
    Article a;
    a.setLike(10);
    std::cout << a.getLike() << std::endl;


    return 0;
}

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

//To stop browser caching, this is the way apparently: https://stackoverflow.com/questions/16716695/prevent-caching-of-html-page
using namespace std;

int main() {
    srand(time(0));
    
    int num1 = rand() % 1000 + 1;
    int num2 = rand() % 1000 + 1;
    
    //more consistent than if
    while (num1 == num2) 
    {
        num2 = rand() % 1000 + 1;
    }

    string Page1, Page2;
    if (num1 > num2) 
    {
        Page1 = "/right.htm";
        Page2 = "/wrong.htm";
    } 
    
    else 
    {
        Page1 = "/wrong.htm";
        Page2 = "/right.htm";
    }

    //sending doc type info, and anti caching info 
    cout << "Content-type: text/html\n\n";
    cout << "<!DOCTYPE html>\n";
    cout << "<html lang=\"en\">\n";
    cout << "<head>\n";
    cout << "<meta http-equiv=\"Cache-Control\" content=\"no-store\">\n";
    
    //content of page
    cout << "<title>Number Game</title>\n";
    cout << "</head>\n";
    cout << "<body>\n";
    cout << "<h1>Which number is larger?</h1>\n";
    cout << "<p>Click on the larger number below:</p>\n";
    
    cout << "<h2>\n";
    cout << "<a href=\"" << Page1 << "\">" << num1 << "</a> &nbsp;\n";
    cout << "<a href=\"" << Page2 << "\">" << num2 << "</a>\n";
    cout << "</h2>\n";
    
    cout << "</body>\n";
    cout << "</html>\n";

    return 0;
}
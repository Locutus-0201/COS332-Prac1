#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int main() {
    // Seed the random number generator
    srand(time(0));
    
    // Generate two distinct random numbers between 1 and 100
    int num1 = rand() % 100 + 1;
    int num2 = rand() % 100 + 1;
    
    // Make sure they aren't the exact same number
    while (num1 == num2) 
    {
        num2 = rand() % 100 + 1;
    }

    // Figure out which link goes to which number
    string link1, link2;
    if (num1 > num2) 
    {
        link1 = "/right.htm";
        link2 = "/wrong.htm";
    } 
    else 
    {
        link1 = "/wrong.htm";
        link2 = "/right.htm";
    }

    // Print the crucial HTTP header followed by TWO blank lines
    cout << "Content-type: text/html\n\n";

    // Print the HTML page structure
    cout << "<!DOCTYPE html>\n";
    cout << "<html lang=\"en\">\n";
    cout << "<head>\n";
    cout << "    <meta charset=\"UTF-8\">\n";
    
    // Anti-caching tags to ensure the browser loads a fresh game every time
    cout << "    <meta http-equiv=\"Cache-Control\" content=\"no-cache, no-store, must-revalidate\">\n";
    cout << "    <meta http-equiv=\"Pragma\" content=\"no-cache\">\n";
    cout << "    <meta http-equiv=\"Expires\" content=\"0\">\n";
    
    cout << "    <title>Number Game</title>\n";
    cout << "</head>\n";
    cout << "<body>\n";
    cout << "    <h1>Which number is larger?</h1>\n";
    cout << "    <p>Click on the larger number below:</p>\n";
    
    // Print the numbers as hyperlinks
    cout << "    <h2>\n";
    cout << "        <a href=\"" << link1 << "\">" << num1 << "</a> &nbsp; &nbsp; &nbsp;\n";
    cout << "        <a href=\"" << link2 << "\">" << num2 << "</a>\n";
    cout << "    </h2>\n";
    
    cout << "</body>\n";
    cout << "</html>\n";

    return 0;
}
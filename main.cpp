#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::string pa = R".mahmoud.(
   <html>

   <body>
     <h1>Hello Mahmood</h1>
     <button>Click Me!</button>
   </body>

   </html>
        ).mahmoud.";
    std::ofstream ss("Reda.html");
    ss << pa;
    ss.close();
    std::cout << pa;
}
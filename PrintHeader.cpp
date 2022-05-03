#include "PrintHeader.h"
#include "Figlet.h"

int print(std::string header)
{
    Figlet figlet(FigletFont::make("Fonts/Standard.flf"), Smushed::make());

    std::cout << figlet(header);

    return 0;
}
#include <stdlib.h>
#include <libxml.h>

int main() {
    struct XmlDocument* doc = parseXml("rip bozo.xml");

    return EXIT_SUCCESS;
}
#include <stdlib.h>
#include <libxml.h>

int main() {
    struct XmlDocument* doc = parseXml("dummy.xml");

    return EXIT_SUCCESS;
}
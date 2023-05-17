#include <stdlib.h>
#include <xml.h>

int main() {
    struct XmlDocument* doc = parseXml("dummy.xml");

    XmlNode* taught = doc->root->firstChild->firstChild->firstChild->nextSibling->nextSibling->nextSibling;
    printf("\n\n\nTAG NAME: %s", taught->name);

    return EXIT_SUCCESS;
}
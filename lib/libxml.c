#include "libxml.h"
#include "vec.h"


#include <stdio.h>
#include <malloc.h>
#include <string.h>

struct XmlDocument *parseXml(const char* filename) {
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: could not open file %s", filename);
        return NULL;
    }

    XmlNode* currentNode = malloc(sizeof(XmlNode));
    int c; // might have to be int for EOF
    enum State state = NodeContent;
    Vec content;
    init_vec(&content, 1);

    while ((c = fgetc(file)) != EOF) {
        printf("%c", c);

        if (c == '<') {
            state = NodeStartOrEnd;
            clear_vec(&content);
        } else if (c == '/' && state == NodeStartOrEnd) {
            state = NodeEnd;
        } else if (c == '>' && state == NodeStart) {
            XmlNode node;
            node.name = malloc(sizeof(content.data));
            strcpy(node.name, (const char*)content.data);
            node.content = "";
            node.parent = currentNode;
            node.nextSibling = NULL;
            node.firstChild = NULL;
            currentNode = &node;
            clear_vec(&content);
        } else if (c == '>' && state == NodeEnd) {
            if (strcmp(currentNode->name, (const char*)content.data) != 0) {
                state = NodeContent;
                currentNode = currentNode->parent;
                clear_vec(&content);
            } else {
                printf("Error: closing tag %s does not match opening tag %s", content.data, currentNode->name);
                return NULL;
            }
        } else {
            if (state == NodeStartOrEnd) {
                state = NodeStart;
            }

            append_to(&content, (char*)c);
        }
    }
}

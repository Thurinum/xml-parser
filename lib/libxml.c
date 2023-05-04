#include "libxml.h"



#include <stdio.h>
#include <malloc.h>
#include <string.h>

struct XmlDocument *parseXml(const char* filename) {
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: could not open file %s", filename);
        return NULL;
    }

    struct XmlNode* currentNode;
    int c; // might have to be int for EOF
    enum State state = NodeContent;
    char content[] = "";

    while ((c = fgetc(file)) != EOF) {
        if (c == '<') {
            state = NodeStartOrEnd;
            content = "";
        } else if (c == '/' && state == NodeStartOrEnd) {
            state = NodeEnd;
        } else if (c == '>' && state == NodeStart) {
            struct XmlNode* node = malloc(sizeof(struct XmlNode));
            node->name = content;
            node->content = "";
            node->parent = currentNode;
            node->nextSibling = NULL;
            node->firstChild = NULL;
            currentNode->nextSibling = node;
            currentNode = node;
            content = "";
        } else if (c == '>' && state == NodeEnd) {
            if (content == currentNode->name) {
                state = NodeContent;
                currentNode = currentNode->parent;
                content = "";
            } else {
                printf("Error: closing tag %s does not match opening tag %s", content, currentNode->name);
                return NULL;
            }
        } else {
            if (state == NodeStartOrEnd) {
                state = NodeStart;
            }

        }
    }
}

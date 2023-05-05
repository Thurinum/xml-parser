#include "libxml.h"
#include "string.h"


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
    int c;
    enum State state = NodeContent;
    String content;
    init_str(&content, 1);

    while ((c = fgetc(file)) != EOF) {
//        printf("%c", c);

        if (c == '<') {
            printf("Found either a start or end tag\n");
            state = NodeStartOrEnd;
            clear_str(&content);
        } else if (c == '/' && state == NodeStartOrEnd) {
            printf("\tTurns out it's an end tag\n");
            state = NodeEnd;
        } else if (c == '>' && state == NodeStart) {
            printf("Processing start tag <%s>\n", str(&content));
            XmlNode node;
            node.name = str(&content);
            node.content = "";
            node.parent = currentNode;
            node.nextSibling = NULL;
            node.firstChild = NULL;
            currentNode = &node;
            clear_str(&content);
            printf("Now parsing element <%s>\n", currentNode->name);
        } else if (c == '>' && state == NodeEnd) {
            const char* node_name = str(&content);
            printf("Processing end tag <%s>\n", node_name);
            if (strcmp(currentNode->name, node_name) == 0) {
                state = NodeContent;
                currentNode = currentNode->parent;
                clear_str(&content);
            } else {
                printf("ERROR: Closing tag <%s> does not match opening tag <%s>", node_name, currentNode->name);
                return NULL;
            }
        } else {
            if (state == NodeStartOrEnd) {
                printf("\tTurns out it's a start tag\n");
                state = NodeStart;
            }

            append_to(&content, (char)c);
        }
    }

    free_str(&content);
    fclose(file);
    return NULL;
}

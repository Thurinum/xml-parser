#include "xml.h"
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

    XmlNode* root = malloc(sizeof(XmlNode));
    XmlNode* currentNode = NULL;

    int c;
    enum State state = NodeContent;
    String content;
    init_str(&content, 1);

    while ((c = fgetc(file)) != EOF) {
        if (c == '<') {
            printf("Found ");
            state = NodeStartOrEnd;
            clear_str(&content);
        } else if (c == '/' && state == NodeStartOrEnd) {
            printf("end tag\n");
            state = NodeEnd;
        } else if (c == '>' && state == NodeStart) {
            printf("\tParsing start tag <%s>\n", str(&content));

            XmlNode* node = malloc(sizeof(XmlNode));
            node->name = str(&content);
            node->content = "";
            node->parent = NULL;
            node->nextSibling = NULL;
            node->firstChild = NULL;

            if (currentNode)
                node->parent = currentNode;
            else {
                root = node;
            }

            if (currentNode && currentNode->firstChild == NULL) {
                currentNode->firstChild = node;
            }

            currentNode = node;
            clear_str(&content);

            if (currentNode->parent) {
                printf("\tNow parsing element <%s> with parent <%s>\n", node->name, currentNode->parent->name);
            } else {
                printf("\tNow parsing root element <%s>\n", node->name);
            }
        } else if (c == '>' && state == NodeEnd) {
            const char* node_name = str(&content);
            printf("\tParsing end tag </%s>\n", node_name);
            if (strcmp(currentNode->name, node_name) == 0) {
                state = NodeContent;

                if (currentNode->parent)
                    currentNode = currentNode->parent;
                
                clear_str(&content);
                printf("\tBack to parent <%s>\n", currentNode->name);
            } else {
                printf("ERROR: End tag </%s> does not match start tag <%s>", node_name, currentNode->name);
                return NULL;
            }
        } else {
            if (state == NodeStartOrEnd) {
                printf("start tag\n");
                state = NodeStart;
            }

            append_to(&content, (char)c);
        }
    }

    printf("DONE.\n");
    free_str(&content);
    fclose(file);
    return NULL;
}

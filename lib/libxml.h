#ifndef XML_PARSER_LIBRARY_H
#define XML_PARSER_LIBRARY_H

#include <stdlib.h>
#include <stdio.h>

typedef struct {
    char *name;
    char *content;
    struct XmlNode *parent;
    struct XmlNode *nextSibling;
    struct XmlNode *firstChild;
} XmlNode;

struct XmlDocument {
    char *name;
    char *version;
    char *encoding;
    char *standalone;
    struct XmlNode *root;
};

enum State {
    NodeStartOrEnd,
    NodeStart,
    NodeEnd,
    NodeContent
};

struct XmlDocument *parseXml(const char* filename);

#endif //XML_PARSER_LIBRARY_H

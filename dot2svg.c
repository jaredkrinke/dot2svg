#include <graphviz/gvc.h>

const char* graphString = "digraph { a -> b }";

void dot2svg(const char* dot, char** svg, int* svgLength) {
    GVC_t* context = gvContext();
    if (context) {
        Agraph_t* graph = agmemread(graphString);
        if (graph) {
            if (gvLayout(context, graph, "dot") == 0) {
                gvRenderData(context, graph, "svg", svg, svgLength);
            }
            agfree(graph, NULL);
        }
        gvFreeContext(context);
    }
}

void dot2svg_free(char** svg) {
    gvFreeRenderData(*svg);
    *svg = NULL;
}

int main() {
    char* result;
    int resultLength;
    dot2svg(graphString, &result, &resultLength);
    puts(result);
    dot2svg_free(&result);
    return 0;
}


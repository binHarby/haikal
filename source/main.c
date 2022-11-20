#include <stdio.h>
#include <stdlib.h>

struct node {
    void *data;
    struct node *next;
};

struct node *node_create(void *data, struct node *next) {
    struct node *node = malloc(sizeof(struct node));
    node->data = data;
    node->next = next;
    return node;
}

void node_destroy(struct node *node) {
    node->data = NULL;
    node->next = NULL;
    free(node);
    return;
}

void node_attach(struct node *from, struct node *to) {
    from->next = to;
    return;
}

int main() {
    float pi = 3.141592;
    float n = 1.0;
    float o = 800.56422;

    struct node *head_node = node_create(&pi, NULL);
    struct node *node_00 = node_create(&n, NULL);

    node_attach(head_node, node_00);

    struct node *node_01 = node_create(&o, NULL);
    node_attach(node_00, node_01);

    struct node *node_walker = head_node;
    while(node_walker) {
        printf("%f\n", *(float *)node_walker->data);
        node_walker = node_walker->next;
    }

    node_destroy(node_01);
    node_destroy(node_00);
    node_destroy(head_node);
    return 0;
}

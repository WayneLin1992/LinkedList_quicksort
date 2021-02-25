#include "LinkedList_quicksort.h"

static bool list_is_ordered(node_t *list) {
    bool first = true;
    int value;
    while (list) {
        if (first) {
            value = list->value;
            first = false;
        } else {
            if (list->value < value)
                return false;
            value = list->value;
        }
        list = list->next;
    }
    return true;
}

static void list_display(node_t *list) {
    printf("%s IN ORDER : ", list_is_ordered(list) ? "   " : "NOT");
    while (list) {
        printf("%d ", list->value);
        list = list->next;
    }
    printf("\n");
}

int random(void){
     int a;
    a = rand();
    return a;
}

static void list_free(node_t **list){
    node_t *ptr = *list;
    while(*list){
        ptr = (*list)->next;
        free(*list);
        *list = ptr;
    }
}

static inline node_t* list_make_node_t(node_t *list, int num){
    node_t *p = malloc(sizeof(node_t));
    if(p==NULL){
        return list;
    }else{
        p->value = num;
        p->next = NULL;
        list_add_node_t(&list,p);
    }
    return list;
}

int main(int argc, char **argv) {

    size_t count = 20;

    node_t *list = NULL;
    while (count--)
        list = list_make_node_t(list, random() % 1024);

    list_display(list);
    quicksort(&list);
    list_display(list);

    if (!list_is_ordered(list))
        return EXIT_FAILURE;

    list_free(&list);
    return EXIT_SUCCESS;
}

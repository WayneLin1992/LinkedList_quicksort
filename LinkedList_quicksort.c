#include "LinkedList_quicksort.h"
#include <time.h>

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
/*
int random(void){
     int a;
    a = rand();
    return a;
}
*/
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

void quicksort_nonrecursive(node_t **list){
    node_t *ptr = *list;
    int arr[20] ;
    int j = 0;
    while(ptr){
        arr[j++] = ptr->value;
        ptr = ptr->next;
    }

    int element = 20;

    int  piv, beg[element], end[element], i=0, L, R ;
    beg[0]=0; end[0]=element;
    while (i>=0) {
        L=beg[i]; R=end[i]-1;
        if (L<R) {
          piv=arr[L]; if (i==element-1) return ;
          while (L<R) {
            while (arr[R]>=piv && L<R)
                R--;
            if (L<R)
                arr[L++]=arr[R];
            while (arr[L]<=piv && L<R)
                L++;
            if (L<R)
                arr[R--]=arr[L]; }
          arr[L]=piv;
          beg[i+1]=L+1;
          end[i+1]=end[i];
          end[i++]=L;
          }
        else {
          i--; }
    }
    node_t*ptr1 = *list;
    i = 0;
    while(ptr1){
        ptr1->value = arr[i++];
        ptr1 = ptr1->next;
    }
}

int main(int argc, char **argv) {
    size_t count = 20;
    srandom(time(NULL));
    node_t *list = NULL;
    while (count--)
        list = list_make_node_t(list, random() % 1024);

    list_display(list);
    quicksort_nonrecursive(&list);
//    quicksort(&list);
    list_display(list);

    if (!list_is_ordered(list))
        return EXIT_FAILURE;

    list_free(&list);
    return EXIT_SUCCESS;
}

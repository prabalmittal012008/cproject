#include <stdio.h>
#include <stdlib.h>
#include "fileops.h"
#include "bus.h"

int save_buses_to_file(const char *filename, Bus *head) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) return 0;

    Bus *cur = head;
    while (cur) {
        Bus tmp = *cur;
        tmp.next = NULL;
        if (fwrite(&tmp, sizeof(Bus), 1, fp) != 1) {
            fclose(fp);
            return 0;
        }
        cur = cur->next;
    }

    fclose(fp);
    return 1;
}

Bus* load_buses_from_file(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) return NULL;

    Bus *head = NULL;
    Bus *last = NULL;

    while (1) {
        Bus tmp;
        if (fread(&tmp, sizeof(Bus), 1, fp) != 1) break;
        Bus *node = malloc(sizeof(Bus));
        if (!node) break;
        *node = tmp;
        node->next = NULL;
        if (!head) head = node; else last->next = node;
        last = node;
    }

    fclose(fp);
    return head;
}

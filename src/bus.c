#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bus.h"
Bus* create_bus(int id, const char *route, int total_seats, float fare) {
    Bus *b = (Bus*)malloc(sizeof(Bus));
    if (!b) return NULL;
    b->id = id;
    strncpy(b->route, route, MAX_ROUTE_LEN-1);
    b->route[MAX_ROUTE_LEN-1] = '\0';
    b->total_seats = total_seats;
    b->booked_seats = 0;
    b->fare = fare;
    b->next = NULL;
    return b;
}
void add_bus(Bus **head, Bus *bus) {
    if (!*head) { *head = bus; return; }
    Bus *cur = *head;
    while (cur->next) cur = cur->next;
    cur->next = bus;
}
Bus* find_bus_by_id(Bus *head, int id) {
    Bus *cur = head;
    while (cur) { if (cur->id == id) return cur; cur = cur->next; }
    return NULL;
}
Bus* find_bus_by_route(Bus *head, const char *route) {
    Bus *cur = head;
    while (cur) { if (strstr(cur->route, route)) return cur; cur = cur->next; }
    return NULL;
}
void view_all_buses(Bus *head) {
    if (!head) { printf("No buses available.\n"); return; }
    printf("ID\tRoute\tSeats\tBooked\tFare\n");
    Bus *cur = head;
    while (cur) {
        printf("%d\t%s\t%d\t%d\t%.2f\n",
            cur->id, cur->route, cur->total_seats, cur->booked_seats, cur->fare);
        cur = cur->next;
    }
}
int book_seat(Bus *b) { if (b->booked_seats >= b->total_seats) return 0; b->booked_seats++; return 1; }
int cancel_seat(Bus *b) { if (b->booked_seats <= 0) return 0; b->booked_seats--; return 1; }
int delete_bus(Bus **head, int id) {
    Bus *cur=*head,*prev=NULL;
    while(cur){
        if(cur->id==id){
            if(!prev)*head=cur->next; else prev->next=cur->next;
            free(cur); return 1;
        }
        prev=cur; cur=cur->next;
    }
    return 0;
}
void free_buses(Bus *head) {
    Bus *cur=head;
    while(cur){ Bus *t=cur; cur=cur->next; free(t); }
}

#include <stdio.h>
#include <stdlib.h>
#include "bus.h"
#include "fileops.h"

void menu() {
    printf("\n1 Add Bus\n2 View\n3 Search ID\n4 Search Route\n5 Book\n6 Cancel\n7 Delete\n8 Exit\n");
}

int main() {
    Bus *head = load_buses_from_file(DB_FILENAME);
    int choice;

    while (1) {
        menu();
        printf("Choose: ");
        if (scanf("%d", &choice) != 1) {
            scanf("%*s");
            continue;
        }

        if (choice == 1) {
            int id, seats;
            float fare;
            char route[100];
            printf("ID: ");
            scanf("%d", &id);
            printf("Route (no spaces): ");
            scanf("%99s", route);
            printf("Seats: ");
            scanf("%d", &seats);
            printf("Fare: ");
            scanf("%f", &fare);

            if (find_bus_by_id(head, id)) {
                printf("Bus exists\n");
            } else {
                add_bus(&head, create_bus(id, route, seats, fare));
                printf("Added\n");
            }

        } else if (choice == 2) {
            view_all_buses(head);

        } else if (choice == 3) {
            int id;
            printf("ID: ");
            scanf("%d", &id);
            Bus *b = find_bus_by_id(head, id);
            if (b) {
                printf("%d %s %d %d %.2f\n", b->id, b->route, b->total_seats, b->booked_seats, b->fare);
            } else {
                printf("Not found\n");
            }

        } else if (choice == 4) {
            char route[100];
            printf("Route: ");
            scanf("%99s", route);
            Bus *b = find_bus_by_route(head, route);
            if (b) printf("%d %s\n", b->id, b->route);
            else printf("Not found\n");

        } else if (choice == 5) {
            int id; printf("ID: "); scanf("%d", &id);
            Bus *b = find_bus_by_id(head, id);
            if (b && book_seat(b)) printf("Booked\n"); else printf("Fail\n");

        } else if (choice == 6) {
            int id; printf("ID: "); scanf("%d", &id);
            Bus *b = find_bus_by_id(head, id);
            if (b && cancel_seat(b)) printf("Cancelled\n"); else printf("Fail\n");

        } else if (choice == 7) {
            int id; printf("ID: "); scanf("%d", &id);
            if (delete_bus(&head, id)) printf("Deleted\n"); else printf("Fail\n");

        } else if (choice == 8) {
            save_buses_to_file(DB_FILENAME, head);
            break;

        } else {
            printf("Invalid choice\n");
        }
    }

    free_buses(head);
    return 0;
}

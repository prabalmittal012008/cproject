#ifndef BUS_H
#define BUS_H
#define MAX_ROUTE_LEN 100
#define DB_FILENAME "buses.dat"
typedef struct Bus {
    int id;
    char route[MAX_ROUTE_LEN];
    int total_seats;
    int booked_seats;
    float fare;
    struct Bus *next;
} Bus;
Bus* load_buses_from_file(const char *filename);
int save_buses_to_file(const char *filename, Bus *head);
Bus* create_bus(int id, const char *route, int total_seats, float fare);
void add_bus(Bus **head, Bus *bus);
Bus* find_bus_by_id(Bus *head, int id);
Bus* find_bus_by_route(Bus *head, const char *route);
void view_all_buses(Bus *head);
int book_seat(Bus *b);
int cancel_seat(Bus *b);
int delete_bus(Bus **head, int id);
void free_buses(Bus *head);
#endif

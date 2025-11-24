#ifndef FILEOPS_H
#define FILEOPS_H
#include "bus.h"
Bus* load_buses_from_file(const char *filename);
int save_buses_to_file(const char *filename, Bus *head);
#endif

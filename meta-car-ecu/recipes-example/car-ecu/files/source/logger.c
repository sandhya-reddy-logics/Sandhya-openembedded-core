#include <stdio.h>
#include "logger.h"

void log_message(const char *message)
{
    FILE *log_file;

    log_file = fopen("logs/car.log", "a");
/*
    if (log_file == NULL)
    {
        printf("Error: Unable to open log file.\n");
        return;
    }
*/
    fprintf(log_file, "%s\n", message);

    fclose(log_file);
}

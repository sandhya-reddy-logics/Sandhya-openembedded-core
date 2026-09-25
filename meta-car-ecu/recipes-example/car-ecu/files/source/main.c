#include <stdio.h>

#include "engine_ecu.h"
#include "brake_ecu.h"
#include "body_ecu.h"
#include "hvac_ecu.h"
#include "infotainment_ecu.h"

static void display_vehicle_status(void)
{
    engine_print_status();
    brake_print_status();
    body_print_status();
    hvac_print_status();
    infotainment_print_status();
}

static void initialize_ecus(void)
{
    engine_init();
    brake_init();
    body_init();
    hvac_init();
    infotainment_init();

    printf("All ECUs initialized successfully....\n");
}

static void update_ecus(void)
{
    engine_update();
    brake_update();
    body_update();
    hvac_update();
    infotainment_update();
}

int main(void)
{
    int choice;

    initialize_ecus();

    while (1)
    {
        printf("1. Display ECU Status\n");
        printf("2. Update ECU Data\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");

        scanf("%d",&choice);

        switch (choice)
        {
            case 1:
                display_vehicle_status();
                break;

            case 2:
                update_ecus();
                printf("ECU data updated successfully.\n");
                break;

            case 3:
                printf("Shutting down vehicle ECU system...\n");
                printf("Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}

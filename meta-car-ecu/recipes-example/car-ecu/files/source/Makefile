CC=gcc
CFLAGS= -Wall -Wextra -I../include
BUILD_DIR=../build
TARGET=$(BUILD_DIR)/car_ecu_app
SOURCES=main.c\
	engine_ecu.c\
	brake_ecu.c\
	body_ecu.c\
	hvac_ecu.c\
	infotainment_ecu.c\
	logger.c
OBJECTS=$(SOURCES:%.c=$(BUILD_DIR)/%.o)

.PHONY:all clean rebuild

all:$(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

$(BUILD_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

rebuild: clean
	$(MAKE) all

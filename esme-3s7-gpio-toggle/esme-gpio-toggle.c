#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <gpiod.h>
#include <string.h>

#define DEFAULT_GPIO 26
#define CHIP_PATH "/dev/gpiochip0"

int main(int argc, char *argv[]) {
    int gpio = DEFAULT_GPIO;
    struct gpiod_chip *chip;
    struct gpiod_line *line;
    int value = 0;

    // Parse command-line arguments
    if (argc == 3 && strcmp(argv[1], "--gpio") == 0) {
        gpio = atoi(argv[2]);
    } else if (argc != 1) {
        fprintf(stderr, "Usage: %s [--gpio <GPIO_ID>]\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Open the GPIO chip
    chip = gpiod_chip_open(CHIP_PATH);
    if (!chip) {
        perror("gpiod_chip_open");
        return EXIT_FAILURE;
    }

    // Get the GPIO line
    line = gpiod_chip_get_line(chip, gpio);
    if (!line) {
        perror("gpiod_chip_get_line");
        gpiod_chip_close(chip);
        return EXIT_FAILURE;
    }

    // Request the line as output
    if (gpiod_line_request_output(line, "gpio-toggle", 0) < 0) {
        perror("gpiod_line_request_output");
        gpiod_line_release(line);
        gpiod_chip_close(chip);
        return EXIT_FAILURE;
    }

    // Toggle the GPIO line in an infinite loop
    while (1) {
        value = !value; // Alternate between 0 and 1
        if (gpiod_line_set_value(line, value) < 0) {
            perror("gpiod_line_set_value");
            break;
        }
        printf("GPIO %d set to %d\n", gpio, value);
        sleep(1); // Wait 1 second
    }

    // Cleanup
    gpiod_line_release(line);
    gpiod_chip_close(chip);

    return EXIT_SUCCESS;
}

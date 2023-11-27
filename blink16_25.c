#include <stdio.h>
#include <gpiod.h>
#include <unistd.h>

int main() {
    struct gpiod_chip *chip;
    struct gpiod_line *line_25, *line_16;
    int offset_25 = 25; // GPIO pin number
    int offset_16 = 16; // GPIO pin number

    chip = gpiod_chip_open("/dev/gpiochip4"); // Replace 4 with the appropriate chip number

    if (!chip) {
        perror("Open chip failed");
        return 1;
    }

    line_25 = gpiod_chip_get_line(chip, offset_25);
    line_16 = gpiod_chip_get_line(chip, offset_16);

    if (!line_25 || !line_16) {
        perror("Get line failed");
        gpiod_chip_close(chip);
        return 1;
    }

    // Request the lines for output
    if (gpiod_line_request_output(line_25, "example", 0) < 0 ||
        gpiod_line_request_output(line_16, "example", 0) < 0) {
        perror("Request line as output failed");
        gpiod_line_release(line_25);
        gpiod_line_release(line_16);
        gpiod_chip_close(chip);
        return 1;
    }

    // Toggle the lines
    while (1) {
        gpiod_line_set_value(line_25, 1);
        gpiod_line_set_value(line_16, 1);
        usleep(500000); // Delay

        gpiod_line_set_value(line_25, 0);
        gpiod_line_set_value(line_16, 0);
        usleep(500000); // Delay
    }

    // Cleanup
    gpiod_line_release(line_25);
    gpiod_line_release(line_16);
    gpiod_chip_close(chip);

    return 0;
}

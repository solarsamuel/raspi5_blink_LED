#include <stdio.h>
#include <gpiod.h>
#include <unistd.h>


int main() {
    
 
    struct gpiod_chip *chip;
    struct gpiod_line *line;
    int offset = 25; // Replace with your GPIO pin number

    chip = gpiod_chip_open("/dev/gpiochip4"); // Replace 0 with the appropriate chip number

    if (!chip) {
        perror("Open chip failed");
        return 1;
    }

    line = gpiod_chip_get_line(chip, offset);

    if (!line) {
        perror("Get line failed");
        gpiod_chip_close(chip);
        return 1;
    }

    // Request the line for output
    if (gpiod_line_request_output(line, "example", 0) < 0) {
        perror("Request line as output failed");
        gpiod_line_release(line);
        gpiod_chip_close(chip);
        return 1;
    }

    // Toggle the line
    while (1) {
        gpiod_line_set_value(line, 1);
        usleep(500000); // Delay 1/2 second

        
        gpiod_line_set_value(line, 0);

        usleep(500000); // Delay
    }

    // Cleanup
    gpiod_line_release(line);
    gpiod_chip_close(chip);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include "network.h"
#include "parser.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <city>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *json_data = get_weather_json(argv[1]);
    if (json_data == NULL) {
        printf("Failed to get a response from the server");
        return EXIT_FAILURE;
    }

    int success = print_weather_data(json_data);
    free(json_data);

    if (!success) {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
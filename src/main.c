#include <stdio.h>
#include <stdlib.h>
#include "network.h"

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

    // check
    printf("%s\n", json_data);
    free(json_data);

    return EXIT_SUCCESS;
}
#include <curl/curl.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "network.h"

#define NO_BYTES 0
#define NULL_TERMINATOR '\0'

static size_t write_callback(void *contents, size_t size, size_t nmemb, void *userp) {
    JSONBuffer *json_buffer = (JSONBuffer *)userp;
    size_t new_size = size * nmemb;
    
    char *tmp = realloc(json_buffer->data, json_buffer->size + new_size + 1);
    if (tmp == NULL) {
        printf("Memory allocated error\n");
        return NO_BYTES;
    }

    json_buffer->data = tmp;

    memcpy(&(json_buffer->data[json_buffer->size]), contents, new_size);
    json_buffer->size += new_size;

    json_buffer->data[json_buffer->size] = NULL_TERMINATOR;

    return new_size;
}

char* get_weather_json(const char *city) {
    // to do ...
}
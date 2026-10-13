#include <curl/curl.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "network.h"

#define NO_BYTES 0
#define NULL_TERMINATOR '\0'
#define WEATHER_URL "http://wttr.in/%s?format=j1"

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
    JSONBuffer chunk = {NULL, 0};
    char url[256];

    snprintf(url, sizeof(url), WEATHER_URL, city);

    CURL *curl_handle = curl_easy_init();
    if (curl_handle == NULL) {
        return NULL;
    }

    curl_easy_setopt(curl_handle, CURLOPT_URL, url);
    curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, (void *)&chunk);

    CURLcode response = curl_easy_perform(curl_handle);
    if (response != CURLE_OK) {
        free(chunk.data);
        curl_easy_cleanup(curl_handle);
        return NULL;
    }

    curl_easy_cleanup(curl_handle);
    
    return chunk.data;
}

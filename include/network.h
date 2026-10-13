/*
* network.h
* components for making http-requests to the wttr.in API
*/

#pragma once

#include <stddef.h>

typedef struct {
    char *data;    
    size_t size;
} JSONBuffer;

char* get_weather_json(const char *city);

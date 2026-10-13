#include <stdio.h>
#include "parser.h"
#include "cJSON.h"

int print_weather_data(const char *data) {
    cJSON *root = cJSON_Parse(data);
    if (root == NULL) {
        printf("Invalid JSON data received, please check the city name\n");
        return 0;
    }

    cJSON *weather_array = cJSON_GetObjectItemCaseSensitive(root, "weather");
    if (!cJSON_IsArray(weather_array)) {
        cJSON_Delete(root);
        return 0;
    }

    cJSON *weather_day = cJSON_GetArrayItem(weather_array, 0);
    if (weather_day == NULL) {
        cJSON_Delete(root);
        return 0;
    }

    cJSON *max_temp = cJSON_GetObjectItemCaseSensitive(weather_day, "maxtempC");
    cJSON *min_temp = cJSON_GetObjectItemCaseSensitive(weather_day, "mintempC");
    if (!cJSON_IsString(max_temp) || !cJSON_IsString(min_temp) || 
        max_temp->valuestring == NULL || min_temp->valuestring == NULL) {
        cJSON_Delete(root);
        return 0;
    }
}
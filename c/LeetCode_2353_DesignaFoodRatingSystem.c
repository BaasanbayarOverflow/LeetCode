#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    char **foods; 
    char **cuisines;
    int *ratings;
    int total;
} FoodRatings;


FoodRatings* foodRatingsCreate(char** foods, int foodsSize, char** cuisines, int cuisinesSize, int* ratings, int ratingsSize) {
    FoodRatings *system = (FoodRatings*) malloc(sizeof(FoodRatings));
    
    system->total = foodsSize;
    system->foods = foods; 
    system->cuisines = cuisines;
    system->ratings = ratings;


    /*
    system->foods = (char**) malloc(foodsSize * sizeof(char*));
    for (int i = 0; i < foodsSize; ++i) {
        system->foods[i] = foods[i];
    }

    system->cuisines = (char**) malloc(cuisinesSize * sizeof(char*));
    for (int i = 0; i < cuisinesSize; ++i) {
        system->cuisines[i] = cuisines[i];
    }

    system->ratings = (int*) malloc(ratingsSize * sizeof(int));
    for (int i = 0; i < ratingsSize; ++i) {
        system->ratings[i] = ratings[i];
        ++system->total;
    }*/


    return system;
}


void foodRatingsChangeRating(FoodRatings* obj, char* food, int newRating) {
    for (int i = 0; i < obj->total; ++i) {
        if (strcmp(obj->foods[i], food) == 0) {
            obj->ratings[i] = newRating;
        }
    }
}


char* foodRatingsHighestRated(FoodRatings* obj, char* cuisine) {
    int high = 0;
    char *food = NULL;
    for (int i = 0; i < obj->total; ++i) {
        if (strcmp(obj->cuisines[i], cuisine) == 0) {
            if (high < obj->ratings[i]) {
                high = obj->ratings[i];
                food = obj->foods[i];
            } else if (high == obj->ratings[i]) {
                int len_selected_food = strlen(food);
                int len_food_array = strlen(obj->foods[i]);

                int inx = 0;
                while (food && obj->foods[i]) {
                    if (food[inx] < obj->foods[i][inx]) {
                        break;
                    } else if (food[inx] > obj->foods[i][inx]) {
                        food = obj->foods[i];
                        break;
                    }

                    if (len_selected_food - 1 == inx) {
                        break;
                    } else if (len_food_array - 1 == inx) {
                        food = obj->foods[i];
                        break;
                    }
                    ++inx;
                }
            }   
        }
    }

    return food;
}


void foodRatingsFree(FoodRatings* obj) {
    for (int i = 0; i < obj->total; ++i) {
        free(obj->foods[i]);
        free(obj->cuisines[i]);
    }    

    free(obj->foods);
    free(obj->cuisines);
    free(obj->ratings);
    free(obj);
}


int main() {
    int *s = calloc(3, sizeof(int));
    int *l = s;

    return 0;
}
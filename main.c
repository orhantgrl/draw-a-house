#include <stdio.h>

/**
 * @author orhantgrl
 * @date Tue Dec 24
 */

void print_house(int house_weight);

void print_roof(int roof_height);

void print_body(int house_height, int house_weight, int windows_and_door_width, int windows_and_door_height);

int round_number(float num) {
    return num < 0 ? num - 0.5 : num + 0.5;
}

static const int HOUSE_WEIGHT = 35;

int main() {
    print_house(HOUSE_WEIGHT);
    return 0;
}

void print_house(int house_weight) {
    const int HOUSE_HEIGHT = house_weight / 2;
    const int ROOF_HEIGHT = (HOUSE_HEIGHT / 2) + 1;
    const int WINDOWS_AND_DOOR_WIDTH = ROOF_HEIGHT;
    const int WINDOWS_AND_DOOR_HEIGHT = (WINDOWS_AND_DOOR_WIDTH / 2) + 1;

    print_roof(ROOF_HEIGHT);
    print_body(HOUSE_HEIGHT, house_weight, WINDOWS_AND_DOOR_WIDTH, WINDOWS_AND_DOOR_HEIGHT);
}

void print_roof(int roof_height) {
    int space = roof_height;

    for (int i = 0; i < roof_height; i++) {
        for (int j = 0; j < space * 2; j++) {
            printf(" ");
        }

        space -= 1;

        for (int k = 0; k < i * 2; k++) {
            printf("/");
        }

        printf("+");

        for (int l = 0; l < i * 2; l++) {
            printf("\\");
        }

        printf("\n");
    }
}

void print_body(int house_height, int house_weight, int windows_and_door_width, int windows_and_door_height) {

    /**
     * WINDOW LEFT
     */
    const float LEFT_WINDOW_CENTER = (float) (house_weight / 2) / 2;
    const int LEFT_HALF_SIDE_OF_THE_LEFT_WINDOW = round_number(LEFT_WINDOW_CENTER) - (windows_and_door_width / 2);
    const int RIGHT_HALF_SIDE_OF_THE_LEFT_WINDOW = round_number(LEFT_WINDOW_CENTER) + (windows_and_door_width / 2);

    /**
     * WINDOW RIGHT
     */
    const int RIGHT_WINDOW_CENTER = (float) (house_weight / 2) + LEFT_WINDOW_CENTER;
    const int LEFT_HALF_SIDE_OF_THE_RIGHT_WINDOW = round_number(RIGHT_WINDOW_CENTER) - (windows_and_door_width / 2);
    const int RIGHT_HALF_SIDE_OF_THE_RIGHT_WINDOW = round_number(RIGHT_WINDOW_CENTER) + (windows_and_door_width / 2);

    /**
     * DOOR
     */
    const int LEFT_HALF_SIDE_OF_THE_DOOR = (house_weight / 2) - (windows_and_door_width / 2);
    const int RIGHT_HALF_SIDE_OF_THE_DOOR = (house_weight / 2) + (windows_and_door_width / 2);


    for (int i = 0; i < house_height; i++) {
        printf(" ");
        for (int j = 0; j < house_weight; j++) {

            /*---- HOUSE LEFT WINDOW ----*/
            if (i > 2 && i <= 2 + windows_and_door_height) {
                if (j >= LEFT_HALF_SIDE_OF_THE_LEFT_WINDOW && j <= RIGHT_HALF_SIDE_OF_THE_LEFT_WINDOW) {
                    if (j == round_number(LEFT_WINDOW_CENTER) ||
                        (i > 2 && i - 2 == round_number(windows_and_door_height * 0.5))) {
                        printf("*");
                        continue;
                    }
                    printf(" ");
                    continue;
                }
            }

            /*---- HOUSE RIGHT WINDOW ----*/
            if (i > 2 && i <= 2 + windows_and_door_height) {
                if (j >= LEFT_HALF_SIDE_OF_THE_RIGHT_WINDOW && j <= RIGHT_HALF_SIDE_OF_THE_RIGHT_WINDOW) {
                    if (j == round_number(RIGHT_WINDOW_CENTER) ||
                        (i > 2 && i - 2 == round_number(windows_and_door_height * 0.5))) {
                        printf("*");
                        continue;
                    }
                    printf(" ");
                    continue;
                }
            }

            /*---- HOUSE DOOR ----*/
            if (i >= house_height - windows_and_door_height &&
                (j >= LEFT_HALF_SIDE_OF_THE_DOOR && j <= RIGHT_HALF_SIDE_OF_THE_DOOR)) {
                if (house_height - i <= windows_and_door_height && j == house_weight / 2) {
                    printf("*");
                    continue;
                }
                printf(" ");
                continue;
            }
            printf("O");
        }
        printf("\n");
    }
}

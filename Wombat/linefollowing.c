#include <linefollowing.h>
#include <kipr/wombat.h>
#include <defaults.h>
#include <unistd.h>
#include <movement.h>

void forwardUntilBlack(int sensor_port) {
    while (analog(sensor_port) < 3000) {
        forwardForSeconds(100, 10);
    }
}

void followLineMilliseconds(int millis, int speed) {
    int i = 0;
    for (i = 0; i < millis / 5; i++) {
        forwardForSeconds(speed, 5);
        if (analog(LEFT_COLOR_SENSOR) < 1500) {
            turn_left_pivot(6);
            msleep(1);
        } else if (analog(RIGHT_COLOR_SENSOR) < 1500) {
            turn_right_pivot(6);
            msleep(1);
        }
    }
}

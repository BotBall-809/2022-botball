#include <defaults.h>
#include <kipr/wombat.h>
#include <movement.h>

void forward(int mm, int speed) {
    double circumference = wheel_diameter * PI;
    int distance = (mm/circumference) * 1800; //in ticks
       
    cmpc(LEFTMOTOR);
    cmpc(RIGHTMOTOR);
    while (gmpc(LEFTMOTOR) < distance)   {
        motor(LEFTMOTOR, speed);
        motor(RIGHTMOTOR, speed);
    }
    freeze(LEFTMOTOR);
    freeze(RIGHTMOTOR);
}

void forwardForSeconds(int speed, int timeMillis) {
    motor(LEFTMOTOR, speed);
    motor(RIGHTMOTOR, speed);
       
    msleep(timeMillis);
    freeze(LEFTMOTOR);
    freeze(RIGHTMOTOR);
}

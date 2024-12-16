#include "motor.h"
#include "headfile.h"

// 定义电机控制引脚
#define LEFT_MOTOR_PIN_1 P1_2  
// 左轮控制引脚1
#define LEFT_MOTOR_PIN_2 P1_3  // 左轮控制引脚2
#define RIGHT_MOTOR_PIN_1 P1_4  // 右轮控制引脚1
#define RIGHT_MOTOR_PIN_2 P1_5  // 右轮控制引脚2

// 初始化电机控制引脚
void motor_init() {
    gpio_mode(LEFT_MOTOR_PIN_1, GPO_PP);
    gpio_mode(LEFT_MOTOR_PIN_2, GPO_PP);
    gpio_mode(RIGHT_MOTOR_PIN_1, GPO_PP);
    gpio_mode(RIGHT_MOTOR_PIN_2, GPO_PP);
}

// 前进
void goForward(void) {
    // 左轮
    gpio_write(LEFT_MOTOR_PIN_1, 1);
    gpio_write(LEFT_MOTOR_PIN_2, 0);
    // 右轮
    gpio_write(RIGHT_MOTOR_PIN_1, 1);
    gpio_write(RIGHT_MOTOR_PIN_2, 0);
}

// 后退
void goBack(void) {
    // 左轮
    gpio_write(LEFT_MOTOR_PIN_1, 0);
    gpio_write(LEFT_MOTOR_PIN_2, 1);
    // 右轮
    gpio_write(RIGHT_MOTOR_PIN_1, 0);
    gpio_write(RIGHT_MOTOR_PIN_2, 1);
}

// 左转
void goLeft(void) {
    // 左轮
    gpio_write(LEFT_MOTOR_PIN_1, 0);
    gpio_write(LEFT_MOTOR_PIN_2, 0);
    // 右轮
    gpio_write(RIGHT_MOTOR_PIN_1, 1);
    gpio_write(RIGHT_MOTOR_PIN_2, 0);
}

// 右转
void goRight(void) {
    // 左轮
    gpio_write(LEFT_MOTOR_PIN_1, 1);
    gpio_write(LEFT_MOTOR_PIN_2, 0);
    // 右轮
    gpio_write(RIGHT_MOTOR_PIN_1, 0);
    gpio_write(RIGHT_MOTOR_PIN_2, 0);
}

// 停止
void stop(void) {
    // 左轮
    gpio_write(LEFT_MOTOR_PIN_1, 0);
    gpio_write(LEFT_MOTOR_PIN_2, 0);
    // 右轮
    gpio_write(RIGHT_MOTOR_PIN_1, 0);
    gpio_write(RIGHT_MOTOR_PIN_2, 0);
}
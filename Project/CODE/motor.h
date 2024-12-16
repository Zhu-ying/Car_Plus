#ifndef MOTOR_H
#define MOTOR_H

// 初始化电机控制引脚
void motor_init();

// 前进
void goForward(void);
// 后退
void goBack(void);

// 左转
void goLeft(void);

// 右转
void goRight(void);

// 停止
void stop(void);

#endif MOTOR_H
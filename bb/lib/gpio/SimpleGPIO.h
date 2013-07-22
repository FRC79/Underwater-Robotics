/*
 * SimpleGPIO.h
 *
 * Based off code by Derek Molloy, School of Electronic Engineering, Dublin City University
 * www.derekmolloy.ie
 *
 */

#ifndef SIMPLEGPIO_H_
#define SIMPLEGPIO_H_

 /****************************************************************
 * Constants
 ****************************************************************/

#define SYSFS_GPIO_DIR "/sys/class/gpio"
#define POLL_TIMEOUT (3 * 1000) /* 3 seconds */
#define MAX_BUF 64

enum PIN_DIRECTION{
	INPUT_PIN=0,
	OUTPUT_PIN=1
};

enum PIN_VALUE{
	LOW=0,
	HIGH=1
};

/****************************************************************
 * gpio_export
 ****************************************************************/
int exportPin(unsigned int gpio);
int unexportPin(unsigned int gpio);
int setDir(unsigned int gpio, PIN_DIRECTION out_flag);
int setValue(unsigned int gpio, PIN_VALUE value);
int getValue(unsigned int gpio, unsigned int *value);
int setEdge(unsigned int gpio, char *edge);
int fdOpen(unsigned int gpio);
int fdClose(int fd);

#endif /* SIMPLEGPIO_H_ */

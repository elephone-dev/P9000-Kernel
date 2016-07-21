#ifndef _NLED_DRIVER_H
#define _NLED_DRIVER_H

struct nled_driver {
	char *name;
	int (*led_set_brightness)(long data, int level);
	int (*led_set_blink)(long data, unsigned long on, unsigned long off);
};

#endif

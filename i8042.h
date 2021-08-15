/* SPDX-License-Identifier: GPL-2.0-only */
#ifndef _I8042_H
#define _I8042_H


/*
 *  Copyright (c) 1999-2002 Vojtech Pavlik
 */

/*
 * Arch-dependent inline functions and defines.
 */

#include "i8042-x86ia64io.h"

/*
 * This is in 50us units, the time we wait for the i8042 to react. This
 * has to be long enough for the i8042 itself to timeout on sending a byte
 * to a non-existent mouse.
 */

#define I8042_CTL_TIMEOUT	10000

/*
 * Return codes.
 */

#define I8042_RET_CTL_TEST	0x55

/*
 * Expected maximum internal i8042 buffer size. This is used for flushing
 * the i8042 buffers.
 */

#define I8042_BUFFER_SIZE	16

/*
 * Number of AUX ports on controllers supporting active multiplexing
 * specification
 */

#define I8042_NUM_MUX_PORTS	4

/*
 * Debug.
 */

#ifdef DEBUG
static unsigned long i8042_start_time;
#define dbg_init() do { i8042_start_time = jiffies; } while (0)
#define dbg(format, arg...)							\
	do {									\
		if (i8042_debug)						\
			printk(KERN_DEBUG KBUILD_MODNAME ": [%d] " format,	\
			       (int) (jiffies - i8042_start_time), ##arg);	\
	} while (0)

#define filter_dbg(filter, data, format, args...)		\
	do {							\
		if (!i8042_debug)				\
			break;					\
								\
		if (!filter || i8042_unmask_kbd_data)		\
			dbg("%02x " format, data, ##args);	\
		else						\
			dbg("** " format, ##args);		\
	} while (0)
#else
#define dbg_init() do { } while (0)
#define dbg(format, arg...)							\
	do {									\
		if (0)								\
			printk(KERN_DEBUG pr_fmt(format), ##arg);		\
	} while (0)

#define filter_dbg(filter, data, format, args...) do { } while (0)
#endif

#endif /* _I8042_H */

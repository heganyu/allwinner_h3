/*
 * (C) Copyright 2014 Chen-Yu Tsai <wens@csie.org>
 *
 * Configuration settings for the Allwinner A23 (sun8i) CPU
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __CONFIG_H
#define __CONFIG_H

/*
 * A23 specific configuration
 */

#ifdef CONFIG_USB_EHCI
#define CONFIG_USB_EHCI_SUNXI
#endif

#ifdef CONFIG_MACH_SUN8I_H3
	#define CONFIG_SUNXI_USB_PHYS	4
#elif defined CONFIG_MACH_SUN8I_A83T
	#define CONFIG_SUNXI_USB_PHYS	3
#else
	#define CONFIG_SUNXI_USB_PHYS	2
#endif

#ifdef CONFIG_ORANGEPI
#ifndef CONFIG_BOOTARGS
#define CONFIG_BOOTARGS		\
	"console=ttyS0,115200 " \
		"root=/dev/ram0 rw init=/linuxrc " \
		"blkdevparts=mmcblk2:1M(uboot),255M(firmware),7G(config),-(others)"
#endif

#ifndef CONFIG_BOOTCOMMAND
#define CONFIG_BOOTCOMMAND	"run load_fw;run bootm_fw"
#endif
#endif

/*
 * Include common sunxi configuration where most the settings are
 */
#include <configs/sunxi-common.h>

#define CONFIG_MACH_TYPE	(0x1029)

#endif /* __CONFIG_H */

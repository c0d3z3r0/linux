/*
 * Copyright (C) 2018 Google, Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <linux/init.h>
#include <linux/of_platform.h>

#include <asm/mach/arch.h>
#include <asm/mach/map.h>

#include "iomap.h"

// This is needed for e.g. earlyprintk
static struct map_desc io_desc[] __initdata = {
	{
		.virtual = AST_IO_VIRT,
		.pfn = __phys_to_pfn(AST_IO_PHYS),
		.length = AST_IO_SIZE,
		.type = MT_DEVICE
	}
};

static void __init aspeed_map_io(void)
{
	iotable_init(io_desc, ARRAY_SIZE(io_desc));
}

static const char * const aspeed_compat[] = {
	"aspeed,ast2400",
	"aspeed,ast2500",
	NULL
};

DT_MACHINE_START(ASPEED_DT, "Aspeed SoC")
	.map_io = aspeed_map_io,
	.dt_compat = aspeed_compat,
MACHINE_END

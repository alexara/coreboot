/*
 * This file is part of the coreboot project.
 *
 * Copyright (C) 2016 Google Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 2 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <soc/romstage.h>
#include <string.h>

#include <fsp/soc_binding.h>

#include "spd/spd.h"

void mainboard_memory_init_params(FSPM_UPD *mupd)
{
	FSP_M_CONFIG *mem_cfg = &mupd->FspmConfig;
	/* DQ byte map */
	const u8 dq_map[2][12] = {
		{ 0x0F, 0xF0, 0x00, 0xF0, 0x0F, 0xF0,
		  0x0F, 0x00, 0xFF, 0x00, 0xFF, 0x00 },
		{ 0xCC, 0x33, 0x00, 0x33, 0xCC, 0x33,
		  0xCC, 0x00, 0xFF, 0x00, 0xFF, 0x00 }
	};
	/* DQS CPU<>DRAM map */
	const u8 dqs_map[2][8] = {
		{ 2, 3, 1, 0, 4, 7, 6, 5 },
		{ 5, 6, 0, 3, 4, 7, 2, 1 },
	};
	/* Rcomp resistor */
	const u16 rcomp_resistor[] = { 200, 81, 162 };
	/* Rcomp target */
	const u16 rcomp_target[] = { 100, 40, 40, 23, 40 };

	memcpy(&mem_cfg->DqByteMapCh0, dq_map, sizeof(dq_map));
	memcpy(&mem_cfg->DqsMapCpu2DramCh0, dqs_map, sizeof(dqs_map));
	memcpy(&mem_cfg->RcompResistor, rcomp_resistor, sizeof(rcomp_resistor));
	memcpy(&mem_cfg->RcompTarget, rcomp_target, sizeof(rcomp_target));

	mem_cfg->MemorySpdPtr00 = mainboard_get_spd_data();
	mem_cfg->MemorySpdPtr10 = mem_cfg->MemorySpdPtr00;
	mem_cfg->MemorySpdDataLen = SPD_LEN;
}

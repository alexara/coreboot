bootblock-y += mem_pool.c
verstage-y += mem_pool.c
romstage-y += mem_pool.c
ramstage-y += mem_pool.c
postcar-y += mem_pool.c

bootblock-y += region.c
verstage-y += region.c
romstage-y += region.c
ramstage-y += region.c
smm-y += region.c
postcar-y += region.c

ramstage-$(CONFIG_PLATFORM_USES_FSP1_1) += fsp_relocate.c
ramstage-$(CONFIG_PLATFORM_USES_FSP2_0) += fsp_relocate.c

bootblock-y += cbfs.c
verstage-y += cbfs.c
romstage-y += cbfs.c
ramstage-y += cbfs.c
smm-y += cbfs.c
postcar-y += cbfs.c

bootblock-y += lz4_wrapper.c
verstage-y += lz4_wrapper.c
romstage-y += lz4_wrapper.c
ramstage-y += lz4_wrapper.c
postcar-y += lz4_wrapper.c

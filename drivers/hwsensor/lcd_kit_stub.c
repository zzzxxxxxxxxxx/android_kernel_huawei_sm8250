/*
 * Standalone-build stub: the kernel-only opensource package ships incomplete
 * lcdkit sources (e.g. lcd_kit_dpd.h is missing), so CONFIG_LCD_KIT_QCOM is
 * disabled for the QEMU research build.  hwsensor (hall / xhub_pm) still
 * references the lcdkit DRM notifier; provide a no-op replacement.
 */
#ifdef CONFIG_LCD_KIT_QCOM
#error "lcd_kit_stub.c must only be built when CONFIG_LCD_KIT_QCOM is disabled"
#else
#include <linux/notifier.h>
#include <linux/types.h>
#include <misc/app_info.h>

int lcd_kit_drm_notifier_register(uint32_t panel_id, struct notifier_block *nb)
{
	return 0;
}

/* APP_INFO (fs/proc/manufacture_app_info) is disabled for the QEMU build
   (it reads Qualcomm SMEM which does not exist on -M virt). */
int app_info_proc_get(const char *name, char *value)
{
	return -ENODEV;
}

int app_info_set(const char *name, const char *value)
{
	return -ENODEV;
}
#endif

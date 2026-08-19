/*
 * Standalone-build stub: QTEE_SHM_BRIDGE is disabled for the QEMU research
 * build because its early_initcall issues an SMC that QEMU does not
 * implement (traps as an undefined instruction at EL1).  The GPU devfreq
 * governor still references allocate_shm; provide a no-op.
 */
#ifdef CONFIG_QTEE_SHM_BRIDGE
#error "qtee_shmbridge_stub.c must only be built when QTEE_SHM_BRIDGE is disabled"
#else
#include <linux/types.h>
#include <soc/qcom/qtee_shmbridge.h>

bool qtee_shmbridge_is_enabled(void)
{
	return false;
}

int32_t qtee_shmbridge_query(phys_addr_t paddr)
{
	return -ENODEV;
}

int32_t qtee_shmbridge_register(
		phys_addr_t paddr,
		size_t size,
		uint32_t *ns_vmid_list,
		uint32_t *ns_vm_perm_list,
		uint32_t ns_vmid_num,
		uint32_t tz_perm,
		uint64_t *handle)
{
	return -ENODEV;
}

int32_t qtee_shmbridge_deregister(uint64_t handle)
{
	return -ENODEV;
}

int32_t qtee_shmbridge_allocate_shm(size_t size, struct qtee_shm *shm)
{
	return -ENODEV;
}

void qtee_shmbridge_free_shm(struct qtee_shm *shm)
{
}
#endif

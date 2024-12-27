/* auto-generated by gen_syscalls.py, don't edit */

#include <syscalls/espi.h>

extern int z_vrfy_espi_send_vwire(const struct device * dev, enum espi_vwire_signal signal, uint8_t level);
uintptr_t z_mrsh_espi_send_vwire(uintptr_t arg0, uintptr_t arg1, uintptr_t arg2,
		uintptr_t arg3, uintptr_t arg4, uintptr_t arg5, void *ssf)
{
	_current->syscall_frame = ssf;
	(void) arg3;	/* unused */
	(void) arg4;	/* unused */
	(void) arg5;	/* unused */
	union { uintptr_t x; const struct device * val; } parm0;
	parm0.x = arg0;
	union { uintptr_t x; enum espi_vwire_signal val; } parm1;
	parm1.x = arg1;
	union { uintptr_t x; uint8_t val; } parm2;
	parm2.x = arg2;
	int ret = z_vrfy_espi_send_vwire(parm0.val, parm1.val, parm2.val);
	_current->syscall_frame = NULL;
	return (uintptr_t) ret;
}


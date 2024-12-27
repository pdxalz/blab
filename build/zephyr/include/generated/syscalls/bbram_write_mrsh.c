/* auto-generated by gen_syscalls.py, don't edit */

#include <syscalls/bbram.h>

extern int z_vrfy_bbram_write(const struct device * dev, size_t offset, size_t size, const uint8_t * data);
uintptr_t z_mrsh_bbram_write(uintptr_t arg0, uintptr_t arg1, uintptr_t arg2,
		uintptr_t arg3, uintptr_t arg4, uintptr_t arg5, void *ssf)
{
	_current->syscall_frame = ssf;
	(void) arg4;	/* unused */
	(void) arg5;	/* unused */
	union { uintptr_t x; const struct device * val; } parm0;
	parm0.x = arg0;
	union { uintptr_t x; size_t val; } parm1;
	parm1.x = arg1;
	union { uintptr_t x; size_t val; } parm2;
	parm2.x = arg2;
	union { uintptr_t x; const uint8_t * val; } parm3;
	parm3.x = arg3;
	int ret = z_vrfy_bbram_write(parm0.val, parm1.val, parm2.val, parm3.val);
	_current->syscall_frame = NULL;
	return (uintptr_t) ret;
}


/* auto-generated by gen_syscalls.py, don't edit */

#include <syscalls/counter.h>

extern uint64_t z_vrfy_counter_ticks_to_us(const struct device * dev, uint32_t ticks);
uintptr_t z_mrsh_counter_ticks_to_us(uintptr_t arg0, uintptr_t arg1, uintptr_t arg2,
		uintptr_t arg3, uintptr_t arg4, uintptr_t arg5, void *ssf)
{
	_current->syscall_frame = ssf;
	(void) arg3;	/* unused */
	(void) arg4;	/* unused */
	(void) arg5;	/* unused */
	union { uintptr_t x; const struct device * val; } parm0;
	parm0.x = arg0;
	union { uintptr_t x; uint32_t val; } parm1;
	parm1.x = arg1;
	uint64_t ret = z_vrfy_counter_ticks_to_us(parm0.val, parm1.val);
	Z_OOPS(Z_SYSCALL_MEMORY_WRITE(((uint64_t *)arg2), 8));
	*((uint64_t *)arg2) = ret;
	_current->syscall_frame = NULL;
	return 0;
}


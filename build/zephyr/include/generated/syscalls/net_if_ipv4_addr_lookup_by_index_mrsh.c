/* auto-generated by gen_syscalls.py, don't edit */

#include <syscalls/net_if.h>

extern int z_vrfy_net_if_ipv4_addr_lookup_by_index(const struct in_addr * addr);
uintptr_t z_mrsh_net_if_ipv4_addr_lookup_by_index(uintptr_t arg0, uintptr_t arg1, uintptr_t arg2,
		uintptr_t arg3, uintptr_t arg4, uintptr_t arg5, void *ssf)
{
	_current->syscall_frame = ssf;
	(void) arg1;	/* unused */
	(void) arg2;	/* unused */
	(void) arg3;	/* unused */
	(void) arg4;	/* unused */
	(void) arg5;	/* unused */
	union { uintptr_t x; const struct in_addr * val; } parm0;
	parm0.x = arg0;
	int ret = z_vrfy_net_if_ipv4_addr_lookup_by_index(parm0.val);
	_current->syscall_frame = NULL;
	return (uintptr_t) ret;
}


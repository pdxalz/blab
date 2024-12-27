/* auto-generated by gen_syscalls.py, don't edit */

#ifndef Z_INCLUDE_SYSCALLS_EC_HOST_CMD_PERIPH_H
#define Z_INCLUDE_SYSCALLS_EC_HOST_CMD_PERIPH_H


#include <zephyr/tracing/tracing_syscall.h>

#ifndef _ASMLANGUAGE

#include <syscall_list.h>
#include <zephyr/syscall.h>

#include <zephyr/linker/sections.h>


#ifdef __cplusplus
extern "C" {
#endif

extern int z_impl_ec_host_cmd_periph_init(const struct device * dev, struct ec_host_cmd_periph_rx_ctx * rx_ctx);

__pinned_func
static inline int ec_host_cmd_periph_init(const struct device * dev, struct ec_host_cmd_periph_rx_ctx * rx_ctx)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		union { uintptr_t x; const struct device * val; } parm0 = { .val = dev };
		union { uintptr_t x; struct ec_host_cmd_periph_rx_ctx * val; } parm1 = { .val = rx_ctx };
		return (int) arch_syscall_invoke2(parm0.x, parm1.x, K_SYSCALL_EC_HOST_CMD_PERIPH_INIT);
	}
#endif
	compiler_barrier();
	return z_impl_ec_host_cmd_periph_init(dev, rx_ctx);
}

#if defined(CONFIG_TRACING_SYSCALL)
#ifndef DISABLE_SYSCALL_TRACING

#define ec_host_cmd_periph_init(dev, rx_ctx) ({ 	int retval; 	sys_port_trace_syscall_enter(K_SYSCALL_EC_HOST_CMD_PERIPH_INIT, ec_host_cmd_periph_init, dev, rx_ctx); 	retval = ec_host_cmd_periph_init(dev, rx_ctx); 	sys_port_trace_syscall_exit(K_SYSCALL_EC_HOST_CMD_PERIPH_INIT, ec_host_cmd_periph_init, dev, rx_ctx, retval); 	retval; })
#endif
#endif


extern int z_impl_ec_host_cmd_periph_send(const struct device * dev, const struct ec_host_cmd_periph_tx_buf * tx_buf);

__pinned_func
static inline int ec_host_cmd_periph_send(const struct device * dev, const struct ec_host_cmd_periph_tx_buf * tx_buf)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		union { uintptr_t x; const struct device * val; } parm0 = { .val = dev };
		union { uintptr_t x; const struct ec_host_cmd_periph_tx_buf * val; } parm1 = { .val = tx_buf };
		return (int) arch_syscall_invoke2(parm0.x, parm1.x, K_SYSCALL_EC_HOST_CMD_PERIPH_SEND);
	}
#endif
	compiler_barrier();
	return z_impl_ec_host_cmd_periph_send(dev, tx_buf);
}

#if defined(CONFIG_TRACING_SYSCALL)
#ifndef DISABLE_SYSCALL_TRACING

#define ec_host_cmd_periph_send(dev, tx_buf) ({ 	int retval; 	sys_port_trace_syscall_enter(K_SYSCALL_EC_HOST_CMD_PERIPH_SEND, ec_host_cmd_periph_send, dev, tx_buf); 	retval = ec_host_cmd_periph_send(dev, tx_buf); 	sys_port_trace_syscall_exit(K_SYSCALL_EC_HOST_CMD_PERIPH_SEND, ec_host_cmd_periph_send, dev, tx_buf, retval); 	retval; })
#endif
#endif


#ifdef __cplusplus
}
#endif

#endif
#endif /* include guard */

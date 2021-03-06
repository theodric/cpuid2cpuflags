/* cpuid2cpuflags -- native AT_HWCAP* getters
 * (c) 2015-2019 Michał Górny
 * 2-clause BSD licensed
 */

#ifdef HAVE_CONFIG_H
#	include "config.h"
#endif
#include "platforms.h"

#if defined(CPUID_ARM) || defined(CPUID_PPC)

#include <stddef.h>
#ifdef HAVE_SYS_AUXV_H
#	include <sys/auxv.h>
#endif
#include <sys/utsname.h>

#ifndef __linux__
#	error "Platform not supported (only Linux supported at the moment)"
#endif
#ifndef HAVE_GETAUXVAL
#	error "Platform not supported (no getauxval())"
#endif

#include "hwcap.h"

/**
 * Returns native AT_HWCAP value.
 */
unsigned long get_hwcap()
{
	return getauxval(AT_HWCAP);
}

/**
 * Returns native AT_HWCAP2 value.
 */
unsigned long get_hwcap2()
{
#ifdef AT_HWCAP2
	return getauxval(AT_HWCAP2);
#else
	return 0;
#endif
}

/**
 * Returns machine name from utsname data, or NULL on failure.
 *
 * The data is stored in static buffer of undefined length.  The caller
 * may modify the string, and must not free it.
 */
char* get_uname_machine()
{
	static struct utsname uname_res;
	if (uname(&uname_res) != -1)
		return uname_res.machine;
	else
		return NULL;
}

#endif

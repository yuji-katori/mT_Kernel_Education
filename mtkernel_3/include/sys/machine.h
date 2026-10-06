/*
 *----------------------------------------------------------------------
 *    micro T-Kernel 3.00.00
 *
 *    Copyright (C) 2006-2019 by Ken Sakamura.
 *    This software is distributed under the T-License 2.1.
 *----------------------------------------------------------------------
 *
 *    Released by TRON Forum(http://www.tron.org) at 2019/12/11.
 *
 *----------------------------------------------------------------------
 */

/*
 *	machine.h
 *	Machine type definition 
 */

#ifndef __SYS_MACHINE_H__
#define __SYS_MACHINE_H__

/* ===== System dependencies definitions ================================ */
#include <config.h>

#ifdef _EK_RX72N_
#include "sysdepend/ek_rx72n/machine.h"
#endif

/* ===== C compiler dependencies definitions ============================= */

#ifdef __CCRX__

#define Csym(sym) sym
#define Inline static __inline
#define Noinit(decl) decl

#endif /* __CCRX__ */

#endif /* __SYS_MACHINE_H__ */

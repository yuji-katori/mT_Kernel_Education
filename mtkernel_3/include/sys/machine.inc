;/*
; *----------------------------------------------------------------------
; *    micro T-Kernel 3.00.00
; *
; *    Copyright (C) 2006-2019 by Ken Sakamura.
; *    This software is distributed under the T-License 2.1.
; *----------------------------------------------------------------------
; *
; *    Released by TRON Forum(http://www.tron.org) at 2019/12/11.
; *
; *----------------------------------------------------------------------
; */

;/*
; *	machine.inc
; *	Machine type definition 
; */

.IF __SYS_MACHINE_H__ != 1
__SYS_MACHINE_H__	.EQU	(1)

;/* ===== System dependencies definitions ================================ */
.INCLUDE config.inc

.IF _EK_RX72N_
.INCLUDE sys/sysdepend/ek_rx72n/machine.inc
.ENDIF

;/* ===== C compiler dependencies definitions ============================= */

;#ifdef __CCRX__

;#define Csym(sym) sym
;#define Inline static __inline
;#define Noinit(decl) decl

;#endif /* __CCRX__ */

.ENDIF ; __SYS_MACHINE_H__

/*
 *----------------------------------------------------------------------
 *    micro T-Kernel 3.00.00
 *
 *    Copyright (C) 2023 by Yuji Katori.
 *    This software is distributed under the T-License 2.2.
 *----------------------------------------------------------------------
 */

/*
 *	usermain.c (usermain)
 *	User Main
 */

#include <tk/tkernel.h>
#include <tm/tmonitor.h>
#include <string.h>
#include "iodefine.h"

EXPORT void led_tsk(INT stacd, void *exinf);
EXPORT void sw_tsk(INT stacd, void *exinf);

EXPORT INT usermain( void )
{
T_CTSK t_ctsk;
ID objid;

	t_ctsk.tskatr = TA_HLNG | TA_DSNAME;			// タスク属性を設定
	t_ctsk.stksz = 1024;					// スタックサイズは1024バイト
	t_ctsk.itskpri = 2;					// タスク優先度は2
	t_ctsk.task =  led_tsk;					// led_tskの起動アドレス
	strcpy( t_ctsk.dsname, "led_tsk" );			// led_tskの名称
	if( (objid = tk_cre_tsk( &t_ctsk )) <= E_OK )		// led_tskの生成
		goto ERROR;
	if( tk_sta_tsk( objid, 0 ) != E_OK )			// led_tskの起動
		goto ERROR;
	t_ctsk.task =  sw_tsk;					// sw_tskの起動アドレス
	strcpy( t_ctsk.dsname, "sw_tsk" );			// sw_tskの名称
	if( (objid = tk_cre_tsk( &t_ctsk )) <= E_OK )		// sw_tskの生成
		goto ERROR;
	if( tk_sta_tsk( objid, 0 ) != E_OK )			// tsk_bの起動
		goto ERROR;

	while( 1 )  tk_slp_tsk(TMO_FEVR);			// 起床待ち
ERROR:
	return 0;
}

EXPORT void led_tsk(INT stacd, void *exinf)
{
	PORT4.PDR.BIT.B0 = 1;
	while( 1 )  {
		tk_dly_tsk( 500 );
		PORT4.PODR.BIT.B0 ^= 1;				// LED2の点滅
	}
}

#define	PUSH	(0)
#define	PULL	(1)

EXPORT void sw_tsk(INT stacd, void *exinf)
{
BOOL pre=PULL, now;
	while( 1 )  {
		tk_dly_tsk( 10 );
		now = PORT0.PIDR.BIT.B7;			// SW2の読み込み
		if( pre == PULL && now == PUSH )		// SW2を押したか？
			tm_putstring("PUSH\n\r");		// メッセージ表示
		pre = now;					// SW2の状態保存
	}
}
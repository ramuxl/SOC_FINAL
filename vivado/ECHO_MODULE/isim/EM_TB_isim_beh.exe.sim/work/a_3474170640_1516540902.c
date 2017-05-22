/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0xfbc00daa */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "/home/INTRA/chakal/workspace/project/vivado/ECHO_MODULE/ECHO_MODULE.vhd";
extern char *IEEE_P_2592010699;
extern char *IEEE_P_1242562249;

char *ieee_p_1242562249_sub_1006216973935652998_1035706684(char *, char *, char *, char *, int );
unsigned char ieee_p_1242562249_sub_1434214030532789707_1035706684(char *, char *, char *, char *, char *);
char *ieee_p_1242562249_sub_1701011461141717515_1035706684(char *, char *, char *, char *, char *, char *);
char *ieee_p_1242562249_sub_3299657338228113225_1035706684(char *, char *, char *, char *, int );
char *ieee_p_1242562249_sub_8645934262925994370_1035706684(char *, char *, char *, char *, int );
unsigned char ieee_p_2592010699_sub_2763492388968962707_503743352(char *, char *, unsigned int , unsigned int );


static void work_a_3474170640_1516540902_p_0(char *t0)
{
    char t13[16];
    char t20[16];
    char *t1;
    unsigned char t2;
    char *t3;
    char *t4;
    unsigned char t5;
    unsigned char t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    unsigned int t14;
    unsigned int t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;

LAB0:    xsi_set_current_line(28, ng0);
    t1 = (t0 + 1152U);
    t2 = ieee_p_2592010699_sub_2763492388968962707_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t2 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 5640);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(29, ng0);
    t3 = (t0 + 1032U);
    t4 = *((char **)t3);
    t5 = *((unsigned char *)t4);
    t6 = (t5 == (unsigned char)2);
    if (t6 != 0)
        goto LAB5;

LAB7:    xsi_set_current_line(33, ng0);
    t1 = (t0 + 1512U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t5 = (t2 == (unsigned char)2);
    if (t5 != 0)
        goto LAB8;

LAB10:    t1 = (t0 + 3272U);
    t3 = *((char **)t1);
    t1 = (t0 + 9472U);
    t4 = (t0 + 3432U);
    t7 = *((char **)t4);
    t4 = (t0 + 9472U);
    t2 = ieee_p_1242562249_sub_1434214030532789707_1035706684(IEEE_P_1242562249, t3, t1, t7, t4);
    if (t2 != 0)
        goto LAB11;

LAB12:    xsi_set_current_line(41, ng0);
    t1 = (t0 + 5880);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(42, ng0);
    t1 = (t0 + 5944);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(43, ng0);
    t1 = (t0 + 1352U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t5 = (t2 == (unsigned char)3);
    if (t5 != 0)
        goto LAB15;

LAB17:
LAB16:
LAB9:
LAB6:    goto LAB3;

LAB5:    xsi_set_current_line(30, ng0);
    t3 = xsi_get_transient_memory(14U);
    memset(t3, 0, 14U);
    t7 = t3;
    memset(t7, (unsigned char)2, 14U);
    t8 = (t0 + 5752);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    memcpy(t12, t3, 14U);
    xsi_driver_first_trans_fast(t8);
    xsi_set_current_line(31, ng0);
    t1 = xsi_get_transient_memory(14U);
    memset(t1, 0, 14U);
    t3 = t1;
    memset(t3, (unsigned char)2, 14U);
    t4 = (t0 + 5816);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 14U);
    xsi_driver_first_trans_fast(t4);
    goto LAB6;

LAB8:    xsi_set_current_line(34, ng0);
    t1 = (t0 + 5880);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    *((unsigned char *)t9) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(35, ng0);
    t1 = (t0 + 5944);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(36, ng0);
    t1 = xsi_get_transient_memory(14U);
    memset(t1, 0, 14U);
    t3 = t1;
    memset(t3, (unsigned char)2, 14U);
    t4 = (t0 + 5752);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 14U);
    xsi_driver_first_trans_fast(t4);
    xsi_set_current_line(37, ng0);
    t1 = xsi_get_transient_memory(14U);
    memset(t1, 0, 14U);
    t3 = t1;
    memset(t3, (unsigned char)2, 14U);
    t4 = (t0 + 5816);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 14U);
    xsi_driver_first_trans_fast(t4);
    goto LAB9;

LAB11:    xsi_set_current_line(39, ng0);
    t8 = (t0 + 3272U);
    t9 = *((char **)t8);
    t8 = (t0 + 9472U);
    t10 = ieee_p_1242562249_sub_1006216973935652998_1035706684(IEEE_P_1242562249, t13, t9, t8, 1);
    t11 = (t13 + 12U);
    t14 = *((unsigned int *)t11);
    t15 = (1U * t14);
    t5 = (14U != t15);
    if (t5 == 1)
        goto LAB13;

LAB14:    t12 = (t0 + 5816);
    t16 = (t12 + 56U);
    t17 = *((char **)t16);
    t18 = (t17 + 56U);
    t19 = *((char **)t18);
    memcpy(t19, t10, 14U);
    xsi_driver_first_trans_fast(t12);
    goto LAB9;

LAB13:    xsi_size_not_matching(14U, t15, 0);
    goto LAB14;

LAB15:    xsi_set_current_line(44, ng0);
    t1 = (t0 + 5944);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    *((unsigned char *)t9) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(45, ng0);
    t1 = (t0 + 3272U);
    t3 = *((char **)t1);
    t1 = (t0 + 6008);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t3, 14U);
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(46, ng0);
    t1 = (t0 + 3272U);
    t3 = *((char **)t1);
    t1 = (t0 + 9472U);
    t4 = ieee_p_1242562249_sub_1006216973935652998_1035706684(IEEE_P_1242562249, t20, t3, t1, 1);
    t7 = ieee_p_1242562249_sub_3299657338228113225_1035706684(IEEE_P_1242562249, t13, t4, t20, 16384);
    t8 = (t13 + 12U);
    t14 = *((unsigned int *)t8);
    t15 = (1U * t14);
    t2 = (14U != t15);
    if (t2 == 1)
        goto LAB18;

LAB19:    t9 = (t0 + 5752);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    t12 = (t11 + 56U);
    t16 = *((char **)t12);
    memcpy(t16, t7, 14U);
    xsi_driver_first_trans_fast(t9);
    xsi_set_current_line(47, ng0);
    t1 = (t0 + 3432U);
    t3 = *((char **)t1);
    t1 = (t0 + 9472U);
    t4 = ieee_p_1242562249_sub_1006216973935652998_1035706684(IEEE_P_1242562249, t20, t3, t1, 1);
    t7 = ieee_p_1242562249_sub_3299657338228113225_1035706684(IEEE_P_1242562249, t13, t4, t20, 16384);
    t8 = (t13 + 12U);
    t14 = *((unsigned int *)t8);
    t15 = (1U * t14);
    t2 = (14U != t15);
    if (t2 == 1)
        goto LAB20;

LAB21:    t9 = (t0 + 5816);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    t12 = (t11 + 56U);
    t16 = *((char **)t12);
    memcpy(t16, t7, 14U);
    xsi_driver_first_trans_fast(t9);
    xsi_set_current_line(48, ng0);
    t1 = (t0 + 3432U);
    t3 = *((char **)t1);
    t1 = (t0 + 6072);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t3, 14U);
    xsi_driver_first_trans_fast_port(t1);
    goto LAB16;

LAB18:    xsi_size_not_matching(14U, t15, 0);
    goto LAB19;

LAB20:    xsi_size_not_matching(14U, t15, 0);
    goto LAB21;

}

static void work_a_3474170640_1516540902_p_1(char *t0)
{
    char t1[16];
    char t4[16];
    char *t2;
    char *t3;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;

LAB0:    xsi_set_current_line(55, ng0);

LAB3:    t2 = (t0 + 1672U);
    t3 = *((char **)t2);
    t2 = (t0 + 9344U);
    t5 = (t0 + 1992U);
    t6 = *((char **)t5);
    t5 = (t0 + 9376U);
    t7 = ieee_p_1242562249_sub_8645934262925994370_1035706684(IEEE_P_1242562249, t4, t6, t5, 1);
    t8 = ieee_p_1242562249_sub_1701011461141717515_1035706684(IEEE_P_1242562249, t1, t3, t2, t7, t4);
    t9 = (t0 + 6136);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    memcpy(t13, t8, 24U);
    xsi_driver_first_trans_fast_port(t9);

LAB2:    t14 = (t0 + 5656);
    *((int *)t14) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_3474170640_1516540902_p_2(char *t0)
{
    char t1[16];
    char t4[16];
    char *t2;
    char *t3;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;

LAB0:    xsi_set_current_line(56, ng0);

LAB3:    t2 = (t0 + 1832U);
    t3 = *((char **)t2);
    t2 = (t0 + 9360U);
    t5 = (t0 + 2152U);
    t6 = *((char **)t5);
    t5 = (t0 + 9392U);
    t7 = ieee_p_1242562249_sub_8645934262925994370_1035706684(IEEE_P_1242562249, t4, t6, t5, 1);
    t8 = ieee_p_1242562249_sub_1701011461141717515_1035706684(IEEE_P_1242562249, t1, t3, t2, t7, t4);
    t9 = (t0 + 6200);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    memcpy(t13, t8, 24U);
    xsi_driver_first_trans_fast_port(t9);

LAB2:    t14 = (t0 + 5672);
    *((int *)t14) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}


extern void work_a_3474170640_1516540902_init()
{
	static char *pe[] = {(void *)work_a_3474170640_1516540902_p_0,(void *)work_a_3474170640_1516540902_p_1,(void *)work_a_3474170640_1516540902_p_2};
	xsi_register_didat("work_a_3474170640_1516540902", "isim/EM_TB_isim_beh.exe.sim/work/a_3474170640_1516540902.didat");
	xsi_register_executes(pe);
}

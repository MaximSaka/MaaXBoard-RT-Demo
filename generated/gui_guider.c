/*
 * Copyright 2021 NXP
 * SPDX-License-Identifier: MIT
 */

#include "lvgl/lvgl.h"
#include <stdio.h>
#include "gui_guider.h"

volatile bool g_red_led_state = false;
volatile bool g_green_led_state = false;
volatile bool g_blue_led_state = false;

void setup_ui(lv_ui *ui){
	setup_scr_welcome_screen(ui);
	lv_scr_load(ui->welcome_screen);

	set_red_led(false);
	set_green_led(false);
	set_blue_led(false);
}

void set_red_led(bool state)
{
	g_red_led_state = state;
}

void set_green_led(bool state)
{
	g_green_led_state = state;
}

void set_blue_led(bool state)
{
	g_blue_led_state = state;
}

bool get_red_led()
{
	return g_red_led_state;
}

bool get_green_led()
{
	return g_green_led_state;
}

bool get_blue_led()
{
	return g_blue_led_state;
}

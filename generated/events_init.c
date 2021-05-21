/*
 * Copyright 2021 NXP
 * SPDX-License-Identifier: MIT
 */

#include "events_init.h"
#include <stdio.h>
#include "lvgl/lvgl.h"
#include "demo_common.h"

void events_init(lv_ui *ui)
{
}

static void screen1_LEDs_left_btnevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_PRESSED:
	{
		openMenuScreen();
	}
		break;
	default:
		break;
	}
}

static void screen1_LEDs_right_btnevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_RELEASED:
	{
		openNetworkScreen();
	}
		break;
	default:
		break;
	}
}

static void screen1_LEDs_redbtn0event_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_PRESSED:
	{
		set_red_led(true);
	}
		break;
	case LV_EVENT_RELEASED:
	{
		set_red_led(false);
	}
		break;
	default:
		break;
	}
}

static void screen1_LEDs_greenbtn0event_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_PRESSED:
	{
		set_green_led(true);
	}
		break;
	case LV_EVENT_RELEASED:
	{
		set_green_led(false);
	}
		break;
	default:
		break;
	}
}

static void screen1_LEDs_bluebtn0event_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_PRESSED:
	{
		set_blue_led(true);
	}
		break;
	case LV_EVENT_RELEASED:
	{
		set_blue_led(false);
	}
		break;
	default:
		break;
	}
}

void events_init_screen1_LEDs(lv_ui *ui)
{
	lv_obj_set_event_cb(ui->screen1_LEDs_left_btn, screen1_LEDs_left_btnevent_handler);
	lv_obj_set_event_cb(ui->screen1_LEDs_right_btn, screen1_LEDs_right_btnevent_handler);
	lv_obj_set_event_cb(ui->screen1_LEDs_redbtn0, screen1_LEDs_redbtn0event_handler);
	lv_obj_set_event_cb(ui->screen1_LEDs_greenbtn0, screen1_LEDs_greenbtn0event_handler);
	lv_obj_set_event_cb(ui->screen1_LEDs_bluebtn0, screen1_LEDs_bluebtn0event_handler);
}

static void screen0_MENU_btn_1event_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_PRESSED:
	{
		openLEDScreen();
	}
		break;
	default:
		break;
	}
}

static void screen0_MENU_btn_2event_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_PRESSED:
	{
		openNetworkScreen();
	}
		break;
	default:
		break;
	}
}

static void screen0_MENU_btn_3event_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_PRESSED:
	{
		openUSBScreen();
	}
		break;
	default:
		break;
	}
}

static void screen0_MENU_btn_4event_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_PRESSED:
	{
		openAVScreen();
	}
		break;
	default:
		break;
	}
}

static void screen0_MENU_btn_5event_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_PRESSED:
	{
		openSystemScreen();
	}
		break;
	default:
		break;
	}
}

static void screen0_MENU_btn_6event_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_PRESSED:
	{
		openHelpScreen();
	}
		break;
	default:
		break;
	}
}

void events_init_screen0_MENU(lv_ui *ui)
{
	lv_obj_set_event_cb(ui->screen0_MENU_btn_1, screen0_MENU_btn_1event_handler);
	lv_obj_set_event_cb(ui->screen0_MENU_btn_2, screen0_MENU_btn_2event_handler);
	lv_obj_set_event_cb(ui->screen0_MENU_btn_3, screen0_MENU_btn_3event_handler);
	lv_obj_set_event_cb(ui->screen0_MENU_btn_4, screen0_MENU_btn_4event_handler);
	lv_obj_set_event_cb(ui->screen0_MENU_btn_5, screen0_MENU_btn_5event_handler);
	lv_obj_set_event_cb(ui->screen0_MENU_btn_6, screen0_MENU_btn_6event_handler);
}

static void screen2_WIFI_left_btnevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_PRESSED:
	{
		openMenuScreen();
	}
		break;
	default:
		break;
	}
}

static void screen2_WIFI_right_btnevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_RELEASED:
	{
		openUSBScreen();
	}
		break;
	default:
		break;
	}
}

void events_init_screen2_WIFI(lv_ui *ui)
{
	lv_obj_set_event_cb(ui->screen2_WIFI_left_btn, screen2_WIFI_left_btnevent_handler);
	lv_obj_set_event_cb(ui->screen2_WIFI_right_btn, screen2_WIFI_right_btnevent_handler);
}

static void screen3_USB_left_btnevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_PRESSED:
	{
		openMenuScreen();
	}
		break;
	default:
		break;
	}
}

static void screen3_USB_right_btnevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_RELEASED:
	{
		openAVScreen();
	}
		break;
	default:
		break;
	}
}

void events_init_screen3_USB(lv_ui *ui)
{
	lv_obj_set_event_cb(ui->screen3_USB_left_btn, screen3_USB_left_btnevent_handler);
	lv_obj_set_event_cb(ui->screen3_USB_right_btn, screen3_USB_right_btnevent_handler);
}

static void screen4_AV_left_btnevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_PRESSED:
	{
		openMenuScreen();
	}
		break;
	default:
		break;
	}
}

static void screen4_AV_right_btnevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_RELEASED:
	{
		openSystemScreen();
	}
		break;
	default:
		break;
	}
}

void events_init_screen4_AV(lv_ui *ui)
{
	lv_obj_set_event_cb(ui->screen4_AV_left_btn, screen4_AV_left_btnevent_handler);
	lv_obj_set_event_cb(ui->screen4_AV_right_btn, screen4_AV_right_btnevent_handler);
}

static void screen5_SYSTEM_left_btnevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_PRESSED:
	{
		openMenuScreen();
	}
		break;
	default:
		break;
	}
}

static void screen5_SYSTEM_right_btnevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_RELEASED:
	{
		openLEDScreen();
	}
		break;
	default:
		break;
	}
}

void events_init_screen5_SYSTEM(lv_ui *ui)
{
	lv_obj_set_event_cb(ui->screen5_SYSTEM_left_btn, screen5_SYSTEM_left_btnevent_handler);
	lv_obj_set_event_cb(ui->screen5_SYSTEM_right_btn, screen5_SYSTEM_right_btnevent_handler);
}

static void screen6_HELP_left_btnevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_PRESSED:
	{
		openMenuScreen();
	}
		break;
	default:
		break;
	}
}

void events_init_screen6_HELP(lv_ui *ui)
{
	lv_obj_set_event_cb(ui->screen6_HELP_left_btn, screen6_HELP_left_btnevent_handler);
}

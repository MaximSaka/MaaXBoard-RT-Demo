/*
 * Copyright 2021 NXP
 * SPDX-License-Identifier: MIT
 */

#include "events_init.h"
#include <stdio.h>
#include "lvgl/lvgl.h"

void events_init(lv_ui *ui)
{
}

static void welcome_screen_rightbtn0event_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_RELEASED:
	{
		lv_obj_clean(lv_scr_act());
		setup_scr_network_screen(&guider_ui);
		lv_scr_load(guider_ui.network_screen);
	}
		break;
	default:
		break;
	}
}

static void welcome_screen_leftbtn0event_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_RELEASED:
	{
		lv_obj_clean(lv_scr_act());
		setup_scr_help_screen(&guider_ui);
		lv_scr_load(guider_ui.help_screen);
	}
		break;
	default:
		break;
	}
}

static void welcome_screen_redbtn0event_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_PRESSED:
	{
		lv_label_set_text(guider_ui.welcome_screen_redlabel0, "Red LED ON!");
		set_red_led(true);
	}
		break;
	case LV_EVENT_RELEASED:
	{
		lv_label_set_text(guider_ui.welcome_screen_redlabel0, "Red LED OFF");
		set_red_led(false);
	}
		break;
	default:
		break;
	}
}

static void welcome_screen_greenbtn0event_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_PRESSED:
	{
		lv_label_set_text(guider_ui.welcome_screen_greenlabel0, "Green LED ON!");
		set_green_led(true);
	}
		break;
	case LV_EVENT_RELEASED:
	{
		lv_label_set_text(guider_ui.welcome_screen_greenlabel0, "Green LED OFF");
		set_green_led(false);
	}
		break;
	default:
		break;
	}
}

static void welcome_screen_bluebtn0event_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_PRESSED:
	{
		lv_label_set_text(guider_ui.welcome_screen_bluelabel0, "Blue LED ON!");
		set_blue_led(true);
	}
		break;
	case LV_EVENT_RELEASED:
	{
		lv_label_set_text(guider_ui.welcome_screen_bluelabel0, "Blue LED OFF");
		set_blue_led(false);
	}
		break;
	default:
		break;
	}
}

void events_init_welcome_screen(lv_ui *ui)
{
	lv_obj_set_event_cb(ui->welcome_screen_rightbtn0, welcome_screen_rightbtn0event_handler);
	lv_obj_set_event_cb(ui->welcome_screen_leftbtn0, welcome_screen_leftbtn0event_handler);
	lv_obj_set_event_cb(ui->welcome_screen_redbtn0, welcome_screen_redbtn0event_handler);
	lv_obj_set_event_cb(ui->welcome_screen_greenbtn0, welcome_screen_greenbtn0event_handler);
	lv_obj_set_event_cb(ui->welcome_screen_bluebtn0, welcome_screen_bluebtn0event_handler);
}

static void network_screen_rightbtn0event_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_RELEASED:
	{
		lv_obj_clean(lv_scr_act());
		setup_scr_usb_screen(&guider_ui);
		lv_scr_load(guider_ui.usb_screen);
	}
		break;
	default:
		break;
	}
}

static void network_screen_leftbtn0event_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_RELEASED:
	{
		lv_obj_clean(lv_scr_act());
		setup_scr_welcome_screen(&guider_ui);
		lv_scr_load(guider_ui.welcome_screen);
	}
		break;
	default:
		break;
	}
}

void events_init_network_screen(lv_ui *ui)
{
	lv_obj_set_event_cb(ui->network_screen_rightbtn0, network_screen_rightbtn0event_handler);
	lv_obj_set_event_cb(ui->network_screen_leftbtn0, network_screen_leftbtn0event_handler);
}

static void usb_screen_rightbtn0event_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_RELEASED:
	{
		lv_obj_clean(lv_scr_act());
		setup_scr_video_screen(&guider_ui);
		lv_scr_load(guider_ui.video_screen);
	}
		break;
	default:
		break;
	}
}

static void usb_screen_leftbtn0event_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_RELEASED:
	{
		lv_obj_clean(lv_scr_act());
		setup_scr_network_screen(&guider_ui);
		lv_scr_load(guider_ui.network_screen);
	}
		break;
	default:
		break;
	}
}

void events_init_usb_screen(lv_ui *ui)
{
	lv_obj_set_event_cb(ui->usb_screen_rightbtn0, usb_screen_rightbtn0event_handler);
	lv_obj_set_event_cb(ui->usb_screen_leftbtn0, usb_screen_leftbtn0event_handler);
}

static void video_screen_rightbtn0event_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_RELEASED:
	{
		lv_obj_clean(lv_scr_act());
		setup_scr_system_screen(&guider_ui);
		lv_scr_load(guider_ui.system_screen);
	}
		break;
	default:
		break;
	}
}

static void video_screen_leftbtn0event_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_RELEASED:
	{
		lv_obj_clean(lv_scr_act());
		setup_scr_usb_screen(&guider_ui);
		lv_scr_load(guider_ui.usb_screen);
	}
		break;
	default:
		break;
	}
}

void events_init_video_screen(lv_ui *ui)
{
	lv_obj_set_event_cb(ui->video_screen_rightbtn0, video_screen_rightbtn0event_handler);
	lv_obj_set_event_cb(ui->video_screen_leftbtn0, video_screen_leftbtn0event_handler);
}

static void system_screen_rightbtn0event_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_RELEASED:
	{
		lv_obj_clean(lv_scr_act());
		setup_scr_help_screen(&guider_ui);
		lv_scr_load(guider_ui.help_screen);
	}
		break;
	default:
		break;
	}
}

static void system_screen_leftbtn0event_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_RELEASED:
	{
		lv_obj_clean(lv_scr_act());
		setup_scr_video_screen(&guider_ui);
		lv_scr_load(guider_ui.video_screen);
	}
		break;
	default:
		break;
	}
}

void events_init_system_screen(lv_ui *ui)
{
	lv_obj_set_event_cb(ui->system_screen_rightbtn0, system_screen_rightbtn0event_handler);
	lv_obj_set_event_cb(ui->system_screen_leftbtn0, system_screen_leftbtn0event_handler);
}

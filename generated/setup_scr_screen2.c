/*
 * Copyright 2021 NXP
 * SPDX-License-Identifier: MIT
 */

#include "lvgl/lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"


void setup_scr_screen2(lv_ui *ui){

	//Write codes screen2
	ui->screen2 = lv_obj_create(NULL, NULL);

	//Write codes screen2_img0
	ui->screen2_img0 = lv_img_create(ui->screen2, NULL);

	//Write style LV_IMG_PART_MAIN for screen2_img0
	static lv_style_t style_screen2_img0_main;
	lv_style_init(&style_screen2_img0_main);

	//Write style state: LV_STATE_DEFAULT for style_screen2_img0_main
	lv_style_set_image_recolor(&style_screen2_img0_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_image_recolor_opa(&style_screen2_img0_main, LV_STATE_DEFAULT, 0);
	lv_style_set_image_opa(&style_screen2_img0_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen2_img0, LV_IMG_PART_MAIN, &style_screen2_img0_main);
	lv_obj_set_pos(ui->screen2_img0, 281, 67);
	lv_obj_set_size(ui->screen2_img0, 158, 158);
	lv_obj_set_click(ui->screen2_img0, true);
	lv_img_set_src(ui->screen2_img0,&_image009_alpha_158x158);
	lv_img_set_pivot(ui->screen2_img0, 0,0);
	lv_img_set_angle(ui->screen2_img0, 0);
}
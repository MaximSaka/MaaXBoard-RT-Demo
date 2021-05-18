/*
 * Copyright 2021 NXP
 * SPDX-License-Identifier: MIT
 */

#include "lvgl/lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "custom.h"


void setup_scr_help_screen(lv_ui *ui){

	//Write codes help_screen
	ui->help_screen = lv_obj_create(NULL, NULL);

	//Write codes help_screen_bkgimg
	ui->help_screen_bkgimg = lv_img_create(ui->help_screen, NULL);

	//Write style LV_IMG_PART_MAIN for help_screen_bkgimg
	static lv_style_t style_help_screen_bkgimg_main;
	lv_style_init(&style_help_screen_bkgimg_main);

	//Write style state: LV_STATE_DEFAULT for style_help_screen_bkgimg_main
	lv_style_set_image_recolor(&style_help_screen_bkgimg_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_image_recolor_opa(&style_help_screen_bkgimg_main, LV_STATE_DEFAULT, 0);
	lv_style_set_image_opa(&style_help_screen_bkgimg_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->help_screen_bkgimg, LV_IMG_PART_MAIN, &style_help_screen_bkgimg_main);
	lv_obj_set_pos(ui->help_screen_bkgimg, 0, 0);
	lv_obj_set_size(ui->help_screen_bkgimg, 720, 1280);
	lv_obj_set_click(ui->help_screen_bkgimg, true);
	lv_img_set_src(ui->help_screen_bkgimg,&_whitebkg_alpha_720x1280);
	lv_img_set_pivot(ui->help_screen_bkgimg, 0,0);
	lv_img_set_angle(ui->help_screen_bkgimg, 0);

	//Write codes help_screen_boardimg
	ui->help_screen_boardimg = lv_img_create(ui->help_screen, NULL);

	//Write style LV_IMG_PART_MAIN for help_screen_boardimg
	static lv_style_t style_help_screen_boardimg_main;
	lv_style_init(&style_help_screen_boardimg_main);

	//Write style state: LV_STATE_DEFAULT for style_help_screen_boardimg_main
	lv_style_set_image_recolor(&style_help_screen_boardimg_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_image_recolor_opa(&style_help_screen_boardimg_main, LV_STATE_DEFAULT, 0);
	lv_style_set_image_opa(&style_help_screen_boardimg_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->help_screen_boardimg, LV_IMG_PART_MAIN, &style_help_screen_boardimg_main);
	lv_obj_set_pos(ui->help_screen_boardimg, 109, 142);
	lv_obj_set_size(ui->help_screen_boardimg, 499, 772);
	lv_obj_set_click(ui->help_screen_boardimg, true);
	lv_img_set_src(ui->help_screen_boardimg,&_maaxBoard01_alpha_499x772);
	lv_img_set_pivot(ui->help_screen_boardimg, 0,0);
	lv_img_set_angle(ui->help_screen_boardimg, 0);

	//Write codes help_screen_imgbtn1
	ui->help_screen_imgbtn1 = lv_imgbtn_create(ui->help_screen, NULL);

	//Write style LV_IMGBTN_PART_MAIN for help_screen_imgbtn1
	static lv_style_t style_help_screen_imgbtn1_main;
	lv_style_init(&style_help_screen_imgbtn1_main);

	//Write style state: LV_STATE_DEFAULT for style_help_screen_imgbtn1_main
	lv_style_set_text_color(&style_help_screen_imgbtn1_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_image_recolor(&style_help_screen_imgbtn1_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_image_recolor_opa(&style_help_screen_imgbtn1_main, LV_STATE_DEFAULT, 0);
	lv_style_set_image_opa(&style_help_screen_imgbtn1_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->help_screen_imgbtn1, LV_IMGBTN_PART_MAIN, &style_help_screen_imgbtn1_main);
	lv_obj_set_pos(ui->help_screen_imgbtn1, 21, 21);
	lv_obj_set_size(ui->help_screen_imgbtn1, 100, 100);
	lv_imgbtn_set_src(ui->help_screen_imgbtn1,LV_BTN_STATE_RELEASED,&_image008_alpha_100x100);
	lv_imgbtn_set_src(ui->help_screen_imgbtn1,LV_BTN_STATE_PRESSED,&_image008_dark_alpha_100x100);
}
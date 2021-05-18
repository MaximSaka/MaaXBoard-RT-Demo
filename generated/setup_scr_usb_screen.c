/*
 * Copyright 2021 NXP
 * SPDX-License-Identifier: MIT
 */

#include "lvgl/lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "custom.h"


void setup_scr_usb_screen(lv_ui *ui){

	//Write codes usb_screen
	ui->usb_screen = lv_obj_create(NULL, NULL);

	//Write codes usb_screen_bkgimg
	ui->usb_screen_bkgimg = lv_img_create(ui->usb_screen, NULL);

	//Write style LV_IMG_PART_MAIN for usb_screen_bkgimg
	static lv_style_t style_usb_screen_bkgimg_main;
	lv_style_init(&style_usb_screen_bkgimg_main);

	//Write style state: LV_STATE_DEFAULT for style_usb_screen_bkgimg_main
	lv_style_set_image_recolor(&style_usb_screen_bkgimg_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_image_recolor_opa(&style_usb_screen_bkgimg_main, LV_STATE_DEFAULT, 0);
	lv_style_set_image_opa(&style_usb_screen_bkgimg_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->usb_screen_bkgimg, LV_IMG_PART_MAIN, &style_usb_screen_bkgimg_main);
	lv_obj_set_pos(ui->usb_screen_bkgimg, 0, 0);
	lv_obj_set_size(ui->usb_screen_bkgimg, 720, 1280);
	lv_obj_set_click(ui->usb_screen_bkgimg, true);
	lv_img_set_src(ui->usb_screen_bkgimg,&_whitebkg_alpha_720x1280);
	lv_img_set_pivot(ui->usb_screen_bkgimg, 0,0);
	lv_img_set_angle(ui->usb_screen_bkgimg, 0);

	//Write codes usb_screen_rightbtn0
	ui->usb_screen_rightbtn0 = lv_imgbtn_create(ui->usb_screen, NULL);

	//Write style LV_IMGBTN_PART_MAIN for usb_screen_rightbtn0
	static lv_style_t style_usb_screen_rightbtn0_main;
	lv_style_init(&style_usb_screen_rightbtn0_main);

	//Write style state: LV_STATE_DEFAULT for style_usb_screen_rightbtn0_main
	lv_style_set_text_color(&style_usb_screen_rightbtn0_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_image_recolor(&style_usb_screen_rightbtn0_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_image_recolor_opa(&style_usb_screen_rightbtn0_main, LV_STATE_DEFAULT, 0);
	lv_style_set_image_opa(&style_usb_screen_rightbtn0_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->usb_screen_rightbtn0, LV_IMGBTN_PART_MAIN, &style_usb_screen_rightbtn0_main);
	lv_obj_set_pos(ui->usb_screen_rightbtn0, 530, 140);
	lv_obj_set_size(ui->usb_screen_rightbtn0, 150, 150);
	lv_imgbtn_set_src(ui->usb_screen_rightbtn0,LV_BTN_STATE_RELEASED,&_right_arrow_alpha_150x150);
	lv_imgbtn_set_src(ui->usb_screen_rightbtn0,LV_BTN_STATE_PRESSED,&_right_arrow_dark_alpha_150x150);

	//Write codes usb_screen_rightlabel
	ui->usb_screen_rightlabel = lv_label_create(ui->usb_screen, NULL);
	lv_label_set_text(ui->usb_screen_rightlabel, "A-V");
	lv_label_set_long_mode(ui->usb_screen_rightlabel, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->usb_screen_rightlabel, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for usb_screen_rightlabel
	static lv_style_t style_usb_screen_rightlabel_main;
	lv_style_init(&style_usb_screen_rightlabel_main);

	//Write style state: LV_STATE_DEFAULT for style_usb_screen_rightlabel_main
	lv_style_set_radius(&style_usb_screen_rightlabel_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_usb_screen_rightlabel_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_usb_screen_rightlabel_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_usb_screen_rightlabel_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_usb_screen_rightlabel_main, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_usb_screen_rightlabel_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_usb_screen_rightlabel_main, LV_STATE_DEFAULT, &lv_font_simsun_36);
	lv_style_set_text_letter_space(&style_usb_screen_rightlabel_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_usb_screen_rightlabel_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_usb_screen_rightlabel_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_usb_screen_rightlabel_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_usb_screen_rightlabel_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->usb_screen_rightlabel, LV_LABEL_PART_MAIN, &style_usb_screen_rightlabel_main);
	lv_obj_set_pos(ui->usb_screen_rightlabel, 545, 300);
	lv_obj_set_size(ui->usb_screen_rightlabel, 128, 0);

	//Write codes usb_screen_avlogoimg0
	ui->usb_screen_avlogoimg0 = lv_img_create(ui->usb_screen, NULL);

	//Write style LV_IMG_PART_MAIN for usb_screen_avlogoimg0
	static lv_style_t style_usb_screen_avlogoimg0_main;
	lv_style_init(&style_usb_screen_avlogoimg0_main);

	//Write style state: LV_STATE_DEFAULT for style_usb_screen_avlogoimg0_main
	lv_style_set_image_recolor(&style_usb_screen_avlogoimg0_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_image_recolor_opa(&style_usb_screen_avlogoimg0_main, LV_STATE_DEFAULT, 0);
	lv_style_set_image_opa(&style_usb_screen_avlogoimg0_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->usb_screen_avlogoimg0, LV_IMG_PART_MAIN, &style_usb_screen_avlogoimg0_main);
	lv_obj_set_pos(ui->usb_screen_avlogoimg0, 235, 80);
	lv_obj_set_size(ui->usb_screen_avlogoimg0, 250, 250);
	lv_obj_set_click(ui->usb_screen_avlogoimg0, true);
	lv_img_set_src(ui->usb_screen_avlogoimg0,&_AvnetIcon310x310_alpha_250x250);
	lv_img_set_pivot(ui->usb_screen_avlogoimg0, 0,0);
	lv_img_set_angle(ui->usb_screen_avlogoimg0, 0);

	//Write codes usb_screen_leftbtn0
	ui->usb_screen_leftbtn0 = lv_imgbtn_create(ui->usb_screen, NULL);

	//Write style LV_IMGBTN_PART_MAIN for usb_screen_leftbtn0
	static lv_style_t style_usb_screen_leftbtn0_main;
	lv_style_init(&style_usb_screen_leftbtn0_main);

	//Write style state: LV_STATE_DEFAULT for style_usb_screen_leftbtn0_main
	lv_style_set_text_color(&style_usb_screen_leftbtn0_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_image_recolor(&style_usb_screen_leftbtn0_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_image_recolor_opa(&style_usb_screen_leftbtn0_main, LV_STATE_DEFAULT, 0);
	lv_style_set_image_opa(&style_usb_screen_leftbtn0_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->usb_screen_leftbtn0, LV_IMGBTN_PART_MAIN, &style_usb_screen_leftbtn0_main);
	lv_obj_set_pos(ui->usb_screen_leftbtn0, 40, 140);
	lv_obj_set_size(ui->usb_screen_leftbtn0, 150, 150);
	lv_imgbtn_set_src(ui->usb_screen_leftbtn0,LV_BTN_STATE_RELEASED,&_left_arrow_alpha_150x150);
	lv_imgbtn_set_src(ui->usb_screen_leftbtn0,LV_BTN_STATE_PRESSED,&_left_arrow_dark_alpha_150x150);

	//Write codes usb_screen_leftlabel
	ui->usb_screen_leftlabel = lv_label_create(ui->usb_screen, NULL);
	lv_label_set_text(ui->usb_screen_leftlabel, "NET");
	lv_label_set_long_mode(ui->usb_screen_leftlabel, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->usb_screen_leftlabel, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for usb_screen_leftlabel
	static lv_style_t style_usb_screen_leftlabel_main;
	lv_style_init(&style_usb_screen_leftlabel_main);

	//Write style state: LV_STATE_DEFAULT for style_usb_screen_leftlabel_main
	lv_style_set_radius(&style_usb_screen_leftlabel_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_usb_screen_leftlabel_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_usb_screen_leftlabel_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_usb_screen_leftlabel_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_usb_screen_leftlabel_main, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_usb_screen_leftlabel_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_usb_screen_leftlabel_main, LV_STATE_DEFAULT, &lv_font_simsun_36);
	lv_style_set_text_letter_space(&style_usb_screen_leftlabel_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_usb_screen_leftlabel_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_usb_screen_leftlabel_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_usb_screen_leftlabel_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_usb_screen_leftlabel_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->usb_screen_leftlabel, LV_LABEL_PART_MAIN, &style_usb_screen_leftlabel_main);
	lv_obj_set_pos(ui->usb_screen_leftlabel, 46, 300);
	lv_obj_set_size(ui->usb_screen_leftlabel, 128, 0);

	//Init events for screen
	events_init_usb_screen(ui);
}
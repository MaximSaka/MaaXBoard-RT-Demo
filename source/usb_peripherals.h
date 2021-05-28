/*
 * usb_peripherals.h
 *
 *  Created on: May 10, 2021
 *      Author: gulziibayar
 */

#ifndef USB_PERIPHERALS_H_
#define USB_PERIPHERALS_H_

#include "usb_host_config.h"
#include "usb_host.h"
#include "fsl_device_registers.h"
#include "fsl_lpuart_freertos.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

#if ((defined USB_HOST_CONFIG_KHCI) && (USB_HOST_CONFIG_KHCI))
#define CONTROLLER_ID kUSB_ControllerKhci0
#endif /* USB_HOST_CONFIG_KHCI */
#if ((defined USB_HOST_CONFIG_EHCI) && (USB_HOST_CONFIG_EHCI))
#define CONTROLLER_ID kUSB_ControllerEhci1
#endif /* USB_HOST_CONFIG_EHCI */
#if ((defined USB_HOST_CONFIG_OHCI) && (USB_HOST_CONFIG_OHCI))
#define CONTROLLER_ID kUSB_ControllerOhci0
#endif /* USB_HOST_CONFIG_OHCI */
#if ((defined USB_HOST_CONFIG_IP3516HS) && (USB_HOST_CONFIG_IP3516HS))
#define CONTROLLER_ID kUSB_ControllerIp3516Hs0
#endif /* USB_HOST_CONFIG_IP3516HS */

#if defined(__GIC_PRIO_BITS)
#define USB_HOST_INTERRUPT_PRIORITY (25U)
#elif defined(__NVIC_PRIO_BITS) && (__NVIC_PRIO_BITS >= 3)
#define USB_HOST_INTERRUPT_PRIORITY (6U)
#else
#define USB_HOST_INTERRUPT_PRIORITY (3U)
#endif

/*! @brief host app device attach/detach status */
typedef enum _usb_host_app_state
{
    kStatus_DEV_Idle = 0, /*!< there is no device attach/detach */
    kStatus_DEV_Attached, /*!< device is attached */
    kStatus_DEV_Detached, /*!< device is detached */
} usb_host_app_state_t;

struct hid_peripheral
{
	uint8_t deviceExist;
	uint32_t devicePid;
	uint32_t deviceVid;
	uint32_t address;
};

/*! hid mouse structure for mouse/keyboard */
struct hid_device
{
	uint8_t dev_type;	/*!< 0x11-mouse, 0x22-keyboard */
	uint8_t dev_btn;	/*!< mouse buttons / keyboard keys */
	int8_t x_motion;	/*!< -127, 127 left or right */
	int8_t y_motion;	/*!< -127, 128 up or down */
	int8_t mouse_wheel;	/*!< -127, 128 up or down */
};
#define MOUSE_DEVICE		0x11
#define KEYBOARD_DEVICE	0x22

/*! Following definitions used for  720x1280 pixel display */
#define X_MAX	720
#define X_MIN	0

#define Y_MAX	1280
#define Y_MIN	0

#define x_sensitivity 0.3
#define y_sensitivity 0.3

/* comment below line if want to remove log task */
#define ENABLED_LOG_TASK	1

//void USB_peripheral_start(lpuart_rtos_handle_t *uart_handle, QueueHandle_t *hid_queue);
void USB_HostApplicationInit(usb_host_handle *t_hostHandle);
void USB_logTask(void *param);
void USB_HostApplicationKeyboardTask(void *param);
void USB_HostApplicationMouseTask(void *param);
void USB_HostTask(void *param);

#endif /* USB_PERIPHERALS_H_ */

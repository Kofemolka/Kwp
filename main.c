/* Copyright (c) 2014 Nordic Semiconductor. All Rights Reserved.
 *
 * The information contained herein is property of Nordic Semiconductor ASA.
 * Terms and conditions of usage are described in detail in NORDIC
 * SEMICONDUCTOR STANDARD SOFTWARE LICENSE AGREEMENT.
 *
 * Licensees are granted free, non-transferable use of the information. NO
 * WARRANTY of ANY KIND is provided. This heading must NOT be removed from
 * the file.
 *
 */

/** @file
 * @defgroup uart_example_main main.c
 * @{
 * @ingroup uart_example
 * @brief UART Example Application main file.
 *
 * This file contains the source code for a sample application using UART.
 *
 */

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include "app_uart.h"
#include "app_error.h"
#include "nrf_delay.h"
#include "nrf.h"
#include "bsp.h"


#define MAX_TEST_DATA_BYTES     (15U)                /**< max number of test bytes to be used for tx and rx. */
#define UART_TX_BUF_SIZE 256                         /**< UART TX buffer size. */
#define UART_RX_BUF_SIZE 256                         /**< UART RX buffer size. */

void uart_error_handle(app_uart_evt_t * p_event)
{
    if (p_event->evt_type == APP_UART_COMMUNICATION_ERROR)
    {
        APP_ERROR_HANDLER(p_event->data.error_communication);
    }
    else if (p_event->evt_type == APP_UART_FIFO_ERROR)
    {
        APP_ERROR_HANDLER(p_event->data.error_code);
    }
}

//static void sendTestPacket()
//{
//	app_uart_put(0x81);
//	
//	app_uart_put(0x11);
//	app_uart_put(0xF1);
//	
//	app_uart_put(0x81);
//	
//	app_uart_put(0x04);
//
//}
//
//#define KWP2000_SCANTOOL_ADDR 0xF1
//#define KWP2000_ECU_ADDR 0x33
//#define KWP2000_GET_LENGTH(x)  ((x[0])&0x3F)
//#define KWP2000_LENGTH_BYTE( len )  (0xC0 | len)
//
//static uint8_t usart_rx_buf[90];
//static uint8_t usart_rx_pos;
//static uint8_t usart_rx_len;
//
//uint8_t usart_tx_buf[16];
//uint8_t usart_tx_pos = 0;
//uint8_t usart_tx_len = 0;
//
//uint8_t kwp2000_calc_crc(uint8_t * msg, uint8_t len)
//{
//	uint8_t i = 0;
//	uint8_t crc = 0;
//	for (i = 0; i < len; i++)
//		crc += msg[i];
//
//	return crc;
//}
//
//int kwp2000_send_pkt(uint8_t dst_addr, uint8_t src_addr, uint8_t * _pkt, uint8_t len)
//{
//	int i = 0;
//
//	usart_tx_buf[0] = 0x80;// KWP2000_LENGTH_BYTE(len);
//	usart_tx_buf[1] = dst_addr;
//	usart_tx_buf[2] = src_addr;
//	usart_tx_buf[3] = len;
//	
//	const unsigned char payloadStart = 4;
//
//	for (i = 0; i < len; i++)
//	{
//		usart_tx_buf[i + payloadStart] = _pkt[i];
//	}
//
//	usart_tx_buf[len + payloadStart] = kwp2000_calc_crc(usart_tx_buf, len + payloadStart);
//
//	usart_tx_len = len + 5;
//	usart_tx_pos = 0;
//
//	for (i = 0; i < usart_tx_len; i++)
//	{		
//		app_uart_put(usart_tx_buf[i]);
//	}
//
//	return 0;
//}
//
//void initECU()
//{
//	static uint8_t request[129];
//	kwp2000_send_pkt(KWP2000_ECU_ADDR,
//		KWP2000_SCANTOOL_ADDR,
//		request,
//		sizeof(request)/sizeof(uint8_t));
//}
//
//void startDiagnostics()
//{
//	static uint8_t request[1] = { 0xC8 };
//	kwp2000_send_pkt(KWP2000_ECU_ADDR,
//		KWP2000_SCANTOOL_ADDR,
//		request,
//		sizeof(request)/sizeof(uint8_t));
//}

#include "ECU/ECU.h"
#include "ECU/Kwp2000Proto.h"
#include "ECU/UartEcuLink.h"

void initUart()
{
	uint32_t err_code;
	const app_uart_comm_params_t comm_params =
	{
		RX_PIN_NUMBER,
		TX_PIN_NUMBER,
		RTS_PIN_NUMBER,
		CTS_PIN_NUMBER,
		APP_UART_FLOW_CONTROL_DISABLED,
		false,
		UART_BAUDRATE_BAUDRATE_Baud115200
	};

	APP_UART_FIFO_INIT(&comm_params,
		UART_RX_BUF_SIZE,
		UART_TX_BUF_SIZE,
		uart_error_handle,
		APP_IRQ_PRIORITY_LOW,
		err_code);

	APP_ERROR_CHECK(err_code);
}

ECU ecu;

int main(void)
{   
	ecu.protocol = Kwp2000Proto(1, 2);
	ecu.link = UartEcuLink();
	    
	initUart();
	
    while (true)
    {
	    EcuRequestPID(1);
	    
	    nrf_delay_ms(100);
	    
	    EcuLoop();       
	    
	    int val = EcuReadPID(1);	    
    }
}



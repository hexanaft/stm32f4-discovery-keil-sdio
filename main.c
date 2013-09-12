//******************************************************************************
#include <inttypes.h>
#include "stm32f4xx.h"
#include "stm32f4xx_conf.h"
#include "discoveryf4utils.h"
#include "uart_to_printf.h"
#include "stm32f4_discovery_sdio_sd.h"
#include "sdio_debug.h"
//******************************************************************************

//******************************************************************************
int main(void)
{
	/*!< At this stage the microcontroller clock setting is already configured,
	   this is done through SystemInit() function which is called from startup
	   file (startup_stm32f4xx.s) before to branch to application main.
	   To reconfigure the default setting of SystemInit() function, refer to
	   system_stm32f4xx.c file
	 */
	uint32_t i = 0;
	uint32_t k = 0;
		
	STM_EVAL_LEDInit(LED_BLUE);
	STM_EVAL_LEDInit(LED_GREEN);
	STM_EVAL_LEDInit(LED_ORANGE);
	STM_EVAL_LEDInit(LED_RED);
	
	UART_Configuration();
	
	#ifdef SD_DMA_MODE
	SD_NVIC_Configuration();
	#endif
	
	SD_test();
	
	while(1) /* Infinite loop */
	{
		//STM_EVAL_LEDToggle(LED_BLUE);
		//STM_EVAL_LEDToggle(LED_GREEN);
		STM_EVAL_LEDToggle(LED_ORANGE);
		STM_EVAL_LEDToggle(LED_RED);
		for(i=0;i<0x01FFFFFF;++i){__NOP();};
		printf("k = %i\n",k++);
	}
}
//******************************************************************************


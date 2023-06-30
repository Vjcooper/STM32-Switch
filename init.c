#include"types.h"
#include"led.h"

int32 main(void){
	LED_init();
	
	while(1){
		if(get_input() == 1){
			pin_out_set(13);
			pin_out_set(14);
		}
		else{
			pin_out_reset(14);
			pin_out_reset(13);
		}
		/* delay();
		delay(); */
		
	}
	
}

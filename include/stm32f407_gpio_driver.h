#include "stm32f407xx.h"

#define GPIO_PORT_MODE_INPUT    0b00u
#define GPIO_PORT_MODE_OUTPUT   0b01u
#define GPIO_PORT_MODE_AF       0b10u
#define GPIO_PORT_MODE_ANALOG   0b11u

#define GPIO_PORT_OUTPUT_TYPE_PP    0b0u
#define GPIO_PORT_OUTPUT_TYPE_OD    0b1u

#define GPIO_PORT_OUTPUT_SPEED_LOW          0B00U
#define GPIO_PORT_OUTPUT_SPEED_MEDIUM       0B01U
#define GPIO_PORT_OUTPUT_SPEED_HIGH         0B10U
#define GPIO_PORT_OUTPUT_SPEED_VERY_HIGH    0B11U

#define GPIO_PORT_PULLUP_PULLDOWN_NO        0B00U
#define GPIO_PORT_PULLUP_PULLDOWN_UP        0B01U
#define GPIO_PORT_PULLUP_PULLDOWN_DOWN      0B10U

#define BIT_SET     0B1U
#define BIT_RESET   0B0U

#define GPIO_PORT_ODR_RESET_31_16 0B1U
#define GPIO_PORT_ODR_SET_15_0 0B1U

#define GPIO_ALTERNATE_FUNC_AF0     0b0000u
#define GPIO_ALTERNATE_FUNC_AF1     0b0001u
#define GPIO_ALTERNATE_FUNC_AF2     0b0010u
#define GPIO_ALTERNATE_FUNC_AF3     0b0011u
#define GPIO_ALTERNATE_FUNC_AF4     0b0100u
#define GPIO_ALTERNATE_FUNC_AF5     0b0101u
#define GPIO_ALTERNATE_FUNC_AF6     0b0110u
#define GPIO_ALTERNATE_FUNC_AF7     0b0111u
#define GPIO_ALTERNATE_FUNC_AF8     0b1000u
#define GPIO_ALTERNATE_FUNC_AF9     0b1001u
#define GPIO_ALTERNATE_FUNC_AF10    0b1010u
#define GPIO_ALTERNATE_FUNC_AF11    0b1011u
#define GPIO_ALTERNATE_FUNC_AF12    0b1100u
#define GPIO_ALTERNATE_FUNC_AF13    0b1101u
#define GPIO_ALTERNATE_FUNC_AF14    0b1110u
#define GPIO_ALTERNATE_FUNC_AF15    0b1111u



typedef struct{
    unsigned char pin_no;
    unsigned char gpio_mode;
    unsigned char gpio_output_type;
    unsigned char gpio_output_speed;
    unsigned char gpio_pull_up_down;
    unsigned char gpio_alternate_function_no;
}GPIO_Specs;

typedef struct{

    GPIO_TypeDef *port_register;

    GPIO_Specs *specs;


}GPIO_Handle; 

void GPIO_init(GPIO_Handle *port);
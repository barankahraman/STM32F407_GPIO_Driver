#include "stm32f407_gpio_driver.h"
#include "stm32f407xx.h"

void GPIO_init(GPIO_Handle *port, uint8_t pin_number,
    uint8_t pin_mode, uint8_t output_type, uint8_t output_speed,
    uint8_t gpio_pull, uint8_t pin_alternate_func){

    uint8_t MASK;

    if(port == GPIOA) MASK = (1u << 0);
    else if(port == GPIOB) MASK = (1u << 1);
    else if(port == GPIOB) MASK = (1u << 2);
    else if(port == GPIOB) MASK = (1u << 3);
    else if(port == GPIOB) MASK = (1u << 4);
    else if(port == GPIOB) MASK = (1u << 5);
    else if(port == GPIOB) MASK = (1u << 6);
    else if(port == GPIOB) MASK = (1u << 7);
    else if(port == GPIOB) MASK = (1u << 8);

    RCC -> AHB1ENR |= MASK; 
    
    port -> specs -> pin_no = pin_number;
    port -> specs -> gpio_mode = pin_mode;
    port -> specs -> gpio_output_type = output_type;
    port -> specs -> gpio_output_speed = output_speed;
    port -> specs -> gpio_pull_up_down = gpio_pull;
    port -> specs -> gpio_alternate_function_no = pin_alternate_func;

    
    port -> port_register -> MODER &= ~(1 << (port ->specs ->pin_no)*2);
    port -> port_register -> MODER |= ((port -> specs ->gpio_mode) << (port->specs->pin_no)*2);

    port -> port_register -> OTYPER &= ~(1 << (port -> specs ->pin_no));
    port -> port_register -> OTYPER |= ((port->specs->gpio_output_type)<<(port->specs->pin_no));

    port -> port_register -> OSPEEDR &= ~(1 << (port ->specs->pin_no)*2);
    port -> port_register -> OSPEEDR |= ((port->specs->gpio_output_speed) << (port->specs->pin_no)*2);

    port ->port_register ->PUPDR &= ~(0b11u << (port->specs->pin_no)*2);
    port ->port_register ->PUPDR |= ((port ->specs-> gpio_pull_up_down) << (port->specs->pin_no)*2);

    if(port -> specs ->pin_no <= 7){
        port -> port_register -> AFR[0] &= ~(0b1111u << (port -> specs->pin_no)*4);
        port -> port_register -> AFR[0] |= ((port ->specs->gpio_alternate_function_no) << (port -> specs->pin_no)*4);
    }
    else{
        port -> port_register -> AFR[1] &= ~(0b1111u << (port -> specs->pin_no)*4);
        port -> port_register -> AFR[1] |= ((port ->specs->gpio_alternate_function_no) << (port -> specs->pin_no)*4);
    }


}
// Note you must always enable a peripheral's clock before using it.
// Failing to do so will render your peripheral useless.
// Try commenting line 21 and see if ADC "SCAN" bit will be set.

#include <stdint.h>

#define ADC_Base_ADDR   		0x40012000UL
#define ADC_CR1_REG_OFFSET 		0x04UL
#define ADC_CR1_REG_ADDR    	(ADC_Base_ADDR + ADC_CR1_REG_OFFSET)


#define RCC_BASE_ADDR            0x40023800UL
#define RCC_APB2_ENR_OFFSET      0x44UL
#define RCC_APB2_ENR_ADDR        (RCC_BASE_ADDR + RCC_APB2_ENR_OFFSET)

int main(void)
{
    uint32_t* pADC_CTR_REG  = (uint32_t*)ADC_CR1_REG_ADDR;
    uint32_t* pRCC_APB2_ENR = (uint32_t*)RCC_APB2_ENR_ADDR;

    *pRCC_APB2_ENR |= (1 << 8);
    *pADC_CTR_REG  |= (1 << 8);

	for(;;);
}

#include "GPIO.h"

GPIO::GPIO()
{
	// Setup pinmux values
	pinmux[P8_3_DIG] = "gpmc_ad6";
	pinmux[P8_4_DIG] = "gpmc_ad7";
	pinmux[P8_5_DIG] = "gpmc_ad2";
	pinmux[P8_6_DIG] = "gpmc_ad3";
	pinmux[P8_7_DIG] = "gpmc_advn_ale";
	pinmux[P8_8_DIG] = "gpmc_oen_ren";
	pinmux[P8_9_DIG] = "gpmc_ben0_cle";
	pinmux[P8_10_DIG] = "gpmc_wen";
	pinmux[P8_11_DIG] = "gpmc_ad13";
	pinmux[P8_12_DIG] = "gpmc_ad12";
	pinmux[P8_13_DIG] = "gpmc_ad9";
	pinmux[P8_14_DIG] = "gpmc_ad10";
	pinmux[P8_15_DIG] = "gpmc_ad15";
	pinmux[P8_16_DIG] = "gpmc_ad14";
	pinmux[P8_17_DIG] = "gpmc_ad11";
	pinmux[P8_18_DIG] = "gpmc_clk";
	pinmux[P8_19_DIG] = "gpmc_ad8";
	pinmux[P8_20_DIG] = "gpmc_csn2";
	pinmux[P8_21_DIG] = "gpmc_csn1";
	pinmux[P8_22_DIG] = "gpmc_ad5";
	pinmux[P8_23_DIG] = "gpmc_ad4";
	pinmux[P8_24_DIG] = "gpmc_ad1";
	pinmux[P8_25_DIG] = "gpmc_ad0";
	pinmux[P8_26_DIG] = "gpmc_csn0";
	pinmux[P8_27_DIG] = "lcd_vsync";
	pinmux[P8_28_DIG] = "lcd_pclk";
	pinmux[P8_29_DIG] = "lcd_hsync";
	pinmux[P8_30_DIG] = "lcd_ac_bias_en";
	pinmux[P8_31_DIG] = "lcd_data14";
	pinmux[P8_32_DIG] = "lcd_data15";
	pinmux[P8_33_DIG] = "lcd_data13";
	pinmux[P8_34_DIG] = "lcd_data11";
	pinmux[P8_35_DIG] = "lcd_data12";
	pinmux[P8_36_DIG] = "lcd_data10";
	pinmux[P8_37_DIG] = "lcd_data8";
	pinmux[P8_38_DIG] = "lcd_data9";
	pinmux[P8_39_DIG] = "lcd_data6";
	pinmux[P8_40_DIG] = "lcd_data7";
	pinmux[P8_41_DIG] = "lcd_data4";
	pinmux[P8_42_DIG] = "lcd_data5";
	pinmux[P8_43_DIG] = "lcd_data2";
	pinmux[P8_44_DIG] = "lcd_data3";
	pinmux[P8_45_DIG] = "lcd_data0";
	pinmux[P8_46_DIG] = "lcd_data1";
	pinmux[P9_11_DIG] = "gpmc_wait0";
	pinmux[P9_12_DIG] = "gpmc_ben1";
	pinmux[P9_13_DIG] = "gpmc_wpn";
	pinmux[P9_14_DIG] = "gpmc_a2";
	pinmux[P9_15_DIG] = "gpmc_a0";
	pinmux[P9_16_DIG] = "gpmc_a3";
	pinmux[P9_17_DIG] = "spi0_cs0";
	pinmux[P9_18_DIG] = "spi0_d1";
	pinmux[P9_19_DIG] = "uart1_rtsn";
	pinmux[P9_20_DIG] = "uart1_ctsn";
	pinmux[P9_21_DIG] = "spi0_d0";
	pinmux[P9_22_DIG] = "spi0_sclk";
	pinmux[P9_23_DIG] = "gpmc_a1";
	pinmux[P9_24_DIG] = "uart1_txd";
	pinmux[P9_25_DIG] = "mcasp0_ahclkx";
	pinmux[P9_26_DIG] = "uart1_rxd";
	pinmux[P9_27_DIG] = "mcasp0_fsr";
	pinmux[P9_28_DIG] = "mcasp0_ahclkr";
	pinmux[P9_29_DIG] = "mcasp0_fsx";
	pinmux[P9_30_DIG] = "mcasp0_axr0";
	pinmux[P9_31_DIG] = "mcasp0_ahclkx";
	pinmux[P9_41_DIG] = "xdma_event_intr0";
	pinmux[P9_42_DIG] = "ecap0_in_pwm0_out";
}

GPIO::~GPIO() { }

void GPIO::pinMode(char pin, string direction) { }

void GPIO::digitalWrite(char pin, string value) { }

string GPIO::digitalRead(char pin) { }

void GPIO::analogWrite(char pin, string value) { }

string GPIO::analogRead(char pin) { }

void GPIO::pinUnexport(char pin) { }

void GPIO::cleanUp() { }
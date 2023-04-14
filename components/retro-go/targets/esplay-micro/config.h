// REF: https://www.makerfabs.com/esplay-micro-v2.html
// This port developed for the Micro V2 listed above. Compatibility with the elusive V1 is unknown.

// WORK IN PROGRESS!
// Issues: Menu, L, and R aren't properly mapped yet. Menu and Select are both mapped to Select for now.
// Battery meter isn't working yet.

// Parts:
// - ESP32-WROVER-B (SoC 16MB Flash + 8MB PSRAM)
// - PCF8574 I2C GPIO (To connect the extra buttons)
// - UDA1334A (I2S DAC)
// - YT240L010 (ILI9341 LCD)
// - TP4054 (Lipo Charger IC)
// - CH340C (USB to Serial)
// - 3.5mm Headphone jack 0_o

// Target definition
#define RG_TARGET_NAME             "ESPLAY-MICRO"

// Storage
#define RG_STORAGE_DRIVER           2                   // 0 = Host, 1 = SDSPI, 2 = SDMMC, 3 = USB, 4 = Flash
#define RG_STORAGE_HOST             SDMMC_HOST_SLOT_1   // Used by SDSPI and SDMMC
#define RG_STORAGE_SPEED            SDMMC_FREQ_DEFAULT  // Used by SDSPI and SDMMC
#define RG_STORAGE_ROOT             "/sd"               // Storage mount point

// Audio
#define RG_AUDIO_USE_INT_DAC        0   // 0 = Disable, 1 = GPIO25, 2 = GPIO26, 3 = Both
#define RG_AUDIO_USE_EXT_DAC        1   // 0 = Disable, 1 = Enable

// Video
#define RG_SCREEN_DRIVER            0   // 0 = ILI9341
#define RG_SCREEN_HOST              SPI2_HOST
#define RG_SCREEN_SPEED             SPI_MASTER_FREQ_40M
#define RG_SCREEN_TYPE              6
#define RG_SCREEN_WIDTH             320
#define RG_SCREEN_HEIGHT            240
#define RG_SCREEN_ROTATE            0
#define RG_SCREEN_MARGIN_TOP        0
#define RG_SCREEN_MARGIN_BOTTOM     0
#define RG_SCREEN_MARGIN_LEFT       0
#define RG_SCREEN_MARGIN_RIGHT      0

// Input
#define RG_GAMEPAD_DRIVER           3   // 1 = ODROID-GO, 2 = Serial, 3 = I2C, 4 = AW9523, 5 = ESPLAY-S3, 6 = SDL2
#define RG_GAMEPAD_HAS_MENU_BTN     1
#define RG_GAMEPAD_HAS_OPTION_BTN   0

// Note: Depending on the driver, the button map can be a bitmask, an index, or a GPIO.
// Refer to rg_input.h to see all available RG_KEY_*
// A and B silkscreen on the board are swapped relative to standard Nintendo layout
// Temporarily shared mapping between Menu and Select until Menu mapping is found.
#define RG_GAMEPAD_MAP {\
    {RG_KEY_UP,     (1<<2)},\
    {RG_KEY_RIGHT,  (1<<5)},\
    {RG_KEY_DOWN,   (1<<3)},\
    {RG_KEY_LEFT,   (1<<4)},\
    {RG_KEY_SELECT, (1<<1)},\
    {RG_KEY_START,  (1<<8)},\
    {RG_KEY_MENU,   (1<<1)},\
    {RG_KEY_A,      (1<<7)},\
    {RG_KEY_B,      (1<<6)},\
}

// Experimental. Caused "Menu" to be mapped to a D-pad direction.
//#define RG_GPIO_GAMEPAD_X           GPIO_NUM_NC
//#define RG_GPIO_GAMEPAD_Y           GPIO_NUM_NC
//#define RG_GPIO_GAMEPAD_SELECT      GPIO_NUM_0
//#define RG_GPIO_GAMEPAD_START       GPIO_NUM_36
//#define RG_GPIO_GAMEPAD_A           GPIO_NUM_32
//#define RG_GPIO_GAMEPAD_B           GPIO_NUM_33
//#define RG_GPIO_GAMEPAD_MENU        GPIO_NUM_35
//#define RG_GPIO_GAMEPAD_OPTION      GPIO_NUM_NC

// Battery
// #define RG_BATTERY_ADC_CHANNEL      ADC1_CHANNEL_3
#define RG_BATTERY_CALC_PERCENT(raw) (((raw) - 170) / 30.f * 100.f)
#define RG_BATTERY_CALC_VOLTAGE(raw) (0)

// Status LED
#define RG_GPIO_LED                 GPIO_NUM_13 // Causes the "power" LED to blink on disk access.

// I2C BUS
#define RG_GPIO_I2C_SDA             GPIO_NUM_21
#define RG_GPIO_I2C_SCL             GPIO_NUM_22

// Display
#define RG_GPIO_LCD_MISO            GPIO_NUM_NC
#define RG_GPIO_LCD_MOSI            GPIO_NUM_23
#define RG_GPIO_LCD_CLK             GPIO_NUM_18
#define RG_GPIO_LCD_CS              GPIO_NUM_5
#define RG_GPIO_LCD_DC              GPIO_NUM_12
#define RG_GPIO_LCD_BCKL            GPIO_NUM_27

// External I2S DAC
#define RG_GPIO_SND_I2S_BCK         GPIO_NUM_26
#define RG_GPIO_SND_I2S_WS          GPIO_NUM_25
#define RG_GPIO_SND_I2S_DATA        GPIO_NUM_19
#define RG_GPIO_SND_AMP_ENABLE      GPIO_NUM_4

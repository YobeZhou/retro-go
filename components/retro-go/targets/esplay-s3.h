// REF: https://wiki.odroid.com/odroid_go/odroid_go

// Target definition
#define RG_TARGET_NAME             "ESPLAY-S3"

// Storage
#define RG_STORAGE_DRIVER           1                   // 0 = Host, 1 = SDSPI, 2 = SDMMC, 3 = USB, 4 = Flash
#define RG_STORAGE_HOST             SDMMC_HOST_SLOT_1   // Used by driver 1 and 2
#define RG_STORAGE_SPEED            SDMMC_FREQ_DEFAULT  // Used by driver 1 and 2
#define RG_STORAGE_ROOT             "/sd"               // Storage mount point

// Audio
#define RG_AUDIO_USE_INT_DAC        0   // 0 = Disable, 1 = GPIO25, 2 = GPIO26, 3 = Both
#define RG_AUDIO_USE_EXT_DAC        1   // 0 = Disable, 1 = Enable

// Video
#define RG_SCREEN_DRIVER            5   // 0 = ILI9341
#define RG_SCREEN_HOST              SPI3_HOST
#define RG_SCREEN_SPEED             SPI_MASTER_FREQ_40M
#define RG_SCREEN_TYPE              5   // 4 = ESPLAY-ST7789V2
#define RG_SCREEN_WIDTH             320
#define RG_SCREEN_HEIGHT            480 /*240 480*/
#define RG_SCREEN_ROTATE            0
#define RG_SCREEN_MARGIN_TOP        0
#define RG_SCREEN_MARGIN_BOTTOM     0
#define RG_SCREEN_MARGIN_LEFT       0
#define RG_SCREEN_MARGIN_RIGHT      0

// Input
#define RG_GAMEPAD_DRIVER           3   // 1 = ODROID-GO, 2 = Serial, 3 = I2C
#define RG_GAMEPAD_HAS_MENU_BTN     1
#define RG_GAMEPAD_HAS_OPTION_BTN   1
// Note: Depending on the driver, the button map can represent bits, registers, keys, or gpios.
#if (RG_GAMEPAD_DRIVER == 3)    // 100ask PCA9555A
    #define RG_GAMEPAD_MAP_UP           (1<<0)
    #define RG_GAMEPAD_MAP_DOWN         (1<<1)
    #define RG_GAMEPAD_MAP_LEFT         (1<<2)
    #define RG_GAMEPAD_MAP_RIGHT        (1<<3)
    #define RG_GAMEPAD_MAP_A            (1<<4)
    #define RG_GAMEPAD_MAP_B            (1<<5)
    #define RG_GAMEPAD_MAP_X            (1<<6)
    #define RG_GAMEPAD_MAP_Y            (1<<7)
    #define RG_GAMEPAD_MAP_START        (1<<8)
    #define RG_GAMEPAD_MAP_SELECT       (1<<9)
    #define RG_GAMEPAD_MAP_MENU         (1<<10)
    #define RG_GAMEPAD_MAP_OPTION       (1<<11)
#elif (RG_GAMEPAD_DRIVER == 2)  // 100ask fc joypad
    #define RG_GAMEPAD_MAP_A            (1<<0)
    #define RG_GAMEPAD_MAP_B            (1<<1)
    #define RG_GAMEPAD_MAP_SELECT       (1<<2)
    //#define RG_GAMEPAD_MAP_START        (1<<3)
    #define RG_GAMEPAD_MAP_MENU         (1<<3)
    #define RG_GAMEPAD_MAP_UP           (1<<4)
    #define RG_GAMEPAD_MAP_DOWN         (1<<5)
    #define RG_GAMEPAD_MAP_LEFT         (1<<6)
    #define RG_GAMEPAD_MAP_RIGHT        (1<<7)
    //#define RG_GAMEPAD_MAP_MENU         (1<<8)
    //#define RG_GAMEPAD_MAP_OPTION       (1<<11)
#endif


// Battery
#define RG_BATTERY_ADC_CHANNEL      ADC1_CHANNEL_1
#define RG_BATTERY_CALC_PERCENT(raw) (((raw) * 2.f - 3500.f) / (4200.f - 3500.f) * 100.f)
#define RG_BATTERY_CALC_VOLTAGE(raw) ((raw) * 2.f * 0.001f)

// Status LED
#define RG_GPIO_LED                 GPIO_NUM_38

// I2C BUS
#define RG_GPIO_I2C_SDA             GPIO_NUM_40
#define RG_GPIO_I2C_SCL             GPIO_NUM_41

// Built-in gamepad
//#define RG_GPIO_GAMEPAD_L           GPIO_NUM_40
//#define RG_GPIO_GAMEPAD_R           GPIO_NUM_41
//#define RG_GPIO_GAMEPAD_MENU        GPIO_NUM_42
//#define RG_GPIO_GAMEPAD_OPTION      GPIO_NUM_41

// SNES-style gamepad
#define RG_GPIO_GAMEPAD_LATCH       GPIO_NUM_41
#define RG_GPIO_GAMEPAD_CLOCK       GPIO_NUM_40
#define RG_GPIO_GAMEPAD_DATA        GPIO_NUM_42

// SPI Display
#define RG_GPIO_LCD_MISO            GPIO_NUM_NC
#define RG_GPIO_LCD_MOSI            GPIO_NUM_11
#define RG_GPIO_LCD_CLK             GPIO_NUM_12
#define RG_GPIO_LCD_CS              GPIO_NUM_10
#define RG_GPIO_LCD_DC              GPIO_NUM_5
#define RG_GPIO_LCD_BCKL            GPIO_NUM_7
#define RG_GPIO_LCD_RST             GPIO_NUM_6

// SPI SD Card
//#define RG_GPIO_SDSPI_CMD          GPIO_NUM_41
//#define RG_GPIO_SDSPI_CLK          GPIO_NUM_40
//#define RG_GPIO_SDSPI_D0           GPIO_NUM_39

#define RG_GPIO_SDSPI_MISO          GPIO_NUM_18
#define RG_GPIO_SDSPI_MOSI          GPIO_NUM_17
#define RG_GPIO_SDSPI_CLK           GPIO_NUM_16
#define RG_GPIO_SDSPI_CS            GPIO_NUM_15

// External I2S DAC
#define RG_GPIO_SND_I2S_BCK         GPIO_NUM_2
#define RG_GPIO_SND_I2S_WS          GPIO_NUM_3
#define RG_GPIO_SND_I2S_DATA        GPIO_NUM_4
//#define RG_GPIO_SND_AMP_ENABLE      GPIO_NUM_9
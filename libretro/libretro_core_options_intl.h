#ifndef LIBRETRO_CORE_OPTIONS_INTL_H__
#define LIBRETRO_CORE_OPTIONS_INTL_H__

#if defined(_MSC_VER) && (_MSC_VER >= 1500 && _MSC_VER < 1900)
/* https://support.microsoft.com/en-us/kb/980263 */
#pragma execution_character_set("utf-8")
#pragma warning(disable:4566)
#endif

#include <libretro.h>

/*
 ********************************
 * VERSION: 2.0
 ********************************
 *
 * - 2.0: Add support for core options v2 interface
 * - 1.3: Move translations to libretro_core_options_intl.h
 *        - libretro_core_options_intl.h includes BOM and utf-8
 *          fix for MSVC 2010-2013
 *        - Added HAVE_NO_LANGEXTRA flag to disable translations
 *          on platforms/compilers without BOM support
 * - 1.2: Use core options v1 interface when
 *        RETRO_ENVIRONMENT_GET_CORE_OPTIONS_VERSION is >= 1
 *        (previously required RETRO_ENVIRONMENT_GET_CORE_OPTIONS_VERSION == 1)
 * - 1.1: Support generation of core options v0 retro_core_option_value
 *        arrays containing options with a single value
 * - 1.0: First commit
*/

#ifdef __cplusplus
extern "C" {
#endif

/*
 ********************************
 * Core Option Definitions
 ********************************
*/

/* RETRO_LANGUAGE_JAPANESE */

/* RETRO_LANGUAGE_FRENCH */

/* RETRO_LANGUAGE_SPANISH */

/* RETRO_LANGUAGE_GERMAN */

/* RETRO_LANGUAGE_ITALIAN */

/* RETRO_LANGUAGE_DUTCH */

/* RETRO_LANGUAGE_PORTUGUESE_BRAZIL */

/* RETRO_LANGUAGE_PORTUGUESE_PORTUGAL */

/* RETRO_LANGUAGE_RUSSIAN */

/* RETRO_LANGUAGE_KOREAN */

/* RETRO_LANGUAGE_CHINESE_TRADITIONAL */

/* RETRO_LANGUAGE_CHINESE_SIMPLIFIED */
struct retro_core_option_v2_category option_cats_chs[] = {
   {
      "system",
      "系统",
      "配置基本硬件选择。"
   },
   {
      "video",
      "视频",
      "配置显示参数：调色板、色彩校正、屏幕边框。"
   },
   {
      "audio",
      "音频",
      "配置音频模拟：高通滤波器、电干扰。"
   },
   {
      "input",
      "输入",
      "配置输入参数：震动支持。"
   },
   { NULL, NULL, NULL },
};

struct retro_core_option_v2_definition option_defs_chs[] = {

   /* Core options used in single cart mode */

   {
      "sameboy_model",
      "系统 - 模拟硬件型号（需要重启）",
      "模拟硬件型号（需要重启）",
      "选择游戏应该以何种系统型号启动。某些游戏在特定型号上可能会激活特殊的游戏内功能。改变此选项须要重启游戏才能生效。",
      NULL,
      "system",
      {
         { "Auto",                 "自动检测DMG/CGB"                       },
         { "Auto (SGB)",           "自动检测DMG/SGB/CGB"                   },
         { "Game Boy",             "Game Boy (DMG-CPU B)"                      },
         { "Game Boy Color C",     "Game Boy Color (CPU-CGB C) (试验性)" },
         { "Game Boy Color",       "Game Boy Color (CPU-CGB E)"                },
         { "Game Boy Advance",     NULL },
         { "Super Game Boy",       "Super Game Boy NTSC"                       },
         { "Super Game Boy PAL",   NULL },
         { "Super Game Boy 2",     NULL },
         { NULL, NULL },
      },
      "Auto"
   },
   {
      "sameboy_auto_sgb_model",
      "系统 - 自动检测的SGB型号（需要重启）",
      "自动检测的SGB型号（需要重启）",
      "当自动检测到SGB游戏时，指定模拟何种型号的Super Game Boy硬件。改变此选项须要重启游戏才能生效。",
      NULL,
      "system",
      {
         { "Super Game Boy",       "Super Game Boy NTSC" },
         { "Super Game Boy PAL",   NULL },
         { "Super Game Boy 2",     NULL },
         { NULL, NULL },
      },
      "Super Game Boy"
   },
   {
      "sameboy_rtc",
      "系统 - 实时时钟模拟",
      "实时时钟模拟",
      "指定在某些使用实时时钟的Game Boy和Game Boy游戏中，如何模拟实时时钟功能。",
      NULL,
      "system",
      {
         { "sync to system clock", "和系统时钟同步" },
         { "accurate",             "精确模拟"             },
         { NULL, NULL },
      },
      "sync to system clock"
   },
   {
      "sameboy_mono_palette",
      "视频 - GB单色调色板",
      "GB单色调色板",
      "选择运行GB游戏时使用的调色板。",
      NULL,
      "video",
      {
         { "greyscale", "灰阶"               },
         { "lime",      "石灰色 (Game Boy)"         },
         { "olive",     "橄榄色 (Game Boy Pocket)" },
         { "teal",      "蓝绿色 (Game Boy Light)"   },
         { NULL, NULL },
      },
      "greyscale"
   },
   {
      "sameboy_color_correction_mode",
      "视频 - GBC色彩校正",
      "GBC色彩校正",
      "选择运行GBC游戏使用的色彩校正方式。",
      NULL,
      "video",
      {
         { "emulate hardware",    "现代 – 平衡"            },
         { "accurate",            "现代 – 精确"            },
         { "preserve brightness", "现代 – 增强对比度"      },
         { "reduce contrast",     "降低对比度"              },
         { "correct curves",      "校正色彩曲线"         },
         { "harsh reality",       "残酷现实 (低对比度)" },
         { "off",                 "禁用"                     },
         { NULL, NULL },
      },
      "emulate hardware"
   },
   {
      "sameboy_light_temperature",
      "视频 - 环境光色温",
      "环境光色温",
      "通过设置自定义的色温值，在Game Boy的非背光屏上模拟环境光效果。如果游戏运行于原始Game Boy (DMG) 的模拟型号上时，此选项无效。",
      NULL,
      "video",
      {
         { "1.0",   "1000K (最暖光)"       },
         { "0.9",   "1550K" },
         { "0.8",   "2100K" },
         { "0.7",   "2650K" },
         { "0.6",   "3200K" },
         { "0.5",   "3750K" },
         { "0.4",   "4300K" },
         { "0.3",   "4850K" },
         { "0.2",   "5400K" },
         { "0.1",   "5950K" },
         { "0",     "6500K (中性白光)" },
         { "-0.1",  "7050K" },
         { "-0.2",  "7600K" },
         { "-0.3",  "8150K" },
         { "-0.4",  "8700K" },
         { "-0.5",  "9250K" },
         { "-0.6",  "9800K" },
         { "-0.7", "10350K" },
         { "-0.8", "10900K" },
         { "-0.9", "11450K" },
         { "-1.0", "12000K (最冷光)"       },
         { NULL, NULL },
      },
      "0"
   },
   {
      "sameboy_border",
      "视频 - 显示边框",
      "显示边框",
      "指定何时显示屏幕边框。",
      NULL,
      "video",
      {
         { "always",              "总是"                  },
         { "Super Game Boy only", "只在Super Game Boy" },
         { "never",               "禁用"                },
         { NULL, NULL },
      },
      "Super Game Boy only"
   },
   {
      "sameboy_high_pass_filter_mode",
      "音频 - 高通滤波器",
      "高通滤波器",
      "在音频输出上应用一个滤波器，用来消除某些由于直流偏移引起的杂音。如果此项禁用，声音将和Game Boy的APU输出保持一致，当模拟器暂停和恢复时会听到杂音。‘精确’模式应用一个全局滤波器，屏蔽杂音的同时也会削减部分低频。‘保留波形’模式只过滤直流偏移。",
      NULL,
      "audio",
      {
         { "accurate",         "精确"              },
         { "remove dc offset", "保留波形"     },
         { "off",              "禁用"              },
         { NULL, NULL },
      },
      "accurate"
   },
   {
      "sameboy_audio_interference",
      "音频 - 干扰声音量",
      "干扰声音量",
      "控制由于Game Boy电路板和扬声器之间的电子干扰引起的电流声的音量大小。",
      NULL,
      "audio",
      {
         { "0",   "0%"   },
         { "5",   "5%"   },
         { "10",  "10%"  },
         { "15",  "15%"  },
         { "20",  "20%"  },
         { "25",  "25%"  },
         { "30",  "30%"  },
         { "35",  "35%"  },
         { "40",  "40%"  },
         { "45",  "45%"  },
         { "50",  "50%"  },
         { "55",  "55%"  },
         { "60",  "60%"  },
         { "65",  "65%"  },
         { "70",  "70%"  },
         { "75",  "75%"  },
         { "80",  "80%"  },
         { "85",  "85%"  },
         { "90",  "90%"  },
         { "95",  "95%"  },
         { "100", "100%" },
         { NULL, NULL },
      },
      "0"
   },
   {
      "sameboy_rumble",
      "输入 - 震动模式",
      "震动模式",
      "指定在何种类型游戏中使用震动效果。",
      NULL,
      "input",
      {
         { "all games",            "总是"                        },
         { "rumble-enabled games", "只在支持震动的游戏" },
         { "never",                "从不"                      },
         { NULL, NULL },
      },
      "rumble-enabled games"
   },

   /* Core options used in dual cart mode */

   {
      "sameboy_link",
      "系统 - 联机线模拟",
      "联机线模拟",
      "模拟联机线，允许在两个Game Boy系统之间通讯和交换数据。",
      NULL,
      "system",
      {
         { "enabled",  "启用" },
         { "disabled", "禁用" },
         { NULL, NULL },
      },
      "enabled"
   },
   {
      "sameboy_screen_layout",
      "系统 - 屏幕布局",
      "屏幕布局",
      "当同时模拟两个Game Boy系统时，指定两个屏幕的相对位置。",
      NULL,
      "system",
      {
      { "top-down",   "上下布局"   },
         { "left-right", "左右布局" },
         { NULL, NULL },
      },
      "top-down"
   },
   {
      "sameboy_audio_output",
      "系统 - 音频输出",
      "音频输出",
      "当同时模拟两个Game Boy系统时，选择输出哪个系统的音频。",
      NULL,
      "system",
      {
         { "Game Boy #1", NULL },
         { "Game Boy #2", NULL },
         { NULL, NULL },
      },
      "Game Boy #1"
   },
   {
      "sameboy_model_1",
      "系统 - 模拟硬件类型 #1（需要重启）",
      "模拟硬件类型 #1（需要重启）",
      "选择1#系统上的游戏应该以何种系统型号启动。某些游戏在特定型号上可能会激活特殊的游戏内功能。改变此选项须要重启游戏才能生效。",
      NULL,
      "system",
      {
         { "Auto",                 "自动检测DMG/CGB"                       },
         { "Auto (SGB)",           "自动检测DMG/SGB/CGB"                   },
         { "Game Boy",             "Game Boy (DMG-CPU B)"                      },
         { "Game Boy Color C",     "Game Boy Color (CPU-CGB C) (试验性)" },
         { "Game Boy Color",       "Game Boy Color (CPU-CGB E)"                },
         { "Game Boy Advance",     NULL },
         { "Super Game Boy",       "Super Game Boy NTSC"                       },
         { "Super Game Boy PAL",   NULL },
         { "Super Game Boy 2",     NULL },
         { NULL, NULL },
      },
      "Auto"
   },
   {
      "sameboy_auto_sgb_model_1",
      "系统 - 自动检测的SGB型号 #1（需要重启）",
      "自动检测的SGB型号 #1（需要重启）",
      "指定#1系统上当自动检测到SGB游戏时，模拟何种型号的Super Game Boy硬件。改变此选项须要重启游戏才能生效。",
      NULL,
      "system",
      {
         { "Super Game Boy",       "Super Game Boy NTSC" },
         { "Super Game Boy PAL",   NULL },
         { "Super Game Boy 2",     NULL },
         { NULL, NULL },
      },
      "Super Game Boy"
   },
   {
      "sameboy_model_2",
      "系统 - 模拟硬件类型 #2（需要重启）",
      "模拟硬件类型 #2（需要重启）",
      "选择#2系统上的游戏应该以何种系统型号启动。某些游戏在特定型号上可能会激活特殊的游戏内功能。改变此选项须要重启游戏才能生效。",
      NULL,
      "system",
      {
         { "Auto",                 "Auto Detect DMG/CGB"                       },
         { "Auto (SGB)",           "Auto Detect DMG/SGB/CGB"                   },
         { "Game Boy",             "Game Boy (DMG-CPU B)"                      },
         { "Game Boy Color C",     "Game Boy Color (CPU-CGB C) (Experimental)" },
         { "Game Boy Color",       "Game Boy Color (CPU-CGB E)"                },
         { "Game Boy Advance",     NULL },
         { "Super Game Boy",       "Super Game Boy NTSC"                       },
         { "Super Game Boy PAL",   NULL },
         { "Super Game Boy 2",     NULL },
         { NULL, NULL },
      },
      "Auto"
   },
   {
      "sameboy_auto_sgb_model_2",
      "系统 - 自动检测的SGB型号 #2（需要重启）",
      "自动检测的SGB型号 #2（需要重启）",
      "指定#2系统上当自动检测到SGB游戏时，模拟何种型号的Super Game Boy硬件。改变此选项须要重启游戏才能生效。",
      NULL,
      "system",
      {
         { "Super Game Boy",       "Super Game Boy NTSC" },
         { "Super Game Boy PAL",   NULL },
         { "Super Game Boy 2",     NULL },
         { NULL, NULL },
      },
      "Super Game Boy"
   },
   {
      "sameboy_mono_palette_1",
      "视频 - GB单色调色板 #1",
      "GB单色调色板 #1",
      "选择#1系统上运行GB游戏时使用的调色板。",
      NULL,
      "video",
      {
         { "greyscale", "灰阶"               },
         { "lime",      "石灰色 (Game Boy)"         },
         { "olive",     "橄榄色 (Game Boy Pocket)" },
         { "teal",      "蓝绿色 (Game Boy Light)"   },
         { NULL, NULL },
      },
      "greyscale"
   },
   {
      "sameboy_mono_palette_2",
      "视频 - GB单色调色板 #1",
      "GB单色调色板 #2",
      "选择#2系统上运行GB游戏时使用的调色板。",
      NULL,
      "video",
      {
         { "greyscale", "灰阶"               },
         { "lime",      "石灰色 (Game Boy)"         },
         { "olive",     "橄榄色 (Game Boy Pocket)" },
         { "teal",      "蓝绿色 (Game Boy Light)"   },
         { NULL, NULL },
      },
      "greyscale"
   },
   {
      "sameboy_color_correction_mode_1",
      "视频 - GBC色彩校正 #1",
      "GBC色彩校正 #1",
      "选择#1系统运行GBC游戏使用的色彩校正方式。",
      NULL,
      "video",
      {
         { "emulate hardware",    "现代 – 平衡"            },
         { "accurate",            "现代 – 精确"            },
         { "preserve brightness", "现代 – 增强对比度"      },
         { "reduce contrast",     "降低对比度"              },
         { "correct curves",      "校正色彩曲线"         },
         { "harsh reality",       "残酷现实 (低对比度)" },
         { "off",                 "禁用"                     },
         { NULL, NULL },
      },
      "emulate hardware"
   },
   {
      "sameboy_color_correction_mode_2",
      "视频 - GBC色彩校正 #2",
      "GBC色彩校正 #2",
      "选择#2系统运行GBC游戏使用的色彩校正方式。",
      NULL,
      "video",
      {
         { "emulate hardware",    "现代 – 平衡"            },
         { "accurate",            "现代 – 精确"            },
         { "preserve brightness", "现代 – 增强对比度"      },
         { "reduce contrast",     "降低对比度"              },
         { "correct curves",      "校正色彩曲线"         },
         { "harsh reality",       "残酷现实 (低对比度)" },
         { "off",                 "禁用"                     },
         { NULL, NULL },
      },
      "emulate hardware"
   },
   {
      "sameboy_light_temperature_1",
      "视频 - 环境光色温 #1",
      "环境光色温 #1",
      "通过设置自定义的色温值，在Game Boy的非背光屏上模拟环境光效果。如果游戏运行于原始Game Boy (DMG) 的模拟型号上时，此选项无效。",
      NULL,
      "video",
      {
         { "1.0",   "1000K (最暖光)"       },
         { "0.9",   "1550K" },
         { "0.8",   "2100K" },
         { "0.7",   "2650K" },
         { "0.6",   "3200K" },
         { "0.5",   "3750K" },
         { "0.4",   "4300K" },
         { "0.3",   "4850K" },
         { "0.2",   "5400K" },
         { "0.1",   "5950K" },
         { "0",     "6500K (中性白光)" },
         { "-0.1",  "7050K" },
         { "-0.2",  "7600K" },
         { "-0.3",  "8150K" },
         { "-0.4",  "8700K" },
         { "-0.5",  "9250K" },
         { "-0.6",  "9800K" },
         { "-0.7", "10350K" },
         { "-0.8", "10900K" },
         { "-0.9", "11450K" },
         { "-1.0", "12000K (最冷光)"       },
         { NULL, NULL },
      },
      "0"
   },
   {
      "sameboy_light_temperature_2",
      "视频 - 环境光色温 #2",
      "环境光色温 #2",
      "通过设置自定义的色温值，在Game Boy的非背光屏上模拟环境光效果。如果游戏运行于原始Game Boy (DMG) 的模拟型号上时，此选项无效。",
      NULL,
      "video",
      {
         { "1.0",   "1000K (最暖光)"       },
         { "0.9",   "1550K" },
         { "0.8",   "2100K" },
         { "0.7",   "2650K" },
         { "0.6",   "3200K" },
         { "0.5",   "3750K" },
         { "0.4",   "4300K" },
         { "0.3",   "4850K" },
         { "0.2",   "5400K" },
         { "0.1",   "5950K" },
         { "0",     "6500K (中性白光)" },
         { "-0.1",  "7050K" },
         { "-0.2",  "7600K" },
         { "-0.3",  "8150K" },
         { "-0.4",  "8700K" },
         { "-0.5",  "9250K" },
         { "-0.6",  "9800K" },
         { "-0.7", "10350K" },
         { "-0.8", "10900K" },
         { "-0.9", "11450K" },
         { "-1.0", "12000K (最冷光)"       },
         { NULL, NULL },
      },
      "0"
   },
   {
      "sameboy_high_pass_filter_mode_1",
      "音频 - 高通滤波器 #1",
      "高通滤波器 #1",
      "在音频输出上应用一个滤波器，用来消除某些由于直流偏移引起的杂音。如果此项禁用，声音将和Game Boy的APU输出保持一致，当模拟器暂停和恢复时会听到杂音。‘精确’模式应用一个全局滤波器，屏蔽杂音的同时也会削减部分低频。‘保留波形’模式只过滤直流偏移。",
      NULL,
      "audio",
      {
         { "accurate",         "精确"              },
         { "remove dc offset", "保留波形"     },
         { "off",              "禁用"              },
         { NULL, NULL },
      },
      "accurate"
   },
   {
      "sameboy_high_pass_filter_mode_2",
      "音频 - 高通滤波器 #2",
      "高通滤波器 #2",
      "在音频输出上应用一个滤波器，用来消除某些由于直流偏移引起的杂音。如果此项禁用，声音将和Game Boy的APU输出保持一致，当模拟器暂停和恢复时会听到杂音。‘精确’模式应用一个全局滤波器，屏蔽杂音的同时也会削减部分低频。‘保留波形’模式只过滤直流偏移。",
      NULL,
      "audio",
      {
         { "accurate",         "精确"              },
         { "remove dc offset", "保留波形"     },
         { "off",              "禁用"              },
         { NULL, NULL },
      },
      "accurate"
   },
   {
      "sameboy_audio_interference_1",
      "音频 - 干扰声音量 #1",
      "干扰声音量 #1",
      "控制由于Game Boy电路板和扬声器之间的电子干扰引起的电流声的音量大小。",
      NULL,
      "audio",
      {
         { "0",   "0%"   },
         { "5",   "5%"   },
         { "10",  "10%"  },
         { "15",  "15%"  },
         { "20",  "20%"  },
         { "25",  "25%"  },
         { "30",  "30%"  },
         { "35",  "35%"  },
         { "40",  "40%"  },
         { "45",  "45%"  },
         { "50",  "50%"  },
         { "55",  "55%"  },
         { "60",  "60%"  },
         { "65",  "65%"  },
         { "70",  "70%"  },
         { "75",  "75%"  },
         { "80",  "80%"  },
         { "85",  "85%"  },
         { "90",  "90%"  },
         { "95",  "95%"  },
         { "100", "100%" },
         { NULL, NULL },
      },
      "0"
   },
   {
      "sameboy_audio_interference_2",
      "音频 - 干扰声音量 #2",
      "干扰声音量 #2",
      "控制由于Game Boy电路板和扬声器之间的电子干扰引起的电流声的音量大小。",
      NULL,
      "audio",
      {
         { "0",   "0%"   },
         { "5",   "5%"   },
         { "10",  "10%"  },
         { "15",  "15%"  },
         { "20",  "20%"  },
         { "25",  "25%"  },
         { "30",  "30%"  },
         { "35",  "35%"  },
         { "40",  "40%"  },
         { "45",  "45%"  },
         { "50",  "50%"  },
         { "55",  "55%"  },
         { "60",  "60%"  },
         { "65",  "65%"  },
         { "70",  "70%"  },
         { "75",  "75%"  },
         { "80",  "80%"  },
         { "85",  "85%"  },
         { "90",  "90%"  },
         { "95",  "95%"  },
         { "100", "100%" },
         { NULL, NULL },
      },
      "0"
   },
   {
      "sameboy_rumble_1",
      "输入 - 震动模式 #1",
      "震动模式 #1",
      "指定在何种类型游戏中使用震动效果。",
      NULL,
      "input",
      {
         { "all games",            "总是"                        },
         { "rumble-enabled games", "只在支持震动的游戏" },
         { "never",                "从不"                         },
         { NULL, NULL },
      },
      "rumble-enabled games"
   },
   {
      "sameboy_rumble_2",
      "输入 - 震动模式 #2",
      "震动模式 #2",
      "指定在何种类型游戏中使用震动效果。",
      NULL,
      "input",
      {
         { "all games",            "总是"                        },
         { "rumble-enabled games", "只在支持震动的游戏" },
         { "never",                "从不"                         },
         { NULL, NULL },
      },
      "rumble-enabled games"
   },

   { NULL, NULL, NULL, NULL, NULL, NULL, {{0}}, NULL },
};

struct retro_core_options_v2 options_chs = {
   option_cats_chs,
   option_defs_chs
};

/* RETRO_LANGUAGE_ESPERANTO */

/* RETRO_LANGUAGE_POLISH */

/* RETRO_LANGUAGE_VIETNAMESE */

/* RETRO_LANGUAGE_ARABIC */

/* RETRO_LANGUAGE_GREEK */

/* RETRO_LANGUAGE_TURKISH */

/* RETRO_LANGUAGE_SLOVAK */

/* RETRO_LANGUAGE_PERSIAN */

/* RETRO_LANGUAGE_HEBREW */

/* RETRO_LANGUAGE_ASTURIAN */

/* RETRO_LANGUAGE_FINNISH */

#ifdef __cplusplus
}
#endif

#endif

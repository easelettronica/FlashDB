/*
 * File      : fal_cfg.h
 * COPYRIGHT (C) 2012-2018, Shanghai Real-Thread Technology Co., Ltd
 *
 * Change Logs:
 * Date           Author       Notes
 * 2018-05-17     armink       the first version
 */
#ifndef _FAL_CFG_H_
#define _FAL_CFG_H_

/* ===================== Flash device Configuration ========================= */
extern const struct fal_flash_dev ext_flash_dev;

/* flash device table */
#define FAL_FLASH_DEV_TABLE                                                                                                                                    \
  {                                                                                                                                                            \
    &ext_flash_dev,                                                                                                                                            \
  }
/* ====================== Partition Configuration ========================== */
#define FAL_PART_HAS_TABLE_CFG
#ifdef FAL_PART_HAS_TABLE_CFG

#define FDB_OFFSET              (0x00000000)

#define DB_GENERAL_SETTINGS_OFF FDB_OFFSET
#define DB_GENERAL_SETTINGS_LEN (0x20000)

/*
 * Partition table
 *
 * Attenzione: name è un array di massimo 24 byte --> quindi 23 caratteri + \0
 *
 *
 */
#define FAL_PART_TABLE                                                                                                                                         \
  {                                                                                                                                                            \
    {                                                                                                                                                          \
      .magic_word = FAL_PART_MAGIC_WORD,                                                                                                                       \
      .name = "DB_GenSettings",                                                                                                                                \
      .flash_name = "ext_flash",                                                                                                                               \
      .offset = DB_GENERAL_SETTINGS_OFF,                                                                                                                       \
      .len = DB_GENERAL_SETTINGS_LEN,                                                                                                                          \
      .reserved = 0,                                                                                                                                           \
    },                                                                                                                                                         \
  }
#endif /* FAL_PART_HAS_TABLE_CFG */

static inline void
printf_nop(const char* fmt, ...) {}

#ifdef DEBUG
#define FAL_PRINTF printf_nop
#else
#define FAL_PRINTF printf_nop
#endif

#endif /* _FAL_CFG_H_ */

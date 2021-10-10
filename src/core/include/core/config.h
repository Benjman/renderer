#ifndef CONFIG_H
#define CONFIG_H

/**
 * This file is generated through a cmake Config.h.in
 */

#define RES_DIR "/home/ben/src/renderer/res/"
#define RES_PATH(rel_path) std::string(std::string(RES_DIR) + rel_path).c_str()
/* #undef IS_DEBUG */

#endif // CONFIG_H

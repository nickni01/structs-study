#ifndef _UTILS_H
#define _UTILS_H

#ifdef __cplusplus
extern "C" {
#endif /*__cplusplus*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

/* MACRO define */
#define ARRAY_SIZE(_a_) ((size_t)(sizeof(_a_)/sizeof((_a_)[0])))
#define MAX(_a_, _b_) (((_a_)>(_b_))?(_a_):(_b_))
#define MIN(_a_, _b_) (((_a_)<(_b_))?(_a_):(_b_))
#define UTILS_ARRAY_SIZE(__a) ARRAY_SIZE(__a)
#define UTILS_MAX(__a, __b) MAX(__a, __b)
#define UTILS_MIN(__a, __b) MIN(__a, __b)
#define UTILS_ASCII_TO_INT(__x) (((__x) - '0'))
#define UTILS_INT_TO_ASCII(__x) (((__x) + '0'))

#define LOG printf("%s:%d on func:(%s) -- ",__FILE__,__LINE__,__FUNCTION__);printf
#define LOG_LINE() printf("\n------------------------------------------------------------------")
#define LOG_LINE_WITH_TR() printf("\n------------------------------------------------------------------\n");
#define LOG_ERR LOG
#define UTILS_CHECK_RET(err)                                                     \
    do {                                                                         \
        if (ret != 0) {                                                          \
            LOG_ERR("Operation failed: err= 0x%x\n", err);                       \
            ret  = -1;                                                           \
            goto finish;                                                         \
        }                                                                        \
    } while(0)
#define UTILS_CHECK_BOOL(err)                                                    \
    do {                                                                         \
        if (ret_b != true) {                                                     \
            LOG_ERR("Operation failed: err= 0x%x\n", err);                       \
            ret_b  = false;                                                      \
            goto finish;                                                         \
        }                                                                        \
    } while(0)
#define UTILS_CHECK_PTR(p)                                                       \
    do {                                                                         \
        if (NULL == (p)) {                                                       \
            LOG_ERR("pointer is NULL\n");                                        \
            ret  = -1;                                                           \
            goto finish;                                                         \
        }                                                                        \
    } while(0)
#define UTILS_CHECK_TEST_RESULT(ret1, ret2)                                      \
    do {                                                                         \
        if ((ret1) == (ret2)) {                                                  \
            LOG("Test PASS!\n");                                                 \
        } else {                                                                 \
            LOG("Test FAILED!\n");                                               \
        }                                                                        \
    } while(0)
#define UTILS_CHECK_LEN(ret)                                                     \
    do {                                                                         \
        if ((ret) == (0)) {                                                      \
            goto finish;                                                         \
        }                                                                        \
    } while(0)
#define UTILS_CHECK_CONDITION(err_condition, ret_code, format, ...)            \
    do {                                                                       \
        if ((err_condition)) {                                                 \
            printf("%s line:%d. Error number is 0x%x \n", __func__, __LINE__,  \
                ret);                                                          \
            printf(format, ##__VA_ARGS__);                                     \
            ret = ret_code;                                                    \
            goto finish;                                                       \
        }                                                                      \
    } while (0)
#define UTILS_SAFE_FREE(_p)                                                     \
    do {                                                                        \
        if ((_p) != NULL) {                                                     \
            free((_p));                                                         \
            (_p) = NULL;                                                        \
        }                                                                       \
    } while(0)
#ifdef __cplusplus
}
#endif /*__cplusplus*/

#endif
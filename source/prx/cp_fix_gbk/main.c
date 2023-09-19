#include <pspsdk.h>
#include "systemctrl.h"

PSP_MODULE_INFO("cp_fix_gbk", 0x1007, 1, 0);

/* supported codepages */
#define CP000  0x00 //ASCII
#define CP437  0x01 //US
#define CP850  0x05 //Multilingual Latin I
#define CP866  0x0b //Russian
#define CP932  0x0d //S-JIS
#define CP936  0x0e //GBK
#define CP949  0x0f //Korean
#define CP950  0x10 //Big5
#define CP1251 0x12 //Cyrillic
#define CP1252 0x13 //Latin II

#define MAKE_JUMP(a, f) _sw(0x08000000 | (((u32)(f) & 0x0FFFFFFC) >> 2), a);

//by Davee
#define HIJACK_FUNCTION(a, f, ptr) \
{ \
    u32 _func_ = a; \
    static u32 patch_buffer[3]; \
    _sw(_lw(_func_), (u32)patch_buffer); \
    _sw(_lw(_func_ + 4), (u32)patch_buffer + 8);\
    MAKE_JUMP((u32)patch_buffer + 4, _func_ + 8); \
    _sw(0x08000000 | (((u32)(f) >> 2) & 0x03FFFFFF), _func_); \
    _sw(0, _func_ + 4); \
    ptr = (void *)patch_buffer; \
}

int (*sceCodepage_set_cp)(u32 cp);
u32 last_cp = 0xff;

int sceCodepage_set_cp_pathed(u32 cp)
{
    if (cp == CP932) {
        cp = CP936;
    }
    if (last_cp == cp) {
        return 0;
    }
    return sceCodepage_set_cp(cp);
}

void hook_codepage(void)
{
    u32 func = sctrlHENFindFunction("sceCodepage_Service", "sceCodepage_driver", 0xB0AE63AA);
    if (func == 0) {
        return;
    }

    HIJACK_FUNCTION(func, sceCodepage_set_cp_pathed, sceCodepage_set_cp);

    sceKernelDcacheWritebackAll();
    sceKernelIcacheClearAll();
}

int module_start(SceSize args, void *argp)
{
    hook_codepage();

	return 0;
}

int module_stop(void)
{
    return 0;
}

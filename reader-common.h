#define ADDRLEN      4    // Address length in EMM commands
#define MAX_PROV     16

//Warning: OK = 0 and ERROR = 1 in csctapi !!!
#define SKIPPED 2
#define OK			1
#define ERROR 	0
#include "csctapi/atr.h" 
#define write_cmd(cmd, data) \
{ \
        if (card_write(reader, cmd, data, cta_res, &cta_lr)) return ERROR; \
}

#define get_atr \
		unsigned char atr[ATR_MAX_SIZE]; \
		uint32_t atr_size; \
		memset(atr, 0, sizeof(atr)); \
		ATR_GetRaw(newatr, atr, &atr_size);

#define get_hist \
		unsigned char hist[ATR_MAX_HISTORICAL]; \
		uint32_t hist_size = 0; \
		ATR_GetHistoricalBytes(newatr, hist, &hist_size);

#define def_resp \
		unsigned char cta_res[CTA_RES_LEN]; \
		memset(cta_res, 0, CTA_RES_LEN); \
		uint16_t cta_lr;

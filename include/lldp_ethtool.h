#ifndef _LLDP_ETHTOOL_H
#define _LLDP_ETHTOOL_H

#include <linux/types.h>
#include <stdbool.h>

struct ethtool_mm {
	bool supported;
	bool tx_enabled;
	bool tx_active;
	bool pmac_enabled;
	__u8 verify_status;
	__u32 verify_time;
	__u32 max_verify_time;
	__u32 add_frag_size;
};

int ethtool_mm_get_state(const char *ifname, struct ethtool_mm *mm);
int ethtool_mm_change_tx_enabled(const char *ifname, bool enabled, bool verify,
				 u32 verify_time);
int ethtool_mm_change_pmac_enabled(const char *ifname, bool enabled);
int ethtool_mm_change_add_frag_size(const char *ifname, u32 add_frag_size);

#endif

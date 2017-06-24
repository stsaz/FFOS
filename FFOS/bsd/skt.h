/**
Copyright (c) 2014 Simon Zolin
*/

#include <sys/socket.h>


static FFINL int ffskt_deferaccept(ffskt sk, int enable)
{
	struct accept_filter_arg af;
	if (enable) {
		memset(&af, 0, sizeof(struct accept_filter_arg));
		strcpy(af.af_name, "dataready");
	}
	return setsockopt(sk, SOL_SOCKET, SO_ACCEPTFILTER, (enable ? &af : NULL), sizeof(struct accept_filter_arg));
}

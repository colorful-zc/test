#include <cstdio>
#include "game_svr.h"
#include "server/comm/log_manager.hpp"
#include "server/comm/base/mempool.h"
#include "server/comm/xy_name.h"
#include "server/comm/cch.hpp"

#pragma comment(lib, "libprotobuf.lib")

svr_base* g_svr = NULL;


int main(int argc, char* argv[])
{
	cch::set_close_handler();
	XY_Name.init();

	LogMgr.init();
	LogMgr.start();
	LogMgr.Log(LOG_SYSTEM, "\n\n***********start GameSvr server***********\n");

	g_svr = new game_svr();
	g_svr->run();
    //delete g_svr;

	LogMgr.close();
	printf("******server closed******\n");
	return 0;
}

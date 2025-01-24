#include <tchar.h>
#include<iostream>
#include<array>
#include<string>
#include<stdlib.h>
#include<dnsPoisonCacheClear.h>

using namespace std;

namespace helperFunctions{
    static int runCommandWithSystem(const std::string_view &command){

       int result = std::system(command.data());

       return result;
    }
}

int _tmain(int argc, _TCHAR* argv[])
{


	//std::string exitPreventer = "";

    int StatusFlushDNS = 0;
    int StatusArpcache = 0;
    int StatusFlushRoute = 0;
    int StatusNetBiosStatRegistaryRemovable = 0;
    int StatusNetBiosStatRegistaryRemovableRR = 0;


	const std::string_view flushDns = "ipconfig /flushdns";
	const std::string_view arpCache = "netsh interface ip delete arpcache";
	const std::string_view routeClear = "route -f";
	const std::string_view netBiosClear = "powershell.exe nbtstat -R";
	const std::string_view netBiosPurge = "powershell.exe nbtstat -RR";


    StatusFlushDNS = helperFunctions::runCommandWithSystem(flushDns.data());
   	StatusArpcache = helperFunctions::runCommandWithSystem(arpCache.data());
    StatusFlushRoute = helperFunctions::runCommandWithSystem(routeClear.data());
    StatusNetBiosStatRegistaryRemovable = helperFunctions::runCommandWithSystem(netBiosClear.data());
    StatusNetBiosStatRegistaryRemovableRR = helperFunctions::runCommandWithSystem(netBiosPurge.data());

    //std::cout << " clue to resource ";
    //std::cout << StatusNetBiosStatRegistaryRemovable;
    //std::cout << StatusNetBiosStatRegistaryRemovableRR;

    //std::cin >> exitPreventer;
    //exitPreventer = "";
}
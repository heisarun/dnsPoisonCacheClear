@echo off
start /B ipconfig /flushdns
start /B netsh interface ip delete arpcache
start /B route -f
start /B nbtstat -R
start /B nbtstat -RR

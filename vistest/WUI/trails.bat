@echo off
:: generate terrain with &GEOM
set option=-geom

set dem2fds=..\intel_win_64\dem2fds_win_64.exe
::set dem2fds=dem2fds

%dem2fds% %option% -show -dir %userprofile%\terrain\trails trails.in 
%dem2fds% %option% -show -dir %userprofile%\terrain\trails trails2.in 
%dem2fds% %option%       -dir %userprofile%\terrain\trails trails4.in 

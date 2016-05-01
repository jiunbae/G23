@echo off
echo Installing OpenGL...

copy glut.dll "C:\Windows\System32\glut.dll"
copy glut32.dll "C:\Windows\System32\glut32.dll"
copy glut.dll "C:\Windows\SysWoW64\glut.dll"
copy glut32.dll "C:\Windows\SysWoW64\glut32.dll"
copy glut.lib "C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\lib\glut.lib"
copy glut32.lib "C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\lib\glut32.lib"
copy glut.h "C:\Program Files (x86)\Windows Kits\8.1\Include\um\gl\glut.h"

echo Finshed!
@echo off
mkdir build
pushd build
cl  /nologo /Za /Zi ..\source\main.c ..\source\list.c ..\source\darray.c ..\source\string.c
popd build

set "srcdir=src"
set "builddir=build"

pushd "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\"
call "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\Tools\VsDevCmd.bat"
popd

if not exist %builddir% mkdir %builddir%
cl "%srcdir%\main.c" C:\libjpeg-turbo\lib\turbojpeg-static.lib /Fo"%builddir%\main.o" /Fe"%builddir%\neovis.exe" /I C:\libjpeg-turbo\include
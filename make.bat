set "srcdir=src"
set "builddir=build"

pushd "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\"
call "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\Tools\VsDevCmd.bat"
popd

if not exist %builddir% mkdir %builddir%
cl "%srcdir%\main.c" C:\libjpeg-turbo\lib\turbojpeg-static.lib /Fo"%builddir%\image-processing.o" /Fe"%builddir%\image-processing.exe" /I C:\libjpeg-turbo\include
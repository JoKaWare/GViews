del /S *.sln
del /S *.ncb
del /S *.vcproj
del /S *.vcproj.*
del /S *.ncb
del /S *.pdb
del /S *.obj
del /S *.idb
del /S *.pch
del /S build\release\*.exe 
rd /S /Q build\release\lib
rd /S /Q build\release\obj
del /S build\debug\*.exe
rd /S /Q build\debug\lib 
rd /S /Q build\debug\obj
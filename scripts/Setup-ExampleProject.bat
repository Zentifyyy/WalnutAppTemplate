@echo off

pushd ..
Walnut\vendor\bin\premake\Windows\premake5.exe --file=Build-Walnut-ExampleProject.lua vs2022
popd
pause
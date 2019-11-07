# xllproject

Template for Excel add-ins.

## Install the xll12 library

If your project is not a git repository then you should clone the xll12 libary in your project directory.

> `git clone https://github.com/keithalewis/xll12.git`

If your project is a git repository then you should add the xll12 library as a submodule.

> `git submodule add https://github.com/keithalewis/xll12.git`

## Building

Set the `Configuration` (Debug or Release) and `Platform` (x86 or x64) and build the `template` project.  
The platform must be the same as Excel: x86 for 32-bit or x64 for 64-bit.

## Debugging

To debug an add-in you must tell Visual Studio the full path to the Excel executable and what add-in to load.  
In the project `Properties` in the `Debugging` tab the `Command` should be 

> `$(registry:HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\App Paths\excel.exe)`

To have Excel open your add-in when debugging and specify the default directory set `Command Arguments` to be 

> `"$(TargetPath)" /p "$(ProjectDir)"`

Set the configuration to `Debug|x86` if using 32-bit Excel or `Debug|x64` for 64-bit Excel.
Set breakpoints by clicking on the left boarder at the line you want to stop at, then hit `F5` to start debugging.


# Codeblocks usefull settings

## Autoformatter

+ To autoformat your code : ```Plugins -> Source Code Autoformatter (A-Style)```
+ To assign a keyboard shortcut : ```Settings -> Editor -> Keyboard shortcuts -> Plugins -> Source code formatter (AStyle)```

## Debugger

+ Setting path for debugger : ```Settings -> Debugger -> Default -> Executable Path```
	* Path is usually : ```ProgramFiles(x84)/CodeBlocks/bin/gdb.exe```

## C99 Standard

In C99, declaring variables in a for loop is permitted :  

```for(int i = 0; i < 99; ++i){}```  

To take advantage of this, we can enable c99 support in our codeblocks compiler by doing this :  
```Settings -> Compiler -> Other options``` and in the white box enter ```-std=c99```. Save and close.

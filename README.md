(These Markdown codes are translated from Chinese to English, and there may be some errors.)

(这些Markdown代码是用中文翻译至英语的，可能有些错误。)

# Kris's MEMZ

> **Changed by MEMZ's source code | Kris's MEMZ(include Change Master-Boot-Recoder[MBR]) **

> Changed content is Visual Studio 2015 is not required.
> 
> But you can also use Visual Studio 2015 for simpler cmpilation
>
> There are more interesting functions!
> 
> In the way you like :D

**<u>Don't use it to do illegal things. The code is not confused&encrypted!</u>**
**Modifying MBR function not enabled by default**

Compile directives (Visual Studio 2015 is not required):

`g++ main.cpp -lgdi32 -o MEMZ.exe -std=c++11 -lwinmm -Os -ffunction-sections -fdata-sections -static -Wall -Wextra -fexec-charset=GBK -finput-charset=UTF-8`

<br/>

The program is compiled using AppVeyor test, so you don't have to worry about the compilation failure after downloading.

# Kris的MEMZ

> **由MEMZ的源代码更改|Kris的MEMZ（包括更改主引导记录[MBR]） **

> 更改的内容是不需要Visual Studio 2015。
>
> 但您也可以使用Visual Studio 2015进行更简单<s>(复杂)</s>的编译
>
> 还有更多有趣的行为！
> 
> 按你喜欢的方式来 :D

**<u>不要用它做违法的事情。代码没有混淆或加密!</u>**
**修改MBR功能未默认开启!**

编译指令（不需要Visual Studio 2015）：

`g++ main.cpp -lgdi32 -o MEMZ.exe -std=c++11 -lwinmm -Os -ffunction-sections -fdata-sections -static -Wall -Wextra -fexec-charset=GBK -finput-charset=UTF-8`

<br/>

该程序是使用AppVeyor进行编译测试的，因此您不必担心下载后编译失败。

REM Build Bat File
REM Precheck the Resource 
"C:\Program Files\MRE SDK V3.0.00\tools\ResEditor\CmdShell.exe" save  "D:\MyGitHub\Textts\Textts.vcproj"
REM Copmile c file 
"C:\Program Files (x86)\CodeSourcery\Sourcery_CodeBench_Lite_for_ARM_EABI\Bin\arm-none-eabi-gcc" -c -fpic -g -mcpu=arm7tdmi-s -fvisibility=hidden -mthumb -mlittle-endian -O2 -D__MRE_COMPILER_GCC__ -fno-exceptions -fno-non-call-exceptions -o "D:\MyGitHub\Textts\arm\gccmain.o" -c "C:\Program Files\MRE SDK V3.0.00\lib\MRE30\src\gccmain.c"      -D _MINIGUI_LIB_ -D _USE_MINIGUIENTRY -D _NOUNIX_ -D _FOR_WNC -D __MRE_SDK__ -D   __MRE_VENUS_NORMAL__  -D  __MMI_MAINLCD_240X320__ -I "C:\Program Files\MRE SDK V3.0.00\include" -I "C:\Program Files\MRE SDK V3.0.00\include\service" -I "D:\MyGitHub\Textts\include" -I "D:\MyGitHub\Textts\include\service" -I "D:\MyGitHub\Textts\include\component" -I "D:\MyGitHub\Textts\ResID" -I "D:\MyGitHub\Textts\src\app\widget" -I "D:\MyGitHub\Textts\src\app\launcher" -I "D:\MyGitHub\Textts\src\app\wallpaper" -I "D:\MyGitHub\Textts\src\app\screen_lock" -I "D:\MyGitHub\Textts\include\service" -I "D:\MyGitHub\Textts\include\component" -I "D:\MyGitHub\Textts\include\service" -I "D:\MyGitHub\Textts\src\framework" -I "D:\MyGitHub\Textts\src\framework\ui_core\base" -I "D:\MyGitHub\Textts\src\framework\ui_core\mvc" -I "D:\MyGitHub\Textts\src\framework\ui_core\pme" -I "D:\MyGitHub\Textts\src\framework\mmi_core" -I "D:\MyGitHub\Textts\src\ui_engine\vrt\interface" -I "D:\MyGitHub\Textts\src\component" -I "D:\MyGitHub\Textts\src\ui_engine\framework\xml" -I "D:\MyGitHub\Textts"
REM Copmile c file 
"C:\Program Files (x86)\CodeSourcery\Sourcery_CodeBench_Lite_for_ARM_EABI\Bin\arm-none-eabi-gcc" -c -fpic -g -mcpu=arm7tdmi-s -fvisibility=hidden -mthumb -mlittle-endian -O2 -D__MRE_COMPILER_GCC__ -fno-exceptions -fno-non-call-exceptions -o "D:\MyGitHub\Textts\arm\Textts.o" -c "d:\MyGitHub\Textts\Textts.c"      -D _MINIGUI_LIB_ -D _USE_MINIGUIENTRY -D _NOUNIX_ -D _FOR_WNC -D __MRE_SDK__ -D   __MRE_VENUS_NORMAL__  -D  __MMI_MAINLCD_240X320__ -I "C:\Program Files\MRE SDK V3.0.00\include" -I "C:\Program Files\MRE SDK V3.0.00\include\service" -I "D:\MyGitHub\Textts\include" -I "D:\MyGitHub\Textts\include\service" -I "D:\MyGitHub\Textts\include\component" -I "D:\MyGitHub\Textts\ResID" -I "D:\MyGitHub\Textts\src\app\widget" -I "D:\MyGitHub\Textts\src\app\launcher" -I "D:\MyGitHub\Textts\src\app\wallpaper" -I "D:\MyGitHub\Textts\src\app\screen_lock" -I "D:\MyGitHub\Textts\include\service" -I "D:\MyGitHub\Textts\include\component" -I "D:\MyGitHub\Textts\include\service" -I "D:\MyGitHub\Textts\src\framework" -I "D:\MyGitHub\Textts\src\framework\ui_core\base" -I "D:\MyGitHub\Textts\src\framework\ui_core\mvc" -I "D:\MyGitHub\Textts\src\framework\ui_core\pme" -I "D:\MyGitHub\Textts\src\framework\mmi_core" -I "D:\MyGitHub\Textts\src\ui_engine\vrt\interface" -I "D:\MyGitHub\Textts\src\component" -I "D:\MyGitHub\Textts\src\ui_engine\framework\xml" -I "D:\MyGitHub\Textts"
REM Link app 
"C:\Program Files (x86)\CodeSourcery\Sourcery_CodeBench_Lite_for_ARM_EABI\Bin\arm-none-eabi-gcc" -o "D:\MyGitHub\Textts\Textts.axf"  "D:\MyGitHub\Textts\arm\gccmain.o"  "D:\MyGitHub\Textts\arm\Textts.o" -fpic -msvr4-struct-return -pie  -T "C:\Program Files\MRE SDK V3.0.00\lib\MRE30\armgcc\scat.ld" -l:"C:\Program Files\MRE SDK V3.0.00\lib\MRE30\armgcc\percommon.a" -l:"C:\Program Files\MRE SDK V3.0.00\lib\MRE30\armgcc\persmsper.a" -l:"C:\Program Files\MRE SDK V3.0.00\lib\MRE30\armgcc\percontact.a" -l:"C:\Program Files\MRE SDK V3.0.00\lib\MRE30\armgcc\permms.a" -l:"C:\Program Files\MRE SDK V3.0.00\lib\MRE30\armgcc\persmsmng.a" -l:"C:\Program Files\MRE SDK V3.0.00\lib\MRE30\armgcc\perfile.a" -l:"C:\Program Files\MRE SDK V3.0.00\lib\MRE30\armgcc\persim.a" -l:"C:\Program Files\MRE SDK V3.0.00\lib\MRE30\armgcc\persmssp.a" -l:"C:\Program Files\MRE SDK V3.0.00\lib\MRE30\armgcc\persysstorage.a" -l:"C:\Program Files\MRE SDK V3.0.00\lib\MRE30\armgcc\persysfile.a"
REM Pack resource to app 
"C:\Program Files\MRE SDK V3.0.00\tools\ResEditor\CmdShell.exe" pack -silent -resolution 240x320 -o "D:\MyGitHub\Textts\Textts.pkd" -e AXF "D:\MyGitHub\Textts\Textts.vcproj" "D:\MyGitHub\Textts\Textts.axf"
REM Add tag infromation 
"C:\Program Files\MRE SDK V3.0.00\tools\PackDigist.exe" "D:\MyGitHub\Textts\Textts.vcproj" "Textts" "0.1.0" "RDZDX" "0" "NotSupportBg" "Not Support rotate" "Textts" "Textts" "Textts" "9246012102087182" "content" " SMS(person) Contact MMS SMSMng File SIM card SMS(SP) SysStorage SysFile" "vxp" "GCC" "PKD" "UnCompress" "NoVPI" "Adaptable" "15728960" "UnSysMemAble" "
    " "-1" "UNPUSH" "-1" ""  "UnAutoStart"  "UnTransferImg" "NoIdleShortcut"  D:\MyGitHub\Textts\arm D:\MyGitHub\Textts\build.log


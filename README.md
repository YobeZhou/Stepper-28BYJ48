# 前言
&emsp;最近做的一个项目涉及对步进电机的控制，一开始时打算在树莓派中直接控制驱动步进电机，但是由于需要达到对步进电机最精确的控制需要有精确到微秒级PWM；然而Linux系统很繁忙，最多只能达到毫秒级别的控制，所以对于安装了Raspbian的树莓派达不到我们要求的精确控制。由此自然联想到了使用单片机进行辅助控制，而其中使用Arduino最为简单，因此最终选择Arduino作为项目的辅助控制外设模块。

# 项目简介
&emsp;本文实现了对五线四相八拍步进电机（28BYJ8）的较为精确的控制，同时加入了EEPROM记录的功能，在运行过程中能记录步进电机目前的位置，在意外掉电重启后能定位自身所处角度并恢复到设定的位置。

&emsp;步进电机是一种将电脉冲转化为角位移的执行机构。通俗一点讲：当步进驱动器接收到一个脉冲信号，它就驱动步进电机按设定的方向转动一个固定的角度（及步进角）。我们可以通过控制脉冲个来控制角位移量，从而达到准确定位的目的；同时亦可通过控制脉冲频率来控制电机转动的速度和加速度，从而达到调速的目的。
步进电机28BYJ48型四相八拍电机，电压为DC5V—DC12V。当对步进电机施加一系列连续不断的控制脉冲时，它可以连续不断地转动。每一个脉冲信号对应步进电机的某一相或两相绕组的通电状态改变一次，也就对应转子转过一定的角度（一个步距角）。当通电状态的改变完成一个循环时，转子转过一个齿距。四相步进电机可以在不同的通电方式下运行，常见的通电方式有单（单相绕组通电）四拍（A-B-C-D-A...），双（双相绕组通电）四拍（AB-BC-CD-DA-AB-...），八拍（A-AB-B-BC-C-CD-D-DA-A...）
``` C
uchar code CCW[8]={0x08,0x0c,0x04,0x06,0x02,0x03,0x01,0x09};   //逆时钟旋转相序表
uchar code CW[8]={0x09,0x01,0x03,0x02,0x06,0x04,0x0c,0x08};    //正时钟旋转相序表
```
# 硬件模块
&emsp;接线图请参考代码注释，使用的硬件模块如下：
&emsp;五线四相八拍步进电机（28BYJ8）：
<div align=center><img width="450" height="450" src="https://github.com/YobeZhou/Stepper-28BYJ48/blob/master/images/五线四相八拍步进电机（28BYJ8）.jpg"/></div>

&emsp;ULN2003驱动模块：
<div align=center><img width="450" height="450" src="https://github.com/YobeZhou/Stepper-28BYJ48/blob/master/images/ULN2003驱动模块.jpg"/></div>

&emsp;全局概览：
<div align=center><img width="450" height="450" src="https://github.com/YobeZhou/Stepper-28BYJ48/blob/master/images/IMG_3450.JPG"/></div>

&emsp;更多内容请移步我的[个人博客](https://zhouyuebiao.cn)

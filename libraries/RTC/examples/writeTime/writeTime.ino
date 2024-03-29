/* 
* Filename:    writeTime.ino
* Revision:    1.0
* Date:        2019/06/03
* Author:      hceng
* Email:       huangcheng.job@foxmail.com
* Website:     http://www.100ask.net/
* Function:    Write Real Time ClockM.
* Notes:       Onboard RTC at I2C0.
* Description: 
* 1. 实例化RTC，传入参数为对应的I2C接口编号；
* 2. 设置rtc的各个参数，含义/范围如下：
+----------+-----------+------------+-----------------------------------------+
| variable |  meaning  |    range   |                   note                  |
+----------+-----------+------------+-----------------------------------------+
|   year   |     年    |  2000-2099 |                                         |
+----------+-----------+------------+-----------------------------------------+
|   month  |     月    |    1-12    |                                         |
+----------+-----------+------------+-----------------------------------------+
|    day   |     日    |    1-31    |                                         |
+----------+-----------+------------+-----------------------------------------+
|   week   |    星期   |     0-6    |       0为周日，1为星期一，以此类推      |
+----------+-----------+------------+-----------------------------------------+
|   hour   |     时    |    00-23   |                  24进制范围             |
+----------+-----------+------------+-----------------------------------------+
|  minute  |     分    |    0-59    |                                         |
+----------+-----------+------------+-----------------------------------------+
|  second  |     秒    |    0-59    |                                         |
+----------+-----------+------------+-----------------------------------------+

* 3. 使用setTime()设置时间；
* 4. 循环里，间隔1S,使用timePrintf()打印RTC模块时间
*/
#include <Arduino.h>
#include <rtc.h>

int main(int argc, char **argv)
{
    RTC rtc(1);
    
    rtc.year = 2019;
    rtc.month = 6;
    rtc.day = 3;
    rtc.week = 1;

    rtc.hour = 23;  
    rtc.minute = 59;
    rtc.second = 57;
    
    rtc.setTime();
    
    while(1)
    {
        rtc.timePrintf();
        sleep(1);
    } 
}
